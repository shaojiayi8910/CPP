#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h>
#include <iostream>

#include <iterator>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

//在msys2下面，这个头文集是在doctest的子目录下面的，所以加上这个子目录
#include "doctest/doctest.h"



// for the row in the cad_table, we create a cad_table_row class
// the code is mainly follow the discussion here:
// ORM and rowset · Issue #1020 · SOCI/soci — https://github.com/SOCI/soci/issues/1020
// bulk ORM partial "insert into TABLE(c1, c5, c7, ...) values(v1, v5, v7, ...)" does not work if I don't specify all the uses
// Issue #798 · SOCI/soci — https://github.com/SOCI/soci/issues/798
struct cad_table_row
{
    cad_table_row(){}
    cad_table_row(const cad_table_row& old)
    {
        cad_id = old.cad_id;
        cam_id = old.cam_id;
        product_id = old.product_id;
        filepath = old.filepath;
        timestamp = old.timestamp;
    }
    int cad_id;
    int cam_id;
    int product_id;
    std::string filepath;
    std::tm timestamp;
};

namespace soci
{
    template<>
    struct type_conversion<cad_table_row>
    {

        typedef values base_type;

        static void from_base(const values& v, indicator ind, cad_table_row& row)
        {
            row.cad_id = v.get<int>("cad_id", -1);
            row.cam_id = v.get<int>("cam_id", -1);
            row.product_id = v.get<int>("product_id", -1);
            row.filepath = v.get<std::string>("filepath", "");
            row.timestamp = v.get<std::tm>("timestamp", std::tm());

        }

        static void to_base(const cad_table_row& row, values& v, indicator& ind)
        {
            v.set("cad_id", row.cad_id);
            v.set("cam_id", row.cam_id);
            v.set("product_id", row.product_id);
            v.set("filepath", row.filepath);
            v.set("timestamp", row.timestamp);

            ind = i_ok;
        }
    };
}



TEST_CASE("MySQL test for the heatmap database")
{
    {
        soci::session sql(soci::mysql, "dbname=heatmap user=root password=123456");

        // 往数据库里面添加一个记录
        // 疑问：这个timestamp类型的变量怎么添加数据？
        // 注意在字符串中间的斜杠的方向
        try
        {
            soci::indicator ind = soci::i_null;
            std::tm time;
            sql << "INSERT INTO cad_table (cam_id, product_id, filepath, timestamp)"
                   "VALUES (:cam_id, :product_id, :filepath, :timestamp)",
                   soci::use(300), soci::use(800), soci::use(std::string("abc/def/xyz.dxf")), soci::use(time, ind);

            // add another row, which does not contains the last timestamp column, it is called partial insert
            sql << "INSERT INTO cad_table (cam_id, product_id, filepath)"
                   "VALUES (:cam_id, :product_id, :filepath)",
                   soci::use(300), soci::use(800), soci::use(std::string("abc/def/xyz.dxf"));


            soci::rowset<soci::row> rows = ( sql.prepare << "SELECT * FROM cad_table");

            // print the number of rows in the result set
            // std::cout << "Result set size: " << rows.size() << std::endl;

            soci::rowset<cad_table_row> rs = (sql.prepare << "SELECT * FROM cad_table");

            // the row can only be looped once, so it is better to copy it to a vector first
            // see discussion here: ORM: the query result rowset becomes invalid after a for loop · Issue #1064 · SOCI/soci — https://github.com/SOCI/soci/issues/1064

//            // Loop through rowset using a range-based for loop
//            for (const auto& row : rs) {
//                // Do something with the current row
//                // For example, print the value of a column
//                std::cout << row.cad_id << std::endl;
//            }
//
//            // Loop through rowset using a standard for loop
//            for (auto it = rs.begin(); it != rs.end(); ++it) {
//                const cad_table_row& row = *it;
//                // Do something with the current row
//                // For example, print the value of a column
//                std::cout << row.cad_id << std::endl;
//            }

            std::vector<cad_table_row> ret{std::make_move_iterator(rs.begin()), std::make_move_iterator(rs.end())};
            //std::vector<cad_table_row> ret{rs.begin(), rs.end()};

            int s = ret.size();

            std::cout << s << std::endl;

            for (int i = 0; i< ret.size(); i++)
            {
                std::cout << ret[i].cad_id << std::endl;
            }

        }
        catch(const soci::soci_error& e)//Catch the exception and output the exception message
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        CHECK( 1 == 1 );
    }
}

class person
{
public:
    person()
    {
        std::cout << "person constructor" << std::endl;
    }

    person(int id_, std::string name_, int age_, float weight_, std::tm t_)
    {
        id = id_;
        name = name_;
        age = age_;
        weight = weight_;
        time = t_ ;
    }

    person(const person & old)
    {
        id = old.id;
        name = old.name;
        age = old.age;
        weight = old.weight;
        time = old.time;
        std::cout << "copy constructor" << std::endl;
    }

    ~person()
    {
        std::cout << "destroy id = " << id << std::endl;
    }
public:
    int id;
    std::string name;
    int age;
    float weight; //Kg
    std::tm time;
};

namespace soci
{
    template<>
    struct type_conversion<person>
    {

        typedef values base_type;

        static void from_base(const values& v, indicator ind, person& row)
        {
            row.id =   v.get<int>("id", -1);
            row.name = v.get<std::string>("name", "");
            row.age =  v.get<int>("age", 0);
            row.weight = v.get<double>("weight", 0.0);
            row.time = v.get<std::tm>("time", std::tm{});

        }

        static void to_base(const person& row, values& v, indicator& ind)
        {
            v.set("id",   row.id);
            v.set("name", row.name);
            v.set("age",  row.age);
            v.set("weight",  double(row.weight));
            v.set("time", row.time);

            ind = i_ok;
        }
    };
}



TEST_CASE("MySQL ORM test")
{
    {
        soci::session sql(soci::mysql, "dbname=testdb user=root password=123456");
        try
        {

            // 重新创建一个新的table，把老的table直接删掉
            // 注意，sql命令会把之前的测试的数据库给覆盖掉！
            sql << "DROP TABLE IF EXISTS `testtable`";
            // 增加一个表，注意最后一列是时间戳
            sql << R"(
                    CREATE TABLE IF NOT EXISTS `testtable` (
                      `id` int NOT NULL AUTO_INCREMENT,
                      `name` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
                      `age` int DEFAULT NULL,
                      `weight` float DEFAULT NULL,
                      `time` timestamp NULL DEFAULT (now()),
                      PRIMARY KEY (`id`)
                    ) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci
            )";

            // 添加若干记录
                    // add another row, which does not contains the last timestamp column, it is called partial insert
            sql << "INSERT INTO testtable (name, age) VALUES (:name, :age)", soci::use(std::string("Bob")), soci::use(50);


            // try to add some "person" to the table
            // Assume that you have a vector of rows to insert
            std::vector<person> rows = {
                {0, "John", 30, 23.4, std::tm{}},
                {0, "Jane", 25, 78.9, std::tm{}},
                {0, "Bob",  40, 34.8,  std::tm{}}
            };

            // Create a statement to insert a row into the table
            person p;
            soci::statement stmt = (sql.prepare << "INSERT INTO testtable (id, name, age, weight) VALUES (:id, :name, :age, :weight)", soci::use(p));

            for (int i=0; i<rows.size(); i++)
            {
                // Bind the placeholders to the values of each row
                p = rows[i];

                // Execute the statement to insert the rows into the table
                stmt.execute(true);
                long long id;
                bool result = sql.get_last_insert_id("testtable", id);
                CHECK(result == true);
                std::cout << "last insert id = " << id << std::endl;

            }

            // 读取结果并进行打印
            soci::rowset<person> rs = (sql.prepare << "SELECT * FROM testtable");

//            // Loop through rowset using a range-based for loop
//            std::cout << "first for loop" << std::endl;
//            for (const auto& row : rs) {
//                std::cout << row.id << std::endl;
//            }
//            std::cout << "second for loop" << std::endl;
//            for (const auto& row : rs) {
//                std::cout << row.id << std::endl;
//            }
//
//            // Loop through rowset using a standard for loop
//            // soci::rowset<person>::const_iterator
//            for (soci::rowset_iterator it = rs.begin(); it != rs.end(); ++it) {
//                const person& row = *it;
//                // Do something with the current row
//                // For example, print the value of a column
//                std::cout << row.id << std::endl;
//            }

            std::vector<person> ret{std::make_move_iterator(rs.begin()), std::make_move_iterator(rs.end())};
            //std::vector<person> ret{rs.begin(), rs.end()};

            int s = ret.size();

            std::cout << "vector size =" << s << std::endl;

            for (int i = 0; i< ret.size(); i++)
            {
                std::cout << ret[i].id << std::endl;
            }

            for (int i = 0; i< ret.size(); i++)
            {
                std::cout << ret[i].id << std::endl;
                std::cout << ret[i].weight << std::endl;
            }

            // modify a record

            std::string newName = "Bob2";
            sql << "update testtable"
                    " set name = :name"
                    " where id = 2",
                    soci::use(newName, "name");

            // Delete the record by ID
            int id = 1;
            sql << "DELETE FROM testtable WHERE id = :id", soci::use(1);


        }
        catch(const soci::soci_error& e)//Catch the exception and output the exception message
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }


        CHECK( 1 == 1 );
    }
}


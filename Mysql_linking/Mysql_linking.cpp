#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h>
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

//在msys2下面，这个头文集是在doctest的子目录下面的，所以加上这个子目录
#include "doctest/doctest.h"


// pacman -S mingw-w64-x86_64-nlohmann-json
// json解析库
#include <nlohmann/json.hpp>
using json = nlohmann::json;

TEST_CASE("MySQL first test")
{
    {
        soci::session sql(soci::mysql, "dbname=testdb user=root password=201028");

        // 注意，sql命令会把之前的测试的数据库给覆盖掉！
        sql << "DROP TABLE IF EXISTS `testtable`";
        sql << R"(
                CREATE TABLE IF NOT EXISTS `testtable` (
                  `id` int NOT NULL AUTO_INCREMENT,
                  `name` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
                  `age` int DEFAULT NULL,
                  `Column 2` binary(50) DEFAULT NULL,
                  PRIMARY KEY (`id`)
                ) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci
        )";
        sql << R"(
                REPLACE INTO `testtable` (`id`, `name`, `age`, `Column 2`) VALUES
                        (1, 'aaa', 23,  _binary 0x7b22706964223a203130312c20226e616d65223a20226e616d6531227d000000000000000000000000000000000000000000),
                        (3, 'bbb', 43, NULL)
        )";

        int count;
        sql << "SELECT COUNT(*) FROM testtable", soci::into(count);

        // 看看这个testdb的数据库里面的表testtable里面，是否有2条记录，如果是，则测试通过！
        CHECK(count == 2);

        std::cout << "There are " << count << " rows in testtable" << std::endl;

        soci::rowset<soci::row> rows = (sql.prepare << "SELECT * FROM testtable");

        // 我们两行的数据在数据库中是这样的
        //     id      name      age        Column2
        //     1       aaa       23         {"pid": 101, "name": "name1"}
        //     3       bbb       43         空

//        for(soci::row& row : rows)
//        {
//            std::cout << "id = " << row.get<int>("id")
//                      << ", name = " << row.get<std::string>("name")
//                      << ", age = " << row.get<int>("age")
//                      << std::endl;
//        }


        // Get the first row
        auto iter = rows.begin();
        if (iter != rows.end())
        {
            // Access members of the first row
            int id;
            std::string name;

            id = iter->get<int>("id");
            name = iter->get<std::string>("name");
            CHECK(id == 1);
            CHECK(name == "aaa");

            std::string str = iter->get<std::string>("Column 2");

            json data = json::parse(str);

            //std::cout << str;

            int pid = data["pid"];

            std::cout << pid;

            CHECK(pid == 101);
        }
    }
}

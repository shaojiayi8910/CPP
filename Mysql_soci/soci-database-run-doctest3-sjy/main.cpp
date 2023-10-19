#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h>
#include <iostream>

#include <iterator>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

//在msys2下面，这个头文集是在doctest的子目录下面的，所以加上这个子目录
#include "doctest/doctest.h"

// 数据库的第一张表格，产品信息的表格
class basic_info
{
public:
    int         product_id;     /// ID值，自动增加
    std::string company_name;   /// 公司名称
    std::string project_name;   /// 项目名称
    std::string product_name;   /// 产品名称
    std::tm     timestamp;      /// 录入产品的时间，例如 2020-10-05 21:16:03
};

namespace soci
{
    template<>
    struct type_conversion<basic_info>
    {

        typedef values base_type;

        static void from_base(const values& v, indicator ind, basic_info& row)
        {
            row.product_id   =   v.get<int>("product_id", -1);
            row.company_name =   v.get<std::string>("company_name", "");
            row.project_name =   v.get<std::string>("project_name", "");
            row.product_name =   v.get<std::string>("product_name", "");
            row.timestamp    =   v.get<std::tm>("timestamp", std::tm());
        }

        static void to_base(const basic_info& row, values& v, indicator& ind)
        {
            v.set("product_id",     row.product_id);
            v.set("company_name",   row.company_name);
            v.set("project_name",   row.project_name);
            v.set("product_name",   row.product_name);
            v.set("timestamp",      row.timestamp);

            ind = i_ok;
        }
    };
}




TEST_CASE("MySQL test for the heatmap database")
{
    try
    {
        soci::session sql(soci::mysql, "dbname=heatmap user=root password=123456");
        soci::rowset<basic_info> rs = (sql.prepare << "SELECT * FROM basic_infos");
        std::vector<basic_info> ret{std::make_move_iterator(rs.begin()), std::make_move_iterator(rs.end())};
        int s = ret.size();

        std::cout << "table size = " << s << std::endl;

        for (int i = 0; i< ret.size(); i++)
        {
            std::cout << ret[i].product_id << std::endl;
        }
    }
    catch(const soci::soci_error& e)//Catch the exception and output the exception message
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    CHECK( 1 == 1 );
}




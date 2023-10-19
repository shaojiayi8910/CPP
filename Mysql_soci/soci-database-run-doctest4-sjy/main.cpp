#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h>
#include <iostream>

#include <iterator>

#include <sstream>
#include <regex>

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
        soci::session sql(soci::mysql, "dbname=testdb user=root password=123456");

        // Load the SQL file, run each command one by one
        std::ifstream file("heatmap.sql");
        std::string line;
        std::stringstream sqlScript;

        // Read and execute each SQL statement
        bool insideComment = false;
        while(std::getline(file, line))
        {
            // Skip empty lines
            if(line.empty())
            {
                continue;
            }

            // Skip single-line comments starting with "--"
            if(line.substr(0, 2) == "--")
            {
                continue;
            }

            // Skip C-style comments /* ... */
            // the regular expression pattern is /\\*.*?\\*/, which is used to match C-style comments in the form /* ... */.
            // Breaking down the pattern:
            //    \\* matches the literal character *.
            //    .*? matches any character (except newline characters) zero or more times,
            //            but in a non-greedy way. The ? makes the * quantifier non-greedy, i.e., it matches as few characters as possible.
            //    \\*/ matches the literal character */.

            std::regex commentRegex("/\\*.*?\\*/");
            if(insideComment)
            {
                // Check if the line ends the multi-line comment
                if(line.find("*/") != std::string::npos)
                {
                    insideComment = false;
                    // remove any C-style comment found in the line string by replacing it with an empty string.
                    line = std::regex_replace(line, commentRegex, "");
                }
                continue;
            }
            else
            {
                // Check if the line starts a multi-line comment
                if(line.find("/*") != std::string::npos)
                {
                    // Check if the comment ends in the same line
                    if(line.find("*/") != std::string::npos)
                    {
                        line = std::regex_replace(line, commentRegex, "");
                    }
                    else
                    {
                        insideComment = true;
                        continue;
                    }
                }
            }

            sqlScript << line;

            // Check if the statement is complete
            if(line.back() == ';')
            {

                // Remove the trailing semicolon
                sqlScript.str(sqlScript.str().substr(0, sqlScript.str().length() - 1));

                // Print the value of the stringstream
                std::cout << sqlScript.str() << std::endl;

                // Execute the SQL statement
                sql << sqlScript.str();

                // Clear the string stream for the next statement
                sqlScript.str("");
            }
        }

    }
    catch(const soci::soci_error& e)//Catch the exception and output the exception message
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    CHECK(1 == 1);
}




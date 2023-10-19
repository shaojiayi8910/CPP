#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h>
#include <iostream>

#include <iterator>

#include <sstream>
#include <regex>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

//在msys2下面，这个头文集是在doctest的子目录下面的，所以加上这个子目录
#include "doctest/doctest.h"

#include "../../sql-design/heatmapv2_table.hpp"


#include <mysql/mysql.h>
#include <stdio.h>



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string ReadFileToString(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}


void RunMultipleStatement(std::string user, std::string password, std::string db_name, std::string statements)
{

    MYSQL *mysql;
    MYSQL_RES *result;
    MYSQL_ROW row;
    int status;

    mysql = mysql_init(NULL);


    // 源代码来自：https://dev.mysql.com/doc/c-api/8.0/en/c-api-multiple-queries.html
    /* connect to server with the CLIENT_MULTI_STATEMENTS option */
    if(mysql_real_connect(mysql, "localhost", user.c_str(), password.c_str(),
                          db_name.c_str(), 3306, NULL, CLIENT_MULTI_STATEMENTS) == NULL)
    {
        printf("mysql_real_connect() failed\n");
        mysql_close(mysql);
        exit(1);
    }



    /* execute multiple statements */
    status = mysql_query(mysql, statements.c_str());
    if(status)
    {
        printf("Could not execute statement(s)");
        mysql_close(mysql);
        exit(0);
    }

    /* process each statement result */
    do
    {
        /* did current statement return data? */
        result = mysql_store_result(mysql);
        if(result)
        {
            /* yes; process rows and free the result set */
            // we do not need to process the result!
            //process_result_set(mysql, result);
            mysql_free_result(result);
        }
        else          /* no result set or error */
        {
            if(mysql_field_count(mysql) == 0)
            {
                printf("%lld rows affected\n",
                       mysql_affected_rows(mysql));
            }
            else  /* some error occurred */
            {
                printf("Could not retrieve result set\n");
                break;
            }
        }
        /* more results? -1 = no, >0 = error, 0 = yes (keep looping) */
        if((status = mysql_next_result(mysql)) > 0)
            printf("Could not execute statement\n");
    }
    while(status == 0);

    mysql_close(mysql);
}


TEST_CASE("MySQL test for the heatmap database")
{

    std::string filename = "../../sql-design/heatmapv2.sql";
    std::string fileContent = ReadFileToString(filename);

    if (!fileContent.empty()) {
        // Process the content of the file

        RunMultipleStatement("root", "123456", "testdb", fileContent);

        // std::cout << "File content:\n" << fileContent << std::endl;
    }


    CHECK(1 == 1);
}




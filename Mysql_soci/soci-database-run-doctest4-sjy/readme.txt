主要测试用sql创建数据库的各种表格问题

基本的代码来自chatGPT生成的如下程序：

#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h> // Include the MySQL backend for SOCI
#include <fstream>
#include <sstream>

int main() {
    soci::session sql(soci::mysql, "host=your_host dbname=your_database user=your_user password=your_password");

    // Load the SQL file
    std::ifstream file("tables.sql");
    std::string line;
    std::stringstream sqlScript;

    // Read and execute each SQL statement
    while (std::getline(file, line)) {
        // Skip empty lines and comments
        if (line.empty() || line.substr(0, 2) == "--") {
            continue;
        }

        sqlScript << line;

        // Check if the statement is complete
        if (line.back() == ';') {
            // Execute the SQL statement
            sql << sqlScript.str();

            // Clear the string stream for the next statement
            sqlScript.str("");
        }
    }

    return 0;
}

主要的目的是进行分号的识别，并进行逐个语句的运行

#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h>
#include <iostream>

int main()
{
    try
    {
        soci::session sql(soci::mysql, "dbname=heatmapv2 user=root password=201028");

        int count;
        sql << "SELECT COUNT(*) FROM testtable", soci::into(count);

        std::cout << "There are " << count << " rows in testtable" << std::endl;


        soci::rowset<soci::row> rows = (sql.prepare << "SELECT * FROM testtable");

        for(soci::row& row : rows)
        {
            std::cout << "id = " << row.get<int>("id")
                      << ", name = " << row.get<std::string>("name")
                      << ", age = " << row.get<int>("age")
                      << std::endl;
        }

    }
    catch(const soci::soci_error& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

#include <iostream>
#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h>

using namespace soci;
using namespace std;
int main()
{
    session sql(mysql, "dbname=testdb user=root password=123456");
//    int id = 4;
//    int age = 25;
//    std :: string name = "first test";
//    sql << "insert into testtable(id, name, age)"
//    " values(:id, :name, :age)",
//    use(id), use(name), use(age);
    int id_c=2;
    int age_c = 0;
    std :: string name_c;
    sql << "select name,age from testtable where id=:id",
    use(id_c),into(name_c), into(age_c);
    if (!sql.got_data())
    {
    std::cout << "no id =2 record" << endl;
    }
    std::cout << "id=2's name:"<<name_c <<endl<<"id=2's age:"<<age_c<<endl;

    int count;
    sql << "SELECT COUNT(*) FROM testtable", into(count);

    std::cout << "Number of testtable: " << count << std::endl;

    return 0;
}

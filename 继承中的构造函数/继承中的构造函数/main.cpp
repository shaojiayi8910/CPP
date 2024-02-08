#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<regex>
using namespace std;

////class A//基类
////{
////protected:
////	int z;
////private:
////	int x;
////public:
////	A()
////	{
////		cout << "A()" << endl;
////	}
////	~A()
////	{
////		cout << "~A" << endl;
////	}
////	A(int a, int b) : z(a), x(b) 
////	{ cout << "A(int a,int b)" << endl; }
////	int get_z()
////	{
////		return z;
////	}
////};
////class B : public A
////{
////public:
////	
////	B()
////	{
////		cout << "B()" << endl;
////	}
////	B(int a, int b):A(a,b)//派生类中可以指定基类中的某个构造函数
////	{
////		/*z = a;*/
////		cout << "B(int a , int b)" << endl;
////	}
////	~B()
////	{
////		cout << "~B" << endl;
////	}
////};
////int main()
////{
////	//实例化一个派生类对象
////	//B b;
////	B t(10, 20);
////	cout << t.get_z() << endl;
////	return 0;
////}
//class A
//{
//public:
//	A() : a_x(10),a_y(10)
//	{}
//	int a_x;
//	int a_y;
//
//};
//class B : public A
//{
//public:
//	B() : b_x(20), a_x(20) 
//	{
//		A::a_x = 30;//派生类内部访问同名的成员变量
//	}//a_x 是B类中
//	int b_x;
//	int a_x;//与基类中的成员变量的名字冲突了
//};
//int main()
//{//派生类中会不会继承重名的成员
//	cout << sizeof(B) << endl;//16 说明可以继承
//	B b;
//	cout << b.a_x << endl;//派生类中的成员变量
//	//通过派生类对象访问基类中的同名成员变量
//	cout << b.A::a_x << endl;
//	return 0;
//}
bool isIPv4(string IP)
{
    int dotcnt = 0;
    //数一共有几个.
    for (int i = 0; i < IP.length(); i++)
    {
        if (IP[i] == '.')
            dotcnt++;
    }
    //ipv4地址一定有3个点
    if (dotcnt != 3)
        return false;
    string temp = "";
    for (int i = 0; i < IP.length(); i++)
    {
        if (IP[i] != '.')
            temp += IP[i];
        //被.分割的每部分一定是数字0-255的数字
        if (IP[i] == '.' || i == IP.length() - 1)
        {
            if (temp.length() == 0 || temp.length() > 3)
                return false;
            for (int j = 0; j < temp.length(); j++)
            {
                if (!isdigit(temp[j]))
                    return false;
            }
            int tempInt = stoi(temp);
            if (tempInt > 255 || tempInt < 0)
                return false;
            string convertString = to_string(tempInt);
            if (convertString != temp)
                return false;
            temp = "";
        }
    }
    if (IP[IP.length() - 1] == '.')
        return false;
    return true;
}
int main()
{	
	
	//std :: regex pattern("(?:(?:1[0-9][0-9]\.)|(?:2[0-4][0-9]\.)|(?:25[0-5]\.)|(?:[1-9][0-9]\.)|(?:[0-9]\.)){3}(?:(?:1[0-9][0-9])|(?:2[0-4][0-9])|(?:25[0-5])|(?:[1-9][0-9])|(?:[0-9]))");
	//std::string ip = "192.168JIJIJIJ.12222222.122";
	//int res = std::regex_match (ip, pattern);
	//cout << res << endl;
    cout << isIPv4("123aaa.111.1.1") << endl;
	return 0;
}


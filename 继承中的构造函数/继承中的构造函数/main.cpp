#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<regex>
using namespace std;

////class A//����
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
////	B(int a, int b):A(a,b)//�������п���ָ�������е�ĳ�����캯��
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
////	//ʵ����һ�����������
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
//		A::a_x = 30;//�������ڲ�����ͬ���ĳ�Ա����
//	}//a_x ��B����
//	int b_x;
//	int a_x;//������еĳ�Ա���������ֳ�ͻ��
//};
//int main()
//{//�������л᲻��̳������ĳ�Ա
//	cout << sizeof(B) << endl;//16 ˵�����Լ̳�
//	B b;
//	cout << b.a_x << endl;//�������еĳ�Ա����
//	//ͨ�������������ʻ����е�ͬ����Ա����
//	cout << b.A::a_x << endl;
//	return 0;
//}
bool isIPv4(string IP)
{
    int dotcnt = 0;
    //��һ���м���.
    for (int i = 0; i < IP.length(); i++)
    {
        if (IP[i] == '.')
            dotcnt++;
    }
    //ipv4��ַһ����3����
    if (dotcnt != 3)
        return false;
    string temp = "";
    for (int i = 0; i < IP.length(); i++)
    {
        if (IP[i] != '.')
            temp += IP[i];
        //��.�ָ��ÿ����һ��������0-255������
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


#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//class A//����
//{
//protected:
//	int z;
//private:
//	int x;
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A" << endl;
//	}
//	A(int a, int b) : z(a), x(b) 
//	{ cout << "A(int a,int b)" << endl; }
//	int get_z()
//	{
//		return z;
//	}
//};
//class B : public A
//{
//public:
//	
//	B()
//	{
//		cout << "B()" << endl;
//	}
//	B(int a, int b):A(a,b)//�������п���ָ�������е�ĳ�����캯��
//	{
//		/*z = a;*/
//		cout << "B(int a , int b)" << endl;
//	}
//	~B()
//	{
//		cout << "~B" << endl;
//	}
//};
//int main()
//{
//	//ʵ����һ�����������
//	//B b;
//	B t(10, 20);
//	cout << t.get_z() << endl;
//	return 0;
//}
class A
{
public:
	A() : a_x(10),a_y(10)
	{}
	int a_x;
	int a_y;

};
class B : public A
{
public:
	B() : b_x(20), a_x(20) 
	{
		A::a_x = 30;//�������ڲ�����ͬ���ĳ�Ա����
	}//a_x ��B����
	int b_x;
	int a_x;//������еĳ�Ա���������ֳ�ͻ��
};
int main()
{//�������л᲻��̳������ĳ�Ա
	cout << sizeof(B) << endl;//16 ˵�����Լ̳�
	B b;
	cout << b.a_x << endl;//�������еĳ�Ա����
	//ͨ�������������ʻ����е�ͬ����Ա����
	cout << b.A::a_x << endl;
	return 0;
}
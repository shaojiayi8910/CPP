#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class A
{
public:
	void func()
	{
		cout<<"A::func()" << endl;
	}
};
class B : public A
{
public:
	void func()
	{
		cout << "B::func()" << endl;
	}
	void func(int x)
	{
		cout << "B::func(int x)" << endl;
	}
};
int main()
{
	B b;
	//b.func();//B::func
	//b.A::func();//A::func
	b.func(10);
	return 0;
}
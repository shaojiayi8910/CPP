#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class A//间接基类
{
public:
	int a_x;
};
class B : public A//直接基类
{
public:
	int b_x;
};
class C : public A//直接基类
{
public:
	int c_x;
};
//派生类
class D :public B, public C
{
public:
	int c_x;
	////B类的
	//int a_x
	//int b_x
	////C类的
	//int a_x
	//int c_x
};
class Animal//虚基类
{
public:
	string name;
	int age;
};
class Buru : virtual public Animal
{};
class Bird : virtual public Animal
{};
class Bianfu : public Buru, public Bird//出现了两种姓名与年龄，所以使用虚继承
{};
int main()
{
	cout << sizeof(D) << endl;
	D d;
	//d.a_x = 100;来自间接基类的成员变量不明确,使用虚继承解决
	d.B::a_x = 100;
	cout << sizeof(Bianfu) << endl;//64
	cout << sizeof(Animal) << endl;//48


	return 0;
}
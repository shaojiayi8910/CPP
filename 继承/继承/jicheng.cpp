#define  _CRT_SECURE_NO_WARNINGS
#include<string>
#include<stdio.h>
#include <iostream>
using namespace std;
class Person
{
public:
	void print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name;
	int _age;
};
class Student : public Person//student派生类
{
protected:
	string _stuid;
public:
	void set_age(int age)
	{
		_age = age;
	}
	int get_age()
	{
		return _age;
	}
};
class Teacher : public Person
{
protected:
	string _jodid;

};//基类中的private成员在派生类中也是无法访问
//基类中的protect成员可以在派生类中访问
int main()
{
	Student s;
	Teacher t;
	s.set_age(10);
	cout << s.get_age() << endl;
	return 0;
}
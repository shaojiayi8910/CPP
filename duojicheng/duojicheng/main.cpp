#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class A//��ӻ���
{
public:
	int a_x;
};
class B : public A//ֱ�ӻ���
{
public:
	int b_x;
};
class C : public A//ֱ�ӻ���
{
public:
	int c_x;
};
//������
class D :public B, public C
{
public:
	int c_x;
	////B���
	//int a_x
	//int b_x
	////C���
	//int a_x
	//int c_x
};
class Animal//�����
{
public:
	string name;
	int age;
};
class Buru : virtual public Animal
{};
class Bird : virtual public Animal
{};
class Bianfu : public Buru, public Bird//�������������������䣬����ʹ����̳�
{};
int main()
{
	cout << sizeof(D) << endl;
	D d;
	//d.a_x = 100;���Լ�ӻ���ĳ�Ա��������ȷ,ʹ����̳н��
	d.B::a_x = 100;
	cout << sizeof(Bianfu) << endl;//64
	cout << sizeof(Animal) << endl;//48


	return 0;
}
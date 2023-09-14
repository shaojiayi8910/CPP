#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<math.h>
typedef unsigned int u32_t;
using namespace std;
class Shape
{
public:
	virtual double getPermiter() = 0;
	virtual double getArea() = 0;
};
//派生三角形类
class Trangle : public Shape
{
public:
	Trangle() : _a(10), _b(10), _c(10) {}
	Trangle(u32_t a, u32_t b, u32_t c) : _a(a),_b(b), _c(c){}
	double getPermiter()
	{
		return double(_a + _b + _c);
	}
	double getArea()
	{
		double p = 0.5 * (_a + _b + _c);
		return sqrt(p * (p - _a) * (p - _b) * (p - _c));
	}
private:
	u32_t _a, _b, _c;
	u32_t _permiter;
	double _area;
};
class Cirle : public Shape
{
private:
	double _r;//半径
	static double pi;//声明
	u32_t _permiter;
	double _area;
public:
	Cirle() : _r(10) {}
	 double getPermiter() ;
	 double getArea() ;
};
//定义一个静态成员变量
double Cirle::pi = 3.14;
double Cirle::getPermiter()
{
	return 2 * pi * _r;
}
double Cirle::getArea()
{
	return pi*_r*_r;
}
int main()
{
	Trangle x;
	//cout << x.getPermiter() << endl;
	Cirle x2;
	//cout << x2.getPermiter() << endl; 
	//cout << x2.getArea() << endl;
	//用一个数组来保存一个三角形与圆
	//用多态来实现
	Shape* shape[2];
	shape[0] = &x;
	shape[1] = &x2;
	for (int i = 0; i < 2; i++)
	{
		cout<<shape[i]->getArea()<<endl;
		cout<<shape[i]->getPermiter()<<endl;
	}
	return 0;
}
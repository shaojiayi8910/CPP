#include "Skill2.h"
#include<iostream>
using namespace std;

#define  _CRT_SECURE_NO_WARNINGS

Skill2::Skill2(const string& name, int damage, int CD) : Skill(name, damage, CD)
{	//使用派生类构造对象，会先调用基类的构造函数
	//基类private成员属性，需要手动调用基类中的带参数的构造函数
	
}

Skill2::~Skill2()
{
}
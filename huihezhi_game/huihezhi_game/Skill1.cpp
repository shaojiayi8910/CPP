#include "Skill1.h"
#include<iostream>
using namespace std;

#define  _CRT_SECURE_NO_WARNINGS

Skill1::Skill1(const string& name, int damage, int CD) : Skill(name, damage,CD)
{
	//����private��Ա���ԣ���Ҫ�ֶ����û����еĴ������Ĺ��캯��
	//ʹ�������๹����󣬻��ȵ��û���Ĺ��캯��
}

Skill1::~Skill1()
{
}


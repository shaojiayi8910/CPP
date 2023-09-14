#define  _CRT_SECURE_NO_WARNINGS
#include"Hero.h"
#include"Skill1.h"
#include<iostream>

using namespace std;
class Libai : public Hero
{
public:
	Libai(const string&, int life = 100, int attack = 5, int defend = 100);
	~Libai();
	//ÓµÓÐskill1¼¼ÄÜ
	Skill1 skill1;
};
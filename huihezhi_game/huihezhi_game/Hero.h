#pragma once
#include<iostream>
#include<string>
using namespace std;
class Hero//所有英雄的基类
{
public:
	Hero(const string&, int life = 100,int attack=5, int defend = 100);
	~Hero();
	string getname()const;
	int getlife()const;
	int getattack()const;
	int getdefend()const;

	bool setname(const string&);
	bool setlife(int);
	bool setattack(int);
	bool setdefend(int);
private:
	//名字
	string _name;
	//生命值
	int _life;
	//基础攻击
	int _attack;
	//防御值
	int _defend;
};

#pragma once
#include<iostream>
#include<string>
using namespace std;
class Hero//����Ӣ�۵Ļ���
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
	//����
	string _name;
	//����ֵ
	int _life;
	//��������
	int _attack;
	//����ֵ
	int _defend;
};

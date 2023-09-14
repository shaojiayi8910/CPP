#pragma once
#include <string>
using namespace std;
class Skill//所有技能的基类
{
private:
	string _name;//名字
	int _damage;//伤害值
	int _CD;//cd值
public:
	Skill(const string&, int, int);
	~Skill();
	string getname()const;
	int getdamage()const;
	int getCD()const;
	bool setname(const string&);
	bool setdamage(int);
	bool setCD(int); 
};

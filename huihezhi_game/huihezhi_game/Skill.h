#pragma once
#include <string>
using namespace std;
class Skill//���м��ܵĻ���
{
private:
	string _name;//����
	int _damage;//�˺�ֵ
	int _CD;//cdֵ
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

#include "Skill.h"
#include<string>
#include<iostream>
#define  _CRT_SECURE_NO_WARNINGS

Skill::Skill(const string&name, int damage, int CD) :_name(name),_damage(damage),_CD(CD)
{
	/*_name = name;
	_damage = damage;
	_CD = CD;*/
}

Skill::~Skill()
{
}

string Skill::getname() const
{
	return this->_name;
}

int Skill::getdamage() const
{
	return this->_damage;
}

int Skill::getCD() const
{
	return this->_CD;
}

bool Skill::setname(const string&name)
{
	_name = name;
	return true;
}

bool Skill::setdamage(int damage)
{
	_damage = damage;
	return true;
}

bool Skill::setCD(int CD)
{
	_CD = CD;
	return true;
}

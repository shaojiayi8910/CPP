#include "Hero.h"
#include<iostream>
Hero::Hero(const string&name, int life,int attack, int defend) : _name(name),_life(life),_attack(attack),_defend(defend)
{

}
Hero::~Hero()
{}
string Hero::getname() const
{
	return _name;
}

int Hero::getlife() const
{
	return _life;
}

int Hero::getattack() const
{
	return _attack;
}

int Hero::getdefend() const
{
	return _defend;
}

bool Hero::setname(const string&name)
{
	_name = name;
	return true;
}

bool Hero::setlife(int life)
{
	_life = life;
	return true;
}

bool Hero::setattack(int attack)
{
	_attack = attack;
	return true;
}

bool Hero::setdefend(int defend)
{
	_defend = defend;
	return true;
}

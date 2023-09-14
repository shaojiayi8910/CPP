#pragma once
#include"Hero.h"
#include<iostream>
#include"Skill2.h"
using namespace std;
class Caocao : public Hero
{
public:
	Caocao(const string&, int life = 100, int attack = 5, int defend = 100);
	~Caocao();
	Skill2 skill2;
};
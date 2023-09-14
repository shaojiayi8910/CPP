#include "libai.h"

Libai::Libai(const string&name, int life, int attack, int defend) : Hero(name,life ,attack,defend),skill1("skill",100,5)
{
}

Libai::~Libai()
{
}

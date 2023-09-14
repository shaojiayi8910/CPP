#ifndef BANSHOUREN_H
#define BANSHOUREN_H

#include <iostream>
#include <string>
#include "guaiwu.h"
using namespace std;


class  banshouren :public guaiwu
{
public:
    banshouren();
    ~banshouren();
    virtual string  Get_guaiwu_name(); //获取怪物名称
    virtual int Get_guaiwu_gongji();//获取怪物攻击
    virtual int Get_guaiwu_def();//获取怪物防御力
    virtual int Get_guaiwu_hp();//获取怪物血量

};


#endif
#ifndef GUAIWU_H
#define GUAIWU_H

#include <iostream>
#include <string>
using namespace std;


class  guaiwu
{
public:
    virtual string Get_guaiwu_name() = 0; //获取怪物名称
    virtual int Get_guaiwu_gongji() = 0;//获取怪物攻击
    virtual int Get_guaiwu_def() = 0;//获取怪物防御力
    virtual int Get_guaiwu_hp() = 0;//获取怪物血量
protected:
    string guaiwuname; //怪物名称
    int gongji;//怪物攻击
    int def;   //怪物防御力
    int Hp;//怪物血量
};


#endif
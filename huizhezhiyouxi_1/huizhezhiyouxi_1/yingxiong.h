#ifndef YINGXIONG_H
#define YINGXIONG_H
#include "langyabang.h"
#include <iostream>
#include <string>
using namespace std;


class  yingxiong
{
public:
    virtual int Get_yingxiong_gongji() = 0;//获取英雄攻击力
    virtual string Get_yingxiong_name() = 0;//获取英雄名称
    virtual int Get_yingxiong_baoji() = 0;//获取英雄暴击率
    virtual int Get_yingxiong_xixue() = 0;//获取英雄吸血率
    virtual int Get_yingxiong_xixuezhi(int num) = 0;//获取英雄吸血值 
    virtual int Get_yingxiong_def() = 0;//获取英雄防御力
    virtual int Get_yingxiong_hp() = 0;//获取英雄血量
    virtual bool is_chufa(int num) = 0;//触发条件
    virtual void Set_yingxiong_wuqi(wuqi* other) = 0; //英雄装备武器
    virtual wuqi* Get_yingxiong_wuqi() = 0;//获取英雄武器
    virtual string Getwuqi_name() = 0;//获取武器名称
protected:
    string yingxiongname; //英雄名称
    int Hp;//英雄血量
    int gongji;//英雄攻击
    int baoji; //英雄暴击率
    int def; //英雄防御
    wuqi* m_wuqi;//装备的武器
};


#endif
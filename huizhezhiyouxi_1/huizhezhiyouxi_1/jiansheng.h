#ifndef JIANSHENG_H
#define JIANSHENG_H
#include "yingxiong.h"
#include <iostream>
#include <string>
using namespace std;


class  jiansheng :public yingxiong
{
public:
    jiansheng();
    ~jiansheng();
    virtual int Get_yingxiong_gongji();//获取攻击力
    virtual int Get_yingxiong_hp();//获取英雄血量
    virtual string Get_yingxiong_name();//获取武器名称
    virtual int Get_yingxiong_baoji();//获取武器暴击率
    virtual int Get_yingxiong_xixue();//获取武器吸血率
    virtual int Get_yingxiong_xixuezhi(int num);//获取英雄吸血值
    virtual int Get_yingxiong_def();//获取英雄防御力
    virtual bool is_chufa(int num);//触发条件
    virtual void Set_yingxiong_wuqi(wuqi* other); //装备武器

    virtual wuqi* Get_yingxiong_wuqi();//获取英雄武器
    virtual string Getwuqi_name();//获取武器名称
};


#endif
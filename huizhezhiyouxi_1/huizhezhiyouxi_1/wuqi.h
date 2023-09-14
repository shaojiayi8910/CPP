//头文件
#ifndef WUQI_H
#define WUQI_H

#include <iostream>
#include <string>
using namespace std;


class  wuqi
{
public:
    virtual int Get_wuqi_gongji() = 0;//获取攻击力
    virtual string Get_wuqi_name() = 0;//获取武器名称
    virtual int Get_wuqi_baoji() = 0;//获取武器暴击率
    virtual int Get_wuqi_xixue() = 0;//获取武器吸血率
    virtual bool is_chufa(int num) = 0;//触发条件
protected:
    string wuqiname; //武器名称
    int gongji;//武器攻击
    int baoji; //武器暴击率
    int xixue; //武器吸血率
};


#endif
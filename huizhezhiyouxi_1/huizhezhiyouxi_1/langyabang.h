#ifndef LANGYABANG_H
#define LANGYABANG_H
#include "wuqi.h"
#include <iostream>
#include <string>
using namespace std;


class  langyabang :public wuqi
{
public:
    langyabang();
    ~langyabang();
    virtual int Get_wuqi_gongji();//获取攻击力
    virtual string Get_wuqi_name();//获取武器名称
    virtual int Get_wuqi_baoji();//获取武器暴击率
    virtual int Get_wuqi_xixue();//获取武器吸血率
    virtual bool is_chufa(int num);//触发条件

};


#endif
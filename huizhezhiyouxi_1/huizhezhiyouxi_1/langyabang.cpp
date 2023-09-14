#define  _CRT_SECURE_NO_WARNINGS
#include "langyabang.h"

//构造
langyabang::langyabang()
{
    this->wuqiname = "狼牙棒";
    this->gongji = 100;
    this->baoji = 20;
    this->xixue = 15;

}
//析构
langyabang::~langyabang()
{

}
int langyabang::Get_wuqi_gongji()//获取攻击力
{
    return this->gongji;
}
string langyabang::Get_wuqi_name()//获取武器名称
{
    if (this == NULL)
        return "双手";
    return this->wuqiname;
}
int langyabang::Get_wuqi_baoji()//获取武器暴击率
{
    return this->baoji;
}
int langyabang::Get_wuqi_xixue()//获取武器吸血率
{
    return this->xixue;
}
bool langyabang::is_chufa(int num)//触发条件
{
    if (rand() % 100 < num)
        return true;
    return false;

}
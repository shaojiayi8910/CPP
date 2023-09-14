#define  _CRT_SECURE_NO_WARNINGS
#include "gunzi.h"

//构造
gunzi::gunzi()
{
    this->wuqiname = "棍子";
    this->gongji = 20;
    this->baoji = 0;
    this->xixue = 0;

}
//析构
gunzi::~gunzi()
{

}
int gunzi::Get_wuqi_gongji()//获取攻击力
{
    return this->gongji;
}
string gunzi::Get_wuqi_name()//获取武器名称
{
    if (this == NULL)
        return "双手";
    return this->wuqiname;
}
int gunzi::Get_wuqi_baoji()//获取武器暴击率
{
    return this->baoji;
}
int gunzi::Get_wuqi_xixue()//获取武器吸血率
{
    return this->xixue;
}
bool gunzi::is_chufa(int num)//触发条件
{
    if (rand() % 100 < num)
        return true;
    return false;

}
#define  _CRT_SECURE_NO_WARNINGS
#include "jiansheng.h"


jiansheng::jiansheng()//构造
{
    this->yingxiongname = "剑圣";
    this->Hp = 800;
    this->gongji = 150;
    this->def = 50;
    this->baoji = 20;
    this->m_wuqi = NULL;
}
jiansheng::~jiansheng() //析构
{

}
string jiansheng::Getwuqi_name()//获取武器名称
{
    if (this->Get_yingxiong_wuqi() == NULL)
        return "空手";
    return this->Get_yingxiong_wuqi()->Get_wuqi_name();

}
int jiansheng::Get_yingxiong_gongji()//获取攻击力
{
    if (this->m_wuqi == NULL)
        return this->gongji;
    else
        return this->gongji + this->m_wuqi->Get_wuqi_gongji();
}
string jiansheng::Get_yingxiong_name()//获取英雄名称
{
    return this->yingxiongname;
}

int jiansheng::Get_yingxiong_hp()//获取英雄血量
{
    return this->Hp;
}
int jiansheng::Get_yingxiong_baoji()//获取英雄暴击率
{
    if (this->m_wuqi == NULL)
        return this->baoji;
    else
        return this->baoji + this->m_wuqi->Get_wuqi_baoji();
}

int jiansheng::Get_yingxiong_xixuezhi(int num)//获取英雄吸血值
{
    if (this->m_wuqi == NULL)
        return 0;
    else
        return  num / 100 * this->Get_yingxiong_xixue();

}
int jiansheng::Get_yingxiong_xixue()//获取英雄吸血率
{
    if (this->m_wuqi == NULL)
        return 0;
    else
        return this->m_wuqi->Get_wuqi_xixue();
}
int jiansheng::Get_yingxiong_def()//获取英雄防御力
{
    return this->def;
}

bool jiansheng::is_chufa(int num)//触发条件
{
    if (rand() % 100 < num)
        return true;
    return false;

}

void jiansheng::Set_yingxiong_wuqi(wuqi* other) //装备武器
{
    this->m_wuqi = other;
}
wuqi* jiansheng::Get_yingxiong_wuqi()//获取英雄武器
{
    if (this->m_wuqi == NULL)
        return NULL;
    return this->m_wuqi;
}
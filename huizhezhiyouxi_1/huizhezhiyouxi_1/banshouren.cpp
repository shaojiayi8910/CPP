#define  _CRT_SECURE_NO_WARNINGS
#include "banshouren.h"
banshouren::banshouren()
{
    this->guaiwuname = "半兽人";
    this->gongji = 200;
    this->def = 50;
    this->Hp = 2000;
}
banshouren::~banshouren()
{

}
string banshouren::Get_guaiwu_name() //获取怪物名称
{
    return this->guaiwuname;
}
int banshouren::Get_guaiwu_gongji()//获取怪物攻击
{
    return this->gongji;
}
int banshouren::Get_guaiwu_def()//获取怪物防御力
{
    return this->def;
}
int banshouren::Get_guaiwu_hp()//获取怪物血量
{
    return this->Hp;
}
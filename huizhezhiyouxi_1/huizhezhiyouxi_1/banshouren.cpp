#define  _CRT_SECURE_NO_WARNINGS
#include "banshouren.h"
banshouren::banshouren()
{
    this->guaiwuname = "������";
    this->gongji = 200;
    this->def = 50;
    this->Hp = 2000;
}
banshouren::~banshouren()
{

}
string banshouren::Get_guaiwu_name() //��ȡ��������
{
    return this->guaiwuname;
}
int banshouren::Get_guaiwu_gongji()//��ȡ���﹥��
{
    return this->gongji;
}
int banshouren::Get_guaiwu_def()//��ȡ���������
{
    return this->def;
}
int banshouren::Get_guaiwu_hp()//��ȡ����Ѫ��
{
    return this->Hp;
}
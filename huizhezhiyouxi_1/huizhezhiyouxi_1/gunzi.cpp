#define  _CRT_SECURE_NO_WARNINGS
#include "gunzi.h"

//����
gunzi::gunzi()
{
    this->wuqiname = "����";
    this->gongji = 20;
    this->baoji = 0;
    this->xixue = 0;

}
//����
gunzi::~gunzi()
{

}
int gunzi::Get_wuqi_gongji()//��ȡ������
{
    return this->gongji;
}
string gunzi::Get_wuqi_name()//��ȡ��������
{
    if (this == NULL)
        return "˫��";
    return this->wuqiname;
}
int gunzi::Get_wuqi_baoji()//��ȡ����������
{
    return this->baoji;
}
int gunzi::Get_wuqi_xixue()//��ȡ������Ѫ��
{
    return this->xixue;
}
bool gunzi::is_chufa(int num)//��������
{
    if (rand() % 100 < num)
        return true;
    return false;

}
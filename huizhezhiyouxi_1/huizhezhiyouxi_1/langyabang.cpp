#define  _CRT_SECURE_NO_WARNINGS
#include "langyabang.h"

//����
langyabang::langyabang()
{
    this->wuqiname = "������";
    this->gongji = 100;
    this->baoji = 20;
    this->xixue = 15;

}
//����
langyabang::~langyabang()
{

}
int langyabang::Get_wuqi_gongji()//��ȡ������
{
    return this->gongji;
}
string langyabang::Get_wuqi_name()//��ȡ��������
{
    if (this == NULL)
        return "˫��";
    return this->wuqiname;
}
int langyabang::Get_wuqi_baoji()//��ȡ����������
{
    return this->baoji;
}
int langyabang::Get_wuqi_xixue()//��ȡ������Ѫ��
{
    return this->xixue;
}
bool langyabang::is_chufa(int num)//��������
{
    if (rand() % 100 < num)
        return true;
    return false;

}
#define  _CRT_SECURE_NO_WARNINGS
#include "jiansheng.h"


jiansheng::jiansheng()//����
{
    this->yingxiongname = "��ʥ";
    this->Hp = 800;
    this->gongji = 150;
    this->def = 50;
    this->baoji = 20;
    this->m_wuqi = NULL;
}
jiansheng::~jiansheng() //����
{

}
string jiansheng::Getwuqi_name()//��ȡ��������
{
    if (this->Get_yingxiong_wuqi() == NULL)
        return "����";
    return this->Get_yingxiong_wuqi()->Get_wuqi_name();

}
int jiansheng::Get_yingxiong_gongji()//��ȡ������
{
    if (this->m_wuqi == NULL)
        return this->gongji;
    else
        return this->gongji + this->m_wuqi->Get_wuqi_gongji();
}
string jiansheng::Get_yingxiong_name()//��ȡӢ������
{
    return this->yingxiongname;
}

int jiansheng::Get_yingxiong_hp()//��ȡӢ��Ѫ��
{
    return this->Hp;
}
int jiansheng::Get_yingxiong_baoji()//��ȡӢ�۱�����
{
    if (this->m_wuqi == NULL)
        return this->baoji;
    else
        return this->baoji + this->m_wuqi->Get_wuqi_baoji();
}

int jiansheng::Get_yingxiong_xixuezhi(int num)//��ȡӢ����Ѫֵ
{
    if (this->m_wuqi == NULL)
        return 0;
    else
        return  num / 100 * this->Get_yingxiong_xixue();

}
int jiansheng::Get_yingxiong_xixue()//��ȡӢ����Ѫ��
{
    if (this->m_wuqi == NULL)
        return 0;
    else
        return this->m_wuqi->Get_wuqi_xixue();
}
int jiansheng::Get_yingxiong_def()//��ȡӢ�۷�����
{
    return this->def;
}

bool jiansheng::is_chufa(int num)//��������
{
    if (rand() % 100 < num)
        return true;
    return false;

}

void jiansheng::Set_yingxiong_wuqi(wuqi* other) //װ������
{
    this->m_wuqi = other;
}
wuqi* jiansheng::Get_yingxiong_wuqi()//��ȡӢ������
{
    if (this->m_wuqi == NULL)
        return NULL;
    return this->m_wuqi;
}
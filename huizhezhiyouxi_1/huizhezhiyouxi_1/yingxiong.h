#ifndef YINGXIONG_H
#define YINGXIONG_H
#include "langyabang.h"
#include <iostream>
#include <string>
using namespace std;


class  yingxiong
{
public:
    virtual int Get_yingxiong_gongji() = 0;//��ȡӢ�۹�����
    virtual string Get_yingxiong_name() = 0;//��ȡӢ������
    virtual int Get_yingxiong_baoji() = 0;//��ȡӢ�۱�����
    virtual int Get_yingxiong_xixue() = 0;//��ȡӢ����Ѫ��
    virtual int Get_yingxiong_xixuezhi(int num) = 0;//��ȡӢ����Ѫֵ 
    virtual int Get_yingxiong_def() = 0;//��ȡӢ�۷�����
    virtual int Get_yingxiong_hp() = 0;//��ȡӢ��Ѫ��
    virtual bool is_chufa(int num) = 0;//��������
    virtual void Set_yingxiong_wuqi(wuqi* other) = 0; //Ӣ��װ������
    virtual wuqi* Get_yingxiong_wuqi() = 0;//��ȡӢ������
    virtual string Getwuqi_name() = 0;//��ȡ��������
protected:
    string yingxiongname; //Ӣ������
    int Hp;//Ӣ��Ѫ��
    int gongji;//Ӣ�۹���
    int baoji; //Ӣ�۱�����
    int def; //Ӣ�۷���
    wuqi* m_wuqi;//װ��������
};


#endif
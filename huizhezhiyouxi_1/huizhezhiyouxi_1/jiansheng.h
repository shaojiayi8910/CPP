#ifndef JIANSHENG_H
#define JIANSHENG_H
#include "yingxiong.h"
#include <iostream>
#include <string>
using namespace std;


class  jiansheng :public yingxiong
{
public:
    jiansheng();
    ~jiansheng();
    virtual int Get_yingxiong_gongji();//��ȡ������
    virtual int Get_yingxiong_hp();//��ȡӢ��Ѫ��
    virtual string Get_yingxiong_name();//��ȡ��������
    virtual int Get_yingxiong_baoji();//��ȡ����������
    virtual int Get_yingxiong_xixue();//��ȡ������Ѫ��
    virtual int Get_yingxiong_xixuezhi(int num);//��ȡӢ����Ѫֵ
    virtual int Get_yingxiong_def();//��ȡӢ�۷�����
    virtual bool is_chufa(int num);//��������
    virtual void Set_yingxiong_wuqi(wuqi* other); //װ������

    virtual wuqi* Get_yingxiong_wuqi();//��ȡӢ������
    virtual string Getwuqi_name();//��ȡ��������
};


#endif
#ifndef LANGYABANG_H
#define LANGYABANG_H
#include "wuqi.h"
#include <iostream>
#include <string>
using namespace std;


class  langyabang :public wuqi
{
public:
    langyabang();
    ~langyabang();
    virtual int Get_wuqi_gongji();//��ȡ������
    virtual string Get_wuqi_name();//��ȡ��������
    virtual int Get_wuqi_baoji();//��ȡ����������
    virtual int Get_wuqi_xixue();//��ȡ������Ѫ��
    virtual bool is_chufa(int num);//��������

};


#endif
#ifndef GUNZI_H
#define GUNZI_H
#include "wuqi.h"
#include <iostream>
#include <string>
using namespace std;


class  gunzi :public wuqi
{
public:
    gunzi();
    ~gunzi();
    virtual int Get_wuqi_gongji();//��ȡ������
    virtual string Get_wuqi_name();//��ȡ��������
    virtual int Get_wuqi_baoji();//��ȡ����������
    virtual int Get_wuqi_xixue();//��ȡ������Ѫ��
    virtual bool is_chufa(int num);//��������

};


#endif
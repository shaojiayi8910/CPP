//ͷ�ļ�
#ifndef WUQI_H
#define WUQI_H

#include <iostream>
#include <string>
using namespace std;


class  wuqi
{
public:
    virtual int Get_wuqi_gongji() = 0;//��ȡ������
    virtual string Get_wuqi_name() = 0;//��ȡ��������
    virtual int Get_wuqi_baoji() = 0;//��ȡ����������
    virtual int Get_wuqi_xixue() = 0;//��ȡ������Ѫ��
    virtual bool is_chufa(int num) = 0;//��������
protected:
    string wuqiname; //��������
    int gongji;//��������
    int baoji; //����������
    int xixue; //������Ѫ��
};


#endif
#ifndef GUAIWU_H
#define GUAIWU_H

#include <iostream>
#include <string>
using namespace std;


class  guaiwu
{
public:
    virtual string Get_guaiwu_name() = 0; //��ȡ��������
    virtual int Get_guaiwu_gongji() = 0;//��ȡ���﹥��
    virtual int Get_guaiwu_def() = 0;//��ȡ���������
    virtual int Get_guaiwu_hp() = 0;//��ȡ����Ѫ��
protected:
    string guaiwuname; //��������
    int gongji;//���﹥��
    int def;   //���������
    int Hp;//����Ѫ��
};


#endif
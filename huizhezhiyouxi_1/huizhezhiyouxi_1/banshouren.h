#ifndef BANSHOUREN_H
#define BANSHOUREN_H

#include <iostream>
#include <string>
#include "guaiwu.h"
using namespace std;


class  banshouren :public guaiwu
{
public:
    banshouren();
    ~banshouren();
    virtual string  Get_guaiwu_name(); //��ȡ��������
    virtual int Get_guaiwu_gongji();//��ȡ���﹥��
    virtual int Get_guaiwu_def();//��ȡ���������
    virtual int Get_guaiwu_hp();//��ȡ����Ѫ��

};


#endif
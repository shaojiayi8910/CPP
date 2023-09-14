#ifndef MANAGER_H
#define MANAGER_H
#include <time.h>
#include "banshouren.h"
#include "langyabang.h"
#include "gunzi.h"
#include "jiansheng.h"
#include <windows.h>
#define DELETEOBJ(p) {if(p!=NULL)delete p;p==NULL; }
using namespace std;



class manager
{

public:
    manager();
    ~manager();
    void  initGame(); //��ʼ����Ϸ
    void yingxiongask();//Ӣ�۹�������
    void guaiwuask();//���﹥��Ӣ��
    int Get_yingxiong_hp_now(); //��ȡ��ǰӢ������ֵ
    int Get_guaiwu_hp_now();//��ȡ��ǰ��������ֵ
    int showgame();//��ʼ��Ϸ�غ�
    void restgame();//��Ϸ�ؿ�
    int showmassager();//��Ϸ������ʾ
    int round = 1;//��Ϸ�غ�
private:
    wuqi* m_langyabang;     //������
    wuqi* m_gunzi;          //������
    yingxiong* m_yingxiong; //Ӣ����
    guaiwu* m_guaiwu;      //������
    int yingxiong_hp_now; //Ӣ�۵�ǰʣ������ֵ
    int guaiwu_hp_now;    //���ﵱǰʣ������ֵ

};




#endif
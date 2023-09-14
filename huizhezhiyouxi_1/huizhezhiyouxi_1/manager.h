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
    void  initGame(); //初始化游戏
    void yingxiongask();//英雄攻击怪物
    void guaiwuask();//怪物攻击英雄
    int Get_yingxiong_hp_now(); //获取当前英雄生命值
    int Get_guaiwu_hp_now();//获取当前怪物生命值
    int showgame();//开始游戏回合
    void restgame();//游戏重开
    int showmassager();//游戏结束提示
    int round = 1;//游戏回合
private:
    wuqi* m_langyabang;     //武器类
    wuqi* m_gunzi;          //武器类
    yingxiong* m_yingxiong; //英雄类
    guaiwu* m_guaiwu;      //怪物类
    int yingxiong_hp_now; //英雄当前剩余生命值
    int guaiwu_hp_now;    //怪物当前剩余生命值

};




#endif
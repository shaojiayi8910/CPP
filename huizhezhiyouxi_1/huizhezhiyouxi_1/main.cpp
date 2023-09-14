#define  _CRT_SECURE_NO_WARNINGS
#include "manager.h"

int main()
{
    manager temp;
    temp.initGame(); //初始化游戏
    temp.showgame(); //开始游戏
    while (1)  //循环判断是否需要重开游戏，代码100为重开否则直接退出
    {
        if (temp.showmassager() == 100)
        {
            temp.showgame();
        }
        else
            return 0;
    }

    return 0;

}
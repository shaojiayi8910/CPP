#define  _CRT_SECURE_NO_WARNINGS
#include "manager.h"

int main()
{
    manager temp;
    temp.initGame(); //��ʼ����Ϸ
    temp.showgame(); //��ʼ��Ϸ
    while (1)  //ѭ���ж��Ƿ���Ҫ�ؿ���Ϸ������100Ϊ�ؿ�����ֱ���˳�
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
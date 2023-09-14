#define  _CRT_SECURE_NO_WARNINGS
#include "manager.h"

manager::manager()
{
    srand((unsigned)time(NULL));//设置随机参数
    this->m_guaiwu = new banshouren;
    this->m_langyabang = new langyabang;
    this->m_gunzi = new gunzi;
    this->m_yingxiong = new jiansheng;
    this->guaiwu_hp_now = m_guaiwu->Get_guaiwu_hp();
    this->yingxiong_hp_now = m_yingxiong->Get_yingxiong_hp();
}

int manager::Get_yingxiong_hp_now()
{
    return this->yingxiong_hp_now;
}
int manager::Get_guaiwu_hp_now()
{
    return this->guaiwu_hp_now;
}


manager::~manager()
{
    DELETEOBJ(m_langyabang);
    DELETEOBJ(m_gunzi);
    DELETEOBJ(m_yingxiong);
    DELETEOBJ(m_guaiwu);
}
void  manager::initGame()
{
    int num;
    cout << "请为英雄装备一把武器，输入1为狼牙棒，输入2为棍子，输入其他则不装备任何武器" << endl;
    cin >> num;
    switch (num)
    {
    case 1:
        m_yingxiong->Set_yingxiong_wuqi(m_langyabang);
        cout << "英雄装备了：" << m_yingxiong->Getwuqi_name() << " 就上了！" << endl;
        break;
    case 2:
        m_yingxiong->Set_yingxiong_wuqi(m_gunzi);
        cout << "英雄装备了：" << m_yingxiong->Getwuqi_name() << " 就上了！" << endl;
        break;
    default:
        cout << "英雄空手就上了！" << endl;
        break;
    }

}
void manager::yingxiongask()
{
    int shanghai;
    //英雄攻击怪物
    if (this->m_yingxiong->is_chufa(this->m_yingxiong->Get_yingxiong_baoji()) == true)//判断是否触发暴击
    {
        shanghai = (this->m_yingxiong->Get_yingxiong_gongji() - this->m_guaiwu->Get_guaiwu_def()) * 2;  //（攻击力-防御力)*2
        cout << "英雄使用" << m_yingxiong->Getwuqi_name() << "对怪物造成了一次暴击伤害：" << shanghai << endl;
    }
    else
    {
        shanghai = this->m_yingxiong->Get_yingxiong_gongji() - this->m_guaiwu->Get_guaiwu_def(); //英雄攻击力 - 防御力
        cout << "英雄使用" << m_yingxiong->Getwuqi_name() << "对怪物造成了一次伤害：" << shanghai << endl;
    }
    this->guaiwu_hp_now -= shanghai;
    //英雄吸血
    if (yingxiong_hp_now + this->m_yingxiong->Get_yingxiong_xixuezhi(shanghai) >= m_yingxiong->Get_yingxiong_hp()) //判断吸血后是否大于总血量，若大于总血量则回满血量并不会溢出， 否则当前血量+吸血量为当前英雄剩余血量
    {
        yingxiong_hp_now = this->m_yingxiong->Get_yingxiong_hp();
        cout << "英雄吸了一口血：" << this->m_yingxiong->Get_yingxiong_xixuezhi(shanghai) << endl;
    }
    else
    {
        yingxiong_hp_now += this->m_yingxiong->Get_yingxiong_xixuezhi(shanghai);
        cout << "英雄吸了一口血：" << this->m_yingxiong->Get_yingxiong_xixuezhi(shanghai) << endl;
    }

}
void manager::guaiwuask()
{
    int shanghai; //定义怪物造成的伤害
    shanghai = this->m_guaiwu->Get_guaiwu_gongji() - this->m_yingxiong->Get_yingxiong_def();
    cout << "怪物对英雄造成了一次伤害：" << shanghai << endl;
    this->yingxiong_hp_now -= shanghai;
}
void manager::restgame()//游戏重开
{
    system("cls");
    guaiwu_hp_now = m_guaiwu->Get_guaiwu_hp();
    yingxiong_hp_now = m_yingxiong->Get_yingxiong_hp();
    this->m_yingxiong->Set_yingxiong_wuqi(NULL);
    round = 1;
    initGame();
}

int manager::showmassager()
{
    int reslut = MessageBox(NULL, TEXT("游戏结束，是否选择重开？"), TEXT("确认"), MB_ICONINFORMATION | MB_YESNO);
    switch (reslut)
    {
    case IDYES:
    {
        restgame();
        return 100; //
    }

    case IDNO:
        return 101;
    }

}

int  manager::showgame()//开始游戏回合
{

    while (1)
    {
        Sleep(1000);
        system("cls");
        printf("--------------------------第%d回合----------------------------\n", round);
        yingxiongask();
        guaiwuask();
        if (Get_guaiwu_hp_now() <= 0)
        {
            cout << "怪物死亡~！" << endl;
            guaiwu_hp_now = 0; //生命值只能为0 不能为负数
            break;
        }
        if (Get_yingxiong_hp_now() <= 0)
        {
            cout << "英雄死亡~！" << endl;
            yingxiong_hp_now = 0;//生命值只能为0 不能为负数

            break;

        }
        cout << "当前英雄血量：" << Get_yingxiong_hp_now() << endl;
        cout << "当前怪物血量：" << Get_guaiwu_hp_now() << endl;


        round++;

    }

    return 0;
}
#define  _CRT_SECURE_NO_WARNINGS
#include "manager.h"

manager::manager()
{
    srand((unsigned)time(NULL));//�����������
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
    cout << "��ΪӢ��װ��һ������������1Ϊ������������2Ϊ���ӣ�����������װ���κ�����" << endl;
    cin >> num;
    switch (num)
    {
    case 1:
        m_yingxiong->Set_yingxiong_wuqi(m_langyabang);
        cout << "Ӣ��װ���ˣ�" << m_yingxiong->Getwuqi_name() << " �����ˣ�" << endl;
        break;
    case 2:
        m_yingxiong->Set_yingxiong_wuqi(m_gunzi);
        cout << "Ӣ��װ���ˣ�" << m_yingxiong->Getwuqi_name() << " �����ˣ�" << endl;
        break;
    default:
        cout << "Ӣ�ۿ��־����ˣ�" << endl;
        break;
    }

}
void manager::yingxiongask()
{
    int shanghai;
    //Ӣ�۹�������
    if (this->m_yingxiong->is_chufa(this->m_yingxiong->Get_yingxiong_baoji()) == true)//�ж��Ƿ񴥷�����
    {
        shanghai = (this->m_yingxiong->Get_yingxiong_gongji() - this->m_guaiwu->Get_guaiwu_def()) * 2;  //��������-������)*2
        cout << "Ӣ��ʹ��" << m_yingxiong->Getwuqi_name() << "�Թ��������һ�α����˺���" << shanghai << endl;
    }
    else
    {
        shanghai = this->m_yingxiong->Get_yingxiong_gongji() - this->m_guaiwu->Get_guaiwu_def(); //Ӣ�۹����� - ������
        cout << "Ӣ��ʹ��" << m_yingxiong->Getwuqi_name() << "�Թ��������һ���˺���" << shanghai << endl;
    }
    this->guaiwu_hp_now -= shanghai;
    //Ӣ����Ѫ
    if (yingxiong_hp_now + this->m_yingxiong->Get_yingxiong_xixuezhi(shanghai) >= m_yingxiong->Get_yingxiong_hp()) //�ж���Ѫ���Ƿ������Ѫ������������Ѫ�������Ѫ������������� ����ǰѪ��+��Ѫ��Ϊ��ǰӢ��ʣ��Ѫ��
    {
        yingxiong_hp_now = this->m_yingxiong->Get_yingxiong_hp();
        cout << "Ӣ������һ��Ѫ��" << this->m_yingxiong->Get_yingxiong_xixuezhi(shanghai) << endl;
    }
    else
    {
        yingxiong_hp_now += this->m_yingxiong->Get_yingxiong_xixuezhi(shanghai);
        cout << "Ӣ������һ��Ѫ��" << this->m_yingxiong->Get_yingxiong_xixuezhi(shanghai) << endl;
    }

}
void manager::guaiwuask()
{
    int shanghai; //���������ɵ��˺�
    shanghai = this->m_guaiwu->Get_guaiwu_gongji() - this->m_yingxiong->Get_yingxiong_def();
    cout << "�����Ӣ�������һ���˺���" << shanghai << endl;
    this->yingxiong_hp_now -= shanghai;
}
void manager::restgame()//��Ϸ�ؿ�
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
    int reslut = MessageBox(NULL, TEXT("��Ϸ�������Ƿ�ѡ���ؿ���"), TEXT("ȷ��"), MB_ICONINFORMATION | MB_YESNO);
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

int  manager::showgame()//��ʼ��Ϸ�غ�
{

    while (1)
    {
        Sleep(1000);
        system("cls");
        printf("--------------------------��%d�غ�----------------------------\n", round);
        yingxiongask();
        guaiwuask();
        if (Get_guaiwu_hp_now() <= 0)
        {
            cout << "��������~��" << endl;
            guaiwu_hp_now = 0; //����ֵֻ��Ϊ0 ����Ϊ����
            break;
        }
        if (Get_yingxiong_hp_now() <= 0)
        {
            cout << "Ӣ������~��" << endl;
            yingxiong_hp_now = 0;//����ֵֻ��Ϊ0 ����Ϊ����

            break;

        }
        cout << "��ǰӢ��Ѫ����" << Get_yingxiong_hp_now() << endl;
        cout << "��ǰ����Ѫ����" << Get_guaiwu_hp_now() << endl;


        round++;

    }

    return 0;
}

#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
int main()
{
    //��������ʼ��һ�� vector ����
    vector<string> myvec{ "STL", "Python", "Java" };
    //�ٴδ���һ�� vector ���������� myvec Ϊ���ʼ��
    vector<string>othvec(make_move_iterator(myvec.begin()), make_move_iterator(myvec.end()));

    cout << "myvec:" << endl;
    //��� myvec �����е�Ԫ��
    for (auto ch : myvec) {
        cout << ch << " ";
    }
    cout << endl << "othvec:" << endl;
    //��� othvec �����е�Ԫ��
    for (auto ch : othvec) {
        cout << ch << " ";
    }
    return 0;
}
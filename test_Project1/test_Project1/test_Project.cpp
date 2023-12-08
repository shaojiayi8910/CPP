
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
int main()
{
    //创建并初始化一个 vector 容器
    vector<string> myvec{ "STL", "Python", "Java" };
    //再次创建一个 vector 容器，利用 myvec 为其初始化
    vector<string>othvec(make_move_iterator(myvec.begin()), make_move_iterator(myvec.end()));

    cout << "myvec:" << endl;
    //输出 myvec 容器中的元素
    for (auto ch : myvec) {
        cout << ch << " ";
    }
    cout << endl << "othvec:" << endl;
    //输出 othvec 容器中的元素
    for (auto ch : othvec) {
        cout << ch << " ";
    }
    return 0;
}
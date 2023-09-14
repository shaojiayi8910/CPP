#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
typedef void (*Fun)();
using namespace std;
/*如果基类指针指向派生类对象，并且通过基类指针调用某些函数时，编译器是如何处理呢？
* 编译器会事先检查函数是否为虚函数，如果f不是虚函数，则采取静态联编，直接调用基类中的函数f，不论基类中的函数f是否被派生类所隐藏
* 如果函数f是虚函数，编译时并不知道该函数到底调用哪个f函数
* 什么时候才知道呢，在程序运行时，指针变量指向了派生类对象，通过该指针就会访问被指向（引用）的派生类对象的虚函数表指针 ，通过该续表指针，找到了派生类中的虚函数表，再在虚函数表中调用虚函数指针
* 如果派生类重写（覆盖了）基类中的虚函数f，派生类的虚函数表中保存的是派生类中的f函数的指针，因此，通过基类指针调用f函数，最终调用的是派生类中的f
* 如果派生类中没有重写，派生类的虚函数表中保存的是基类中的f函数的指针，因此最终调用的是基类中的f
*/
class Base
{
public:
	virtual void f(){cout << "f" << endl;}
	virtual void g() { cout << "g" << endl; }
	virtual void h() { cout << "h" << endl; }
	//virtual void huicheng() = 0;//纯虚函数，基类中并不实现


};
int main()
{	
	Base b;
	//虚表指针是对象中的第一个元素，虚表指针的地址就是对象的地址
	printf("%p\n",(int*) & b);//000000909A1FF718
	//(int *)&b=&vfptr  *(int *)(&b)=*vfptr=虚表指针的值=虚函数表的首地址
	printf("%p\n", (int*)(*(int*)&b));//00000000C7A3BD30
	printf("%p\n", (int*)(*(int*)&b)+0);//8Bytes
	printf("%p\n", (int*)(*(int*)&b+2));//虚函数表中下一个元素的地址
	printf("%p\n", (int*)(*(int*)&b)+4);
	printf("%p\n", *((long long*)(*(long long*)(& b) ) + 0));//虚函数表中的成员
	Fun p;
	p =(Fun)( * ((long long*)(*(long long*)(&b)) + 2));//h函数的地址给Fun
	p(); 


	return 0;
}
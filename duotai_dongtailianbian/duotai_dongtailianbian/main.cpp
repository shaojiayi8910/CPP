#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
typedef void (*Fun)();
using namespace std;
/*�������ָ��ָ����������󣬲���ͨ������ָ�����ĳЩ����ʱ������������δ����أ�
* �����������ȼ�麯���Ƿ�Ϊ�麯�������f�����麯�������ȡ��̬���ֱ࣬�ӵ��û����еĺ���f�����ۻ����еĺ���f�Ƿ�������������
* �������f���麯��������ʱ����֪���ú������׵����ĸ�f����
* ʲôʱ���֪���أ��ڳ�������ʱ��ָ�����ָ�������������ͨ����ָ��ͻ���ʱ�ָ�����ã��������������麯����ָ�� ��ͨ��������ָ�룬�ҵ����������е��麯�����������麯�����е����麯��ָ��
* �����������д�������ˣ������е��麯��f����������麯�����б�������������е�f������ָ�룬��ˣ�ͨ������ָ�����f���������յ��õ����������е�f
* �����������û����д����������麯�����б�����ǻ����е�f������ָ�룬������յ��õ��ǻ����е�f
*/
class Base
{
public:
	virtual void f(){cout << "f" << endl;}
	virtual void g() { cout << "g" << endl; }
	virtual void h() { cout << "h" << endl; }
	//virtual void huicheng() = 0;//���麯���������в���ʵ��


};
int main()
{	
	Base b;
	//���ָ���Ƕ����еĵ�һ��Ԫ�أ����ָ��ĵ�ַ���Ƕ���ĵ�ַ
	printf("%p\n",(int*) & b);//000000909A1FF718
	//(int *)&b=&vfptr  *(int *)(&b)=*vfptr=���ָ���ֵ=�麯�������׵�ַ
	printf("%p\n", (int*)(*(int*)&b));//00000000C7A3BD30
	printf("%p\n", (int*)(*(int*)&b)+0);//8Bytes
	printf("%p\n", (int*)(*(int*)&b+2));//�麯��������һ��Ԫ�صĵ�ַ
	printf("%p\n", (int*)(*(int*)&b)+4);
	printf("%p\n", *((long long*)(*(long long*)(& b) ) + 0));//�麯�����еĳ�Ա
	Fun p;
	p =(Fun)( * ((long long*)(*(long long*)(&b)) + 2));//h�����ĵ�ַ��Fun
	p(); 


	return 0;
}
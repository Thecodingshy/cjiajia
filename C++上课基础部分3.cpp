#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;	//չ������
using std::cout;
using std::endl;

//��������
//��inline���εĺ���������������������ʱC++���������ڵ�������������ʱ��չ��
//û�к���ѹջ�Ŀ�����������������Ч�ʾͱ��糣�õ�Swap()

//C �����к꺯���ĸ���
//ʹ�ú꺯�����ŵ��ǣ�a �����ά����ǿ��b �꺯�����Ч�ʼ���ջ֡�Ľ���
//ʹ�ú꺯����ȱ���ǣ�a �ɶ��Բ� b û�����Ͱ�ȫ��� c ���������
//
////ADD�꣺
//#define ADD(a,b) ((a)+(b))	//Ԥ�����ڼ��滻
//int main()
//{
//	ADD(1, 2);
//	if (ADD(1, 2))
//	ADD(1, 2) * 3;		//((1)+(2))*3
//
//	int x = 1, y = 2;
//	ADD(x | y, x & y); //((x+y)+(x&y))  ������
//		return 0;
//}


//inline int ADD(int a, int b)
//{
//	return a + b;
//}
//inline ����������������ڵ��õĵط�չ����������const,enum,inline ����꣩

//ע���
// 1 inline ���ڱ��������ԣ�ֻ��һ�����飬��� inline �ĺ��������бȽϳ�(�����ڲ�ʵ�ִ���ָ��ȱȽϳ�)/�ݹ飬�������Ż�ʱ����������

// 2 inline ��һ���Կռ任ʱ���������ʡȥ�������õĶ��⿪�������Դ���ܳ������еݹ鲻����

// 3 inline �����������Ͷ�����룬����ᵼ�����Ӵ�����Ϊinline��չ������û�к����ĵ�ַ�ˣ�.c�ļ��·��ű�գ������Ӿͻ��Ҳ���//������.hֱ��д����ʵ��

//C++����auto
//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d=TestAuto();
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//}

////��ʹ��auto����ı���ʱ�򣬱�����г�ʼ�����ڱ���׶Σ�������Ҫ���ݳ�ʼ�����ʽ���Ƶ�auto��ʵ�����ͣ�
////��ˣ�auto������һ�֡����͡�����ʱ��ġ�ռλ�������ڱ������ڼ�������Ὣauto�滻Ϊ����ʵ�ʵ�����
//int main()
//{
//	int a[] = { 1,2,3,4,5,6 };
//	for (auto& e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto *b = &x;
//	auto &c = x;
//
//	cout << typeid(a).name() << endl;//int *
//	cout << typeid(b).name() << endl;//int *
//	cout << typeid(c).name() << endl;//int
//	cout << endl;
//	cout << typeid(a).name() << endl;	//int *
//	cout << typeid(*b).name() << endl;	//int 
//	cout << typeid(&c).name() << endl;	//int *
//	return 0;
//}
//
////void TestAuto(auto a)�������ʧ�� auto������Ϊ�β����ͣ���ʱ��������޷���a��ʵ�����ͽ����Ƶ�
////auto b[]={4,5,6}	//auto����ֱ����������
//
//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int *)" << endl;
//}
//int main()
//{
//	int* p = NULL;
//	f(0);
//	f(NULL);
//	f(p);
//	f((int*)NULL);
//	int* ptr = nullptr;
//	f(nullptr);
//	f(ptr);
//}
//NULL��C++98�б�����Ϊ0���궨��
//C++ 11 �м���nullptr ����NULL;
//��ʼ����ָ��int* ptr=nullptr

//ע��
//a : ��ʹ��nullptr ��ʾָ���ֵʱ�򣬲��ð�ͷ�ļ�����Ϊnullptr��C++11��Ϊ�¹ؼ��������
//b : ��C++11��sizeof(nullptr)��sizeof((void* )0)��ռ�ֽ���һ��
//c : ��ߴ��뽡׳�ԣ��ں���ʹ��ָ��ʱ�����ʹ��nullptr
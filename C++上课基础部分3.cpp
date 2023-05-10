#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;	//展开常用
using std::cout;
using std::endl;

//内联函数
//以inline修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的时候展开
//没有函数压栈的开销，内联函数提升效率就比如常用的Swap()

//C 里面有宏函数的概念
//使用宏函数的优点是：a 代码可维护性强，b 宏函数提高效率减少栈帧的建立
//使用宏函数的缺点是：a 可读性差 b 没有类型安全检查 c 不方便调试
//
////ADD宏：
//#define ADD(a,b) ((a)+(b))	//预处理期间替换
//int main()
//{
//	ADD(1, 2);
//	if (ADD(1, 2))
//	ADD(1, 2) * 3;		//((1)+(2))*3
//
//	int x = 1, y = 2;
//	ADD(x | y, x & y); //((x+y)+(x&y))  内括号
//		return 0;
//}


//inline int ADD(int a, int b)
//{
//	return a + b;
//}
//inline 符合条件的情况，在调用的地方展开（建议用const,enum,inline 代替宏）

//注意点
// 1 inline 对于编译器而言，只是一个建议，如果 inline 的函数体内有比较长(函数内部实现代码指令长度比较长)/递归，编译器优化时候会忽略内联

// 2 inline 是一种以空间换时间的做法，省去函数调用的额外开销，所以代码很长或者有递归不适用

// 3 inline 不建议声明和定义分离，分离会导致连接错误，因为inline被展开，就没有函数的地址了（.c文件下符号表空），链接就会找不到//所以在.h直接写函数实现

//C++对于auto
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

////在使用auto定义的变量时候，必须进行初始化，在编译阶段，编译器要根据初始化表达式来推导auto的实际类型，
////因此，auto并非是一种“类型”声明时候的“占位符”，在编译器期间编译器会将auto替换为变量实际的类型
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
////void TestAuto(auto a)这里编码失败 auto不能作为形参类型，这时候编译器无法对a的实际类型进行推导
////auto b[]={4,5,6}	//auto不能直接声明数组
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
//NULL在C++98中被定义为0；宏定义
//C++ 11 中加入nullptr 代替NULL;
//初始化空指针int* ptr=nullptr

//注意
//a : 在使用nullptr 表示指针空值时候，不用包头文件，因为nullptr是C++11作为新关键字引入的
//b : 在C++11中sizeof(nullptr)和sizeof((void* )0)所占字节数一样
//c : 提高代码健壮性，在后续使用指针时候最好使用nullptr
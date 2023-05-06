#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;	//展开常用
using std::cout;
using std::endl;

//int main()
//{
//	int a = 10;
//	int& b = a;	//权限平移
//	//typeid(a).name()  输出a的类型
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//
//	const int c = 20;
//	//int& d = c;	//err这里涉及权限放大
//
//	const int &d = c;	//说明了c和d都可读可写
//
//	int e = 30;
//	const int f = e;	//权限缩小可以
//
//	int ii = 1;
//	//double& rdd = ii;	err这里涉及类型转换ii会隐式转化，在隐式转化过程中会拷贝一份具有常属性（const）的临时变量
//						//这个临时变量不匹配double类型
//	const double& rdd = ii;	//这样看来两边都是const没问题
//	//所以25行根本问题就是：发生了权限放大
//
//	//整型提升根据符号位，在ch的临时拷贝高位补0或者1，提升后在把临时拷贝的值给int i;
//	char ch = 'x';
//	int i = ch;
//	
//	
//	const double& dd = (double)ii;
//	//强转：ii产生了一个临时变量（提升和截断）都不是对原变量处理的；都是产生一个临时变量
//	//上述原因是：原变量空间不一定够
//	//在这之后ii还是int只是我对ii临时拷贝进行改变并且赋值给(double dd)
//	//综上强转和提升不会改变原变量类型
//	cout << typeid(ii).name() << endl;
//}

//正常
//void func1(int n)
//{}
//int main()
//{
//	int a = 10;
//	const int b = 20;
//
//	func1(a);
//	func1(b);
//	func1(10);
//	return 0;
//}

//void func2(int& n)	//可读可写
//{}
//int main()
//{
//	int a = 10;
//	const int b = 20;
//
//	func2(a);
//	//func2(b);  err 这里涉及权限放大
//	//func2(10);
//	return 0;
//}

////如果使用引用传参，如果不改变n尽量用const做引用参数
//void func3(const int& n)	//可读可写
//{}
//int main()
//{
//	int a = 10;
//	const int b = 20;
//
//	func3(a);
//	func3(b);  
//	func3(10);
//
//	func3(1.11);		//发生强制类型转化，可能会丢失数据
//	double c = 1.11;
//	func3(c);			// 发生强制类型转化，可能会丢失数据
//	return 0;	
//}

//指针和引用的区别
//1.引用在定义时候必须初始，指针没有要求
//2.引用在初始化时候，不能引用其他实体，而指针在任何时候，都可以指向任何一个同类型实体
//3.没有NULL引用，但有NULL指针
//4.sizeof意义不一样，引用结果为引用类型大小，但是指针始终是地址空间所占字节个数（32位平台下4个字节）
//5.引用自加即引用实体增加1，指针自加即指针向后偏移一个类型大小
//6.有多级指针，没有多级引用
//7.访问实体不同，指针要显示解引用，引用编译自己处理（底层逻辑一样）
//8.引用比指针安全

////但也有例外
//struct SlistNode
//{
//	int data;
//	struct SlistNode* next;
//};
////这里引用替代不了


//转到反汇编从底层来看引用是拿指针来实现的
//int main()
//{
//	//语法角度ra没有开辟空间
//	int a = 10;
//	int& ra = a;	//定义了变量ra ra存的是a的地址
//	ra = 20;		//用ra时候实际上拿这块地址解引用（跟指针一样）
//
//	//指针开辟了4 or 8 Byte
//	int* pa = &a;
//	*pa = 20;
//}

//C++为什么支持重载，但C不支持重载（C和C++对于函数名的处理是不一样的）
//C语言编译时候，不处理函数名；
//C++区分函数名，没有声明函数的地址我们用修饰完的名字去符号表找，
//找到函数的地址，拿过来合并，就是最终的可执行程序最终就可以运行了；


//		func.h		func.c		main.c
//预处理阶段：头文件展开，宏替换，条件编译，去掉注释
//					func.i		main.i
//编译（找语法错误）：语法检查，生成汇编代码（指令级处理但是这时候处理的结果CPU不认识）
//					func.s		main.s
// 编译结束的时候会给每个.o配一个符号表生成文件下的所以函数的名字{C不处理名字，C++处理（重载函数的参数不一样所以修饰出的名字不一样）名字}和地址
// 
//汇编：把汇编代码转化位二进制机器码
//					fun.o		main.o
//链接（找链接错误）；把 .o的目标文件合并到一起，其次还要找一些只给了声明的函数


//C和C++编译器，编译后生成的都是二进制指令，都可以合并在一起，虽然语法不同，但最终合成二进制指令
//所以C程序可以调用C++编译器
//C++编译器可以调用C编译器
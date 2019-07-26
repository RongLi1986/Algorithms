#include <iostream>
#include <vector>
#include <assert.h>
#include <stdlib.h>
#include <memory>
#include <initializer_list>

using namespace std;

/*
C/C++ knowledge note
*/

/*
C/C++
const
作用
1. 修饰变量，说明该变量不可以被改变；
2. 修饰指针，分为指向常量的指针和指针常量；
3. 常量引用，经常用于形参类型，即避免了拷贝，又避免了函数对值的修改；
4. 修饰成员函数，说明该成员函数内不能修改成员变量。
*/

// 类
class A
{
private:
    const int a;                // 常对象成员，只能在初始化列表赋值

public:
    // 构造函数
    //A() { };
    A(int x) : a(x) { };        // 初始化列表

    // const可用于对重载函数的区分
    int getValue();             // 普通成员函数
    int getValue() const;       // 常成员函数，不得修改类中的任何数据成员的值
};

void function()
{
    // 对象
    A b(4);                        // 普通对象，可以调用全部成员函数
    const A a(4);                  // ？？常对象，只能调用常成员函数、更新常成员变量
    const A *p = &a;            // 常指针
    const A &q = a;             // 常引用

    // 指针
    char greeting[] = "Hello";
    char* p1 = greeting;                // 指针变量，指向字符数组变量
    const char* p2 = greeting;          // 指针变量，指向字符数组常量  数组不能变
    char* const p3 = greeting;          // 常指针，指向字符数组变量    数组地址不能变
    const char* const p4 = greeting;    // 常指针，指向字符数组常量    都不可以变
}


// 函数
void function1(const int Var);           // 传递过来的参数在函数内不可变
void function2(const char* Var);         // 参数指针所指内容为常量
void function3(char* const Var);         // 参数指针为常指针
void function4(const int& Var);          // 引用参数在函数内为常量 不可变


// 函数返回值
const int function5();      // 返回一个常数
const int* function6();     // 返回一个指向常量的指针变量，使用：const int *p = function6();
int* const function7();     // 返回一个指向变量的常指针，使用：int* const p = function7();


/*
static 作用:
1. 修饰普通变量，修改变量的存储区域和生命周期，使变量存储在静态区，在 main 函数运行前就分配了空间，如果有初始值就用初始值初始化它，如果没有初始值系统用默认值初始化它。
2. 修饰普通函数，表明函数的作用范围，仅在定义该函数的文件内才能使用。在多人开发项目时，为了防止与他人命令函数重名，可以将函数定位为 static。
3. 修饰成员变量，修饰成员变量使所有的对象只保存一个该变量，而且不需要生成对象就可以访问该成员。
4. 修饰成员函数，修饰成员函数使得不需要生成对象就可以访问该函数，但是在 static 函数内不能访问非静态成员。
*/

static void foo(){  // 2. this function only can be accessed in this file
	int l =0;
	static int s = 0;
	l++;   // local vals
	s++;   // 1. in static zone, not vanish when foo destory

	cout<<s<<endl;
}

//singleton example
class S
{
    public:

    	int b = 0;
        static S& getInstance()  //only access static varible
        {
            static S    instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
            int a = 0; 			  //local varible is ok
            //b = 1;              //not allowed
            return instance;
        }
    private:
        S() {}                    // Constructor? (the {} brackets) are needed here.

    public:
        S(S const&)               = delete;
        void operator=(S const&)  = delete;

        // Note: Scott Meyers mentions in his Effective Modern
        //       C++ book, that deleted functions should generally
        //       be public as it results in better error messages
        //       due to the compilers behavior to check accessibility
        //       before deleted status
};


/*
this 指针
1. this 指针是一个隐含于每一个非静态成员函数中的特殊指针。它指向正在被该成员函数操作的那个对象。
2. 当对一个对象调用成员函数时，编译程序先将对象的地址赋给 this 指针，然后调用成员函数，每次成员函数存取数据成员时，由隐含使用 this 指针。
3. 当一个成员函数被调用时，自动向它传递一个隐含的参数，该参数是一个指向这个成员函数所在的对象的指针。
4. this 指针被隐含地声明为: ClassName *const this，这意味着不能给 this 指针赋值；在 ClassName 类的 const 成员函数中，this 指针的类型为：const ClassName* const，这说明不能对 this 指针所指向的这种对象是不可修改的（即不能对这种对象的数据成员进行赋值操作）；
5. this 并不是一个常规变量，而是个右值，所以不能取得 this 的地址（不能 &this）。
6. 在以下场景中，经常需要显式引用 this 指针：
为实现对象的链式引用；
为避免对同一对象进行赋值操作；
在实现一些数据结构时，如 list。
*/
class thisExample
{
private:
    int a;                // 常对象成员，只能在初始化列表赋值

public:
    // 构造函数
    thisExample() { };
    thisExample(int x) : a(x) { };        // 初始化列表

    // const可用于对重载函数的区分
    int getValue(){
    	this->a = 8;    // this ptr

    	//this = NULL;    //this cannot change
    	return this->a;
    }             
};

/*
inline 内联函数
特征
相当于把内联函数里面的内容写在调用内联函数处；
相当于不用执行进入函数的步骤，直接执行函数体；
相当于宏，却比宏多了类型检查，真正具有函数特性；
不能包含循环、递归、switch 等复杂操作；
类中除了虚函数的其他函数都会自动隐式地当成内联函数。
*/

/*
编译器对 inline 函数的处理步骤
1. 将 inline 函数体复制到 inline 函数调用点处；
2. 为所用 inline 函数中的局部变量分配内存空间；
3. 将 inline 函数的的输入参数和返回值映射到调用方法的局部变量空间中；
4. 如果 inline 函数有多个返回点，将其转变为 inline 函数代码块末尾的分支（使用 GOTO）。

优点:
内联函数同宏函数一样将在被调用处进行代码展开，省去了参数压栈、栈帧开辟与回收，结果返回等，从而提高程序运行速度。
内联函数相比宏函数来说，在代码展开时，会做安全检查或自动类型转换（同普通函数），而宏定义则不会。
在类中声明同时定义的成员函数，自动转化为内联函数，因此内联函数可以访问类的成员变量，宏定义则不能。
内联函数在运行时可调试，而宏定义不可以。

缺点:
代码膨胀。内联是以代码膨胀（复制）为代价，消除函数调用带来的开销。如果执行函数体内代码的时间，相比于函数调用的开销较大，那么效率的收获会很少。另一方面，每一处内联函数的调用都要复制代码，将使程序的总代码量增大，消耗更多的内存空间。
inline 函数无法随着函数库升级而升级。inline函数的改变需要重新编译，不像 non-inline 可以直接链接。
是否内联，程序员不可控。内联函数只是对编译器的建议，是否对函数内联，决定权在于编译器。
*/

// 声明1（加 inline，建议使用）
inline int functionName(int first, int secend);
// 声明2（不加 inline）
int functionName(int first, int secend);
// 定义
inline int functionName(int first, int secend) {return 0;};


/*
虚函数（virtual）可以是内联函数（inline）吗？
Are "inline virtual" member functions ever actually "inlined"?

虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联。
内联是在编译器建议编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，
因此虚函数表现为多态性时（运行期）不可以内联。
inline virtual 唯一可以内联的时候是：编译器知道所调用的对象是哪个类（如 Base::who()），这只有在编译器具有实际对象而不是对象的指针或引用时才会发生
*/

/*
函数inline example

#include <iostream>  
using namespace std;
class Base
{
public:
	inline virtual void who()
	{
		cout << "I am Base\n";
	}
	virtual ~Base() {}
};

class Derived : public Base
{
public:
	inline void who()  // 不写inline时隐式内联
	{
		cout << "I am Derived\n";
	}
};

int main()
{
	// 此处的虚函数 who()，是通过类（Base）的具体对象（b）来调用的，编译期间就能确定了，所以它可以是内联的，但最终是否内联取决于编译器。 
	Base b;
	b.who();

	// 此处的虚函数是通过指针调用的，呈现多态性，需要在运行时期间才能确定，所以不能为内联。  
	Base *ptr = new Derived();
	ptr->who();

	// 因为Base有虚析构函数（virtual ~Base() {}），所以 delete 时，会先调用派生类（Derived）析构函数，再调用基类（Base）析构函数，防止内存泄漏。
	delete ptr;
	ptr = nullptr;

	system("pause");
	return 0;
} 
*/

/*
assert()
断言，是宏，而非函数。assert 宏的原型定义在<assert.h>（C）、<cassert>（C++）中，其作用是如果它的条件返回错误，则终止程序执行。如：

assert( p != NULL );
*/

/*
sizeof()
sizeof 对数组，得到整个数组所占空间大小。
sizeof 对指针，得到指针本身所占空间大小。
*/
void sizeofEXample(){
 	char greeting[] = "abcdefgh";
    char* p1 = greeting;                // 指针变量，指向字符数组变量
    
    cout<<sizeof(greeting)<<endl;    //9 why + 1
    cout<<sizeof(p1)<<endl;          //8  64bit os ptr size()

    return;
}

/*
C++ 中 struct 和 class
总的来说，struct 更适合看成是一个数据结构的实现体，class 更适合看成是一个对象的实现体。

区别
最本质的一个区别就是默认的访问控制
默认的继承访问权限。struct 是 public 的，class 是 private 的。
struct 作为数据结构的实现体，它默认的数据访问控制是 public 的，而 class 作为对象的实现体，
它默认的成员变量访问控制是 private 的。
*/

// cpp
struct Student { 
    int age; 
};

void f( Student me );       // 正确，"struct" 关键字可省略


/*
union 联合
联合（union）是一种节省空间的特殊的类，一个 union 可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值。当某个成员被赋值后其他成员变为未定义状态。联合有如下特点：

默认访问控制符为 public
可以含有构造函数、析构函数
不能含有引用类型的成员
不能继承自其他类，不能作为基类
不能含有虚函数
匿名 union 在定义所在作用域可直接访问 union 成员
匿名 union 不能包含 protected 成员或 private 成员
全局匿名联合必须是静态（static）的
*/

/*
union UnionTest {
    UnionTest() : i(10) {};
    int i;
    double d;
};

static union {
    int i;
    double d;
};

int main() {
    UnionTest u;

    union {
        int i;
        double d;
    };

    std::cout << u.i << std::endl;  // 输出 UnionTest 联合的 10

    ::i = 20;
    std::cout << ::i << std::endl;  // 输出全局静态匿名联合的 20

    i = 30;
    std::cout << i << std::endl;    // 输出局部匿名联合的 30

    return 0;
}
*/

/*
explicit（显式）构造函数
explicit 修饰的构造函数可用来防止隐式转换
*/
class Test1
{
public:
    Test1(int n)            // 普通构造函数
    {
        num=n;
    }
private:
    int num;
};

class Test2
{
public:
    explicit Test2(int n)   // explicit（显式）构造函数
    {
        num=n;
    }
private:
    int num;
};

//    Test1 t1=12;            // 隐式调用其构造函数，成功
//    Test2 t2=12;            // 编译错误，不能隐式调用其构造函数
//    Test2 t2(12);           // 显式调用成功

/*
friend 友元类和友元函数
能访问私有成员
破坏封装性
友元关系不可传递
友元关系的单向性
友元声明的形式及数量不受限制


1) Friends should be used only for limited purpose. too many functions or external classes are declared as friends of a class with protected or private data, it lessens the value of encapsulation of separate classes in object-oriented programming.

2) Friendship is not mutual. If a class A is friend of B, then B doesn’t become friend of A automatically.

3) Friendship is not inherited (See this for more details)

4) The concept of friends is not there in Java.

*/
class LinkedList
{
public:
	int search(){
		return 0;
	}
};

class Node 
{ 
private: 
  int key; 
  Node *next; 
  /* Other members of Node Class */
  
  friend class LinkedList; // Now class  LinkedList can  
                           // access private members of Node 
}; 


class Node2
{ 
private: 
  int key; 
  Node *next; 
  
  /* Other members of Node Class */
  friend int LinkedList::search(); // Only search() of linkedList  
                                  // can access internal members 
}; 


/*
:: 范围解析运算符
分类
全局作用域符（::name）：用于类型名称（类、类成员、成员函数、变量等）前，
表示作用域为全局命名空间
类作用域符（class::name）：用于表示指定类型的作用域范围是具体某个类的
命名空间作用域符（namespace::name）:用于表示指定类型的作用域范围是具体某个命名空间的
*/

int count = 0;        // 全局（::）的 count

class Count {
public:
    static int count; // 类 A 的 count（A::count）
};
//    ::count = 1;      // 设置全局的 count 的值为 1
//    A::count = 2;     // 设置类 A 的 count 为 2
//    int count = 0;    // 局部的 count
//    count = 3;        // 设置局部的 count 的值为 3


/*
引用
左值引用
常规引用，一般表示对象的身份。

??
右值引用
右值引用就是必须绑定到右值（一个临时对象、将要销毁的对象）的引用，一般表示对象的值。

右值引用可实现转移语义（Move Sementics）和精确传递（Perfect Forwarding），它的主要目的有两个方面：

消除两个对象交互时不必要的对象拷贝，节省运算存储资源，提高效率。
能够更简洁明确地定义泛型函数。
*/

/*
int a = 42;
int b = 43;

// a and b are both l-values:
a = b; // ok
b = a; // ok
a = a * b; // ok

// a * b is an rvalue:
int c = a * b; // ok, rvalue on right hand side of assignment
a * b = 42; // error, rvalue on left hand side of assignment
*/


/*
成员初始化列表
好处

更高效：少了一次调用默认构造函数的过程。
有些场合必须要用初始化列表：
常量成员，因为常量只能初始化不能赋值，所以必须放在初始化列表里面
引用类型，引用必须在定义的时候初始化，并且不能重新赋值，所以也要写在初始化列表里面
没有默认构造函数的类类型，因为使用初始化列表可以不必调用默认构造函数来初始化，
而是直接调用拷贝构造函数初始化。
*/

template <class T>
struct initlist {
    std::vector<T> v;
    initlist(std::initializer_list<T> l) : v(l) {
         std::cout << "constructed with a " << l.size() << "-element list\n";
    }

    void append(std::initializer_list<T> l) {
        v.insert(v.end(), l.begin(), l.end());
    }
    
    std::pair<const T*, std::size_t> c_arr() const {
        return {&v[0], v.size()};  // 在 return 语句中复制列表初始化
                                   // 这不使用 std::initializer_list
    }
};

/*
面向对象
面向对象程序设计（Object-oriented programming，OOP）
是种具有对象概念的程序编程典范，同时也是一种程序开发的抽象方针。
面向对象三大特征 —— 封装、继承、多态
*/

/*
封装
把客观事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者对象操作，对不可信的进行信息隐藏。
关键字：public, protected, friendly, private。不写默认为 friendly。

关键字	    当前类	包内	 子孙类	包外
public	     √	     √	   √	 √
protected	 √	     √	   √	 ×
friendly	 √	     √	   ×	 ×
private	     √	     ×	   ×	 ×
*/

/*
继承
基类（父类）——> 派生类（子类）
*/

/*
多态
多态，即多种状态，在面向对象语言中，接口的多种不同的实现方式即为多态。
C++ 多态有两种：静态多态（早绑定）、动态多态（晚绑定）。静态多态是通过函数重载实现的；动态多态是通过虚函数实现的。
多态是以封装和继承为基础的。
*/

/* overload 
静态多态（早绑定）
函数重载
*/

class exampleOverload
{
public:
    void func1(int a);
    void func1(int a, int b);
};

/*
动态多态（晚绑定）
虚函数：用 virtual 修饰成员函数，使其成为虚函数

普通函数（非类成员函数）不能是虚函数
静态函数（static）不能是虚函数
构造函数不能是虚函数（因为在调用构造函数时，虚表指针并没有在对象的内存空间中，
必须要构造函数调用完成后才会形成虚表指针）


虚析构函数
虚析构函数是为了解决基类的指针指向派生类对象，并用基类的指针删除派生类对象。
*/

class Shape                     // 形状类
{
public:
    virtual double calcArea()
    {
    	cout<<"i don't know"<<endl;
    	return 0.0;
    }
    virtual ~Shape();
};

class Circle : public Shape     // 圆形类
{
public:
	Circle(double r){

	}
    virtual double calcArea();
};

class Rect : public Shape       // 矩形类
{
public:
	Rect(double l, double w){

	}
    virtual double calcArea();
};

//Shape * shape1 = new Circle(4.0);
//Shape * shape2 = new Rect(5.0, 6.0);
//shape1->calcArea();         // 调用圆形类里面的方法
//shape2->calcArea();         // 调用矩形类里面的方法
//delete shape1;			// 因为Shape有虚析构函数，所以delete释放内存时，先调用子类析构函数，再调用基类析构函数，防止内存泄漏。
//shape1 = nullptr;
//delete shape2;
//shape2 = nullptr;

/*
纯虚函数
纯虚函数是一种特殊的虚函数，在基类中不能对虚函数给出有意义的实现，而把它声明为纯虚函数，它的实现留给该基类的派生类去做。

virtual int A() = 0;
*/


/*
虚函数、纯虚函数
CSDN . C++ 中的虚函数、纯虚函数区别和联系

类里如果声明了虚函数，这个函数是实现的，哪怕是空实现，它的作用就是为了能让这个函数在它的子类里面可以被覆盖，这样的话，
这样编译器就可以使用后期绑定来达到多态了。纯虚函数只是一个接口，是个函数的声明而已，它要留到子类里去实现。

虚函数在子类里面也可以不重载的；但纯虚函数必须在子类去实现。

虚函数的类用于 “实作继承”，继承接口的同时也继承了父类的实现。当然大家也可以完成自己的实现。纯虚函数关注的是接口的统一性，实现由子类完成。

带纯虚函数的类叫虚基类，这种基类不能直接生成对象，而只有被继承，并重写其虚函数后，才能使用。这样的类也叫抽象类。
抽象类和大家口头常说的虚基类还是有区别的，在 C# 中用 abstract 定义抽象类，而在 C++ 中有抽象类的概念，但是没有这个关键字。
抽象类被继承后，子类可以继续是抽象类，也可以是普通类，而虚基类，是含有纯虚函数的类，它如果被继承，那么子类就必须实现虚基类里面的所有纯虚函数，其子类不能是抽象类。
*/

/*
虚函数指针、虚函数表
虚函数指针：在含有虚函数类的对象中，指向虚函数表，在运行时确定。
虚函数表：在程序只读数据段（.rodata section，见：目标文件存储结构），存放虚函数指针，如果派生类实现了基类的某个虚函数，
则在虚表中覆盖原本基类的那个虚函数指针，在编译时根据类的声明创建。
*/

/*
虚继承

虚继承用于解决多继承条件下的菱形继承问题（浪费存储空间、存在二义性）。

底层实现原理与编译器相关，一般通过虚基类指针和虚基类表实现，每个虚继承的子类都有一个虚基类指针（占用一个指针的存储空间，4字节）
和虚基类表（不占用类对象的存储空间）（需要强调的是，虚基类依旧会在子类里面存在拷贝，只是仅仅最多存在一份而已，并不是不在子类里面了；
当虚继承的子类被当做父类继承时，虚基类指针也会被继承。

实际上，vbptr 指的是虚基类表指针（virtual base table pointer），该指针指向了一个虚基类表（virtual table），
虚表中记录了虚基类与本类的偏移地址；通过偏移地址，这样就找到了虚基类成员，而虚继承也不用像普通多继承那样维持着公共基类（虚基类）的两份同样的拷贝，节省了存储空间。
*/

/*
虚继承、虚函数
相同之处：都利用了虚指针（均占用类的存储空间）和虚表（均不占用类的存储空间）
不同之处：
虚继承
虚基类依旧存在继承类中，只占用存储空间
虚基类表存储的是虚基类相对直接继承类的偏移
虚函数
虚函数不占用存储空间
虚函数表存储的是虚函数地址
*/


/*
抽象类、接口类、聚合类
抽象类：含有纯虚函数的类
接口类：仅含有纯虚函数的抽象类
聚合类：用户可以直接访问其成员，并且具有特殊的初始化语法形式。满足如下特点：
	所有成员都是 public
	没有有定于任何构造函数
	没有类内初始化
	没有基类，也没有 virtual 函数
*/


/*
内存分配和管理
malloc、calloc、realloc、alloca
malloc：申请指定字节数的内存。申请到的内存中的初始值不确定。
calloc：为指定长度的对象，分配能容纳其指定个数的内存。申请到的内存的每一位（bit）都初始化为 0。
realloc：更改以前分配的内存长度（增加或减少）。当增加长度时，可能需将以前分配区的内容移到另一个
足够大的区域，而新增区域内的初始值则不确定。
alloca：在栈上申请内存。程序在出栈的时候，会自动释放内存。但是需要注意的是，alloca 不具可移植性, 
而且在没有传统堆栈的机器上很难实现。alloca 不宜使用在必须广泛移植的程序中。C99 中支持变长数组
(VLA)，可以用来替代 alloca。
*/

/*
malloc、free
用于分配、释放内存
*/
int memExample(){
	char *str = (char*) malloc(100);
	//assert(str != nullptr);
	free(str); 
	str = nullptr;
	return 0;
}


/*
new、delete
new / new[]：完成两件事，先底层调用 malloc 分了配内存，然后调用构造函数（创建对象）。
delete/delete[]：也完成两件事，先调用析构函数（清理资源），然后底层调用 free 释放空间。
new 在申请内存时会自动计算所需字节数，而 malloc 则需我们自己输入申请内存空间的字节数。
*/

 //T* t = new T();     // 先内存分配 ，再构造函数
 //delete t;           // 先析构函数，再内存释放
 

/*
智能指针

C++ 标准库（STL）中
头文件：#include <memory>

C++ 11
shared_ptr
unique_ptr
weak_ptr
auto_ptr（被 C++11 弃用）

Class shared_ptr 实现共享式拥有（shared ownership）概念。多个智能指针指向相同对象，该对象和其相关资源会在 “最后一个 reference 被销毁” 时被释放。
为了在结构较复杂的情景中执行上述工作，标准库提供 weak_ptr、bad_weak_ptr 和 enable_shared_from_this 等辅助类。

Class unique_ptr 实现独占式拥有（exclusive ownership）或严格拥有（strict ownership）概念，保证同一时间内只有一个智能指针可以指向该对象。
你可以移交拥有权。它对于避免内存泄漏（resource leak）——如 new 后忘记 delete ——特别有用。

shared_ptr
多个智能指针可以共享同一个对象，对象的最末一个拥有着有责任销毁对象，并清理与该对象相关的所有资源。

支持定制型删除器（custom deleter），可防范 Cross-DLL 问题（对象在动态链接库（DLL）中被 new 创建，却在另一个 DLL 内被 delete 销毁）、自动解除互斥锁

weak_ptr
weak_ptr 允许你共享但不拥有某对象，一旦最末一个拥有该对象的智能指针失去了所有权，任何 weak_ptr 都会自动成空（empty）。
因此，在 default 和 copy 构造函数之外，weak_ptr 只提供 “接受一个 shared_ptr” 的构造函数。

可打破环状引用（cycles of references，两个其实已经没有被使用的对象彼此互指，使之看似还在 “被使用” 的状态）的问题

unique_ptr
unique_ptr 是 C++11 才开始提供的类型，是一种在异常时可以帮助避免资源泄漏的智能指针。采用独占式拥有，意味着可以确保一个对象和其相应的资源同一时间只被一个 pointer 拥有。一旦拥有着被销毁或编程 empty，或开始拥有另一个对象，先前拥有的那个对象就会被销毁，其任何相应资源亦会被释放。

unique_ptr 用于取代 auto_ptr
auto_ptr
被 c++11 弃用，原因是缺乏语言特性如 “针对构造和赋值” 的 std::move 语义，以及其他瑕疵。
*/



/*
强制类型转换运算符
MSDN . 强制转换运算符

static_cast
用于非多态类型的转换
不执行运行时类型检查（转换安全性不如 dynamic_cast）
通常用于转换数值数据类型（如 float -> int）
可以在整个类层次结构中移动指针，子类转化为父类安全（向上转换），父类转化为子类不安全（因为子类可能有不在父类的字段或方法）
向上转换是一种隐式转换。

dynamic_cast
用于多态类型的转换
执行行运行时类型检查
只适用于指针或引用
对不明确的指针的转换将失败（返回 nullptr），但不引发异常
可以在整个类层次结构中移动指针，包括向上转换、向下转换

const_cast
用于删除 const、volatile 和 __unaligned 特性（如将 const int 类型转换为 int 类型 ）

reinterpret_cast
用于位的简单重新解释
滥用 reinterpret_cast 运算符可能很容易带来风险。 除非所需转换本身是低级别的，否则应使用其他强制转换运算符之一。
允许将任何指针转换为任何其他指针类型（如 char* 到 int* 或 One_class* 到 Unrelated_class* 之类的转换，但其本身并不安全）
也允许将任何整数类型转换为任何指针类型以及反向转换。
reinterpret_cast 运算符不能丢掉 const、volatile 或 __unaligned 特性。
reinterpret_cast 的一个实际用途是在哈希函数中，即，通过让两个不同的值几乎不以相同的索引结尾的方式将值映射到索引。

bad_cast
由于强制转换为引用类型失败，dynamic_cast 运算符引发 bad_cast 异常。
bad_cast 使用
*/



/*
运行时类型信息 (RTTI)

dynamic_cast
用于多态类型的转换

typeid
typeid 运算符允许在运行时确定对象的类型
type_id 返回一个 type_info 对象的引用
如果想通过基类的指针获得派生类的数据类型，基类必须带有虚函数
只能获取对象的实际类型

type_info
type_info 类描述编译器在程序中生成的类型信息。 此类的对象可以有效存储指向类型的名称的指针。 
type_info 类还可存储适合比较两个类型是否相等或比较其排列顺序的编码值。 
类型的编码规则和排列顺序是未指定的，并且可能因程序而异。
头文件：typeinfo
*/


class Flyable                       // 能飞的
{
public:
    virtual void takeoff() = 0;     // 起飞
    virtual void land() = 0;        // 降落
};

class Bird : public Flyable         // 鸟
{
public:
    void foraging() {
    	cout<<"eating"<<endl;		// 觅食
    }           
    virtual void takeoff() { cout<<"bird fly"<<endl;}
    virtual void land() {cout<<"bird land"<<endl;}
};

class Plane : public Flyable        // 飞机
{
public:
    void carry() { cout<<"carry"<<endl;}     // 运输
    virtual void takeoff() {cout<<"plane fly"<<endl;}
    virtual void land() {cout<<"plane land"<<endl;}
};

/*
class type_info
{
public:
    const char* name() const;
    bool operator == (const type_info & rhs) const;
    bool operator != (const type_info & rhs) const;
    int before(const type_info & rhs) const;
    virtual ~type_info();
private:
};
*/

void doSomething(Flyable *obj)                 // 做些事情
{
    obj->takeoff();

    cout << typeid(*obj).name() << endl;        // 输出传入对象类型（"class Bird" or "class Plane"）

    if(typeid(*obj) == typeid(Bird))            // 判断对象类型
    {
        Bird *bird = dynamic_cast<Bird *>(obj); // 对象转化
        bird->foraging();
    }

    obj->land();

    return;
};


int main(){
	//Flyable* ptr = new Bird();
	//doSomething(ptr);

	return 0;
}

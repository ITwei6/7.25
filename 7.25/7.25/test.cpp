#include <iostream>

using namespace std;

//class person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////protected:
//	string _name = "xiaotao";
//	int _age = 19;
//};
//
//class student :public person
//{
//protected:
//	int _stuid;
//};
//class teacher :public person
//{
//protected:
//	int _joined;
//};
//int main()
//{
//	person p;
//	student s;
//	//赋值兼容转化：切片，切割
//	//不同类型之间赋值正常来说是会发生类型转化
//	p = s;
//
//	person p1 = s;
//
//	person& p2 = s;
//	//中间不会产生临时变量，所以可以将子类赋给父类变名
//	//将子类中跟父类对应那一部分切割拷贝过来
//	p2._name = "xiaoyao";
//	//可以通过别名，指针来找到子类中的跟父类相对应的数据
//	//子类是一种特殊的父类
//	person* p3 = &s;
//	p3->_name = "hehehe";
//
//}
//class person
//{
//public:
//	void fun()
//	{
//		cout << "person::fun()" << endl;
//	}
//protected:
//	string _name = "heeheh";
//	int _num = 111;
//};
//class student :public person
//{
//public:
//	void fun()
//	{
//		cout << "student::fun()" << endl;
//
//	}
//	void Print()
//	{
//		cout << "姓名：" << _name << endl;
//		cout << "学号" << _num << endl;
//		cout << person::_num << endl;
//	}
//protected:
//	int _num = 999;
//};
//int main()
//{
//	student s;
//	s.Print();
//	s.fun();
//	//默认会先到子类找，子类找不到就会报错
//	s.person::fun();
//}
//class person
//{
//public:
//	void fun()
//	{
//		cout << "person::fun()" << endl;
//	}
//protected:
//	string _name = "heeheh";
//	int _num = 111;
//};
//class student :public person
//{
//public:
//	void fun(int i)
//	{
//		cout << "student::fun()" << endl;
//
//	}
//	void Print()
//	{
//		cout << "姓名：" << _name << endl;
//		cout << "学号" << _num << endl;
//		cout << person::_num << endl;
//	}
//protected:
//	int _num = 999;
//};
////在继承中只要子类和父类中成员函数或者成员变量名字相同就构成隐藏，不管参数如何
//int main()
//{
//	student s;
//	s.person::fun();
//	s.fun(2);
//}

//继承中的默认成员函数：
//class person
//{
//public:
//	
//	person(const char* name)
//		:_name(name)
//	{
//
//	}
//	person(const person& p)
//		:_name(p._name)
//	{
//		cout << "person(const person& p)" << endl;
//	}
//	person& operator=(const person& p)
//	{
//		cout << "person& operator=(const person& p)" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		
//		return *this;
//	}
//	~person()
//	{
//		cout << "~person" << endl;
//	}
//		
//protected:
//	string _name;
//};
//
//class student :public person
//{
//	public:
//	//父类先声明的，所以初始化需要先初始化父类
//	student(const char* name="SDSAD", int id=123)
//		:person(name)//需要显式的初始化父类,父类的构造
//		, _id(id)
//	{
//
//	}
//	student(const student& s)
//		:person(s)//显式的调用父类中的拷贝构造
//		, _id(s._id)
//	{
//	}
//	student& operator=(const student& s)
//	{
//		if (this != &s)
//		{
//			//父类中的赋值运算符与子类中的赋值运算符重载构成的隐藏,必须显式的调用父类中的赋值重载来赋值父类的数据
//			person::operator=(s);
//			_id = s._id;
//		}
//		return *this;
//	}
//	~student()
//	{
//		//多态中将父类和子类的析构弄成隐藏，先找子类再找父类
//		// 
//		//应该先析构子类再析构父类
//	}
//protected:
//	int _id;
//};
//int main()
// {
//	student s1;
//	student s2(s1);
//
//	student s("xiaotao", 555);
//	s1 = s;
//}


//继承中父类的友元不能继承，如果子类想要父类的友元，需要自己手动添加友元。

//继承中的静态变量
//class person
//{
//
//public:
//	person()
//	{
//		++_cout;
//	}
////protected:
//	string _name;
//public:
//	static int _cout;
//};
//int person::_cout = 1;
//
//class student :public person
//{
//
//protected:
//	int _num;
//};
////静态成员是共同属于父类和子类的，子类继承静态成员不是将父类的静态成员拷贝过来，而是
////继承父类静态成员的使用权
//int main()
//{
//	person p;
//	student s1;
//	student s2;
//
//	cout << &s1._name << endl;
//	cout << &s2._name << endl;
//
//	cout << &p._cout << endl;
//	cout << &s1._cout << endl;
//	cout << &s2._cout << endl;
//
//	cout << &person::_cout << endl;
//	cout << &student::_cout << endl;
//}

//双继承
class person
{
public:
	string _name;
	int _age;
};
class student :virtual public person
{
protected:
	int _num;
};
class teacher :virtual public person
{
protected:
	int _id;
};
//双继承--->存在问题：菱形继承
//person ,student ,teacher 都没事，只有assistant有事，存在两个person中的数据
//解决方法：虚继承
class assistant :public student, public teacher
{
protected:
	string _marjor;
};
int main()
{
	assistant a;
	a.student::_age = 10;
	a.teacher::_age = 20;
	//使用虚继承后，person中的数据就只有一个了
	a._age = 31;
}
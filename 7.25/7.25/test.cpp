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
//	//��ֵ����ת������Ƭ���и�
//	//��ͬ����֮�丳ֵ������˵�ǻᷢ������ת��
//	p = s;
//
//	person p1 = s;
//
//	person& p2 = s;
//	//�м䲻�������ʱ���������Կ��Խ����ำ���������
//	//�������и������Ӧ��һ�����и������
//	p2._name = "xiaoyao";
//	//����ͨ��������ָ�����ҵ������еĸ��������Ӧ������
//	//������һ������ĸ���
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
//		cout << "������" << _name << endl;
//		cout << "ѧ��" << _num << endl;
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
//	//Ĭ�ϻ��ȵ������ң������Ҳ����ͻᱨ��
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
//		cout << "������" << _name << endl;
//		cout << "ѧ��" << _num << endl;
//		cout << person::_num << endl;
//	}
//protected:
//	int _num = 999;
//};
////�ڼ̳���ֻҪ����͸����г�Ա�������߳�Ա����������ͬ�͹������أ����ܲ������
//int main()
//{
//	student s;
//	s.person::fun();
//	s.fun(2);
//}

//�̳��е�Ĭ�ϳ�Ա������
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
//	//�����������ģ����Գ�ʼ����Ҫ�ȳ�ʼ������
//	student(const char* name="SDSAD", int id=123)
//		:person(name)//��Ҫ��ʽ�ĳ�ʼ������,����Ĺ���
//		, _id(id)
//	{
//
//	}
//	student(const student& s)
//		:person(s)//��ʽ�ĵ��ø����еĿ�������
//		, _id(s._id)
//	{
//	}
//	student& operator=(const student& s)
//	{
//		if (this != &s)
//		{
//			//�����еĸ�ֵ������������еĸ�ֵ��������ع��ɵ�����,������ʽ�ĵ��ø����еĸ�ֵ��������ֵ���������
//			person::operator=(s);
//			_id = s._id;
//		}
//		return *this;
//	}
//	~student()
//	{
//		//��̬�н���������������Ū�����أ������������Ҹ���
//		// 
//		//Ӧ����������������������
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


//�̳��и������Ԫ���ܼ̳У����������Ҫ�������Ԫ����Ҫ�Լ��ֶ������Ԫ��

//�̳��еľ�̬����
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
////��̬��Ա�ǹ�ͬ���ڸ��������ģ�����̳о�̬��Ա���ǽ�����ľ�̬��Ա��������������
////�̳и��ྲ̬��Ա��ʹ��Ȩ
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

//˫�̳�
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
//˫�̳�--->�������⣺���μ̳�
//person ,student ,teacher ��û�£�ֻ��assistant���£���������person�е�����
//�����������̳�
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
	//ʹ����̳к�person�е����ݾ�ֻ��һ����
	a._age = 31;
}
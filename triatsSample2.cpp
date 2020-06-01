#include<iostream>
#include<string>

using namespace std;

struct A{
	void fun(){
		cout << endl << "In A" << endl;
	}
};

struct B{
	void fun1(){
			cout << endl << "In B" << endl;
		}
};

template<typename T>
struct supports_opt_impl{
	static const bool value = false;
};

template<>
struct supports_opt_impl<B>{
	static const bool value = true;
};

template<bool b>
struct algorithm_selector{
	template<typename T>
	static void impl(T &obj){
		obj.fun();
	}
};

template<>
struct algorithm_selector<true>{
	template<typename T>
	static void impl(T &obj){
		obj.fun1();
	}
};

template<typename T>
void  algorithm(T &obj){
	algorithm_selector< supports_opt_impl< T >::value >::impl(obj);
}

int main(){
	A a;
	algorithm(a);
	B b;
	algorithm(b);
	cout << endl << "End" << endl ;
	return 0;
}

/*
 * ReferenceSamples.cpp
 *
 *  Created on: Nov 27, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<type_traits>

using namespace std;

void f1(){
	int x = 20;
	auto &y = x;
	auto && r = y;
	cout << " X is " << r << endl;

}
template<typename T>
void type_check1(T &&x){
	cout << std::is_same<int&&, decltype(x)>() << endl;
	cout << std::is_same<int&, decltype(x)>() << endl;
}

void type_check(int &&x){
	cout << std::is_same<int&&, decltype(x)>() << endl;
	//type_check1(std::forward<int>(x));
	type_check1(x);
}
void f2(){
	type_check(20);
}

int main(){
	f2();
}



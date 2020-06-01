/*
 * test2.cpp
 *
 *  Created on: Nov 26, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<vector>
using namespace std;

std::vector<int> Range(const int &low, const int &high){
	std::vector<int> v;
	for(int i = low; i < high; i++)
		v.push_back(i);

	return std::move(v);
}

struct Test{
	static int i;
	int j = 0;
	Test() : j(i++) {
		cout << "\nCONS " << j << endl;
	}
	Test(const Test &o) : j(i++){
		cout << "\nCopy const " << j << endl;
	}
	Test(Test &&o) {
		j = i++;
		cout << "\nMove const " << j << endl;
	}
	Test &operator=(const Test &o){
		cout << "\ncopy assign\n";
		return *this;
	}
	Test &operator=(const Test &&o){
		cout << "\nMove assign\n";
		return *this;
	}
	~Test(){
		cout << "\nDestructor" << i << endl;
	}
};

int Test::i = 0;
std::vector<Test> fun2(){
	std::vector<Test> v;
		Test t1, t2;
		//v.resize(10);
		cout << "\n+++++++++++++++\n";
		//for(auto i = 0; i < 2; i++)
			//v.emplace_back(t1);
		v.emplace_back(std::move(t1));
		v.emplace_back(std::move(t2));
	//	v.push_back(std::move(t1));
	//	v.push_back(std::move(t2));
		cout <<"\n returning\n";
	return std::move(v);
	//return v;

}

void fun1(){
	std::vector<Test> v;
	Test t1, t2;
	//v.resize(10);
	cout << "\n+++++++++++++++\n";
	//for(auto i = 0; i < 2; i++)
		//v.emplace_back(t1);
	//v.emplace_back(std::move(t1));
	//v.emplace_back(std::move(t2));
	v.push_back(std::move(t1));
	v.push_back(std::move(t2));
}

int main(){

	for(auto i : Range(1,10 ))
		cout << i << " ";

	std::vector<Test> v1 = fun2();
	//fun1();

	cout << "Main end\n";

}

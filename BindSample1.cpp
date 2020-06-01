/*
 * BindSample1.cpp
 *
 *  Created on: Nov 26, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<functional>
#include<vector>

using namespace std;

int fun1(int a, int b, int c){
	return a-b-c;
}
void bind1(){
	using namespace std::placeholders;
	auto f1 = std::bind(fun1,_2, _1, _3);
	cout << "\nResult is " << f1(20,10, 4) << endl;

}


void MoveWithBind(){
	std::vector<int> data{1,2,3,4,5,6,7,8,9};
	cout << "\n binding the vector\n";
	auto func = std::bind(
					[](vector<int> &data) mutable {data[0] = 100; for(auto x : data){cout << x << " ";}},
					std::move(data));
	func(data);
}
int main(){

	//bind1();
	MoveWithBind();
	return 0;

}




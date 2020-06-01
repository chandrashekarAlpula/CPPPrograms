#include<iostream>

using namespace std;

auto fun(auto &x)->decltype(x){
	x += 103;
	return x;

}

int main(){
	auto a = 1;
	auto &x = a;
	auto &y = fun(x);
	y++;
	cout << "X is " << x << endl;

}

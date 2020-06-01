#include<iostream>
using namespace std;

int main(){

	long sum = 3;
	cout << endl;
	for(auto x : {sum*1, sum*2, sum*3}) {

		cout << x << " ";
	}
	cout << endl;
	return 0;
}

#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

template<typename T>
void print(std::initializer_list<T> list){
	for(auto val : list)
		cout << val << " ";
	cout << endl;
}

void f1(){
	int arr[] {1,2,3,4,5};
	vector<int> vec{10,20,30,40};

	list<std::string> str{"Hello", "Hi", "How r u"};
	cout << endl;
	print({44,55,66,77,88,99,100});
	print({2.3,4.5,6.7});

	for(auto i : arr){
		cout << i << " " ;
	}

	cout << endl;
	for(auto i : vec)
		cout << i << " " ;

	cout << endl;
	for(auto i : str)
		cout << i << " " ;


}

class Test1{
public :
	int x, y;
	char c;
	string s;
	friend void f2();
};
void f2(){

	Test1 t{3, 8, 'g', "hello"}; // Initializes only if all the member variables are public
	cout << endl << "x " << t.x << " y " << t.y << " c " << t.c << " string " << t.s <<  endl;
}
int main(){

	f2();
	return 0;
}

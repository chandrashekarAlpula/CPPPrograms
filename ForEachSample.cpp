#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
template<typename T>
void show(const T &it){
 //cout << endl ;
  cout << it << "\t";
}
int main(){

	std::vector<std::string> vec1{"chandra", "shekhar", "test.org", "hello.org", "test.com", "hi.com", "wold.com", "hello"};
	//for_each(vec1.begin(), vec1.end(), show<std::string>);
	for_each( vec1.begin(), vec1.end(), [](std::vector<std::string>::iterator itr ){cout << *itr << " "; });
	return 0;
}

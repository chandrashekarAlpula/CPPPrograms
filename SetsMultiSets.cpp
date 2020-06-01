#include<iostream>
#include<set>
#include<algorithm>
#include<iterator>

using namespace std;

void f1(){
	std::set<int> s1{1,2,3,4};
	std::pair<std::set<int>::iterator, bool> st = s1.insert(5);
	if(st.second){
		cout << "Element 5 is inserted at position  " << std::distance(s1.begin(), st.first) + 1<< endl;
	}else{
		cout << "Element 5 is already present at position " << std::distance(s1.begin(), st.first) + 1 << endl;
	}

	for(const auto &elem : s1){
		cout << elem << endl;
	}

	std::set<int> s2(s1);

	for(const auto &elem : s2){
		cout << elem << endl;
	}


	s2.erase(s2.begin(), s2.find(4));
	std::copy(s2.begin(), s2.end(), std::ostream_iterator<int>(cout , " "));


	cout << endl;
	// Greater
	std::set<int, std::greater<int>> s3{1,2,3,4,5};
	std::copy(s3.begin(), s3.end(), std::ostream_iterator<int>(cout , " "));


}

int main(){

	f1();
	return 0;
}

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
struct AddressBook{
	std::vector<std::string> address;

	AddressBook(){}
	AddressBook(const std::initializer_list<std::string> &list) : address(list){}
	void AddToAddressBook(const std::string &add){
		address.push_back(add);
	}
	template<typename FunType>
	std::vector<std::string> FindInAddressBook(FunType fun);
	friend std::ostream &operator <<(std::ostream &out, const AddressBook &a){
		for(auto itr = a.address.begin(); itr != a.address.end(); itr++)
			cout << endl << *itr << " ";
		out << endl;

		return out;
	}
};

template<typename FunType>
std::vector<std::string> AddressBook::FindInAddressBook(FunType fun){
	std::vector<std::string> result ;
	for(auto itr = address.begin(); itr != address.end(); itr++){
		if(fun(*itr))
			result.push_back(*itr);
	}
	return result;
}

void sumOfVectorElements(){
	std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
	int sum = 0;
	for_each(v.begin(), v.end(), [&sum](auto itr) {sum += itr;});
	cout << endl << "Sum is " << sum;
}

void AddressBookTest(){
	AddressBook addr{"chandra", "shekhar", "test.org", "hello.org", "test.com", "hi.com", "wold.com", "hello"};
	cout  << addr;
	std::vector<std::string> result = addr.FindInAddressBook([]
					(const std::string &str) {return str.find("tes")  != std::string::npos;});
	cout << "Result " << endl;

	for(auto itr : result)
		std::cout << itr << " ";
	cout << endl;
}

int main(){
	//AddressBookTest();
	sumOfVectorElements();
	return 0;
}

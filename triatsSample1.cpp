#include<iostream>
#include<string>

using namespace std;

namespace mySpace {
template<typename T>
bool is_pointer(){
	return false;
}

template<typename T>
bool is_pointer(T *){
	return true;
}

/*
template<typename T>
struct is_pointer{
	static constexpr bool value = false;
};

template<typename T>
struct is_pointer<T *>{
	static constexpr bool value = true;
}
*/


template<typename T>
struct is_pointer1{
	static constexpr bool value {false};
};

template<typename T>
struct is_pointer1<T *>{
	static constexpr bool value {true};
};
}

template<typename T>
void implementer(const T &a, std::true_type){
	cout << "value of ptr " << *a << endl ;
}

template<typename T>
void implementer(const T &a, std::false_type){
	cout << "value of var " << a << endl ;
}

template<typename T>
void impl(const T &v){
	implementer(v, std::is_pointer<T>());
}

int main(){
	int *a = new int(20);
	int b = 40;
	if(mySpace::is_pointer1<decltype(b)>::value == true){
		cout << "It is a  pointer";
	}else{
		cout << " it is not a pointer \n";
	}
	/*static_assert(is_pointer<int *>::value == true, "Its not a pointer type");
	 * */
	if(mySpace::is_pointer(a) == true){
		cout << "\n It is a  pointer \n";
	}else{
		cout << " \n It is not a pointer \n";
	}
	impl(a);
	impl(b);
	cout << endl << "End" << endl ;
	return 0;
}

#include<iostream>
#include<utility>
#include<functional>
#include<tuple>
#include<string>

using namespace std;

std::tuple<int, float, std::string> maketuple(){
	return std::make_tuple(456, 23.6, "hello Mr");
}

void f2(){

	std::string s = "abc";
	auto t = std::tie(s);
	cout << " Tuple " << std::get<0>(t) << endl;
	std::get<0>(t) = "abcdefgh";
	cout << " Tuple " << s << endl;

}
void f1(){
	int i =0;
	float j = 0;
	std::string s;

	//
	//std::make_tuple(std::ref(i), std::ref(j), std::ref(s)) = maketuple();
	//OR
	std::tie(i, j, s) = maketuple();
	cout << "I " << i << " J " << j << " S " << s << endl ;

	i++;
	auto t = std::make_tuple(7, 23.6, "hello");
	//typename std::tuple<int, float, std::string> TupleType;

	cout << "Size of tuple " << std::tuple_size<decltype(t)>::value << endl;
	//cout << "type of 0 " << std::tuple_element<1, decltype(t)>::type << endl;
	cout << "Tuple 0 " << std::get<0>(t) << " and I  " << i <<  endl;

}

/***  Tuples and IO streams ***/
/*
template<int IDX, int MAX, typename ...Args>
struct PRINT_T{
	static void print(std::ostream &os, const std::tuple<Args...> &tup){
		os << std::get<IDX>(tup) << ( (IDX+1 == MAX) ? " " : ", " );
		PRINT_T<IDX+1, MAX,Args...>::print(os, tup);
	}
};

template<int MAX, typename ...Args>
struct PRINT_T<MAX,MAX,Args...> {
	static void print(std::ostream &os, const std::tuple<Args...> &tup){

	}
};
*/

template<int IDX, int MAX, typename ...Args>
struct PRINT_TUPLE{
	static void print(std::ostream &os,  const std::tuple<Args...> &t){
		os << std::get<IDX>(t) << ( (IDX+1 == MAX) ? " " : ", ");
		PRINT_TUPLE<IDX+1, MAX, Args...>::print(os, t);
	}
};

template<int MAX, typename ...Args>
struct PRINT_TUPLE<MAX, MAX, Args...>{
	static void print(std::ostream &os,  const std::tuple<Args...> &t){}
};

template<typename ...Args>
std::ostream &operator<<(std::ostream &os, const std::tuple<Args...> &t){
	os << "[" ;
	PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os , t);
	os << "]";
	return os;
}

void TupleAndIO(){
	auto t = std::make_tuple("hi", "Hello", 123, 45.6);
	cout << t << endl;
}

int main(){
	TupleAndIO();

	return 0;
}

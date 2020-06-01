#include<iostream>
#include<tuple>
#include<type_traits>

using namespace std;

//C++11
template<typename E>
constexpr typename std::underlying_type<E>::type ToUType(E enumeration){
	return static_cast<typename std::underlying_type<E>::type>(enumeration);
}

//C++14
template<typename E>
constexpr std::underlying_type_t<E> ToUType_t(E enumeration){
	return static_cast<std::underlying_type_t<E>>(enumeration);
}
enum class UserInfoFields{uiName, uiEmail, uiReputation};
using UserInfo = std::tuple<std::string, std::string,std::size_t>;
//typedef std::tuple<std::string, std::string,std::size_t> UserInfo ;

int main(){

	UserInfo uinfo1("chandra", "cc.gmail.com", 5);
	UserInfo uinfo2 = make_tuple("Shekhar", "ss@gmail.com", 6);

	cout << std::get<ToUType(UserInfoFields::uiName)>(uinfo1) << endl ;
	cout << std::get<ToUType_t(UserInfoFields::uiEmail)>(uinfo2) << endl ;

	auto t = tuple<std::string, int>("hi", 25);
	cout << endl << std::get<1>(t) << endl;
	return 0;
}

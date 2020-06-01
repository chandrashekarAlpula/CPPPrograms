#include<iostream>

using namespace std;

struct Point{
	int x,y;
	constexpr Point(int x, int y) : x(x), y(y){}

	constexpr int GetX(){return x;};
	//constexpr void SetX(int a){x = a;}
	constexpr int GetY(){return y;};
	//constexpr void SetY(int a){y = a;}

	friend std::ostream &operator <<(std::ostream &os, const Point &p){
		os << "X: " << p.x <<"," << " Y: " << p.y << endl;
		return os;
	}

};
int main(){

	Point p{1,2};
	cout << p;
	return 0;
}

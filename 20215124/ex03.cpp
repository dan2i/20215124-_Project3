//11주차 실습 3번
#include <iostream>
using namespace std;

class Vector {
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z } {}

	friend ostream& operator<<(ostream& os, Vector& v);
	friend istream& operator>>(istream& is, Vector& v);
};

//ostream
ostream& operator<<(ostream& os, Vector& v) {
	os << v.x << " " << v.y << " " << v.z << endl;
	return os;
}

//istream
istream& operator>>(istream& is, Vector& v) {
	is >> v.x >> v.y >> v.z;
	return is;
}

int main() {
	Vector v0{ 1,2,3 };
	cout << v0 << endl;		//ostream
	Vector v1;
	cin >> v1;	//istream
	cout << v1 << endl;
}
//11주차 실습 5번
#include <iostream>
#include <cstring>
using namespace std;

class Vector {
private:
	float x, y, z;
	char* _chars;
public:
	Vector() {}
	Vector(float x, float y, float z, const char* chars)
		: x{ x }, y{ y }, z{ z }, _chars(new char[strlen(chars) + 1])
	{
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}
	
	Vector(Vector& v) : Vector(v.x, v.y, v.z, v._chars)
	{
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);
		cout << "copy" << endl;	//복사 생성자가 어느 시점에 발생되는지 확인하기 위해서!
	}

	~Vector() {
		delete[] _chars;
	}

	Vector& operator=(Vector& v) {
		x = v.x;
		y = v.y;
		z = v.z;

		delete[] _chars;
		_chars = new char[strlen(v._chars) + 1];
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);
		return *this;
	}

	friend ostream& operator<<(ostream& os, Vector& v) {
		os << v.x << " " << v.y << " " << v.z;
		return os;
	}
};

int main() {
	int a = 1;
	int b = a;	//복사
	int c;
	c = a;	//대입

	Vector v0{ 1,2,3, "abc" };
	Vector v1 = v0;	//복사: 얕은 복사가 일어남!
	Vector v2;
	v2 = v0;	//대입

	cout << v0 << endl;	//1 2 3
	cout << v1 << endl;	//1 2 3
	cout << v2 << endl;	//1 2 3
}
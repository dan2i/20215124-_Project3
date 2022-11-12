//11���� �ǽ� 4��
#include <iostream>
#include <cstring>
using namespace std;

//Vector �̿�
class Vector {
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) : x(x), y(y), z(z) {}

	float& operator[](int index) {
		if (index < 1)
			return x;
		if (index == 1)
			return y;
		else
			return z;
	}
};

//String �̿�
class String {
private:
	char* _chars;
public:
	String() {}
	String(const char* chars) : _chars{ new char[strlen(chars) + 1] } {
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}

	char& operator[](int index) {
		return _chars[index];
	}

};

int main() {
	//Vector �̿�
	Vector v0{ 1,2,3 };

	cout << v0[-1] << endl;	//x=1
	cout << v0[0] << endl;	//x=1
	cout << v0[1] << endl;	//y=2
	cout << v0[2] << endl;	//z=3

	v0[0] = 100;
	cout << v0[0] << endl;	//x=100;

	//String �̿�
	String str{ "abc" };
	cout << str[0] << endl;	//a
	cout << str[1] << endl;	//b
	cout << str[2] << endl;	//c

	str[2] = 'd';	
	cout << str[2] << endl;
}
//11주차 실습 1번
#include <iostream>
using namespace std;

class Vector {
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) : x{ x }, y{ y }, z{ z } {}

	void print() {
		cout << x << " " << y << " " << z << " " << endl;
	}

	//단항 연산자 +
	Vector operator+() const {
		return Vector(+x, +y, +z);
	}

	//단항 연산자 -
	Vector operator-() const {
		return Vector(-x, -y, -z);	
	}

	//이항 연산자 +
	Vector operator+(const Vector& v) const {	
		return Vector{ this->x + v.x, this->y + v.y, this->z + v.z };
	}

	//이항 연산자 -
	Vector operator-(const Vector& v) const {
		return Vector{ this->x - v.x, this->y - v.y, this->z - v.z };
	}

	//벡터 간 내적 계산
	float operator* (const Vector& v) const {
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return dot;
	}

	//상수 곱하기
	Vector operator*(float n) const {
		return Vector(x * n, y * n, z * n);
	}

	//전위 연산자 ++
	Vector& operator++() {
		++x;
		++y;
		++z;
		return *this;	
	}

	//전위 연산자 --
	Vector& operator--() {
		--x;
		--y;
		--z;
		return *this;
	}

	//후위 연산자 ++
	Vector& operator++(int) {
		Vector temp = *this;	
		++x;
		++y;
		++z;
		return temp;	
	}

	//후위 연산자 --
	Vector& operator--(int) {
		Vector temp = *this;
		--x;
		--y;
		--z;
		return temp;
	}
};

int main() {
	Vector v0{ 0,1,2 };
	Vector v1{ 1,2,3 };

	Vector v2 = +v1;	//단항 연산자 +
	v2.print();	//1 2 3
	Vector v3 = -v1;	//단항 연산자 - 
	v3.print();	//-1 -2 -3

	Vector v4 = v0 + v1;	//이항 연산자 +
	v4.print();	//1 3 5
	Vector v5 = v1 - v0;	//이항 연산자 -
	v5.print();	//1 1 1

	float v6 = v0 * v1;	//벡터 간 내적 계산
	cout << v6 << endl;	//8

	Vector v7 = v1 * 3.0f;	//상수 곱하기
	v7.print();	//3 6 9

	
	Vector v8 = ++v1;	//전위 연산자 ++
	v8.print();	//2 3 4
	Vector v9 = --v1;	//전위 연산자 --
	v9.print();	//1 2 3

	
	Vector v10 = v1++;	//후위 연산자 ++
	v10.print();	//1 2 3: 값이 바뀌기 전
	v1.print();	//2 3 4: 값이 바뀐 후
	Vector v11 = v1--;	//후위 연산자 --
	v11.print();	//2 3 4: 값이 바뀌기 전
	v1.print();	//1 2 3: 값이 바뀐 후
}
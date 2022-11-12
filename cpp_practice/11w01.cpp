//cpp 11주차 실습 ppt 
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

	//이항 연산자 오버로딩 함수
	//매개변수 안에서 const & 붙이면 들어오는 값을 변경할 수 없게 읽는 용도로만 사용 가능! 
	//클래스 멤버함수 자체에 붙이는 const: 함수 내에서 멤버 변수를 이용해서 값을 바꾸는 것 불가능
	Vector operator+(const Vector& v) const {	//여기서 this = v0, 파라미터 v = v1
		return Vector{ this->x + v.x, this->y + v.y, this->z + v.z };	//Vector 공간을 만든 후 연산을 해서 return 해줘야함!
	}

	//나 자신의 값을 마이너스로 만들어주고 반환시키는 형태: 파라미터가 없어야함
	Vector operator-() const {
		return Vector(-x, -y, -z);	//나 자신의 값을 마이너스를 붙인 다음에 복사해서 전달하는 과정: 실질적으로 값 자체가 변하는 것은 아님! 매개변수 뒤에 const 붙여도 무방!
	}

	

	//벡터 간 내적 계산: 각각의 멤버 변수를 더해서 float형이 나와야함: 반환형이 float
	float operator* (const Vector& v) const {
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return dot;
	}

	//상수 곱하기
	Vector operator*(float n) const{
		return Vector(x * n, y * n, z * n);
	}
};

int main() {
	Vector v0{ 0,1,2 };
	Vector v1{ 1,2,3 };

	//새로운 벡터 객체에 v0, v1을 더한 값을 넣어줘!
	//이항연산자+ 오버로딩 함수를 만들어야함
	//여기서 v2와 v3은 동일한 결과!

	/*
	Vector operator+(const Vector& v) const {
			return Vector{this->x+v.x, this->y+v.y, this->z+v.z};
		}
	나의 멤버 변수 값과 파라미터로 들어온 객체의 멤버 변수를 바꾸는 것 없이 단순 더하기 연산만 이루어짐,
	더한 값 자체를 복사해서 main함수로 전달해 새로운 객체인 v2에 넣어주는 일련의 과정에서 x, y, z에 대한 값이나
	파라미터로 들어온 v에 대한 x, y, z의 값이 바뀌지 않고 있기 때문에 const를 붙일 수 있음
	:오류 줄일 수 있는 장점이 있음
	*/


	Vector v2 = v0 + v1;	//연산자 중복: 함수 호출이 아닌 연산자 기호를 사용했지만 operator 멤버 함수가 호출됨!
	Vector v3 = v0.operator+(v1);
	v2.print();	//1 3 5
	v3.print();	//1 3 5

	Vector v4 = -v1;	//단항 연산자- 오버로딩 함수를 만들어야함! = v1.operator-();
	v4.print();	//-1 -2 -3

	//이항 연산자*의 계산 방법 2가지
	//1. 내적 계산 (v0.x * v1.x) + (v0.y * v1.y) = float값이 나오도록!
	float v5 = v0 * v1;	//v0.operator*(v1);
	cout << v5 << endl;	//0*1 + 1*2 + 2*3 = 8
	//왜 v5.print(); 안될까?
	
	//2. 벡터 연산: 벡터 * 실수값 = 벡터값
	Vector v6 = v1 * 3.0f;	//v1.operator*(3.0f);
	v6.print();	//3 6 9
}


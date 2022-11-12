//cpp 11주차 실습 ppt p10: 대입 연산자 오버로딩 =
#include <iostream>
#include <cstring>
using namespace std;

class Vector {
private:
	float x, y, z;
	char* _chars;
public:
	Vector(){}
	Vector(float x, float y, float z, const char* chars)
		: x{x}, y{y}, z{z}, _chars(new char[strlen(chars) + 1]) 
	{
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}
	//복사 생성자 -> 위임생성자 호출 방식으로 만듦
	Vector(Vector& v) : Vector(v.x, v.y, v.z, v._chars) 
	{
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);
		cout << "copy" << endl;	//복사 생성자가 어느 시점에 발생되는지 확인하기 위해서!
	}

	~Vector() {
		delete[] _chars;
	}

	//반환형 Vector, 대입연산자는 const 붙일 수 없음!: 내가 가지고 있는 x값을 v로 받아온 x값으로 바꾸는 행위이기 때문에!
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

	Vector v0{ 1,2,3, "abc"};
	Vector v1 = v0;	//복사: 얕은 복사가 일어남!
	Vector v2;
	v2 = v0;	//대입: v2.operator=(v0)
	/*
	Vector& operator=(Vector & v)처럼 함수 선언 시 레퍼런스 연산자를 붙여줘야 복사 과정이 따로 없이 v2 = v0의 대입 연산만 일어나게 됨!
    레퍼런스 안 붙이면 v2 = v0에도 복사가 일어나 결과값에 copy가 연속으로 2번 출력됨
    또한 return *this;를 할 때 나의 값이 임시 객체 벡터로 복사됨: 반환할 때 복사 생성자 호출되어 copy 출력됨
	*/

	cout << v0 << endl;	//1 2 3
	cout << v1 << endl;	//1 2 3
	cout << v2 << endl;	//1 2 3

	/*
	얕은 복사: 포인터 변수인 char* chars에서는 주솟값을 받음, Vector v1 = v0를 통해 '주솟값'만 복사된 상태
	이후 객체가 하나 만들어진 다음에 소멸자의 호출에 의해 주솟값이 사라짐
	v1은 v0을 가리키는 주솟값만 가지고 있었는데, 그 주솟값 자체가 사라지게 되어버린 것 -> 깊은 복사를 해야함!
	v0에서 주솟값 뿐만 아니라 "abc" 값 자체도 함께 복사를 해야한다: 복사 생성자 이용
	*/
}
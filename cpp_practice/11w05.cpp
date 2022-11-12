//cpp 11주차 실습 ppt p10: Vector 이용한 첨자 연산자[] 오버로딩
#include <iostream>
using namespace std;

class Vector {
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) : x(x), y(y), z(z) {}

	//반환형이 float: 반환값이 x, y, z라서!
	float& operator[](int index) {
		if (index < 1)
			return x;
		if (index == 1)
			return y;
		else
			return z;
	}
};

int main() {
	Vector v0{ 1,2,3 };
	//실수값을 가져오는 cout 문장: cout 연산자 오버로딩 함수가 필요하지 않음!
	cout << v0[-1] << endl;	//-1 < 1이기 때문에 x=1 출력
	cout << v0[0] << endl;	//x=1, v0.operator[](int index); :: index는 가리키는 위치
	cout << v0[1] << endl;	//y=2
	cout << v0[2] << endl;	//z=3

	// float& operator[](int index)처럼 &를 붙여서 레퍼런스 함수로 만들면 값 변경 가능, 반환된 값 자체가 넘어오기 때문에!
	v0[0] = 100;
	cout << v0[0] << endl;	//x=100;

	/*
	함수의 값 변경을 불가능하게 하려면
	const float& operator[](int index) const
	사용하면 v0[0] = 100;에서 error 발생!
	복사x, 값 변경x: 효율적인 메모리 공간 이용, 코딩 오류 최소화
	*/
}
//cpp 11주차 실습 ppt p8
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

	//전위증감연산자: 내가 증가되는 것이므로 파라미터 필요없음
	//객체 v1 자체를 실제로 증가시켜줘야하기 때문에 const를 붙일 수 없음
	Vector& operator++() {	//레퍼런스 붙여주면 복사가 일어나지 않고 바로 전달할 수 있음
		++x;
		++y;
		++z;
		return *this;	//나 자신을 반환: this포인터 사용하기!
	}
	
	//후위증감연산자: 컴파일러가 전위증감연산자와 후위증감연산자를 구별하기 위해 파라미터에 아무 자료형이나 넣어서 알려주기
	Vector& operator++(int) {
		Vector temp = *this;	//임시객체 temp를 만들어서 나를 저장시킴
		++x;
		++y;
		++z;
		return temp;	//나의 값이 바뀌기 전에 나 자신을 반환을 하고 그 이후에 자신을 하나씩 증가시키기 떄문에 후위증가 가능 
	}
};

int main() {
	Vector v0{ 0,1,2 };
	Vector v1{ 1,2,3 };

	//전위증감연산자 ++v1
	Vector v2 = ++v1;	//v1.operator++();
	v2.print();	//2 3 4
	
	//후위증감연산자 v1++ 
	Vector v3 = v1++;
	v3.print();	//2 3 4: 값이 바뀌기 전에 먼저 출력, 이후 값이 바뀌기 때문에 v2와 결과값이 같음
	v1.print();	//3 4 5: v1 자체는 v3의 연산 이후에 증가했기 때문에!
}
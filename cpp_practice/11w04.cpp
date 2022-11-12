//cpp 11주차 실습 ppt p10: 입출력 연산 오버로딩
//cout, cin의 입출력을 내가 만든 Vector에 대한 연산자 오버로딩 함수(벡터 자체를 출력)를 통해 실행하기
//cout, cin은 이미 정의된 이름이기 때문에 이 자체로 멤버 함수를 만들 수 없어서 전역함수로 만들어줌, 
//이 때 클래스 내부의 priavte 멤버 변수를 사용하기 위해 friend 키워드를 이용함
#include <iostream>
using namespace std;

class Vector {
private:
	float x, y, z;
public:
	Vector(){}
	Vector(float x, float y, float z):x{x}, y{y},z{z}{}

	friend ostream& operator<<(ostream& os, Vector& v);	//이 함수는 내 친구니까 우리 클래스의 private 멤버 함수에 접근하도록 해줄게!
	friend istream& operator>>(istream& is, Vector& v);
};

//cout: ostream
//외부함수에서 Vector의 priavate 멤버 변수에 접근하기 위해서는 Vector 클래스에 firend 키워드로 선언해줘야함!
ostream& operator<<(ostream& os, Vector& v) {
	os << v.x << " " << v.y << " " << v.z << endl;
	return os;
}

istream& operator>>(istream& is, Vector& v) {
	is >> v.x >> v.y >> v.z;
	return is;
}

int main() {
	Vector v0{ 1,2,3 };
	cout << v0 << endl;		//cout << v0; :: '<<'가 정의되지 않음: operator<<(cout, v), 이 형태를 보고 멤버 함수가 아니라 클래스 외부함수라는 것을 예상해야함
							//operator << (cout,v) << endl; :: error! operator 함수의 반환형이 void, 따라서 operator << (cout, v)에는 아무 값도 들어있지 않음.
							// 이 상태에서 endl 실행시키면 에러 발생! endl;은 cout의 멤버함수, cout.endl;으로 사용할 수 있어야함! 반환형을 ostream으로 바꾸면 해결됨
	Vector v1;
	cin >> v1;	//operator>>(cin,v); :: cin이 이미 istream에 정의되어 있기 때문에 이 자체로 이용할 수 없음. 따라서 외부에 전역 함수를 만들어주는 형태로 이용해야함!
	cout << v1 << endl;
}
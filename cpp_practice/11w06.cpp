//cpp 11주차 실습 ppt p10: String 이용한 첨자 연산자[] 오버로딩
#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
	char* _chars;
public:
	String() {}
	String(const char* chars) : _chars{ new char[strlen(chars) + 1] } {
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}

	//각각의 위치에 있는 요소 반환: 반환형 char
	char& operator[](int index) {
		return _chars[index];
	}

};

int main() {
	String str{ "abc" };
	cout << str[0] << endl;	//a
	cout << str[1] << endl;	//b
	cout << str[2] << endl;	//c

	str[2] = 'd';	//char& operator[](int index) 처럼 레퍼런스 연산자 붙여줘야 값 접근해서 변경 가능!
	cout << str[2] << endl;	
	
	/*
	값 변경을 원하지 않고 값 가져오기만 할 때 const 이용
	const char& operator[](int index) const로 만들기
	*/
}
//cpp 11주차 실습 ppt p9
//기존에는 문자열을 쓸 때 string 클래스를 이용했지만 이번에는 직접 string을 다룰 수 있는 클래스를 만들어서 이용하며 비교&관계 연산자 오버로딩까지 실행해봄!
#include <iostream>
#include <cstring>	//strcpy, strcmp
using namespace std;

class String {
private:
	char* _chars;	//포인터변수 설정: 내부적으로 들어오는 값을 동적으로 할당 받아서 사용을 하겠다는 의미
public:
	String() {}
	String(const char* chars) : _chars{ new char[strlen(chars) + 1] } {
		strcpy_s(_chars, strlen(chars) + 1, chars);	//나의 멤버 변수 공간에 파라미터로 받아온 값을 복사할게
		//문자열을 파라미터로 보내면 주솟값도 함께 따라감: 디레퍼런싱 해줌, 이때 앞에 const를 붙여야 오류가 나지 않음
		//멤버 초기화 리스트에서 new char[파라미터로 받은 문자열의 길이 + 1]: 뒤에 null이 있어야 해서 +1해서 동적 할당 받음
	}

	bool operator==(const String& str) const {
		return strcmp(_chars, str._chars) == 0;	//내가 가지고 있는 객체(_chars)와 새로 받아온 객체(str._chars)가 같으면 true 반환 
	}

	bool operator>(const String& str) const {
		return strcmp(_chars, str._chars) > 0;
	}

	bool operator<=(const String& str) const {
		//'<=' 의 반대 연산자 '>' 이용하기
		return !(*this > str);		//이미 정의된 기호 '>' 사용하기!
	}
};
	
int main() {
	String str0{ "abc" };
	String str1{ "abc" };

	/*
	bool operator==(const String& str) const가 없을 경우 error! 원래 cstring의 내부에서 구현된 함수 사용, but 우리 직접 정의한 string 클래스에는 비교 기능 함수가 없기 때문에
	if (str0 == str1)
		cout << "equal" << endl;
	*/

	if (str0 == str1)	//str0.operator==(str1); 여기서 true인지 false인지 받아와야 하기 때문에 bool형 반환형 이용
		cout << "eqaul" << endl;	//print!
	else
		cout << "not equal" << endl;

	String str2{ "abc" };
	String str3{ "cde" };
	if (str2 > str3)	//str0.operator>(str1): true와 false값이 필요하기 때문에 bool 반환받음
		cout << "str2 > str3" << endl;
	else
		cout << "str2 < str3" << endl;	//print!

	if (str2 <= str3)	//str2.operator<=(str3): true와 false값이 필요하기 때문에 bool 반환받음
		cout << "str2 <= str3" << endl;	//print!
	else
		cout << "str2 > str3" << endl;
}
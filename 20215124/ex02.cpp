//11주차 실습 2번
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

	//'==' 연산자
	bool operator==(const String& str) const {
		return strcmp(_chars, str._chars) == 0;
	}

	//'!=' 연산자
	bool operator!=(const String& str) const {
		return strcmp(_chars, str._chars) != 0;
	}

	//'>' 연산자
	bool operator>(const String& str) const {
		return strcmp(_chars, str._chars) > 0;
	}

	//'<' 연산자
	bool operator<(const String& str) const {
		return strcmp(_chars, str._chars) < 0;
	}

	//'>=' 연산자
	bool operator>=(const String& str) const {
		return !(*this < str);
	}

	//'<=' 연산자
	bool operator<=(const String& str) const {
		return !(*this > str);
	}
};

int main() {
	String str0{ "abc" };
	String str1{ "def" };

	//'==' 연산자
	if (str0 == str1)	
		cout << "str0 == str1 is true" << endl;	
	else
		cout << "str0 == str1 is false" << endl;	//print!

	//'!=' 연산자
	if (str0 != str1)
		cout << "str0 != str1 is true" << endl;		//print!
	else
		cout << "str0 != str1 is false" << endl;

	//'>' 연산자
	if (str0 > str1)
		cout << "str0 > str1 is true" << endl;
	else
		cout << "str0 > str1 is false" << endl;		//print!

	//'<' 연산자
	if (str0 < str1)
		cout << "str0 < str1 is true" << endl;		//print!
	else
		cout << "str0 < str1 is false" << endl;

	//'>=' 연산자
	if (str0 >= str1)
		cout << "str0 >= str1 is true" << endl;
	else
		cout << "str0 >= str1 is false" << endl;	//print!

	//'<=' 연산자
	if (str0 <= str1)
		cout << "str0 <= str1 is true" << endl;		//print!
	else
		cout << "str0 <= str1 is false" << endl;
}
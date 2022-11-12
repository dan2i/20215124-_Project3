//cpp 11���� �ǽ� ppt p10: String �̿��� ÷�� ������[] �����ε�
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

	//������ ��ġ�� �ִ� ��� ��ȯ: ��ȯ�� char
	char& operator[](int index) {
		return _chars[index];
	}

};

int main() {
	String str{ "abc" };
	cout << str[0] << endl;	//a
	cout << str[1] << endl;	//b
	cout << str[2] << endl;	//c

	str[2] = 'd';	//char& operator[](int index) ó�� ���۷��� ������ �ٿ���� �� �����ؼ� ���� ����!
	cout << str[2] << endl;	
	
	/*
	�� ������ ������ �ʰ� �� �������⸸ �� �� const �̿�
	const char& operator[](int index) const�� �����
	*/
}
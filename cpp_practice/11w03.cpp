//cpp 11���� �ǽ� ppt p9
//�������� ���ڿ��� �� �� string Ŭ������ �̿������� �̹����� ���� string�� �ٷ� �� �ִ� Ŭ������ ���� �̿��ϸ� ��&���� ������ �����ε����� �����غ�!
#include <iostream>
#include <cstring>	//strcpy, strcmp
using namespace std;

class String {
private:
	char* _chars;	//�����ͺ��� ����: ���������� ������ ���� �������� �Ҵ� �޾Ƽ� ����� �ϰڴٴ� �ǹ�
public:
	String() {}
	String(const char* chars) : _chars{ new char[strlen(chars) + 1] } {
		strcpy_s(_chars, strlen(chars) + 1, chars);	//���� ��� ���� ������ �Ķ���ͷ� �޾ƿ� ���� �����Ұ�
		//���ڿ��� �Ķ���ͷ� ������ �ּڰ��� �Բ� ����: ���۷��� ����, �̶� �տ� const�� �ٿ��� ������ ���� ����
		//��� �ʱ�ȭ ����Ʈ���� new char[�Ķ���ͷ� ���� ���ڿ��� ���� + 1]: �ڿ� null�� �־�� �ؼ� +1�ؼ� ���� �Ҵ� ����
	}

	bool operator==(const String& str) const {
		return strcmp(_chars, str._chars) == 0;	//���� ������ �ִ� ��ü(_chars)�� ���� �޾ƿ� ��ü(str._chars)�� ������ true ��ȯ 
	}

	bool operator>(const String& str) const {
		return strcmp(_chars, str._chars) > 0;
	}

	bool operator<=(const String& str) const {
		//'<=' �� �ݴ� ������ '>' �̿��ϱ�
		return !(*this > str);		//�̹� ���ǵ� ��ȣ '>' ����ϱ�!
	}
};
	
int main() {
	String str0{ "abc" };
	String str1{ "abc" };

	/*
	bool operator==(const String& str) const�� ���� ��� error! ���� cstring�� ���ο��� ������ �Լ� ���, but �츮 ���� ������ string Ŭ�������� �� ��� �Լ��� ���� ������
	if (str0 == str1)
		cout << "equal" << endl;
	*/

	if (str0 == str1)	//str0.operator==(str1); ���⼭ true���� false���� �޾ƿ;� �ϱ� ������ bool�� ��ȯ�� �̿�
		cout << "eqaul" << endl;	//print!
	else
		cout << "not equal" << endl;

	String str2{ "abc" };
	String str3{ "cde" };
	if (str2 > str3)	//str0.operator>(str1): true�� false���� �ʿ��ϱ� ������ bool ��ȯ����
		cout << "str2 > str3" << endl;
	else
		cout << "str2 < str3" << endl;	//print!

	if (str2 <= str3)	//str2.operator<=(str3): true�� false���� �ʿ��ϱ� ������ bool ��ȯ����
		cout << "str2 <= str3" << endl;	//print!
	else
		cout << "str2 > str3" << endl;
}
//cpp 11���� �ǽ� ppt p10: ���� ������ �����ε� =
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
	//���� ������ -> ���ӻ����� ȣ�� ������� ����
	Vector(Vector& v) : Vector(v.x, v.y, v.z, v._chars) 
	{
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);
		cout << "copy" << endl;	//���� �����ڰ� ��� ������ �߻��Ǵ��� Ȯ���ϱ� ���ؼ�!
	}

	~Vector() {
		delete[] _chars;
	}

	//��ȯ�� Vector, ���Կ����ڴ� const ���� �� ����!: ���� ������ �ִ� x���� v�� �޾ƿ� x������ �ٲٴ� �����̱� ������!
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
	int b = a;	//����
	int c;
	c = a;	//����

	Vector v0{ 1,2,3, "abc"};
	Vector v1 = v0;	//����: ���� ���簡 �Ͼ!
	Vector v2;
	v2 = v0;	//����: v2.operator=(v0)
	/*
	Vector& operator=(Vector & v)ó�� �Լ� ���� �� ���۷��� �����ڸ� �ٿ���� ���� ������ ���� ���� v2 = v0�� ���� ���길 �Ͼ�� ��!
    ���۷��� �� ���̸� v2 = v0���� ���簡 �Ͼ ������� copy�� �������� 2�� ��µ�
    ���� return *this;�� �� �� ���� ���� �ӽ� ��ü ���ͷ� �����: ��ȯ�� �� ���� ������ ȣ��Ǿ� copy ��µ�
	*/

	cout << v0 << endl;	//1 2 3
	cout << v1 << endl;	//1 2 3
	cout << v2 << endl;	//1 2 3

	/*
	���� ����: ������ ������ char* chars������ �ּڰ��� ����, Vector v1 = v0�� ���� '�ּڰ�'�� ����� ����
	���� ��ü�� �ϳ� ������� ������ �Ҹ����� ȣ�⿡ ���� �ּڰ��� �����
	v1�� v0�� ����Ű�� �ּڰ��� ������ �־��µ�, �� �ּڰ� ��ü�� ������� �Ǿ���� �� -> ���� ���縦 �ؾ���!
	v0���� �ּڰ� �Ӹ� �ƴ϶� "abc" �� ��ü�� �Բ� ���縦 �ؾ��Ѵ�: ���� ������ �̿�
	*/
}
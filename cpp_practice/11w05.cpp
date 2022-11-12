//cpp 11���� �ǽ� ppt p10: Vector �̿��� ÷�� ������[] �����ε�
#include <iostream>
using namespace std;

class Vector {
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) : x(x), y(y), z(z) {}

	//��ȯ���� float: ��ȯ���� x, y, z��!
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
	//�Ǽ����� �������� cout ����: cout ������ �����ε� �Լ��� �ʿ����� ����!
	cout << v0[-1] << endl;	//-1 < 1�̱� ������ x=1 ���
	cout << v0[0] << endl;	//x=1, v0.operator[](int index); :: index�� ����Ű�� ��ġ
	cout << v0[1] << endl;	//y=2
	cout << v0[2] << endl;	//z=3

	// float& operator[](int index)ó�� &�� �ٿ��� ���۷��� �Լ��� ����� �� ���� ����, ��ȯ�� �� ��ü�� �Ѿ���� ������!
	v0[0] = 100;
	cout << v0[0] << endl;	//x=100;

	/*
	�Լ��� �� ������ �Ұ����ϰ� �Ϸ���
	const float& operator[](int index) const
	����ϸ� v0[0] = 100;���� error �߻�!
	����x, �� ����x: ȿ������ �޸� ���� �̿�, �ڵ� ���� �ּ�ȭ
	*/
}
//cpp 11���� �ǽ� ppt 
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

	//���� ������ �����ε� �Լ�
	//�Ű����� �ȿ��� const & ���̸� ������ ���� ������ �� ���� �д� �뵵�θ� ��� ����! 
	//Ŭ���� ����Լ� ��ü�� ���̴� const: �Լ� ������ ��� ������ �̿��ؼ� ���� �ٲٴ� �� �Ұ���
	Vector operator+(const Vector& v) const {	//���⼭ this = v0, �Ķ���� v = v1
		return Vector{ this->x + v.x, this->y + v.y, this->z + v.z };	//Vector ������ ���� �� ������ �ؼ� return �������!
	}

	//�� �ڽ��� ���� ���̳ʽ��� ������ְ� ��ȯ��Ű�� ����: �Ķ���Ͱ� �������
	Vector operator-() const {
		return Vector(-x, -y, -z);	//�� �ڽ��� ���� ���̳ʽ��� ���� ������ �����ؼ� �����ϴ� ����: ���������� �� ��ü�� ���ϴ� ���� �ƴ�! �Ű����� �ڿ� const �ٿ��� ����!
	}

	

	//���� �� ���� ���: ������ ��� ������ ���ؼ� float���� ���;���: ��ȯ���� float
	float operator* (const Vector& v) const {
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return dot;
	}

	//��� ���ϱ�
	Vector operator*(float n) const{
		return Vector(x * n, y * n, z * n);
	}
};

int main() {
	Vector v0{ 0,1,2 };
	Vector v1{ 1,2,3 };

	//���ο� ���� ��ü�� v0, v1�� ���� ���� �־���!
	//���׿�����+ �����ε� �Լ��� ��������
	//���⼭ v2�� v3�� ������ ���!

	/*
	Vector operator+(const Vector& v) const {
			return Vector{this->x+v.x, this->y+v.y, this->z+v.z};
		}
	���� ��� ���� ���� �Ķ���ͷ� ���� ��ü�� ��� ������ �ٲٴ� �� ���� �ܼ� ���ϱ� ���길 �̷����,
	���� �� ��ü�� �����ؼ� main�Լ��� ������ ���ο� ��ü�� v2�� �־��ִ� �Ϸ��� �������� x, y, z�� ���� ���̳�
	�Ķ���ͷ� ���� v�� ���� x, y, z�� ���� �ٲ��� �ʰ� �ֱ� ������ const�� ���� �� ����
	:���� ���� �� �ִ� ������ ����
	*/


	Vector v2 = v0 + v1;	//������ �ߺ�: �Լ� ȣ���� �ƴ� ������ ��ȣ�� ��������� operator ��� �Լ��� ȣ���!
	Vector v3 = v0.operator+(v1);
	v2.print();	//1 3 5
	v3.print();	//1 3 5

	Vector v4 = -v1;	//���� ������- �����ε� �Լ��� ��������! = v1.operator-();
	v4.print();	//-1 -2 -3

	//���� ������*�� ��� ��� 2����
	//1. ���� ��� (v0.x * v1.x) + (v0.y * v1.y) = float���� ��������!
	float v5 = v0 * v1;	//v0.operator*(v1);
	cout << v5 << endl;	//0*1 + 1*2 + 2*3 = 8
	//�� v5.print(); �ȵɱ�?
	
	//2. ���� ����: ���� * �Ǽ��� = ���Ͱ�
	Vector v6 = v1 * 3.0f;	//v1.operator*(3.0f);
	v6.print();	//3 6 9
}


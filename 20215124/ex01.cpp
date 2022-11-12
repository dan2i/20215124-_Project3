//11���� �ǽ� 1��
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

	//���� ������ +
	Vector operator+() const {
		return Vector(+x, +y, +z);
	}

	//���� ������ -
	Vector operator-() const {
		return Vector(-x, -y, -z);	
	}

	//���� ������ +
	Vector operator+(const Vector& v) const {	
		return Vector{ this->x + v.x, this->y + v.y, this->z + v.z };
	}

	//���� ������ -
	Vector operator-(const Vector& v) const {
		return Vector{ this->x - v.x, this->y - v.y, this->z - v.z };
	}

	//���� �� ���� ���
	float operator* (const Vector& v) const {
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return dot;
	}

	//��� ���ϱ�
	Vector operator*(float n) const {
		return Vector(x * n, y * n, z * n);
	}

	//���� ������ ++
	Vector& operator++() {
		++x;
		++y;
		++z;
		return *this;	
	}

	//���� ������ --
	Vector& operator--() {
		--x;
		--y;
		--z;
		return *this;
	}

	//���� ������ ++
	Vector& operator++(int) {
		Vector temp = *this;	
		++x;
		++y;
		++z;
		return temp;	
	}

	//���� ������ --
	Vector& operator--(int) {
		Vector temp = *this;
		--x;
		--y;
		--z;
		return temp;
	}
};

int main() {
	Vector v0{ 0,1,2 };
	Vector v1{ 1,2,3 };

	Vector v2 = +v1;	//���� ������ +
	v2.print();	//1 2 3
	Vector v3 = -v1;	//���� ������ - 
	v3.print();	//-1 -2 -3

	Vector v4 = v0 + v1;	//���� ������ +
	v4.print();	//1 3 5
	Vector v5 = v1 - v0;	//���� ������ -
	v5.print();	//1 1 1

	float v6 = v0 * v1;	//���� �� ���� ���
	cout << v6 << endl;	//8

	Vector v7 = v1 * 3.0f;	//��� ���ϱ�
	v7.print();	//3 6 9

	
	Vector v8 = ++v1;	//���� ������ ++
	v8.print();	//2 3 4
	Vector v9 = --v1;	//���� ������ --
	v9.print();	//1 2 3

	
	Vector v10 = v1++;	//���� ������ ++
	v10.print();	//1 2 3: ���� �ٲ�� ��
	v1.print();	//2 3 4: ���� �ٲ� ��
	Vector v11 = v1--;	//���� ������ --
	v11.print();	//2 3 4: ���� �ٲ�� ��
	v1.print();	//1 2 3: ���� �ٲ� ��
}
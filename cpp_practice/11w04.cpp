//cpp 11���� �ǽ� ppt p10: ����� ���� �����ε�
//cout, cin�� ������� ���� ���� Vector�� ���� ������ �����ε� �Լ�(���� ��ü�� ���)�� ���� �����ϱ�
//cout, cin�� �̹� ���ǵ� �̸��̱� ������ �� ��ü�� ��� �Լ��� ���� �� ��� �����Լ��� �������, 
//�� �� Ŭ���� ������ priavte ��� ������ ����ϱ� ���� friend Ű���带 �̿���
#include <iostream>
using namespace std;

class Vector {
private:
	float x, y, z;
public:
	Vector(){}
	Vector(float x, float y, float z):x{x}, y{y},z{z}{}

	friend ostream& operator<<(ostream& os, Vector& v);	//�� �Լ��� �� ģ���ϱ� �츮 Ŭ������ private ��� �Լ��� �����ϵ��� ���ٰ�!
	friend istream& operator>>(istream& is, Vector& v);
};

//cout: ostream
//�ܺ��Լ����� Vector�� priavate ��� ������ �����ϱ� ���ؼ��� Vector Ŭ������ firend Ű����� �����������!
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
	cout << v0 << endl;		//cout << v0; :: '<<'�� ���ǵ��� ����: operator<<(cout, v), �� ���¸� ���� ��� �Լ��� �ƴ϶� Ŭ���� �ܺ��Լ���� ���� �����ؾ���
							//operator << (cout,v) << endl; :: error! operator �Լ��� ��ȯ���� void, ���� operator << (cout, v)���� �ƹ� ���� ������� ����.
							// �� ���¿��� endl �����Ű�� ���� �߻�! endl;�� cout�� ����Լ�, cout.endl;���� ����� �� �־����! ��ȯ���� ostream���� �ٲٸ� �ذ��
	Vector v1;
	cin >> v1;	//operator>>(cin,v); :: cin�� �̹� istream�� ���ǵǾ� �ֱ� ������ �� ��ü�� �̿��� �� ����. ���� �ܺο� ���� �Լ��� ������ִ� ���·� �̿��ؾ���!
	cout << v1 << endl;
}
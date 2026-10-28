#include <iostream>
using namespace std;

int karatsubaAlgorithm(int n1, int n2) {
	if (n1 < 10 || n2 < 10) {
		return n1 * n2;
	}
	int n = max((int)(floor(log(n1) / log(10)) + 1), (int)(floor(log(n2) / log(10)) + 1));
	int m = n / 2;
	int power = (int)pow(10, m);
	int a = n1 / power; int b = n1 % power;
	int c = n2 / power; int d = n2 % power;
	int z0 = karatsubaAlgorithm(a, c);
	int z1 = karatsubaAlgorithm((a + b), (c + d));
	int z2 = karatsubaAlgorithm(b, d);
	return (z0 * pow(10, (2 * m))) + ((z1 - z0 - z2) * pow(10, (m))) + z2;
}

int main() {
	int num1, num2;
	cout << "Enter two numbers separated by a space" << endl;
	cin >> num1 >> num2;
	cout << "The Product of entered numbers by Karatsuba is " << karatsubaAlgorithm(num1, num2) << endl;

	return 0;
}
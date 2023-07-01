#include <iostream>
using namespace std;

int cifmax(int n) {
	if (n < 10)
		return n;
	else {
		int x = cifmax(n / 10);
		if (x > n % 10)
			return x;
		else return n % 10;
	}
}

int main()
{
	cout << cifmax(9352137);
}
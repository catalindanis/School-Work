#include <iostream>
//#include <fstream>
#include <cstring>
using namespace std;

//ifstream cin("halfsort1.in");
//ofstream cout("halfsort1.out");

void afisvec(int v[], int n) {
	if (n == 1)
		cout << v[n - 1] << ' ';
	else {
		afisvec(v, n - 1);
		cout << v[n - 1] << ' ';
	}
}



int main() {
	int v[] = { 1,2,3,4 }, n = 4;
	afisvec(v, n);
}


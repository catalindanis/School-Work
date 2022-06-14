#include <iostream>
using namespace std;

void sub(int n, int* v, int x) {
	int ind = 0;
	for (int i = 0; i < n; i++)
		if (v[i] == x)
			swap(v[ind], v[i]), ind++;
	for (int i = 0; i < n; i++)
		cout << v[i] << ' ';
}

int main() {
	int n, v[1001], x;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cin >> x;
	sub(n, v, x);
	return 0;
}
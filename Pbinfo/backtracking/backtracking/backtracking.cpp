#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

//ifstream cin("permutari.in");
//ofstream cout("permutari.out");

int n;
int v[12], ap[12], x[12];

bool prim(int n) {
    int c = 0;
    for (int i = 1; i * i <= n; i++)
        if (i * i == n)
            c++;
        else if (n % i == 0)
            c += 2;
    return c == 2;
}

bool apare(int val) {
    for (int i = 1; i <= n; i++)
        if (x[i] == val)
            return true;
    return false;
}

bool isOk(int ind) {
    if (ind == 1)
        return true;
    
    return !(prim(x[ind]) && prim(x[ind-1]));
}

void afis() {
    for (int i = 1; i <= n; i++)
        cout << x[i] << ' ';
    cout << '\n';
}

void back(int k) {
    for (int i = 1; i <= n; i++) {
        if (!apare(v[i])) {
            x[k] = v[i];
            if (isOk(k)) {
                if (k < n)
                    back(k + 1);
                else afis();
            }
            x[k] = 0;
        }
    }
}

void sort(int* v) {
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (v[i] > v[j])
                swap(v[i], v[j]);
}

int main()
{
    cin >> n;
    int val;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        v[i] = val;
    }
    sort(v);
    back(1);
}

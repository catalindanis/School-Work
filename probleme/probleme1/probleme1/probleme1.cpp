#include <iostream>
#include <cmath>
using namespace std;

bool prim(int n) {
    if (n < 2)
        return 0;
    else {
        int c = 0;
        for (int i = 1; i * i <= n; i++)
            if (i * i == n)
                c++;
            else if (n % i == 0)
                c += 2;
        return c == 2;
    }
}

void hanoi(int n, char sursa, char intermediar, char destinatie) {
    if (n == 1) {
        cout << sursa << "->" << destinatie<<endl;
    }
    else {
        hanoi(n - 1, sursa, destinatie, intermediar);
        cout << sursa << "->" << destinatie<<endl;
        hanoi(n - 1, intermediar, sursa, destinatie);
    }
}

int main()
{
    int n, a[1001];
    cin >> n;
    //for (int i = 1; i <= n; i++)
        //cin >> a[i];
    //for (int i = 1; i <= n; i++, cout << ' ')
        //cout << a[i];    
    
    //hanoi(n, 'A', 'B', 'C');
    cout << (2 << 3);
    return 0;
}

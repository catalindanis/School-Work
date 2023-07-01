#include <iostream>
#include <fstream>

using namespace std;
int INF = 1000000;
ifstream fin("adiacenta.in");
ofstream fout("adiacenta.out");

int n, sursa;
int x, y, c;
int M[101][101];
bool v[101];
int d[101];
int t[101];

void afis() {
    for (int i = 1; i <= n; i++)
        fout << d[i] << ' ';
    fout << endl;
    for (int i = 1; i <= n; i++)
        fout << t[i] << ' ';
}

void afisDrum(int nod) {
    if (d[nod] == -1) {
        cout << "Nu se poate ajunge la acest nod!";
        return;
    }
    if (t[nod])
        afisDrum(t[nod]);
    cout << nod << ' ';
}

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        d[i] = M[sursa][i];
        if (d[i] != INF)
            t[i] = sursa;
    }
    v[sursa] = true;
    d[0] = INF;
    t[sursa] = 0;
    for (int k = 1; k < n; k++) {
        int imax = 0;
        for (int i = 1; i <= n; i++)
            if (!v[i] && d[i] < d[imax])
                imax = i;
        if (imax) {
            v[imax] = 1;
            for (int i = 1; i <= n; i++)
                if (!v[i] && d[i] > d[imax] + M[imax][i]) {
                    d[i] = d[imax] + M[imax][i];
                    t[i] = imax;
                }
        }
    }
    for (int i = 1; i <= n; i++)
        if (d[i] == INF)
            d[i] = -1;
}

int main() {
    fin >> n >> sursa;
    while (fin >> x >> y >> c) {
        M[x][y] = c;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && !M[i][j])
                M[i][j] = INF;
    dijkstra();
    afis();
    while (true) {
        cout << "VEZI DRUMUL PANA LA NODUL : ";
        cin >> x;
        afisDrum(x);
        cout << endl;
    }
    return 0;
}

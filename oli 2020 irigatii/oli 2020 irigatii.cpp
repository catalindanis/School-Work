#include <iostream>
using namespace std;
int n, m;
int a[1000][1000];
int c;
int l, e;
int dl[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

int main()
{
    cin >> c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    cin >> l >> e;
    if (c == 1) {
        int fotografii = (m / l) * (n / l);
        int suprafata_ramasa = (n * m) - (l * l) * fotografii;
        cout << fotografii << ' ' << suprafata_ramasa;
    }
    else if (c == 2) {
        int cn = n, cm = m;
        while (cm) {
            int r = cn % cm;
            cn = cm;
            cm = r;
        }
        cout << cn;
    }
    else if (c == 3) {
        struct poz {
            int x, y;
        };
        poz coada[1000];
        int inc = 1, sf = 0;
        int zonapomi = 0, zonavegetatie = 0, maxpomi = 0, maxveg = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == 1) {
                    zonapomi = 1;
                    sf = 1;
                    inc = 1;
                    coada[sf].x = i;
                    coada[sf].y = j;
                    while (inc <= sf) {
                        for (int k = 0; k < 4; k++) {
                            int x, y;
                            x = dl[k] + coada[inc].x;
                            y = dc[k] + coada[inc].y;
                            if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == 1) {
                                zonapomi++;
                                sf++;
                                coada[sf].x = x;
                                coada[sf].y = y;
                            }
                        }
                        inc++;
                    }
                    if (zonapomi > maxpomi)
                        maxpomi = zonapomi;
                }
                else if (a[i][j] == 2) {
                    zonavegetatie = 1;
                    sf = 1;
                    inc = 1;
                    coada[sf].x = i;
                    coada[sf].y = j;
                    while (inc <= sf) {
                        for (int k = 0; k < 4; k++) {
                            int x, y;
                            x = dl[k] + coada[inc].x;
                            y = dc[k] + coada[inc].y;
                            if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == 2) {
                                zonavegetatie++;
                                sf++;
                                coada[sf].x = x;
                                coada[sf].y = y;
                            }
                        }
                        inc++;
                    }
                    if (zonavegetatie > maxveg)
                        maxveg = zonavegetatie;

                }
            }
        cout << maxpomi << ' ' << maxveg;
    }
    else {

    }

}

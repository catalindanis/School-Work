#include <iostream>
#include <fstream>

using namespace std;
int INF = 1000000;
ifstream fin("adiacenta.in");
ofstream fout("adiacenta.out");

struct muchie {
    int x, y, c;
};

int n, m;
muchie M[101];
int t[101];
int costTotal;
int arbore[202];
int indArbore;

void kruskal() {
    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
            if (M[i].c > M[j].c)
                swap(M[i], M[j]);

    for (int i = 1; i <= n; i++)
        t[i] = i;

    for (int i = 1; i <= m; i++) {
        if (t[M[i].x] != t[M[i].y]) {
            
            arbore[++indArbore] = M[i].x;
            arbore[++indArbore] = M[i].y;
            costTotal += M[i].c;
            
            int ai = t[M[i].x], aj = t[M[i].y];
            for (int j = 1; j <= n; j++)
                if (t[j] == aj)
                    t[j] = ai;
        }
    }
    
    fout << costTotal << endl;
    for (int i = 1; i <= indArbore; i+=2) {
        fout << arbore[i] << ' ' << arbore[i + 1] << endl;
    }
}

int main(){
    fin >> n >> m;
    for (int i = 1; i <= m; i++)
        fin >> M[i].x >> M[i].y >> M[i].c;
    kruskal();
    return 0;
}

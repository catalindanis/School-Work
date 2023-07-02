#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

ifstream fin("bitcoin.in");
ofstream fout("bitcoin.out");

struct pereche{
    int x,y;
}p;

int nrTeste,x,y;
int minim = -1;
int maxim = -1;
vector <pereche> v;
vector <int> sDiv;
int s;

int sumaDiv(int n){
    s = 0;
    for(int i=1;i*i<=n;i++)
        if(i*i == n)
            s += i;
        else if(n%i == 0)
            s += ((n/i) + i);
    return s;
}

int main()
{
    v.push_back(p);
    fin>>nrTeste;
    for(int i=1;i<=nrTeste;i++){
        fin>>p.x>>p.y;
        if(minim == -1)
            minim = p.x;
        else minim = min(p.x,minim);

        if(maxim == -1)
            maxim = p.y;
        else maxim = max(p.y,maxim);

        v.push_back(p);
    }

    sDiv.push_back(0);
    for(int i=minim;i<=maxim;i++){
        sDiv.push_back(sDiv[i-1] + sumaDiv(i));

    }

    for(int i=1;i<=nrTeste;i++){
        //fout<<"SUMA INTRE : "<<v[i].x<<' '<<v[i].y<<endl;
        fout<<sDiv[v[i].y] - sDiv[v[i].x-1]<<endl;
    }
    return 0;
}


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

ifstream fin("secvente.in");
ofstream fout("secvente.out");

int N,x,y;
vector <int> v;
queue <int> qMin,qMax;
int dif;

void nrSolutii(){
    int nrSol = 0;
    while(!qMin.empty() && !qMax.empty()){
        int dif = abs(qMin.front() - qMax.front()) - 1;
        for(int i=min(qMin.front(),qMax.front());i<=N;i++){
            if(v[i] < x || v[i] > y)
                break;
            nrSol++;
            //cout<<min(qMin.front(),qMax.front())<<' '<<i<<endl;
        }
        if(nrSol > 0)
            nrSol -= dif;
        if(nrSol > 0)
            nrSol -- ;
        if(qMin.front() < qMax.front())
            qMin.pop();
        else
            qMax.pop();
    }
    fout<<nrSol;
}

int main()
{
    fin>>N>>x>>y;
    v.push_back(-1);
    for(int i=1;i<=N;i++){
        int nr;
        fin>>nr;
        v.push_back(nr);
        if(nr == x)
            qMin.push(i);
        if(nr == y)
            qMax.push(i);
    }

    nrSolutii();

    return 0;
}


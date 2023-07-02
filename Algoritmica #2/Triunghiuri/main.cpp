#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

ifstream fin("triunghiuri.in");
ofstream fout("triunghiuri.out");

int n,m;
int M[1001][1001];
int x,y;
int c;
int v[1001];
int ind;

void DFS(int varf,int tata,int nrVarfuri){
    //fout<<"IL MARCHEZ PE : "<<varf<<" CA VIZITAT"<<endl;
    v[varf] = 1;
    for(int k=1;k<=n;k++){
        if(M[varf][k]){
            //fout<<"EXISTA CULOAR INTRE : "<<varf<<' '<<k<<endl;
            if(v[k]){
                //fout<<k<<" ESTE DEJA VIZITAT"<<endl;
                if(k == tata && nrVarfuri == 3){
                    //fout<<"AM GASIT TRIUNGHI!"<<endl;
                    //fout<<endl;
                    c++;
                }
            }
            else if(nrVarfuri < 3){
                //fout<<"CONTINUI CAUTAREA IN : "<<k<<endl;
                DFS(k,tata,nrVarfuri+1);
                v[k] = 0;
            }
        }
    }

}

int nrTriunghiuri(){
    for(int i=1;i<=n;i++){
        //fout<<"INCEP CAUTAREA IN : "<<i<<endl;
        DFS(i,i,1);
        for(int j=1;j<=n;j++)
            v[j] = 0;
        //fout<<"TERMIN CAUTAREA IN : "<<i<<endl<<endl<<endl;
    }
    return c;
}

int main()
{
    fin>>n>>m;
    for(int i=1;i<=m;i++){
        fin>>x>>y;
        M[x][y] = M[y][x] = 1;
    }
    nrTriunghiuri();
    fout<<c/6;
    return 0;
}

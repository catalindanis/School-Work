#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("summit.in");
ofstream fout("summit.out");

int gasit(int *sc,int inc,int sf,int val){
    if(inc > sf)
        return 0;
    else{
        int mij = (inc+sf)/2;
        if(sc[mij] ==val)
            return mij;
        else if(sc[mij] < val)
            return gasit(sc,mij+1,sf,val);
        else return gasit(sc,inc,mij-1,val);
    }
}

void det(int *a,int n,int *sc){
    for(int i=1;i<=n;i++){
        fout<<gasit(sc,1,n,a[i])<<endl;
    }
}

int main()
{
    int n;
    int a[100001],sc[100001];
    fin>>n;
    sc[0] = 0;
    for(int i=1;i<=n;i++){
        fin>>a[i];
        sc[i] = sc[i-1]+a[i];
    }
    det(a,n,sc);
    return 0;
}

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//ifstream cin("siruri.in");
//ofstream cout("siruri.out");

int C,n;
int ap[10];
int x[9];

void afis(){
    for(int i=1;i<=n;i++)
        cout<<x[i];
    cout<<'\n';
}

void back1(int k){
    for(int i=0;i<=9;i++){
        if(k == 1 && i == 0)
            continue;
        if(!ap[i] && i%2 != k%2){
            ap[i] = 1;
            x[k] = i;
            if(k < n)
                back1(k+1);
            else afis();
            ap[i] = 0;
        }
    }
}

void back2(int k){
    for(int i=0;i<=9;i++){
        if(k == 1 && i == 0)
            continue;
        if((k == 1 || i >= x[k-1]) && k != i){
            x[k] = i;
            if(k < n)
                back2(k+1);
            else afis();
        }
    }
}

int main()
{
    cin>>C>>n;
    if(C == 1){
        back1(1);
    }
    else{
        back2(1);
    }
    return 0;
}

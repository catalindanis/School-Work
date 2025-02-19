#include <iostream>
using namespace std;

int a[100][100];
int x[11],n;

bool col(int x,int y){
    for(int i=x+1;i<=n;i++)
        if(a[i][y] == 1)
            return false;
    return true;
}
bool lin(int x,int y){
    for(int i=y+1;i<=n;i++)
        if(a[x][i] == 1)
            return false;
    return true;
}

bool diag(int x,int y){
    for(int i=x+1,j=y+1;i<=n && j<=n;i++,j++)
        if(a[i][j] == 1)
            return false;
    for(int i=x+1,j=y-1;i<=n && j>=1;i++,j--)
        if(a[i][j] == 1)
            return false;
    return true;
}

bool isSol(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j] == 1)
                if(!col(i,j) || !lin(i,j) || !diag(i,j))
                    return false;
    return true;
}

void backtracking(int k){
    for(int i=1;i<=n;i++){
        a[k][i] = 1;
        if(k == n){
            if(isSol()){
                for(int i=1;i<=n;i++,cout<<endl)
                    for(int j=1;j<=n;j++)
                        cout<<a[i][j]<<' ';
                    cout<<endl;
            }
        }
        else backtracking(k+1);
        a[k][i] = 0;
    }
}

int main(){
    cout<<"Introduceti dimensiunea tablei: ";
    cin>>n;
    if(n <= 3 || cin.fail()){
        cout<<"Dimensiunea tablei e prea mica sau nu ati introdus o cifra!";
        return 0;
    }
    backtracking(1);
    return 0;
}


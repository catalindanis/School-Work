#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

// ifstream cin("acces1.in");
// ofstream cout("acces1.out");
queue <pair<int,int>>q;
char a[1001][1001];
int b[1001][1001] = {-1};
int n, m;
const int dl[] = {-1,0,+1,0};
const int dc[] = {0,+1,0,-1};

bool inmat(int i,int j){
    return i>=1 && j>=1 && i<=n && j<=m;
}

void lee(int istart,int jstart){
    q.push(make_pair(istart,jstart));
    b[istart][jstart] = 0;
    while(!q.empty()){
        for(int k=0;k<4;k++){
            int inou = q.front().first + dl[k];
            int jnou = q.front().second + dc[k];
            if(inmat(inou,jnou) && a[inou][jnou] != '#' && a[inou][jnou !='P']){
                if(b[inou][jnou] == -1)
                    b[inou][jnou] = b[q.front().first][q.front().second] + 1;
                else if(b[q.front().first][q.front().second] + 1 < b[inou][jnou])
                    b[inou][jnou] = b[q.front().first][q.front().second] + 1;
                q.push(make_pair(inou,jnou));
            }
        }
        q.pop();
    }
}

void afisare(){
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=m;j++)
            if(b[i][j] != -1){
                if(a[i][j] == 'P')
                    cout<<0<<' ';
                else cout<<b[i][j]<<' ';
            }
            else{
                cout<<a[i][j]<<' ';
            }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j] == 'P')
                lee(i,j);
    afisare();
    return 0;
}
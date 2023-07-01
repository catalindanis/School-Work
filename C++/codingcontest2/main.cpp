#include <iostream>
#include <queue>
using namespace std;

char matrix[101][101];
int coinsMatrix[101][101];
int n;
string row;
int numberOfGhosts;
int dx[] = {-1,0,+1,0};
int dy[] = {0,+1,0,-1};
string moveChar[] = {"U", "R", "D", "L"};

struct PacMan{
    int x,y = -1;
    bool isDead = false;
    int maxNumberOfMoves = 0;
    string moves = string();
    int collectedCoins = 0;
}player;

bool collectedAllCoins(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(matrix[i][j] == 'C')
                return false;
    return true;
}

bool isWall(int x,int y){
    return matrix[x][y] == 'W';
}

bool isGhost(int x,int y){
    return matrix[x][y] == 'G';
}

bool inMatrix(int x,int y){
    return x >= 1 && y >= 1 && x <= n && y <= n;
}

bool visited(int x,int y){
    return matrix[x][y] == 'V';
}

void findPath(int x,int y,int lx,int ly){
    matrix[x][y] = 'N';

    if(collectedAllCoins())
        return;

    for(int k=0;k<4;k++){
        int nX = x + dx[k];
        int nY = y + dy[k];
        if(matrix[nX][nY] == 'C'){
            player.moves.append(moveChar[k]);
            findPath(nX,nY,x,y);
            if(!collectedAllCoins()){
            if(k == 0)
                player.moves.append("D");
            if(k == 1)
                player.moves.append("L");
            if(k == 2)
                player.moves.append("U");
            if(k == 3)
                player.moves.append("R");
            }
        }
    }

    return;
}

int main()
{

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>row;
        for(int j=1;j<=n;j++){
            matrix[i][j] = row[j-1];
            if(matrix[i][j] == 'C')
                coinsMatrix[i][j] = 1;
        }
    }
    cin>>player.x>>player.y;
    cin>>player.maxNumberOfMoves;

    findPath(player.x,player.y,player.x,player.y);
    //cin>>n;
    cout<<player.moves;
    return 0;
}

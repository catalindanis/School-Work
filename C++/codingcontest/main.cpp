#include <iostream>

using namespace std;

char matrix[101][101];
int coinsMatrix[101][101];
int n;
string row;
int numberOfGhosts;

struct PacMan{
    int x,y = -1;
    bool isDead = false;
    int numberOfMoves = 0;
    string moves;
    int collectedCoins = 0;
}player;

struct Ghost{
    int x,y;
    int numberOfMoves = 0;
    string moves;
};

void checkForMove(){
    if(matrix[player.x][player.y] == 'G' || matrix[player.x][player.y] == 'W')
        player.isDead = true;
    else{
        if(matrix[player.x][player.y] == 'C'){
            player.collectedCoins++;
            coinsMatrix[player.x][player.y] = 0;
        }
        matrix[player.x][player.y] = 'P';
    }
}

void displayStatus(){
    cout<<player.collectedCoins<<' ';
    player.isDead ? cout<<"NO" : cout<<"YES";
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
    cin>>player.numberOfMoves;
    cin>>player.moves;
    cin>>numberOfGhosts;
    Ghost ghost[numberOfGhosts];
    for(int i=0;i<numberOfGhosts;i++){
        cin>>ghost[i].x>>ghost[i].y;
        cin>>ghost[i].numberOfMoves>>ghost[i].moves;
    }
    for(int i=0;i<player.numberOfMoves && !player.isDead;i++){
        for(int j=0;j<numberOfGhosts;j++)
            switch(ghost[j].moves[i]){
                case 'U':
                    if(coinsMatrix[ghost[j].x][ghost[j].y] == 1)
                        matrix[ghost[j].x][ghost[j].y] = 'C';
                    else matrix[ghost[j].x][ghost[j].y] = 'N';
                    ghost[j].x--;
                    matrix[ghost[j].x][ghost[j].y] = 'G';
                    break;
                case 'D':
                    if(coinsMatrix[ghost[j].x][ghost[j].y] == 1)
                        matrix[ghost[j].x][ghost[j].y] = 'C';
                    else matrix[ghost[j].x][ghost[j].y] = 'N';
                    ghost[j].x++;
                    matrix[ghost[j].x][ghost[j].y] = 'G';
                    break;
                case 'L':
                    if(coinsMatrix[ghost[j].x][ghost[j].y] == 1)
                        matrix[ghost[j].x][ghost[j].y] = 'C';
                    else matrix[ghost[j].x][ghost[j].y] = 'N';
                    ghost[j].y--;
                    matrix[ghost[j].x][ghost[j].y] = 'G';
                    break;
                case 'R':
                    if(coinsMatrix[ghost[j].x][ghost[j].y] == 1)
                        matrix[ghost[j].x][ghost[j].y] = 'C';
                    else matrix[ghost[j].x][ghost[j].y] = 'N';
                    ghost[j].y++;
                    matrix[ghost[j].x][ghost[j].y] = 'G';
                    break;
            }
        switch(player.moves[i]){
                case 'U':
                    player.x--;
                    checkForMove();
                    break;
                case 'D':
                    player.x++;
                    checkForMove();
                    break;
                case 'L':
                    player.y--;
                    checkForMove();
                    break;
                case 'R':
                    player.y++;
                    checkForMove();
                    break;
        }
    }
    displayStatus();
    return 0;
}

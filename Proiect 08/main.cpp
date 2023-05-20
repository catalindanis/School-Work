#include <iostream>

using namespace std;

const int GRAPH_SIZE = 67;
const int MAZE_N = 12;
const int MAZE_M = 13;
const int START_VERTEX = 0, START_X = 0, START_Y = 1;
const int END_VERTEX = 29, END_X = 10, END_Y = 0;

const int vI[4] = {-1,0,1,0};
const int vJ[4] = {0,-1,0,+1};

int m[GRAPH_SIZE][GRAPH_SIZE];
int v[GRAPH_SIZE];

int M[12][13] = {
    {-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1, 1,-1, 7, 8, 9, 10,11,-1, 60, 59, 58,-1},
    {-1, 2,-1, 6,-1,-1,-1, 12,-1, 61,-1, 57,-1},
    {-1, 3, 4, 5, 63, 64,-1, 13,-1, 62,-1, 56,-1},
    {-1,-1,-1,-1,-1, 65,-1, 14,-1,-1,-1, 55,-1},
    //{-1,-1,-1,-1,-1,0,-1,-1,-1,-1,0,-1},
    {-1, 50, 49, 48,-1, 66,-1, 15, 51, 52, 53, 54,-1},
    {-1,-1,-1, 47,-1,-1,-1, 16,-1,-1,-1,-1,-1},
    {-1, 32,-1, 46, 45, 44, 43, 17, 42, 41, 40, 39,-1},
    {-1, 31,-1,-1,-1,-1,-1, 18,-1,-1,-1, 38,-1},
    {-1, 30,-1, 25, 24, 23,-1, 19,-1, 35,-1, 37,-1},
    {29,28,27,26,-1,22,21, 20, 33, 34,-1, 36,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
};

char caracter(int c){
    switch(c){
        case -1:
            return '*';
        case -2:
            return '.';
        case -3:
            return 'S';
        case -4:
            return 'F';
        default:
            return ' ';
    }
}

void displayMaze(){
    for(int i=0;i<MAZE_N;i++,cout<<endl)
        for(int j=0;j<MAZE_M;j++)
            cout<<caracter(M[i][j])<<' ';
    cout<<endl;
}

void findPath(int vertex){
    for(int i=0;i<MAZE_N;i++)
        for(int j=0;j<MAZE_M;j++)
            if(M[i][j] == v[vertex])
                M[i][j] = -2;
    if(vertex != START_VERTEX)
    for(int k=0;k<67;k++)
        if(v[k] == v[vertex] - 1){
            findPath(k);
            break;
        }
    //cout<<vertex<<' ';
}

void displayNeighbours(){
    for(int i=0;i<GRAPH_SIZE;i++){
        cout<<"NODUL "<<i<<": ";
        for(int j=0;j<GRAPH_SIZE;j++)
            if(m[i][j] == 1)
                cout<<j<<' ';
        cout<<endl;
    }
    cout<<endl;
}

void convertMazeToGraph(){
    for(int i=0;i<MAZE_N;i++)
        for(int j=0;j<MAZE_M;j++)
            if(M[i][j] != -1){
                for(int k = 0;k<4;k++){
                    int x = i + vI[k];
                    int y = j + vJ[k];
                    if(M[x][y] != -1 && !m[M[i][j]][M[x][y]]
                       && x >= 0 && x < 12 && y >= 0 && y < 13)
                        m[M[i][j]][M[x][y]] = 1;

                }
            }
}

void BFS(){
    int q[67];
    int st,dr;
    st = dr = 0;
    v[st] = 1;
    q[st] = m[0][1];
    while(st<=dr){
        int k = q[st];
        for(int j=0;j<GRAPH_SIZE;j++)
            if(m[k][j] && !v[j]){
                q[++dr] = j;
                v[j] = v[k] + 1;
            }
        st++;
    }
}

void solveMaze(){
    convertMazeToGraph();
    BFS();
    findPath(END_VERTEX);
    M[START_X][START_Y] = -3;
    M[END_X][END_Y] = -4;
}

void waitForEnter(){
    cin.get();
}

void start(){
    displayMaze();
    cout<<"APASA ENTER PENTRU A REZOLVA LAIBIRINTUL!\n";
    waitForEnter();
    solveMaze();
    displayMaze();
}

int main()
{
    start();
    return 0;
}

#include<iostream>
#include <conio.h> //_getch() - for getting input keys
#include <windows.h> //system("cls") - refresh the console after every move
#include <stdlib.h> //rand() - random number
#include <time.h> //srand(time(NULL)) - reset seed time so you can get random numbers everytime

using namespace std;

int pozx = 5, pozy = 5; //start position 
char a[10][10];//playing space
bool gameOver = 0;
int rx, ry;//random x and y coordonates
bool eat = 1; // know when the fruit is eated, and you need to generate another one
int score=0;

void mission() {
    srand(time(NULL));
    rx = rand() % 8;
    ry = rand() % 8;
    if (rx < 2)
        rx = 2;
    if (ry < 2)
        ry = 2;
    if (rx == pozx && ry == pozy)
        rx++, ry++;
    a[rx][ry] = '*';
    eat = 0;
}

void getkey() {
    char key = _getch();
    if (key == int(27))
        gameOver = 1;

    if (key == 'w') {
        if (pozx - 1 != 1) {
            a[pozx][pozy] = 0;
            a[pozx - 1][pozy] = 'X';
            pozx--;
        }
    }
    if (key == 'a') {
        if (pozy - 1 != 1) {
            a[pozx][pozy] = 0;
            a[pozx][pozy - 1] = 'X';
            pozy--;
        }
    }
    if (key == 'd') {
        if (pozy + 1 != 9) {
            a[pozx][pozy] = 0;
            a[pozx][pozy + 1] = 'X';
            pozy++;
        }
    }
    if (key == 's') {
        if (pozx + 1 != 9) {
            a[pozx][pozy] = 0;
            a[pozx + 1][pozy] = 'X';
            pozx++;
        }
    }
    if (pozx == rx && pozy == ry)
        eat = 1,score++;
}

void display() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (a[i][j] != 0)
                cout << a[i][j];
            else
                cout << " ";
        }
        cout << endl;
    }
    cout <<"Scorul tau este: " <<score << endl;
}

int main()
{
    for (int i = 1; i <= 9; i++)
        a[1][i] = '-', a[9][i] = '-';
    for (int i = 2; i <= 8; i++)
        a[i][1] = '|', a[i][9] = '|';
    a[5][5] = 'X';
    mission();
    while (!gameOver) {
        display();
        getkey();
        system("cls");
        if (eat)
            mission();
    }
    display();
    cout << "AI IESIT";
    
    return 0;
}
#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>

using namespace std;

char table[10][10];
char player = 'X';
int px=5, py=5;

void input() {
	char key = _getch(); 
		if (key == 'w') {
			table[px][py] = 0;
			table[px - 1][py] = player;
			px--;
		}
		if (key == 'a') {
			table[px][py] = 0;
			table[px][py - 1] = player;
			py--;

		}
		if (key == 'd') {
			table[px][py] = 0;
			table[px][py + 1] = player;
			py++;

		}
		if (key == 's') {
			table[px][py] = 0;
			table[px + 1][py] = player;
			px++;
		}
		if (px == 10) {
			table[px][py] = 0;
			px = 1;
			table[px][py] = player;
		}
		if (px == 0) {
			table[px][py] = 0;
			px = 9;
			table[px][py] = player;
		}
		if (py == 0) {
			table[px][py] = 0;
			py = 9;
			table[px][py] = player;
		}
		if (py == 10) {
			table[px][py] = 0;
			py = 1;
			table[px][py] = player;
		}
}

void display() {
	cout << "~~~~~~~~~~~"<<endl;
	for (int i = 1; i <= 9; i++) {
		cout << "|";
		for (int j = 1; j <= 9; j++)
			if (table[i][j] != 0)
				cout << player;
			else cout << ' ';
		cout << "|"<<endl;
	}
	cout << "~~~~~~~~~~~";
}

int main()
{
		table[5][5] = player;
		while (1) {
			display();
			input();
			system("cls");
		}

}

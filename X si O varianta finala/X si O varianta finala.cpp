#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
char table[100][100];
int wichplayer = 1;
string player1, player2;
char point = 'X';
bool gameStage = 1;
int gameRound=0;
char winner;
bool gameExit = 0;
void sg();
void draw() {
	cout <<"Oops, it is a draw!" << endl;
	cout << "Play Again?(y/n): ";
	char question = _getch();
	if (question == 'n')
		gameExit = 1;
	else {
		wichplayer = 1;
		gameRound = 0;
		gameStage = 1;
		point = 'X';
		char k = '1';
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				table[i][j] = k, k++;
	}
}

void gameOver() {
	cout << winner << " won the match!"<<endl;
	cout << "Play Again?(y/n): ";
	char question = _getch();
	if (question == 'n')
		gameExit = 1;
	else {
		gameRound = 1;
		gameStage = 1;
		point = 'X';
		char k = '1';
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				table[i][j] = k, k++;
		system("cls");
	}
	
}

void input() {
	if (wichplayer == 1) {
		cout << player1 << " enter your move number: ";
		wichplayer = 2;
	}
	else {
		cout << player2 << " enter your move number: ";
		wichplayer = 1;
	}
	char move = _getch();

	if (move == '1')
		table[1][1] = point;
	else if (move == '2')
		table[1][2] = point;
	else if (move == '3')
		table[1][3] = point;
	else if (move == '4')
		table[2][1] = point;
	else if (move == '5')
		table[2][2] = point;
	else if (move == '6')
		table[2][3] = point;
	else if (move == '7')
		table[3][1] = point;
	else if (move == '8')
		table[3][2] = point;
	else if (move == '9')
		table[3][3] = point;

	if (point == 'X')
		point = 'O';
	else point = 'X';

	if (table[1][1] == table[1][2] && table[1][2] == table[1][3]) {
		gameStage = 0;
		winner = table[1][1];
	}
	if (table[2][1] == table[2][2] && table[2][2] == table[2][3]) {
		gameStage = 0;
		winner = table[2][1];
	}
	if (table[3][1] == table[3][2] && table[3][2] == table[3][3]) {
		gameStage = 0;
		winner = table[3][1];
	}
	if (table[1][1] == table[2][1] && table[2][1] == table[3][1]) {
		gameStage = 0;
		winner = table[1][1];
	}
	if (table[1][2] == table[2][2] && table[2][2] == table[3][2]) {
		gameStage = 0;
		winner = table[1][2];
	}
	if (table[1][3] == table[2][3] && table[2][3] == table[3][3]) {
		gameStage = 0;
		winner = table[1][3];
	}
	if (table[1][1] == table[2][2] && table[2][2] == table[3][3]) {
		gameStage = 0;
		winner = table[1][1];
	}
	if (table[1][3] == table[2][2] && table[2][2] == table[3][1]) {
		gameStage = 0;
		winner = table[1][3];
	}

}

void display() {
	cout << "////TicTacToe.v1\\\\\\\\" << endl << endl;
	if(gameRound==0)
	Sleep(80);
	cout << "      -------" << endl;
	for (int i = 1; i <= 3; i++) {
		cout << "      |";
		for (int j = 1; j <= 3; j++)
			cout << table[i][j] << '|';
		if (gameRound == 0)
		Sleep(80);
		cout << "\b|";
		cout << endl;
		if (i != 3) {
			cout << "      -------";
			cout << endl;
		}
	}
	if (gameRound == 0)
	Sleep(80);
	cout << "      -------" << endl<<endl;

}
void welcome() {
	cout << "////TicTacToe.v1\\\\\\\\" << endl << endl;
	cout << "Press any key to continue...";
	_getch();
	system("cls");
	char word[26] = { 'P','r','e','s','s',' ','a','n','y',' ','k','e','y',' ','t','o',
	' ','c','o','n','t','i','n','u','e' };
	int final = 26;
	while (final) {
		cout << "////TicTacToe.v1\\\\\\\\" << endl << endl;
		for (int i = 0; i <= final; i++) {
			cout << word[i];
		}
		Sleep(15);
		system("cls");
		final--;
	}
	cout << "////TicTacToe.v1\\\\\\\\" << endl << endl;
	cout << "Type Player1 name: ";
	cin >> player1;
	system("cls");
	cout << "////TicTacToe.v1\\\\\\\\" << endl << endl;
	cout<< "Type Player2 name : ";
	cin >> player2;
	system("cls");
	
}

int main() {

	welcome();
	char k = '1';
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			table[i][j] = k, k++;
	while (!gameExit) {
		display();
		input();
		gameRound++;
		if (gameRound == 9)
			draw();
		else if(!gameStage)
			gameOver();
		else system("cls");
	}
	cout <<endl<< "Exiting game. Please wait!";
	Sleep(1000);
	
	
	
}
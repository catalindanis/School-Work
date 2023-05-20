#include <iostream>
#include <stdlib.h>
using namespace std;
int user_value;

void guessed(int user_value, int contor){
    cout<<"Ai ghicit numarul din "<<contor<<" incercari!";
}

void clearScreen(){
    system("cls");
}

void start(){
    cout<<"Introdu valoarea care va fi ghicita: "; cin>>user_value;
    clearScreen();
    int user_input;
    int contor = 0;
    do{
        contor++;
        cout<<"Introdu un numar: "; cin>>user_input;
        if(user_input < user_value)
            cout<<"Numarul introdus este prea mic!"<<endl;
        if(user_input > user_value)
            cout<<"Numarul introdus este prea mare!"<<endl;
        if(user_input == user_value)
            guessed(user_value,contor);
    }while(user_input != user_value);
}

int main()
{
    start();
    return 0;
}

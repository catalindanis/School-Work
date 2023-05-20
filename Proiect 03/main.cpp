#include <iostream>
#include <fstream>
#include <cstdlib>

std::ifstream read("Danis_Pr3_in.txt");

const std::string fileEmptyExceptionMessage = "Invalid Input! Check if your file is empty.\n";
const std::string invalidInputExceptionMessage = "Invalid Input! Check your input data type.\n";
std::string input = std::string();
bool exitRequested = false;

void readFromFile(){
    read>>input;
    if(input.empty()){
        std::cout<<fileEmptyExceptionMessage;
        exit(-1);
    }
}

void displayMenu(){
    std::cout<<"1.Afiseaza input-ul\n";
    std::cout<<"2.Afiseaza numarul de vocale\n";
    std::cout<<"3.Afiseza numarul de consoane\n";
    std::cout<<"4.Verifica conditie palindrom\n";
    std::cout<<"0.Iesire\n";
    std::cout<<"Alege optiunea : ";
}

void displayInput(){
    std::cout<<input<<std::endl;
}

bool isVowel(char character){
    return character == 'a' || character == 'e' || character == 'i' ||
        character == 'o' || character == 'u' || character == 'A' ||
       character == 'E' || character == 'I' || character == 'O' || character == 'U';
}

void displayNumberOfVowels(){
    int start = 0;
    int end = input.size();
    int counter = 0;
    while(start < end){
        if(isVowel(input[start]))
            counter++;
        start++;
    }
    std::cout<<"Numar vocale: "<<counter<<std::endl;
}

void displayNumberOfConsonant(){
    int end = input.size()-1;
    int counter = 0;
    do{
        if(!isVowel(input[end]))
            counter++;
    }while(end--);
    std::cout<<"Numar consoane: "<<counter<<std::endl;
}

void verifyPalindrom(){
    bool isPalindrom = true;
    for(int start = 0, end = input.size()-1; start < end &&
        isPalindrom; start++, end--){
            if(input[start] != input[end])
                isPalindrom = false;
    }
    isPalindrom ? std::cout<<"Cuvantul este palindrom"<<std::endl :
            std::cout<<"Cuvantul nu este palindrom"<<std::endl;
}

void waitForEnterKey(){
    std::cout<<"Apasa tasta ENTER pentru a continua\n";
    std::cin.ignore(200,'\n');
    std::cin.get();
}

void processInput(){
    int n;
    if(!(std::cin>>n)){
        std::cin.clear();
        std::cin.ignore(200,'\n');
        return;
    }
    switch(n){
        case 0:
            exitRequested = true;
            return;
            break;
        case 1:
            displayInput();
            break;
        case 2:
            displayNumberOfVowels();
            break;
        case 3:
            displayNumberOfConsonant();
            break;
        case 4:
            verifyPalindrom();
            break;
        case 5:
            readFromFile();
            break;
    }
    waitForEnterKey();
}

void clearScreen(){
    system("cls");
}

void displayExitMessage(){
    std::cout<<"La revedere!";
}

void start(){
    readFromFile();
    do{
        displayMenu();
        processInput();
        clearScreen();
    }while(!exitRequested);
    displayExitMessage();
}

int main()
{
    start();
    return 0;
}

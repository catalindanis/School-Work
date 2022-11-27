#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

int generatedValues[20] = {-1};
char results[2][15];
double headProcent, tailProcent;
bool exitRequested = false;

//init() =>
//-genereaza un seed random, pentru a nu se repeta valorile la rulari multiple ale programului
//-copiaza intr-un vector de cuvinte, valorile 'cap' si 'pajura', folosite la afisari
void init(){
    srand(time(NULL));
    strcpy(results[0],"cap");
    strcpy(results[1],"pajura");
}

//calculatePercents() =>
//-calculeaza procentajele pe baza valorilor generate
//-valorile 0 reprezinta cap, valorile 1 reprezinta pajura
void calculatePercents(){
    int headNumber = 0;
    int tailNumber = 0;
    for(int i=0;i<20;i++)
        switch(generatedValues[i]){
            case 0:
                headNumber ++;
                break;
            case 1:
                tailNumber ++;
                break;
        }
    headProcent = headNumber * 5;
    tailProcent = tailNumber * 5;
}

//generateValues() =>
//-folosind metoda rand(), din libraria cstdlib, generam numere aleatorii
//-stiind ca impartirea la 2 poate avea fie restul 1, fie restul 0,
//folosim aceste 2 valori pentru diferentierea dintre cap/pajura
void generateValues(){
    for(int i=0;i<20;i++)
        generatedValues[i] = rand()%2;
    calculatePercents();
}

//displayValues() =>
//-afiseaza valorile din vectorul de cuvinte results, folosind valorile din vectorul generatedValues ( 0 / 1 )
//-results[0] = "cap", results[1] = "pajura"
//-inainte de afisare, verificam daca deja au fost generate numere; in caz contrar, generam numere, si doar dupa afisam
//-dupa afisare, programul este pus pe pauza pana la apasarea tastei ENTER
void displayValues(){
    if(generatedValues[0] == -1)
        generateValues();
    for(int i=0;i<20;i++,std::cout<<std::endl){
            std::cout<<results[generatedValues[i]]<<' ';
    }
    std::cout<<"\nApasa tasta ENTER pentru a continua";
    std::cin.ignore(200,'\n');
    std::cin.get();
}


//displayPercents() =>
//-afiseaza procentajele, calculate pe baza numerelor generate
//-inainte de afisare, verificam daca deja au fost generate numere; in caz contrar,
//generam numere,calcula procentajul, si doar dupa afisam
//-dupa afisare, programul este pus pe pauza pana la apasarea tastei ENTER
void displayPercents(){
    if(generatedValues[0] == -1)
        generateValues();
    std::cout<<"Procentaj cap: "<<headProcent<<"%\n";
    std::cout<<"Procentaj pajura: "<<tailProcent<<"%\n";
    std::cout<<"\nApasa tasta ENTER pentru a continua";
    std::cin.ignore(200,'\n');
    std::cin.get();
}

//displayMenu() =>
//-afiseaza optiunuile disponibile
void displayMenu(){
    std::cout<<"Alege o optiune: \n";
    std::cout<<"1.Genereaza valori noi\n";
    std::cout<<"2.Afiseaza valorile curente\n";
    std::cout<<"3.Afiseaza procentele curente\n";
    std::cout<<"4.Iesire\n";
}

//processInpput() =>
//-citeste si prelucreaza datele introduse de utilizator de la tastatura
//-dupa citire, verificam daca utilizatorul a introdus un tip de date corect, in caz contrar ignoram
//si iesim din functie
//-daca datele introduse sunt corecte, actionam corespunzator optiunii alese; daca optiunea nu corespunde
//cu cele disponibile, programul va iesi din functie
void processInput(){
    int input;
    if(!(std::cin>>input)){
        std::cin.clear();
        std::cin.ignore(200,'\n');
        return;
    }
    switch(input){
        case 1:
            generateValues();
            break;
        case 2:
            displayValues();
            break;
        case 3:
            displayPercents();
            break;
        case 4:
            exitRequested = true;
            break;
    }
}

//clearScreen() =>
//-curata fereastra terminalului
void clearScreen(){
    system("cls");
}

//displayExitMessage() =>
//-scrie mesajul pentru iesirea din program
void displayExitMessage(){
    std::cout<<"La revedere!";
}

//start() =>
//-reprezinta intreg parcursul programului, cat si momentul in care acesta este finalizat
//-dupa initializare, programul repeta 3 pasi, pana cand se doreste iesirea din program:
//   -curata ecranul
//   -afiseaza meniu
//   -proceseaza datele introduse
//-cand se doreste iesirea din program, afiseaza mesajul de iesire dupa care iese din functie
void start(){
    init();
    while(!exitRequested){
        clearScreen();
        displayMenu();
        processInput();
    }
    displayExitMessage();
}

//main() =>
//-locul de unde incepe rularea programului
int main(){
    start();
}

#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>

using namespace std;

void bankName();
void homePage();
int getUserInput();
void existingCard();
void infoArea();
void developerMode();
void developerModePASSWORD();
void newCard();
void checkBalance();
void depositFunds();
void withdrawFunds();
void convertBalance();

class personInfo {
public:
    string name;
    string card_number;
    double balanceRon = 0, balanceEur = 0, balanceUSD = 0;
    string llname;
    int lltransactions=0;
    string llip="192.169.0.239:1994";

    string Card_number;
    void getCardNumber() {
        cout << "Enter your card number: \n";
        cin >> Card_number;
        if (Card_number.length() == 16)
            card_number = Card_number;
        else {
            cout << "INVALID CARD";
            Sleep(400);
            system("cls");
            getCardNumber();
        }
    }
    void generateName() {
        if (Card_number[14] == '0')
            name = "Daniel";
        if (Card_number[14] == '1')
            name = "Alex";
        if (Card_number[14] == '2')
            name = "John";
        if (Card_number[14] == '3')
            name = "Ana";
        if (Card_number[14] == '4')
            name = "Noah";
        if (Card_number[14] == '5')
            name = "Emma";
        if (Card_number[14] == '6')
            name = "Charlotte";
        if (Card_number[14] == '7')
            name = "Henry";
        if (Card_number[14] == '8')
            name = "Harper";
        if (Card_number[14] == '9')
            name = "Sophya";


        if (Card_number[15] == '0')
            name += " Smith";
        if (Card_number[15] == '1')
            name += " Johnson";
        if (Card_number[15] == '2')
            name += " Davis";
        if (Card_number[15] == '3')
            name += " Williams";
        if (Card_number[15] == '4')
            name += " Brown";
        if (Card_number[15] == '5')
            name += " Jones";
        if (Card_number[15] == '6')
            name += " Lopez";
        if (Card_number[15] == '7')
            name += " Taylor";
        if (Card_number[15] == '8')
            name += " Adams";
        if (Card_number[15] == '9')
            name += " Anderson";

        llname = name;
    }
    void generateBalance() {
        srand(time(NULL));
        if (card_number[13] == '0' || card_number[13] == '1' || card_number[13] == '2' || card_number[13] == '3') {
            balanceRon = rand() % 6000;
        }
        else if (card_number[13] == '4' || card_number[13] == '5' || card_number[13] == '6' || card_number[13] == '7') {
            balanceEur = rand() % 3000;
        }
        else {
            balanceUSD = rand() % 4500;
        }
    }
    void generateCard() {
        srand(time(NULL));
        for (int i = 1; i <= 16; i++) {
            int x = (rand() % 11);
            if (x == 0) {
                if (i > 1)
                    card_number += '0';
                else card_number += '4';
            }
            else if (x == 1)
                card_number += '1';
            else if (x == 2)
                card_number += '2';
            else if (x == 3)
                card_number += '3';
            else if (x == 4)
                card_number += '4';
            else if (x == 5)
                card_number += '5';
            else if (x == 6)
                card_number += '6';
            else if (x == 7)
                card_number += '7';
            else if (x == 8)
                card_number += '8';
            else if (x == 9)
                card_number += '9';
        }
    }
};

personInfo person;

int main()
{
    system("color 2");
    homePage();
}

void bankName() {
    cout << "Danis's Bank v1.0\n\n";
}

void homePage() {
    system("cls");
    bankName();
    cout << "Add an existing card (1)\n";
    cout << "Create a new card (2)\n";
    cout << "Choose your option: ";
    int value = _getch();
    if (value == '1')
        existingCard();
    if (value == '2')
        newCard();
    if (value == '9')
        developerModePASSWORD();
    else
        homePage();
}
void existingCard() {

    system("cls");
    bankName();
    person.getCardNumber();
    person.generateBalance();
    person.generateName();
    infoArea();
}
void infoArea() {
    system("cls");
    bankName();
    cout << person.name << '\n';
    cout << person.card_number << "\n\n";
    cout << "Check balance (1)\n";
    cout << "Deposit funds (2)\n";
    cout << "Withdraw fund (3)\n";
    cout << "Convert balance (4)\n\n";
    cout << "Back to main menu (5)\n";
    cout << "Choose your option: ";
    int value = _getch();
    if (value == '1')
        checkBalance();
    if (value == '2')
        depositFunds();
    if (value == '3')
        withdrawFunds();
    if (value == '4')
        convertBalance();
    if (value == '5')
        homePage();
    else {
        infoArea();
    }

};
void checkBalance() {
    person.lltransactions++;
    system("cls");
    bankName();
    cout << "RON: " << person.balanceRon << endl;
    cout << "EUR: " << person.balanceEur << endl;
    cout << "USD: " << person.balanceUSD << endl;
    cout << endl << "Press (1) to go back: ";
    int value = _getch();
    if (value == '1')
        infoArea();
    else checkBalance();
}
void depositFunds() {
    person.lltransactions++;
    srand(time(NULL));
    system("cls");
    bankName();
    cout << "Choose your currency: ";
    cout << "RON (1)  EUR (2)  USD (3)\n";
    cout << "Back (4)\n";
    cout << "Choose your option: \n";
    char value = _getch();
    if (value == '1') {

        cout << "Insert the amount you want to deposit: ";
        double bal;
        cin >> bal;
        cout << "Processing your order...\n";
        Sleep(1000);
        int x = rand() % 10 + 1;
        if (x == 9) {
            cout << "Operation wasn't successful\nPlease try again";
            Sleep(1000);
        }
        else {
            person.balanceRon += bal;
            cout << "Operation succeeded";
            Sleep(1000);
        }
        depositFunds();
    }
    if (value == '2') {
        cout << "Insert the amount you want to deposit: ";
        double bal;
        cin >> bal;
        cout << "Processing your order...\n";
        Sleep(1000);
        int x = rand() % 10 + 1;
        if (x == 9) {
            cout << "Operation wasn't successful\nPlease try again";
            Sleep(1000);
        }
        else {
            person.balanceEur += bal;
            cout << "Operation succeeded";
            Sleep(1000);
        }
        depositFunds();
    }
    if (value == '3') {
        cout << "Insert the amount you want to deposit: ";
        double bal;
        cin >> bal;
        cout << "Processing your order...\n";
        Sleep(1000);
        int x = rand() % 10 + 1;
        if (x == 9) {
            cout << "Operation wasn't successful\nPlease try again";
            Sleep(1000);
        }
        else {
            person.balanceUSD += bal;
            cout << "Operation succeeded";
            Sleep(1000);
        }
        depositFunds();
    }
    if (value == '4') {
        infoArea();
    }
    else depositFunds();
}
void withdrawFunds() {
    person.lltransactions++;
    srand(time(NULL));
    system("cls");
    bankName();
    cout << "Choose your currency: ";
    cout << "RON (1)  EUR (2)  USD (3)\n";
    cout << "Back (4)\n";
    cout << "Choose your option: \n";
    char value = _getch();
    if (value == '1') {
        cout << "Insert the amount you want to withdraw: ";
        double bal;
        cin >> bal;
        if (bal > person.balanceRon) {
            cout << "Not enough funds";
            Sleep(1000);
        }
        else {
            int x = rand() % 10 + 1;
            if (x == 9) {
                cout << "Operation wasn't successful\nPlease try again";
                Sleep(1000);
            }
            else {
                person.balanceRon -= bal;
                cout << "Operation succeeded";
                Sleep(1000);
            }
        }
        withdrawFunds();
    }

    if (value == '2') {
        cout << "Insert the amount you want to withdraw: ";
        double bal;
        cin >> bal;
        if (bal > person.balanceEur) {
            cout << "Not enough funds";
            Sleep(1000);
        }
        else {
            int x = rand() % 10 + 1;
            if (x == 9) {
                cout << "Operation wasn't successful\nPlease try again";
                Sleep(1000);
            }
            else {
                person.balanceEur -= bal;
                cout << "Operation succeeded";
                Sleep(1000);
            }
        }
        withdrawFunds();
    }
    if (value == '3') {
        cout << "Insert the amount you want to withdraw: ";
        double bal;
        cin >> bal;
        if (bal > person.balanceUSD) {
            cout << "Not enough funds";
            Sleep(1000);
        }
        else {
            int x = rand() % 10 + 1;
            if (x == 9) {
                cout << "Operation wasn't successful\nPlease try again";
                Sleep(1000);
            }
            else {
                person.balanceUSD -= bal;
                cout << "Operation succeeded";
                Sleep(1000);
            }
        }
        withdrawFunds();
    }
    if (value == '4') {
        infoArea();
    }
    else withdrawFunds();

}
void convertBalance() {
    person.lltransactions++;
    srand(time(NULL));
    system("cls");
    bankName();
    cout << "Choose currency you want to convert:";
    cout << "RON (1)  EUR (2)  USD (3)\n";
    cout << "BACK (4)\n";
    cout << "___ -> ___\n";
    cout << "Choose your option: \n";
    char value = _getch();
    if (value == '1') {
        system("cls");
        bankName();
        cout << "EUR (1)  USD (2)\n";
        cout << "RON -> ___\n";
        cout << "Choose your option: \n";
        char val = _getch();
        if (val == '1') {
            system("cls");
            bankName();
            cout << "RON -> EUR\n";
            cout << "Enter the amount you want to convert: ";
            double bal;
            cin >> bal;
            if (bal <= person.balanceRon) {
                cout << "Converting your money...";
                Sleep(1000);
                person.balanceRon -= bal;
                person.balanceEur += bal / 4.9;
                cout << "Operation succeded";
                Sleep(1000);
                convertBalance();
            }
            else {
                cout << "Not enough balance";
                Sleep(1000);
                convertBalance();
            }
        }
        else if (val == '2') {
            system("cls");
            bankName();
            cout << "RON -> USD\n";
            cout << "Enter the amount you want to convert: ";
            double bal;
            cin >> bal;
            if (bal <= person.balanceRon) {
                cout << "Converting your money...";
                Sleep(1000);
                person.balanceRon -= bal;
                person.balanceUSD += bal / 4.3;
                cout << "Operation succeded";
                Sleep(1000);
                convertBalance();
            }
            else {
                cout << "Not enough balance";
                Sleep(1000);
                convertBalance();
            }
        }
        else {
            convertBalance();
        }
    }
    if (value == '2') {
        system("cls");
        bankName();
        cout << "RON (1)  USD (2)\n";
        cout << "EUR -> ___\n";
        cout << "Choose your option: \n";
        char val = _getch();
        if (val == '1') {
            system("cls");
            bankName();
            cout << "EUR -> RON\n";
            cout << "Enter the amount you want to convert: ";
            double bal;
            cin >> bal;
            if (bal <= person.balanceEur) {
                cout << "Converting your money...";
                Sleep(1000);
                person.balanceEur -= bal;
                person.balanceRon += (bal * 4.9);
                cout << "Operation succeded";
                Sleep(1000);
                convertBalance();
            }
            else {
                cout << "Not enough balance";
                Sleep(1000);
                convertBalance();
            }
        }
        else if (val == '2') {
            system("cls");
            bankName();
            cout << "EUR -> USD\n";
            cout << "Enter the amount you want to convert: ";
            double bal;
            cin >> bal;
            if (bal <= person.balanceEur) {
                cout << "Converting your money...";
                Sleep(1000);
                person.balanceEur -= bal;
                person.balanceUSD += (bal * 1.13);
                cout << "Operation succeded";
                Sleep(1000);
                convertBalance();
            }
            else {
                cout << "Not enough balance";
                Sleep(1000);
                convertBalance();
            }
        }
        else {
            convertBalance();
        }

    }
    if (value == '3') {
        system("cls");
        bankName();
        cout << "RON (1)  EUR (2)\n";
        cout << "USD -> ___\n";
        cout << "Choose your option: \n";
        char val = _getch();
        if (val == '1') {
            system("cls");
            bankName();
            cout << "USD -> RON\n";
            cout << "Enter the amount you want to convert: ";
            double bal;
            cin >> bal;
            if (bal <= person.balanceUSD) {
                cout << "Converting your money...";
                Sleep(1000);
                person.balanceUSD -= bal;
                person.balanceRon += (bal * 4.3);
                cout << "Operation succeded";
                Sleep(1000);
                convertBalance();
            }
            else {
                cout << "Not enough balance";
                Sleep(1000);
                convertBalance();
            }
        }
        else if (val == '2') {
            system("cls");
            bankName();
            cout << "USD -> EUR\n";
            cout << "Enter the amount you want to convert: ";
            double bal;
            cin >> bal;
            if (bal <= person.balanceUSD) {
                cout << "Converting your money...";
                Sleep(1000);
                person.balanceUSD -= bal;
                person.balanceEur += (bal / 1.13);
                cout << "Operation succeded";
                Sleep(1000);
                convertBalance();
            }
            else {
                cout << "Not enough balance";
                Sleep(1000);
                convertBalance();
            }
        }
        else {
            convertBalance();
        }
    }
    if (value == '4') {
        infoArea();
    }
    else {
        convertBalance();
    }
}

void newCard() {
    system("cls");
    bankName();
    cout << "First name: ";
    string n;
    cin >> n;
    person.name = n;
    cout << "Last name: ";
    cin >> n;
    person.name += n;
    cout << "\nGenerating your card...\n";
    Sleep(1500);
    person.generateCard();
    cout << "Done!";
    Sleep(1000);
    person.generateBalance();
    infoArea();
}

void developerModePASSWORD() {
    system("cls");
    bankName();
    cout << "**Developer Mode**\n\n";
    cout << "Enter password: ";
    string password;
    cin >> password;
    if (password == "dev") {
        cout << "\nCORRECT PASSWORD. SETTING UP DEVELOPER MODE";
        Sleep(1000);
        developerMode();
    }
    else {
        cout << "\nINCORRECT PASSWORD!";
        Sleep(1000);
        developerModePASSWORD();
    }
}

void developerMode() {
        system("cls");
        cout << "Restart system (1)\n";
        cout << "Lock ATM (2)\n";
        cout << "See last log (3)\n";
        cout << "Auto-repair.tool (4)\n";
        cout << "Back to main menu (9)\n";
        char x = _getch();
        if (x == '1') {
            system("cls");
            cout << "Restarting system. This can take a moment\n";
            Sleep(2000);
            system("cls");
            cout << "Shutting down";
            Sleep(1500);
            system("cls");
            cout << "Starting system";
            Sleep(1500);
            system("cls");
            cout << "Initializing bank.script";
            Sleep(550);
            system("cls");
            cout << "Initializing bank.hardware";
            Sleep(550);
            system("cls");
            cout << "Initializing bank.interface";
            Sleep(550);
            system("cls");
            cout << "Initializing person.info";
            system("cls");
            cout << "Initializing infoArea.bk";
            Sleep(550);
            system("cls");
            system("cls");
            cout << "Initializing depositFunds.cpp"; 
            Sleep(550);
            system("cls");
            cout << "Initializing depositFunds.js";
            Sleep(550);
            system("cls");
            cout << "Initializing withdrawFunds.cpp";
            Sleep(550);
            system("cls");
            cout << "Initializing withdraw.funds.extend";
            system("cls");
            cout << "Initializing resolvingTOP.cpp";
            Sleep(550);
            system("cls");
            cout << "Initializing filessystem";
            Sleep(550);
            system("cls");
            cout << "Initializing hardwareStorage";
            Sleep(550);
            system("cls");
            cout << "Setting up INTERFACE.bk";
            Sleep(550);
            system("cls");
            cout << "Initializing protection.js";
            Sleep(550);
            system("cls");
            cout << "Initializing protection.hardware.eula";
            Sleep(550);
            system("cls");
            cout << "Extends bank.resolvehostname";
            Sleep(550);
            system("cls");
            cout << "Connecting to 192.168.1.1224:0001";
            Sleep(800);
            system("cls");
            system("cls");
            cout << "Connection port found: Danis's Bank";
            Sleep(550);
            system("cls");
            cout << "Connection established";
            Sleep(550);
            system("cls");
            cout << "Finishing processes";
            Sleep(550);
            system("cls");
            cout << "Restart completed";
            Sleep(1500);
            homePage();
        }
        else if (x == '2') {
            system("cls");
            cout << "Locking up ATM...\n";
            Sleep(1500);
            cout << "ATM is not working at the moment\nWe working hard to bring it back to you!";
            for (int contor = 0; contor <= 1000000000; contor++) {
                if (GetAsyncKeyState('A')) {                  
                    break;
                }
                Sleep(500);
            }
            cout << "\nUnlocking ATM\n";
            Sleep(1000);
            developerMode();
        }
        else if (x == '3') {
            if (person.balanceEur || person.balanceRon || person.balanceUSD) {
                cout << "LAST LOG\n";
                cout << "Name: " << person.llname << endl;
                cout << "Card: " << "************";
                cout << person.card_number[12] << person.card_number[13] << person.card_number[14] << person.card_number[15] << endl;
                cout << "Ip: " << person.llip << endl;
                cout << "Transactions: " << person.lltransactions << endl << endl;
                cout << "Press any key to go back";
                char b = _getch();

                developerMode();
            }
            else {
                cout << "No logs to display";
                Sleep(1500);
                developerMode();
            }
        }
        else if (x == '4') {
            system("cls");
            cout << "Auto-repair.tool in progress...";
            Sleep(2500);
            srand(time(NULL));
            int x = rand() % 11;
            cout << x << " ERRORS WERE FOUND\n";
            Sleep(1500);
            if (x) {
                for (int i = 1; i <= x; i++) {
                    srand(time(NULL));
                    int x = rand() % 11;
                    if (x % 2 == 0)
                        cout << "ERROR " << i << "FIXED SUCCESSFULLY";
                    else
                        cout << "ERROR " << i << "FIXED FAILED";
                    Sleep(400);
                    cout << endl;
                }
                cout << "REDIRECTING YOU BACK...";
            }
            Sleep(3000);
            developerMode();
        }
        else if (x == '9') {
            homePage();
        }
}
#include <iostream>
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Password {
    string text;
    bool hasUpperLetter = false;
    bool hasNumber = false;
    bool hasSpecialCharacter = false;
    bool hasPersonalDetails = false;
    int securityLevel = 0;
};

struct User
{
    string firstName;
    string lastName;
    string birthDate;
    Password password;

    void determinePasswordLevel(){
        if(password.hasUpperLetter)
            password.securityLevel ++;
        if(password.hasNumber)
            password.securityLevel ++;
        if(password.hasSpecialCharacter)
            password.securityLevel ++;
        if(!password.hasPersonalDetails)
            password.securityLevel ++;
    }
};

User user;

bool containsPersonalDetails(string password) {
    for(int i=0;i<password.length();i++)
        password[i] = tolower(password[i]);
    for(int i=0;i<user.firstName.length();i++)
        user.firstName[i] = tolower(user.firstName[i]);
    for(int i=0;i<user.lastName.length();i++)
        user.lastName[i] = tolower(user.lastName[i]);

    string birthDay;
    birthDay.push_back(user.birthDate[0]);
    birthDay.push_back(user.birthDate[1]);

    string birthMonth;
    birthMonth.push_back(user.birthDate[2]);
    birthMonth.push_back(user.birthDate[3]);

    string birthYear;
    birthYear.push_back(user.birthDate[4]);
    birthYear.push_back(user.birthDate[5]);
    birthYear.push_back(user.birthDate[6]);
    birthYear.push_back(user.birthDate[7]);

    return strstr(password.c_str(),user.firstName.c_str()) ||
          strstr(password.c_str(),user.lastName.c_str()) ||
          strstr(password.c_str(),birthDay.c_str()) ||
          strstr(password.c_str(),birthMonth.c_str()) ||
          strstr(password.c_str(),birthYear.c_str());

    return 0;
}

string generatePassword(){
    srand(time(NULL));
    string generatedPassword;
    const char alphanum[] = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int string_length = sizeof(alphanum)-1;
    do{
        generatedPassword = "";
        for(int i = 0; i < user.password.text.length(); i++)
            generatedPassword.push_back(alphanum[rand() % string_length]);
    }while(containsPersonalDetails(generatedPassword));
    return generatedPassword;
}

int main()
{
    cout<<"Introduceti numele si prenumele (separate prin spatiu): ";
    cin>>user.firstName>>user.lastName;
    cout<<"Introduceti data de nastere (in formatul ZZLLAAAA): ";
    cin>>user.birthDate;
    cout << "Introduceti parola : ";
    bool passwordMeetRequirements = false;
    while(!passwordMeetRequirements){
        bool enterPressed = false;
        while(!enterPressed){
            char characterPressed = getch();
            switch(characterPressed){
            case (13)://ENTER
                enterPressed = true;
                break;
            case (8)://BACKSPACE
                cout<<"\b \b";
                user.password.text.pop_back();
                break;
            default:
                cout<<"*";
                user.password.text.push_back(characterPressed);
                break;
            }
        }
        if(user.password.text.length() >= 8){
            for (int i = 0; i < user.password.text.length(); i++) {
                char ch = user.password.text[i];
                if (ch >= '0' && ch <= '9')
                    user.password.hasNumber = true;
                if (ch >= 'A' && ch <= 'Z')
                    user.password.hasUpperLetter = true;
                if (!isalnum(ch))
                    user.password.hasSpecialCharacter = true;
            }
            user.password.hasPersonalDetails = containsPersonalDetails(user.password.text);
            user.determinePasswordLevel();
            passwordMeetRequirements = true;
        }
        else{
            cout<<" Parola este prea mica!";
            for(int i=1;i<=23;i++)
                cout<<"\b \b";
            for(int i=1;i<=user.password.text.length();i++)
                cout<<"\b \b";
            user.password.text.clear();
        }
    }
    cout<<endl<<endl;
    cout<<"Parola introdusa a fost : "<<user.password.text<<endl;
    cout<<"Parola contine numere : "; user.password.hasNumber ? cout<<"true\n" : cout<<"false\n";
    cout<<"Parola contine litere mari : "; user.password.hasUpperLetter ? cout<<"true\n" : cout<<"false\n";
    cout<<"Parola contine caractere speciale : "; user.password.hasSpecialCharacter ? cout<<"true\n" : cout<<"false\n";
    cout<<"Parola contine date personale : "; user.password.hasPersonalDetails ? cout<<"true\n" : cout<<"false\n";
    cout<<"Nivelul de securitate al parolei : "; cout<<user.password.securityLevel<<endl;
    cout<<"Parola sugerata : "<<generatePassword();
    return 0;
}

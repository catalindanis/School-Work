#include <iostream>
#include <fstream>
using namespace std;

struct Muchie{
    int v1,v2;
};

int matriceIncidenta[101][101];
int lungimeaMuchiei[101];
int nrMuchii;
int nrNoduri;
Muchie muchie;

void citireMuchii(bool orientat){
    cout<<"Numarul de noduri ale grafului = ";
    cin>>nrNoduri;
    cout<<"Numarul de muchii ale grafului = ";
    cin>>nrMuchii;
    cout<<"Introduceti muchiile :\n";
    if(!orientat){
        int c = nrMuchii;
        while(c){
            cout<<"Muchia #"<<nrMuchii-c+1<<" : ";
            cin>>muchie.v1>>muchie.v2;
            matriceIncidenta[muchie.v1][nrMuchii-c+1] =
            matriceIncidenta[muchie.v2][nrMuchii-c+1] = 1;
            c--;
        }
    }
    else{
        int c = nrMuchii;
        while(c){
            cout<<"Muchia #"<<nrMuchii-c+1<<" : ";
            cin>>muchie.v1>>muchie.v2;
            matriceIncidenta[muchie.v1][nrMuchii-c+1] = -1;
            matriceIncidenta[muchie.v2][nrMuchii-c+1] = 1;
            c--;
        }
    }
}

void afisareGradNodP(){
    int nod;
    cout<<"Nodul = ";
    cin>>nod;
    int grad = 0;
    for(int j=1;j<=nrMuchii;j++)
        if(matriceIncidenta[nod][j] != 0)
            grad++;
    cout<<"Grad("<<nod<<") este "<<grad;
}

void afisareMatriceIncidenta(){
    for(int i=1;i<=nrNoduri;i++,cout<<endl)
        for(int j=1;j<=nrMuchii;j++)
            cout<<matriceIncidenta[i][j]<<' ';
}

void salvareMatriceIncidenta(bool orientat){
    if(!orientat){
        ofstream fout0("Pr05_mi_v1a.txt");
        fout0<<nrNoduri<<' '<<nrMuchii<<'\n';
        for(int i=1;i<=nrNoduri;i++,fout0<<endl)
            for(int j=1;j<=nrMuchii;j++)
                fout0<<matriceIncidenta[i][j]<<' ';
        fout0.close();
    }
    else{
        ofstream fout1("Pr05_mi_v1b.txt");
        fout1<<nrNoduri<<' '<<nrMuchii<<'\n';
        for(int i=1;i<=nrNoduri;i++,fout1<<endl)
            for(int j=1;j<=nrMuchii;j++)
                fout1<<matriceIncidenta[i][j]<<' ';
        fout1.close();
    }
}

void citireMatriceFisier(bool orientat){
    ifstream fin0("Pr05_mi_v1a.txt");
    ifstream fin1("Pr05_mi_v1b.txt");

    if(!orientat){
        fin0>>nrNoduri>>nrMuchii;
        int val;
        for(int i=1;i<=nrNoduri;i++)
            for(int j=1;j<=nrMuchii;j++){
                fin0>>val;
                matriceIncidenta[i][j] = val;
        }
    }
    else{
        fin1>>nrNoduri>>nrMuchii;
        int val;
        for(int i=1;i<=nrNoduri;i++)
            for(int j=1;j<=nrMuchii;j++){
                fin1>>val;
                matriceIncidenta[i][j] = val;
        }
    }
}

void citireMuchiiFisier(bool orientat){
    ifstream fin0("Pr05_mi_v3a.txt");
    ifstream fin1("Pr05_mi_v3b.txt");

    if(!orientat){
        fin0>>nrNoduri>>nrMuchii;
        for(int i=1;i<=nrMuchii;i++){
            fin0>>muchie.v1>>muchie.v2>>lungimeaMuchiei[i];
            matriceIncidenta[muchie.v1][i] =
            matriceIncidenta[muchie.v2][i] = 1;
        }
        fin0.close();
    }
    else{
        fin1>>nrNoduri>>nrMuchii;
        for(int i=1;i<=nrMuchii;i++){
            fin1>>muchie.v1>>muchie.v2>>lungimeaMuchiei[i];
            matriceIncidenta[muchie.v1][i] = -1;
            matriceIncidenta[muchie.v2][i] = 1;
        }
        fin1.close();
    }
}

void afisareVeciniNodP(){
    int nod;
    cout<<"Nodul = ";
    cin>>nod;
    cout<<"Vecinii nodului "<<nod<<" : ";
    bool exista = false;
    for(int j=1;j<=nrMuchii;j++)
        if(matriceIncidenta[nod][j] != 0 && nod != j){
            cout<<j<<' ';
            exista = true;
        }
    if(!exista)
        cout<<"nu exista";
}

void afisareMuchiiLungime(){
    int media = 0;
    for(int i=1;i<=nrMuchii;i++)
        media += lungimeaMuchiei[i];
    media = media / nrMuchii;
    cout<<"Muchiile care au media mai mare decat "
    <<media<<" :\n";
    bool exista = false;
    for(int j=1;j<=nrMuchii;j++)
        if(lungimeaMuchiei[j] > media){
            exista = true;
            for(int i=1;i<=nrNoduri;i++)
                if(matriceIncidenta[i][j] != 0)
                    cout<<i<<' ';
            cout<<endl;
        }
    if(!exista)
        cout<<"nu exista";
}

void varianta1MI(){
    int tip = -1;
    while(tip != 0 && tip != 1){
        cout<<"Alege tipul grafului Neorientat(0) / Orientat(1): ";
        cin>>tip;
        system("cls");
    }

    citireMuchii(tip);

    afisareGradNodP();

    salvareMatriceIncidenta(tip);

    //afisareMatriceIncidenta();
}

void varianta2MI(){
    int tip = -1;
    while(tip != 0 && tip != 1){
        cout<<"Alege tipul grafului Neorientat(0) / Orientat(1): ";
        cin>>tip;
        system("cls");
    }

    citireMatriceFisier(tip);

    afisareVeciniNodP();

    //afisareMatriceIncidenta();
}

void varianta3MI(){
    int tip = -1;
    while(tip != 0 && tip != 1){
        cout<<"Alege tipul grafului Neorientat(0) / Orientat(1): ";
        cin>>tip;
        system("cls");
    }

    citireMuchiiFisier(tip);

    afisareMuchiiLungime();
}


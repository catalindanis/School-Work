#include <iostream>
#include <fstream>
using namespace std;

struct Muchie{
    int v1,v2;
    int lungime;
};

int matriceMuchii[101][3];
int nrMuchii;
int nrNoduri;
int aparitii[101];
Muchie muchie;
Muchie listaMuchii[101];

void citireMuchii(){
    cout<<"Numarul de noduri ale grafului = ";
    cin>>nrNoduri;
    cout<<"Numarul de muchii ale grafului = ";
    cin>>nrMuchii;
    cout<<"Introduceti muchiile :\n";
    int c = nrMuchii;
    while(c){
        cout<<"Muchia #"<<nrMuchii-c+1<<" : ";
        cin>>muchie.v1>>muchie.v2;
        matriceMuchii[nrMuchii-c+1][1] = muchie.v1;
        matriceMuchii[nrMuchii-c+1][2] = muchie.v2;
        c--;
    }
}

void citireMuchiiFisier(bool orientat){
    ifstream fin0("Pr05_mi_v3a.txt");
    ifstream fin1("Pr05_mi_v3b.txt");

    if(!orientat){
        fin0>>nrNoduri>>nrMuchii;
        for(int i=1;i<=nrMuchii;i++){
            fin0>>listaMuchii[i].v1
                >>listaMuchii[i].v2
                >>listaMuchii[i].lungime;
        }
    }
    else{
        fin1>>nrNoduri>>nrMuchii;
        for(int i=1;i<=nrMuchii;i++){
            fin1>>listaMuchii[i].v1
                >>listaMuchii[i].v2
                >>listaMuchii[i].lungime;
        }
    }
}

void afisareNoduriIzolate(){
    bool exista = false;
    cout<<"Noduri izolate : ";
    for(int i=1;i<=nrMuchii;i++){
        aparitii[matriceMuchii[i][1]]++;
        aparitii[matriceMuchii[i][2]]++;
    }
    for(int i=1;i<=nrNoduri;i++){
        if(aparitii[i] == 0){
            cout<<i<<' ';
            exista = true;
        }
    }
    if(!exista)
        cout<<"nu exista";
    cout<<endl;
}

void afisareNoduriTerminale(){
    bool exista = false;
    cout<<"Noduri terminale : ";
    for(int i=1;i<=nrNoduri;i++){
        if(aparitii[i] == 1){
            cout<<i<<' ';
            exista = true;
        }
    }
    if(!exista)
        cout<<"nu exista";
    cout<<endl;
}

void afisareMatriceMuchii(){
    for(int i=1;i<=nrMuchii;i++)
        cout<<matriceMuchii[i][1]<<' '<<matriceMuchii[i][2]<<endl;
}

void afisareListaMuchii(){
    for(int i=1;i<=nrMuchii;i++)
        cout<<listaMuchii[i].v1<<' '
            <<listaMuchii[i].v2<<' '
            <<listaMuchii[i].lungime<<endl;
}

void salvareMatriceMuchii(bool orientat){
    if(!orientat){
        ofstream fout0("Pr05_lm_v1a.txt");
        fout0<<nrNoduri<<' '<<nrMuchii<<endl;
        for(int i=1;i<=nrMuchii;i++)
            fout0<<matriceMuchii[i][1]<<' '<<
                matriceMuchii[i][2]<<endl;
        fout0.close();
    }
    else{
        ofstream fout1("Pr05_lm_v1b.txt");
        fout1<<nrNoduri<<' '<<nrMuchii;
        for(int i=1;i<=nrMuchii;i++)
            fout1<<matriceMuchii[i][1]<<' '<<
                matriceMuchii[i][2]<<endl;
        fout1.close();
    }
}

void afisareVecini(bool orientat){
    int nod;
    cout<<"Nodul = ";
    cin>>nod;
    cout<<"Cel/Cei mai apropiat/i vecin/i : ";
    bool exista = false;
    if(!orientat){
        int min = -1;
        for(int i=1;i<=nrMuchii;i++)
            if(listaMuchii[i].v1 == nod ||
                listaMuchii[i].v2 == nod){
                exista = true;
                if(min == -1)
                    min = listaMuchii[i].lungime;
                if(listaMuchii[i].lungime < min)
                    min = listaMuchii[i].lungime;
            }
        for(int i=1;i<=nrMuchii;i++){
            if(listaMuchii[i].v1 == nod)
                if(listaMuchii[i].lungime == min)
                    cout<<listaMuchii[i].v2<<' ';
            if(listaMuchii[i].v2 == nod)
                if(listaMuchii[i].lungime == min)
                    cout<<listaMuchii[i].v1<<' ';
        }
    }
    else{
        int min = -1;
        for(int i=1;i<=nrMuchii;i++)
            if(listaMuchii[i].v1 == nod){
                exista = true;
                if(min == -1)
                    min = listaMuchii[i].lungime;
                if(listaMuchii[i].lungime < min)
                    min = listaMuchii[i].lungime;
            }
        for(int i=1;i<=nrMuchii;i++){
            if(listaMuchii[i].v1 == nod)
                if(listaMuchii[i].lungime == min)
                    cout<<listaMuchii[i].v2<<' ';
        }
    }
    if(!exista)
        cout<<"nu exista";
}

void varianta1LM(){
    int tip = -1;
    while(tip != 0 && tip != 1){
        cout<<"Alege tipul grafului Neorientat(0) / Orientat(1): ";
        cin>>tip;
        system("cls");
    }

    citireMuchii();

    afisareNoduriIzolate();
    afisareNoduriTerminale();

    salvareMatriceMuchii(tip);
    //afisareMatriceMuchii();
}

void varianta2LM(){
    int tip = -1;
    while(tip != 0 && tip != 1){
        cout<<"Alege tipul grafului Neorientat(0) / Orientat(1): ";
        cin>>tip;
        system("cls");
    }

    citireMuchiiFisier(tip);

    afisareVecini(tip);

    //afisareListaMuchii();
}

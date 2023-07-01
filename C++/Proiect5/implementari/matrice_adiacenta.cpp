#include <iostream>
#include <fstream>
using namespace std;

struct Muchie{
    int v1,v2;
};

int matriceAdiacenta[101][101];
int nrMuchii;
int nrNoduri;
Muchie muchie;

void citireMuchii(bool orientat){
    cout<<"Numarul de noduri ale grafului = ";
    cin>>nrNoduri;
    cout<<"Numarul de muchii ale grafului = ";
    cin>>nrMuchii;
    cout<<"Introduceti muchiile :\n";
    int c = nrMuchii;
    while(c){
        cout<<"Muchia #"<<nrMuchii-c+1<<" : ";
        cin>>muchie.v1>>muchie.v2;
        matriceAdiacenta[muchie.v1][muchie.v2] = 1;
        if(!orientat){
            matriceAdiacenta[muchie.v2][muchie.v1] = 1;
        }
        c--;
    }
}

void citireMuchiiFisier(bool orientat){
    ifstream fin0("Pr05_ma_v3a.txt");
    ifstream fin1("Pr05_ma_v3b.txt");

    if(!orientat){
        fin0>>nrNoduri>>nrMuchii;
        int c = nrMuchii;
        while(c){
            c--;
            fin0>>muchie.v1>>muchie.v2;
            matriceAdiacenta[muchie.v1][muchie.v2] =
            matriceAdiacenta[muchie.v2][muchie.v1] = 1;
        }
    }
    else{
        fin1>>nrNoduri>>nrMuchii;
        int c = nrMuchii;
        while(c){
            c--;
            fin1>>muchie.v1>>muchie.v2;
            matriceAdiacenta[muchie.v1][muchie.v2] = 1;
        }
    }
}

void afisareNoduriIzolate(){
    int nrVecini;
    bool exista = false;
    cout<<"Noduri izolate : ";
    for(int i=1;i<=nrNoduri;i++){
        nrVecini = 0;
        for(int j=1;j<=nrNoduri;j++){
            nrVecini  += matriceAdiacenta[i][j] + matriceAdiacenta[j][i];
        }
        if(nrVecini == 0){
            exista = true;
            cout<<i<<" ";
        }
    }
    if(!exista)
        cout<<"nu exista";
    cout<<endl;
}

void afisareNoduriTerminale(bool orientat){
    int nrVecini;
    bool exista = false;
    cout<<"Noduri terminale : ";
    for(int i=1;i<=nrNoduri;i++){
        nrVecini = 0;
        for(int j=1;j<=nrNoduri;j++){
            if(orientat){
                nrVecini  += matriceAdiacenta[i][j] + matriceAdiacenta[j][i];
            }
            else{
                nrVecini  += matriceAdiacenta[i][j];
            }
        }
        if(nrVecini == 1){
            exista = true;
            cout<<i<<" ";
        }
    }
    if(!exista)
        cout<<"nu exista";
    cout<<endl;
}

void afisareMatriceAdiacenta(){
    for(int i=1;i<=nrNoduri;i++,cout<<endl)
        for(int j=1;j<=nrNoduri;j++)
            cout<<matriceAdiacenta[i][j]<<' ';
}

void salvareMatriceAdiacenta(bool orientat){
    if(!orientat){
        ofstream fout0("Pr05_ma_v1a.txt");
        fout0<<nrNoduri<<"\n";
        for(int i=1;i<=nrNoduri;i++,fout0<<endl)
            for(int j=1;j<=nrNoduri;j++)
                fout0<<matriceAdiacenta[i][j]<<' ';
        fout0.close();
    }
    else{
        ofstream fout1("Pr05_ma_v1b.txt");
        fout1<<nrNoduri<<"\n";
            for(int i=1;i<=nrNoduri;i++,fout1<<endl)
                for(int j=1;j<=nrNoduri;j++)
                    fout1<<matriceAdiacenta[i][j]<<' ';
        fout1.close();
    }
}

void citireMatrici(bool orientat){
    ifstream fin0("Pr05_ma_v1a.txt");
    ifstream fin1("Pr05_ma_v1b.txt");

    if(!orientat){
        fin0>>nrNoduri;
        for(int i=1;i<=nrNoduri;i++)
            for(int j=1;j<=nrNoduri;j++)
                fin0>>matriceAdiacenta[i][j];
    }
    else{
        fin1>>nrNoduri;
        for(int i=1;i<=nrNoduri;i++)
            for(int j=1;j<=nrNoduri;j++)
                fin1>>matriceAdiacenta[i][j];
    }

    fin0.close();
    fin1.close();
}

void afisareNoduriVeciniMax(bool orientat){
    cout<<"Noduri cu nr maxim de vecini : ";
    int nrMaxVecini = 0;
        int noduri[100];
        int l = 0;
    if(!orientat){
        for(int i=1;i<=nrNoduri;i++){
            int vC = 0;
            for(int j=1;j<=nrNoduri;j++)
                vC += matriceAdiacenta[i][j];
            if(vC > nrMaxVecini){
                nrMaxVecini = vC;
                l = 0;
                noduri[0] = i;
            }
            else if(vC == nrMaxVecini){
                noduri[++l] = i;
            }
        }
        for(int i=0;i<=l;i++)
            cout<<noduri[i]<<' ';
    }
    else{
        for(int i=1;i<=nrNoduri;i++){
            int vC = 0;
            for(int j=1;j<=nrNoduri;j++){
                if(matriceAdiacenta[i][j] == 0)
                    vC += matriceAdiacenta[j][i];
                else
                    vC += matriceAdiacenta[i][j];
            }
            if(vC > nrMaxVecini){
                nrMaxVecini = vC;
                l = 0;
                noduri[0] = i;
            }
            else if(vC == nrMaxVecini){
                noduri[++l] = i;
            }
        }
        for(int i=0;i<=l;i++)
            cout<<noduri[i]<<' ';
    }
    cout<<endl;
}

void afisareVecini(){
    cout<<"Vecinii fiecarui nod : \n";
    for(int i=1;i<=nrNoduri;i++,cout<<endl){
        cout<<"Nodul "<<i<<" : ";
        for(int j=1;j<=nrNoduri;j++)
            if(matriceAdiacenta[i][j] != 0 ||
               matriceAdiacenta[j][i] != 0)
                cout<<j<<' ';
    }
}

void afisareMuchii(){
    for(int i=1;i<=nrNoduri;i++)
        for(int j=1;j<=nrNoduri;j++)
            if(matriceAdiacenta[i][j] == 1)
                cout<<i<<' '<<j<<'\n';
}

void varianta1MA(){
    int tip = -1;
    while(tip != 0 && tip != 1){
        cout<<"Alege tipul grafului Neorientat(0) / Orientat(1): ";
        cin>>tip;
        system("cls");
    }

    citireMuchii(tip);

    //afisareMatriceAdiacenta();

    afisareNoduriIzolate();
    afisareNoduriTerminale(tip);

    salvareMatriceAdiacenta(tip);
}

void varianta2MA(){
    int tip = -1;
    while(tip != 0 && tip != 1){
        cout<<"Alege tipul grafului Neorientat(0) / Orientat(1): ";
        cin>>tip;
        system("cls");
    }

    citireMatrici(tip);

    //afisareMatriceAdiacenta();

    afisareNoduriVeciniMax(tip);
    afisareMuchii();
}

void varianta3MA(){
    int tip = -1;
    while(tip != 0 && tip != 1){
        cout<<"Alege tipul grafului Neorientat(0) / Orientat(1): ";
        cin>>tip;
        system("cls");
    }

    citireMuchiiFisier(tip);

    //afisareMatriceAdiacenta();

    afisareVecini();
}

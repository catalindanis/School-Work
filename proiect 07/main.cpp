#include <iostream>

using namespace std;

void sortDesc(int n, int *g){
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(g[i] < g[j])
                swap(g[i],g[j]);
}

void afisare(int n, int *g){
    for(int i=0;i<n;i++,cout<<' ')
        cout<<g[i];
    cout<<endl;
}

void readError(){
    cin.clear();
    cin.ignore(200,'\n');
    cout<<"Valoarea introdusa nu este corecta!\n";
}

int suma(int n, int *g){
    int suma = 0;
    for(int i=0;i<n;i++)
        suma += g[i];
    return suma;
}

int nrNoduriGradeImpare(int n, int *g){
    int nr = 0;
    for(int i=0;i<n;i++)
        nr += g[i]%2;
    return nr;
}

bool existaGradeEgale(int n,int *g){
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(g[i] == g[j])
                return 1;
    return 0;
}

bool havelHakimi(int n, int *g){
    int cn = n;
    while(n > 0){
        sortDesc(n,g);
        cout<<"#"<<cn-n+1<<" iteratie : ";
        int nrM = g[0];
        n--;
        for(int i=0;i<n;i++)
            g[i] = g[i+1];
        for(int i=0;i<nrM;i++){
            g[i]--;
            if(g[i] == -1){
                cout<<"Exista un nod care are gradul -1\n";
                return false;
            }
        }
        afisare(n,g);
    }
    return true;
}

void algoritm(int n, int *g){
    sortDesc(n,g);
    bool conditiiIndeplinite[5];
    cout<<"Sirul dupa sortare : "; afisare(n,g);
    cout<<"G(1) <= N-1 : "; conditiiIndeplinite[0] = g[0] < n;
    conditiiIndeplinite[0] ? cout<<"true\n" : cout<<"false\n";
    cout<<"Suma gradelor este : "; conditiiIndeplinite[1] = suma(n,g)%2 == 0;
    conditiiIndeplinite[1] ? cout<<"para\n" : cout<<"impara\n";
    cout<<"Nr noduri cu grade impare este : "; conditiiIndeplinite[2] = nrNoduriGradeImpare(n,g)%2 == 0;
    conditiiIndeplinite[2] ? cout<<"par\n" : cout<<"impar\n";
    cout<<"Cel putin 2 noduri au acelasi grad : "; conditiiIndeplinite[3] = existaGradeEgale(n,g);
    conditiiIndeplinite[3] ? cout<<"true\n" : cout<<"false\n";
    cout<<"Aplicare algoritm Havel Hakimi :\n";
    conditiiIndeplinite[4] = havelHakimi(n,g);
    conditiiIndeplinite[4] ?
    cout<<"Indeplineste algoritmul Havel Hakimi\n" :
    cout<<"Nu indeplineste algoritmul Havel Hakimi\n";
    for(int i=0;i<5;i++)
        if(!conditiiIndeplinite[i]){
            cout<<"Sirul nu este un sir grafic!\n";
            return;
        }
    cout<<"Sirul este un sir grafic!\n";
}

int main()
{
    int n,g[10000];
    cout<<"Introdu dimensiunea sirului: ";
    cin>>n;
    if(n < 0 || cin.fail())
        readError();
    cout<<"Introduceti fiecare valoare: \n";
    for(int i=0;i<n;i++){
        cout<<"G("<<i+1<<"): ";
        cin>>g[i];
        if(g[i] < 0 || cin.fail()){
            readError();
            i--;
        }
    }
    algoritm(n,g);
    return 0;
}

#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
using namespace std;

char s[100001];
int l;
int contor = 0;
char sir[1001];
char copie[1001];

void tip1(int inc,int sf){
    //cout<<s[inc]<<' '<<s[sf]<<endl;
    int nr=0;
    strcpy(sir,"\0");
    int ind = 0;
    bool inainte = true;
    for(int i=inc;i<sf;i++){
        if(s[i] == '(')
            inainte = false;
        if(inainte)
            nr = nr*10 + (s[i]-'0');
        else if(!inainte && s[i]!='(' && s[i]!=')')
            sir[ind] = s[i],ind++;
        //cout<<"adaug: "<<s[i]<<endl;
    }
    strcpy(copie,sir);
    sir[ind] = '\0';
    for(int i=1;i<nr;i++)
        strcat(sir,copie);
    strcpy(copie,s+sf);
    strcpy(s+inc,sir);
    strcat(s,copie);
    //cout<<nr<<' '<<sir;
    //cout<<s<<endl;
    contor++;
}

int main()
{
    cin>>s;
    l = strlen(s);
    for(int i=0;i<l;){
        if(s[i]>='0' && s[i]<='9'){
            ///tip 1
            //cout<<"am gasit: "<<s[i]<<endl;
            int inc,sf;
            int paranteze_deschise = 0;
            int paranteze_inchise = 0;
            int poz_paranteza_deschisa;
            inc = sf = i;
            while(s[sf]!='\0' && !paranteze_inchise){
                if(s[sf] == '('){
                    paranteze_deschise ++;
                    if(paranteze_deschise > 1){
                        inc = poz_paranteza_deschisa+1;
                        //cout<<"paranteza deschisa 2"<<endl;
                    }
                    poz_paranteza_deschisa = sf;
                }
                if(s[sf] == ')')
                    paranteze_inchise++,i=0;
                sf++;
            }
            if(paranteze_deschise && paranteze_inchise){
                tip1(inc,sf);
            }
            i=0;
        }
        else i++;
    }
    //tip1(0,strlen(s));
    cout<<contor<<endl;
    cout<<s;
    return 0;
}

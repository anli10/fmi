#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("fisier.txt");
int numarSubsiruri;
int cautareBinara(int minim[],int stanga,int dreapta,int elem){
    int gasit=0;
    int m;
    while((stanga<dreapta) && (gasit ==0)){
        m=(stanga+dreapta)/2;
        if(minim[m]==elem){
            gasit=1;
        }
        else{
            if(minim[m]<elem) stanga=m+1;
            else dreapta=m;
        }
    }
    if(gasit){
        while((elem==minim[m]) && (m<numarSubsiruri)){
            m=m+1;
        }
        if(m<=numarSubsiruri) return m;
        else return 0;
    }
    else{
        if(stanga<=numarSubsiruri && minim[stanga]>elem) return stanga;
        else return 0;
    }
}
int main()
{
    int n;
    vector <int>sir;
    int apartenenta[1000];
    int minim[1000];
    f>>n;
    for(int i=0;i<n;i++){
        int x;
        f>>x;
        sir.push_back(x);
        }
    numarSubsiruri=1;
    apartenenta[numarSubsiruri-1]=1; //primul element din sir este in subsirul 1
    minim[numarSubsiruri]=sir[0];
    for(int i=1;i<n;i++){
        int k=cautareBinara(minim,1,numarSubsiruri,sir[i]);
        if(k==0){
            numarSubsiruri++;
            apartenenta[i]=numarSubsiruri;
            minim[numarSubsiruri]=sir[i];
        }
        else{
            apartenenta[i]=k;
            minim[k]=sir[i];
        }
    }
    for(int j=1;j<=numarSubsiruri;j++){
        for(int i=0;i<=n;i++){
            if(apartenenta[i]==j)
                cout<<sir[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

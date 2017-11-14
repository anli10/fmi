#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
ifstream f("fisier.in");
int numarSubsiruri;
int cautareBinara(vector <stack<int> > stive,int elem){
    int gasit=0;
    int m;
    int stanga=0;
    int dreapta=stive.size()-1;
    while((stanga<dreapta) && (gasit ==0)){
        m=(stanga+dreapta)/2;
        if(stive[m].top()==elem){
            gasit=1;
        }
        else{
            if(stive[m].top()<elem) stanga=m+1;
            else dreapta=m;
        }
    }
    if(gasit){
        while((elem==stive[m].top()) && (m<stive.size()-1)){
            m=m+1;
        }
        if(m<=numarSubsiruri) return m;
        else return -1;
    }
    else{
        if((stanga<=(stive.size()-1)) && (stive[stanga].top()>elem) ){return stanga;}
        else return -1;
    }
}
int main()
{
    int n;
    vector <int>sir;
    vector < stack<int> > stive;
    vector <int> solutie;
    //int apartenenta[1000];
    int minim[1000];
    f>>n;
    for(int i=0;i<n;i++){
        int x;
        f>>x;
        sir.push_back(x);
        }
    numarSubsiruri=1;
    stack<int> aux;
    aux.push(sir[0]);
    stive.push_back(aux);
    aux.pop();
    //apartenenta[numarSubsiruri-1]=1; //primul element din sir este in subsirul 1
    minim[numarSubsiruri]=sir[0];
    for(int i=1;i<n;i++){
        int k=cautareBinara(stive,sir[i]);
        if(k==-1){
            numarSubsiruri++;
            aux.push(sir[i]);
            stive.push_back(aux);
            //stive[stive.size()-1].push(sir[i]);
            //apartenenta[i]=numarSubsiruri;
            //minim[numarSubsiruri]=sir[i];
            aux.pop();
        }
        else{
            stive[k].push(sir[i]);
            //apartenenta[i]=k;
           // minim[k]=sir[i];
        }
    }
//    for(int j=1;j<=numarSubsiruri;j++){
//        for(int i=0;i<=n;i++){
//            if(apartenenta[i]==j)
//                cout<<sir[i]<<" ";
//        }
//        cout<<endl;
//    }
//    for(int i=0;i<numarSubsiruri;i++){
//        while(!stive[i].empty()){
//            cout<<stive[i].top()<<" ";
//            stive[i].pop();
//        }
//        cout<<endl;
//    }
    int nrStive=stive.size();
    while(solutie.size()!=n){
        int minimul=stive[0].top();
        int poz=0;
        for(int i=1;i<stive.size();i++){
            if(stive[i].top()<minimul){
                minimul=stive[i].top();
                poz=i;}
        }
        solutie.push_back(minimul);
        stive[poz].pop();
        if(stive[poz].empty()) stive[poz].push(12345);
    }
    for(int i=0;i<solutie.size();i++){
        cout<<solutie[i]<<" ";
    }
    return 0;
}

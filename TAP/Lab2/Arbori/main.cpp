#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include<algorithm>
using namespace std;
ifstream f("fisier.in");
struct Nod{
  int info;
  Nod * st,* dr;
  Nod(int x):info(x),st(NULL),dr(NULL){}
};
//Nod* newNod(int info)
//{
//    Nod* nod = (Nod*)malloc(sizeof(Nod));
//    nod->info = info;
//    nod->st = nod->dr = NULL;
//    return (nod);
//}

vector<int> inord;
vector<int> postord;
int N;
Nod *construire(vector<int> inord,vector<int>postord){
    int n=inord.size();
    if(n==0){
        return 0;
    }
    int val=postord[n-1];       //radacina

    Nod *arbore=new Nod(val);    //radacina in arborele nou


    //cautam in inordine unde e radacina

    int j;
    for(int i=0;i<n;i++)
        if(inord[i]==val) j=i;

    vector<int> stangaInord;
    //stangaInord.reserve(50);
    for(int i=0;i<j;i++) stangaInord.push_back(inord[i]);

    vector<int> stangaPostord;
    //stangaPostord.reserve(50);
    for(int i=0;i<j;i++) stangaPostord.push_back(postord[i]);

    vector<int> dreaptaInord;
   // dreaptaInord.reserve(50);
    for(int i=j+1;i<n;i++) dreaptaInord.push_back(inord[i]);

    vector<int> dreaptaPostord;
   // dreaptaPostord.reserve(50);
    for(int i=j;i<n-1;i++) dreaptaPostord.push_back(postord[i]);

    arbore->st=construire(stangaInord,stangaPostord);
    arbore->dr=construire(dreaptaInord,dreaptaPostord);
    return arbore;
}
void preordine(Nod *pre){
    if(pre==NULL) return;
    cout<<pre->info<<" ";
    preordine(pre->st);
    preordine(pre->dr);
}
int main()
{
    f>>N;
    int x;
    for(int i=0;i<N;i++){       //citire postordine
        f>>x;
        postord.push_back(x);
    }
    for(int i=0;i<N;i++){       //citire inordiness
        f>>x;
        inord.push_back(x);
    }

    for(int i=0;i<N;i++){
        cout<<postord[i]<<" ";
    }
    cout<<endl;
     for(int i=0;i<N;i++){
        cout<<inord[i]<<" ";
    }
    cout<<"Preordine:"<<endl;
    Nod *arbore=construire(inord,postord);

    preordine(arbore);

    return 0;
}

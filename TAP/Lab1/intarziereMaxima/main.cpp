#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream f("fisier.in");
bool myfunction (pair<int,int> i, pair<int,int> j) { return (i.second<j.second); }
int main(){
    vector<pair<int, int> > activitate; //dutata si termen limita
    vector<pair<int,int> > interval;    //cand incepe si cand se termina
    int n,l,t;
    int start=0;    //punctul din care incepe prima cativitate
    int finish=0;   //punctul in care se termina ultima activitate adaugata
    f>>n;
    for(int i=0;i<n;i++){
        f>>l>>t;
        activitate.push_back(make_pair(l,t));
    }

    sort(activitate.begin(),activitate.end(),myfunction);


    for(int i=0;i<n;i++){
       interval.push_back(make_pair(finish,finish+activitate[i].first));
       finish=finish+activitate[i].first;
    }
    int Max=0;
    for(int i=0;i<n;i++){
        cout<<activitate[i].first<<" "<<activitate[i].second<<" incepe la "<<interval[i].first;
        cout<<" si se termina la "<<interval[i].second;
        cout<<" intarziere: "<<max(0,interval[i].first+activitate[i].first-activitate[i].second)<<endl;
        if (max(0,interval[i].first+activitate[i].first-activitate[i].second)>Max) Max=max(0,interval[i].first+activitate[i].first-activitate[i].second);

    }
    cout<<"intarziere maxima: "<<Max;
    return 0;
}

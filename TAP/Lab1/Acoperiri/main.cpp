#include <iostream>
#include <utility>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("fisier.in");
bool myfunction (pair<int,int> i, pair<int,int> j) { return (i.first<j.first); }
int main()
{
    vector< pair <int,int> > interval;
    vector< pair <int,int> > solutie;
    int a,b,n,x,y;
    //cout<<"a:";cin>>a;
    //cout<<"b:";cin>>b;
    //cout<<"n:";cin>>n;
    f>>a>>b>>n;
    for(int i=0;i<n;i++){
        f>>x>>y;
        interval.push_back(make_pair(x,y));
    }

    sort(interval.begin(),interval.end(),myfunction);
//    for(int i=0;i<interval.size();i++)
//        cout<<interval[i].first<<" "<<interval[i].second<<endl;
    int var=a;
    for(int i=0;i<n;i++){
        if(interval[i].first<=var && interval[i].second>=var){
            solutie.push_back(interval[i]);
            var=interval[i].second;
            //cout<<var;
            break;
        }
    }
    int i=1;


    for(int i=1;(i<n)&& solutie[solutie.size()-1].second<b;i++){

        if(interval[i].first<=var && interval[i].second>solutie[solutie.size()-1].second){//  && interval[i+1].second<interval[i].second){
            while(interval[i+1].second<interval[i].second) i++;
                solutie.push_back(interval[i]);
                var=interval[i].second;
        }


    }


    if((solutie.size()==1 && solutie[solutie.size()-1].second<b)||((solutie.size()==0))) cout<<"-1";
    else {
        for(int i=0;i<solutie.size();i++){
        if(solutie[i].first !=0)
        cout<<solutie[i].first<<" "<<solutie[i].second<<endl;
        }
    }
    return 0;
}

#include <iostream>
#include<math.h>
#include <stdlib.h>
using namespace std;
struct punct {
        float x, y;
}A1, A2, A3, A4;
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return (abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0));
}
int main()
{
    cout << "Introduceti coordonatele punctului A1: ";
    cin >> A1.x >> A1.y; cout<< endl;
    cout << "Introduceti coordonatele punctului A2: ";
    cin >> A2.x >> A2.y; cout << endl;
    cout << "Introduceti coordonatele punctului A3: ";
    cin >> A3.x >> A3.y; cout << endl;
    cout << "Introduceti coordonatele punctului A4: ";
    cin >> A4.x >> A4.y; cout << endl;
    int a = (A2.y - A1.y) *A3.x + (A1.x - A2.x) * A3.y + (A2.x * A1.y - A1.x * A2.y);
    int b = (A2.y - A1.y) *A4.x + (A1.x - A2.x) * A4.y + (A2.x * A1.y - A1.x * A2.y);
    if(a==0 && b==0){
         int dist[7];
         dist[1]=sqrt( (A2.x-A1.x)*(A2.x-A1.x)+(A2.y-A1.y)*(A2.y-A1.y));
         dist[2]=sqrt( (A3.x-A1.x)*(A3.x-A1.x)+(A3.y-A1.y)*(A3.y-A1.y));
         dist[3]=sqrt( (A4.x-A1.x)*(A4.x-A1.x)+(A4.y-A1.y)*(A4.y-A1.y));
         dist[4]=sqrt( (A3.x-A2.x)*(A3.x-A2.x)+(A3.y-A2.y)*(A3.y-A2.y));
         dist[5]=sqrt( (A4.x-A2.x)*(A4.x-A2.x)+(A4.y-A2.y)*(A4.y-A2.y));
         dist[6]=sqrt( (A4.x-A3.x)*(A4.x-A3.x)+(A4.y-A3.y)*(A4.y-A3.y));
        int mmax=0;int imax=0;int i;
        for(i=1;i<=6;i++)
            if(dist[i]>mmax) {mmax=dist[i];imax=i;}
        if(imax==1) cout<<"multimea I:{A1,A2} J:{A3,A4}";
        if(imax==2) cout<<"multimea I:{A1,A3} J:{A2,A4}";
        if(imax==3) cout<<"multimea I:{A1,A4} J:{A2,A3}";
        if(imax==4) cout<<"multimea I:{A2,A3} J:{A1,A4}";
        if(imax==5) cout<<"multimea I:{A2,A4} J:{A1,A3}";
        if(imax==6) cout<<"multimea I:{A3,A4} J:{A1,A2}";
        return 0;
    }
    float arie1=area(A1.x,A1.y,A2.x,A2.y,A3.x,A3.y);
    float arie2=area(A1.x,A1.y,A2.x,A2.y,A4.x,A4.y);
    float arie3=area(A4.x,A4.y,A2.x,A2.y,A3.x,A3.y);
    if(arie1!=0){
        float A=area(A4.x,A4.y,A2.x,A2.y,A3.x,A3.y);
        float B=area(A1.x,A1.y,A2.x,A2.y,A4.x,A4.y);
        float C=area(A1.x,A1.y,A3.x,A3.y,A4.x,A4.y);
        if(arie1==A+B+C) {cout<<"multimea I:{A1,A2,A3} J:{A4}";return 0;}
    }
    else if(arie2!=0){
        float A=area(A4.x,A4.y,A2.x,A2.y,A3.x,A3.y);
        float B=area(A1.x,A1.y,A2.x,A2.y,A3.x,A3.y);
        float C=area(A1.x,A1.y,A3.x,A3.y,A4.x,A4.y);
        if(arie2==A+B+C) {cout<<"multimea I:{A1,A2,A4} J:{A3}";return 0;}
    }
    else if(arie3!=0){
        float A=area(A4.x,A4.y,A2.x,A2.y,A1.x,A1.y);
        float B=area(A1.x,A1.y,A2.x,A2.y,A3.x,A3.y);
        float C=area(A1.x,A1.y,A3.x,A3.y,A4.x,A4.y);
        if(arie2==A+B+C) {cout<<"multimea I:{A2,A3,A4} J:{A1}";return 0;}
    }
    if( (((A1.y-A2.y)*(A3.x-A1.x)+(A2.x-A1.x)*(A3.y-A1.y) )*((A1.y-A2.y)*(A4.x-A1.x)+(A2.x-A1.x)*(A4.y-A1.y)) )<0)
        cout<<"multimea I:{A1,A2} J:{A3,A4}";
    if( (((A1.y-A3.y)*(A2.x-A1.x)+(A3.x-A1.x)*(A2.y-A1.y) )*((A1.y-A3.y)*(A4.x-A1.x)+(A3.x-A1.x)*(A4.y-A1.y)) )<0)
        cout<<"multimea I:{A1,A3} J:{A2,A4}";
    if( (((A1.y-A4.y)*(A3.x-A1.x)+(A4.x-A1.x)*(A3.y-A1.y) )*((A1.y-A4.y)*(A2.x-A1.x)+(A4.x-A1.x)*(A2.y-A1.y)) )<0)
        cout<<"multimea I:{A1,A4} J:{A2,A3}";
    return 0;
}

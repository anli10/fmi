//
//  main.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
string w;

int n,nf,s,t[10000][10000],drum[10000][10000],nod_bun[10000],vizitat[10000],parcurgere[10000];
vector <int> noduri[10000],vecini[10000];

int DFS(int st) {
	
	int i;
	if (vecini[st].size() == 0)
	{
		vizitat[st] = 0;
		return 0;
	}
	if (nod_bun[st] == 0) {
		vizitat[st] = 0;
		return 0;
	}
	for (i = 0; i<vecini[st].size(); ++i){
		
		if (vizitat[vecini[st][i]])
			return 1;
		vizitat[vecini[st][i]] = 1;
		if (DFS( vecini[st][i] )== 1)
			return 1;
	}
	vizitat[st] = 0;
	return 0;
	
}

int main(int argc, const char ** argv) {
	
	ifstream file;
	file.open(argv[1], std::ifstream::in);
	//citire cuvant din fisier
	file>>w;

	//citire nr stari, nr stari finale, nr simboluri
	file>>n>>nf>>s;
	
	//initializare matrice tranzitii
	int i,j;
	for(i=0;i<=10000;i++)
		for(j=0;j<=10000;j++)
			t[i][j]=-1;
	for(i=0;i<=10000;i++)
		for(j=0;j<=10000;j++)
			drum[i][j]=0;
	for(i=0;i<=10000;i++)
		nod_bun[i]=0;
	//PUNCTUL B
	if (w[0]=='_'){
		
		//verificare limbaj infinit

		while (file.eof() == 0) {
			int st1,st2;
			char y;
			file>>st1>>y>>st2;//citim date de intrare, tranzitia
			//daca descoperim cel putin o muchie intre doua noduri o marcam, putem ajunge intr-un nod din mai multe alte noduri (numarul lor este memorat pe coloana 0 a matricii) memorate in matrice liniar.
			if(drum[st1][st2]!=1){
				drum[st1][st2]=1;
				vecini[st1].push_back(st2);//vector in care retinem vecinii in care se ajunge intr-un nod
				noduri[st2].push_back(st1);//vector in care retinem vecinii din care se ajunge intr-un nod
			}
		}
		int k=0;
		//parcurgem automatul pornind de la starile finale
		
		//marcam nodurile finale
		for(i=(n-nf);i<n;++i){
			parcurgere[k]=i;
			k++;
			nod_bun[i]=1;//nodurile din care putem ajunge in stari finale
		}
		//cat timp mai avem noduri din care sa plecam
		while(k!=0){
			
			int inceput;j=0;
			inceput=parcurgere[j];
			for(i=j;i<k-1;i++)
				parcurgere[i]=parcurgere[i+1];
			k--;
			
			if(noduri[inceput].size()!=0)
				for(i = 0 ; i < noduri[inceput].size(); ++i)
					//daca inca nu am marcat nodul ca fiind un nod din care se poate ajunge in stare finala
					if(nod_bun[noduri[inceput][i]]==0){
						nod_bun[noduri[inceput][i]]=1;
						parcurgere[k]=noduri[inceput][i];
						k++;
					}
		}
		//initianlizare vector pentru dfs
		for (i=1; i<=10000; i++)
			vizitat[i]=0;
		vizitat[0]=1;
		cout<<(1-DFS(0));
		}
		
	//PUNCTUL A
	else{
		for(i=0;i<=10000;i++)
			for(j=0;j<=10000;j++)
				t[i][j]=-1;
		while (file.eof() == 0) {
			
			int st1,st2,c;
			char y;
			file>>st1>>y>>st2;
			c=(int)y-65;
			t[st1][c]=st2;
			
		}
		int stare = 0;
		int i,ok=1;
		char simbol;
		for (i=0; i < w.size(); ++i) {

			simbol = (int)w[i]-65;
			if (t[stare][simbol]!=-1)
				stare=t[stare][simbol];
		    else ok=0;
			
		}
		if (stare < (n - nf) || ok==0 )
			cout<< 0;
		else if (ok==1)
			cout<<1;
	}
    return 0;
}

//By N Purushotam Kumar; 3330; TE-COMP A T2
//Assignment 3 N Queens Problem using Branch and Bound.
#include <bits/stdc++.h>
using namespace std;
int n;
vector <vector <int>> g;
vector <int> col, rdia, dia;
bool issafe(int x,int y){
	return (col[y] == 0 and dia[x-y+n] == 0 and rdia[x+y] == 0);
}

bool nqueen(int x){
	if(x == n)
		return true;
	for(int i = 0; i < n; i++){
		if(issafe(x, i)){
			col[i] = 1;
			dia[x-i+n] = 1;
			rdia[x+i] = 1;
			g[x][i] = 1;
			if(nqueen(x+1)){
				return true;
			}
			col[i] = 0;
			dia[x-i+n] = 0;
			rdia[x+i] = 0;
			g[x][i] = 0;
		}
	}
	return false;
}

int main(){
	cin>>n;
	g = vector <vector <int>> (n, vector <int> (n, 0));
	col = vector <int> (n, 0);
	dia = vector <int> (2*n-1, 0);
	rdia = vector <int> (2*n-1, 0);
	if(nqueen(0)){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout<<g[i][j]<<" "; 
			cout<<"\n";
		}
	}else
		cout<<"Not Possible!";
    return 0;
}
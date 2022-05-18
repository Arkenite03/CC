//Assignment 2 : Dijkstra's algorithm 
//By N Purushotam Kumar; 3330; TE-COMP A T2
#include <bits/stdc++.h>
using namespace std;
//...
const int N = 100, inf = 1e9;
int len[N][N], visited[N], n, m, dis[N], s, par[N];
vector <int> path[N];

void initialise(){
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++)	
			len[i][j] = inf;
		dis[i] = inf;
	}
}

void Input(){
	cout<<"Enter number of vertices :";
	cin>>n;
	initialise();
	//If there is no edge between some vertices enter -1 for them
	cout<<"Enter n*n matrix for the given graph : \n\n";
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int weight; cin>>weight;
			if(weight != -1)
				len[i][j] = weight;
		}
	}
}

void Dijkstra(){
	cout<<"Enter the source vertex : ";
	cin>>s;
	dis[s] = 0, par[s] = s;
	cout<<"\n";
	for(int i = 0; i < n-1; i++){
		int mn = inf, u = -1; 
		for(int j = 1; j <= n; j++){
			if(!visited[j] and mn > dis[j])
				mn = dis[j], u = j;
		}
		visited[u] = 1;
		for(int j = 1; j <= n; j++){
			if(!visited[j]){
				if(dis[j] > dis[u] + len[u][j])
						dis[j] = dis[u] + len[u][j], par[j] = u;
			}
		}
		/*cout<<"Iteration "<<i+1<<" : ";
		for(int j = 1; j <= n; j++)
			cout<<dis[j]<<" "; cout<<"\n";*/
	}
	cout<<"\nDistance of all vertices from source : \n";
	cout<<"Vertex - Distance\n";
	for(int i = 1; i <= n; i++)
		cout<<i<<"        "<<dis[i]<<"\n";
}

void GetPath(){
	cout<<"\nPath of vertices from source "<<s<<" : \n";
	for(int i = 1; i <= n; i++){
		cout<<"Source to vertex "<<i<<" : ";
		int j = i;
		vector <int> t;
		while(par[j] != j){
			t.push_back(j);
			j = par[j];
		}
		t.push_back(s);
		reverse(t.begin(), t.end());
		for(auto i : t)
			cout<<i<<" "; cout<<"\n";
	}
}

int main(){
	Input();
	Dijkstra();
	GetPath();
    return 0;
}


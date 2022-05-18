#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 7;
std::vector <int> G[MAX];

void dfs(int node, vector <bool> &vis, vector <int> &parent){
	vis[node] = true;
	for(auto u : G[node]){
		if(!vis[u]){
			parent[u] = node;
			dfs(u, vis, parent);
		}
	}
}

void detect_path(int start, int goal, vector <int> &parent){
	int curr = goal;
	vector <int> path;
	while(curr != start){
		path.push_back(curr);
		curr = parent[curr];	
		//cout << curr << "\n";
	}
	path.push_back(curr);
	reverse(path.begin(), path.end());
	for(auto u : path){
		cout << u << " ";	
	}
}

int main(){
	cout << "Enter Number Of Nodes and Edges" << "\n";
	int n, m;
	cin >> n >> m;
	cout << "Enter the edges - (u - v)" << "\n";
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	cout << "Enter Staring Node And Goal Node" << "\n";
	int start, goal;
	cin >> start >> goal;
	vector <bool> vis(n + 1, 0);
	vector <int> parent(n + 1, 0);
	dfs(start, vis, parent);
	detect_path(start, goal, parent);  

    return 0;

}

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector <int> g[N];

int n, m, h, root;

void displayTree(){
	queue <pair <int, int>> q;
	q.push({root, 1});
	map <int, int> mp;
	while(!q.empty()){
		pair <int, int> x = q.front();
		q.pop();
		int level = x.second;
		if(!mp[level]){
			cout<<"\nLevel "<<level<<" : ";
			mp[level] = 1;
		} cout<<x.first<<" ";
		for(int i : g[x.first]){
				q.push({i, level+1});
		}
	}cout<<"\n\n";
}
int flag;
void dfs(int x, int target){
	if(flag)
		return;
	cout<<"(Current value) "<<x<<" ";
	if(x == target){
		flag = 1;
		cout<<" == (target value) "<<target<<"\n";
	}else{
		cout<<" != (target value) "<<target<<"\n";
	}
	for(int i : g[x])
		dfs(i, target);
}

void bfs(int target){
	queue <int> q;
	q.push(root);
	while(!q.empty()){
		if(flag)
			break;
		int x = q.front();
		q.pop();
		cout<<"(Current value) "<<x<<" ";
		if(x == target){
			flag = 1;
			cout<<" == (target value) "<<target<<"\n";
		}else{
			cout<<" != (target value) "<<target<<"\n";
		}
		for(int i : g[x])
			q.push(i);
	}
}

int main(){
	cout<<"Enter maximum number of children : ";
	cin>>n; cout<<"\n";
	queue <int> q;
	cout<<"Enter value of root node : ";
	cin>>root;
	q.push(root);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout<<"Enter total children of node "<<x<<" : ";
		cin>>m;
		cout<<"Enter values of "<<m<<" children of "<<x<<" : \n";
		for(int i = 0; i < m; i++){
			int y; cin>>y;
			g[x].push_back(y);
			q.push(y);
		} cout<<"\n"; 
	}
	displayTree();
	
	cout<<"---> Enter value to be searched : ";
	
	int target; cin>>target;
	
	flag = 0;
	cout<<"\nUsing DFS : \n\n";
	dfs(root, target);
	if(flag)
		cout<<"Target found!\n\n";
	else
		cout<<"Target not found!\n\n";
		
	flag = 0;
	cout<<"\nUsing BFS : \n\n";
	bfs(target);
	if(flag)
		cout<<"Target found!\n\n";
	else
		cout<<"Target not found!\n\n";
}
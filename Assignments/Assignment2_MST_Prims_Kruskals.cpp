//By N Purushotam Kumar; 3330; TE-COMP A T2
//Assignment 2 MST Prim's and Kruskal's
#include <bits/stdc++.h>
using namespace std;
#define dbg(a) cout << #a << " is " << (a); cout << "\n";
#define inf 100000000

struct Node{
	int w, x, y;
};

struct cmp{
	public:
		bool operator()(const Node lb, const Node rb) const{
			return lb.w > rb.w;
		}
};

class MinSpanningTree{
	priority_queue <Node, vector <Node>, cmp> pq;
	int par[1000], sz[1000], n, m;
	Node GraphEdges[1000], Tree[1000];
	public:
		MinSpanningTree (int n){
			this->n = n;
			this->m = 0;
			for(int i = 1; i <= n; i++)	
				par[i] = i, sz[i] = 1; 
		}
		int  Find_parent(int x);
		void Union(int x, int y);
		void Kruskal();
		void Prims();
		void InputGraph();
};

int MinSpanningTree :: Find_parent(int x){
	if(par[x] == x)
		return x;
	return par[x] = Find_parent(par[x]);
}
void MinSpanningTree :: Union(int x, int y){
	int px = Find_parent(x);
	int py = Find_parent(y);
	if(px != py){
		if(sz[px] > sz[py])
			swap(px, py);
		par[px] = py;
		sz[py] += sz[px];
	}
}

void MinSpanningTree :: Kruskal(){
	cout<<"\n\t ------------ Output for Kruskal's Algorithm ------------\n ";
	int cnt = 0, TreeWeight = 0;
	while(!pq.empty() and cnt < n-1){
		Node cur = pq.top();
		pq.pop();
		if(Find_parent(cur.x) != Find_parent(cur.y)){
			Union(cur.x, cur.y);
			Tree[cnt].x = cur.x, Tree[cnt].y = cur.y, Tree[cnt].w = cur.w;
			TreeWeight += cur.w;
			cnt += 1;
		}
	}
	if(cnt != n-1){
		cout<<"Graph is not connected!"; return;
	}
	cout<<"\n---> Minimum Spanning Tree : \n";
	cout<<"\tTotal cost : "<<TreeWeight<<"\n";
	cout<<"\tPair of vartices and weight of edge between them : \n";
	for(int i = 0; i < n-1; i++){
		cout<<"\t[ "<<Tree[i].x<<", "<<Tree[i].y<<" ] , cost = "<<Tree[i].w<<"\n";
	}
}

void MinSpanningTree :: Prims(){
	cout<<"\n\t ------------ Output for Prims's Algorithm ------------\n ";
	int cnt = 0, TreeWeight = 0, 
		c = 0, vis[n+1] = {};
	vis[1] = 1;
	while(c < n){
		int wt = inf;
		Node temp; 
		for(int i = 1; i <= n; i++){
			if(vis[i]){ //Considering visited vertices..
				for(int j = 0; j< m; j++){
					Node k = GraphEdges[j];
					int x = k.x, y = k.y;
					if(y == i)
						swap(x, y);
					if(x == i){
						if(vis[y]) //If vertex is already visited..
							continue;
						if(wt > k.w){
							wt = k.w;
							temp = k;
						}
					}	
				}
			}
		}
		if(wt != inf){
			Tree[cnt++] = temp;
			TreeWeight += wt; vis[temp.y] = 1, vis[temp.x] = 1;
		} ++c;
	}
	
	if(cnt != n-1){
		cout<<"Graph is not connected!"; return;
	}
	cout<<"\n---> Minimum Spanning Tree : \n";
	cout<<"\tTotal cost : "<<TreeWeight<<"\n";
	cout<<"\tPair of vartices and weight of edge between them : \n";
	for(int i = 0; i < n-1; i++){
		cout<<"\t[ "<<Tree[i].x<<", "<<Tree[i].y<<" ] , cost = "<<Tree[i].w<<"\n";
	}
}

void MinSpanningTree :: InputGraph(){
	cout<<"Enter n*n matrix for the given graph \n";
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int weight; cin>>weight;
			if(weight != -1){
				GraphEdges[m].x = i, GraphEdges[m].y = j, GraphEdges[m].w = weight;
				pq.push(GraphEdges[m]);
				m++;
			}
		}
	}
}

int main(){
	cout<<"Enter total number of vertices : ";
	int n; cin>>n;
	MinSpanningTree obj(n); 
	obj.InputGraph();
	obj.Kruskal();
	obj.Prims();
    return 0;
}


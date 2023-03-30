#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Graph
{
	int V;
	
	vector<int> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<int>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back(v);
}
void DFT(Graph* g,int x,int d,int &cnt,vector<bool> &vis)
{
	if(x==d)
	{
		cnt++;
		return;
	}
	
	vis[x]=true;
	
	for(auto i : g->adj[x])
	if(!vis[i])
	DFT(g,i,d,cnt,vis);
	
	vis[x]=false;
}
int findPathCount(Graph* g,int s,int d)
{
	int cnt=0;
	
	if(s==d)
	return cnt;
	
	vector<bool> vis(g->V,false);
	
	DFT(g,s,d,cnt,vis);
	
	return cnt;
}
signed main()
{
	int V=5;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,0,4);
	addEdge(g,1,3);
	addEdge(g,1,4);
	addEdge(g,2,4);
	addEdge(g,3,2);
	
	int s=0,d=4;
	
	cout<<findPathCount(g,s,d)<<endl;
	
	return 0;
}

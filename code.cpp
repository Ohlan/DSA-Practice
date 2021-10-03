#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define INF INT_MAX
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define pq priority_queue<int>
#define dq deque<int>
typedef pair<int,int> ii;
void solve();
void addEdge(vector<int> adjacent[],int a,int b)
{
	adjacent[a].push_back(b);
}
void scanList(vector<int> adjacent[],int e,map<ii,int> &weights)
{
	while(e--)
	{
		int a,b,w;
		cin>>a>>b;
		cin>>w;
		weights.insert(make_pair(make_pair(a,b),w));
		addEdge(adjacent,a,b);
	}
}

void printList(vector<int> adjacent[],int v)
{
	for(int i=0;i<v;i++)
	{
		cout<<i<<":  ";
		for(int j=0;j<adjacent[i].size();j++)
			cout<<adjacent[i][j]<<" ";
		cout<<"\n";
	}
}
int weight(map<ii,int> &mp,int a,int b)
{
	if(mp.count(make_pair(a,b))==0)
		return INF;
	else
		return mp[make_pair(a,b)];
}

void DFSRec(vector<int>adjacent[],int u,int visited[],stack<int> &ans)
{
	visited[u]=1;
	for(auto x:adjacent[u])
	{
		if(visited[x]==0)
		{
			DFSRec(adjacent,x,visited,ans);
		}
	}
	ans.push(u);
}

vi shortestPathDAG(vector<int> adjacent[],int v,map<ii,int> &mp,int source)
{
	stack<int> topologicalSorted;
	int visited[v]={0};
	for(int i=0;i<v;i++)
	{
		if(visited[i]==0)
			DFSRec(adjacent,i,visited,topologicalSorted);
	}
	vi dist(v,INF);
	dist[source]=0;
	while(!topologicalSorted.empty())
	{
		int u=topologicalSorted.top();
		if(dist[u]!=INF)	
			for(int x:adjacent[u])
			{
				if(dist[x]>dist[u]+weight(mp,u,x))
					dist[x]=dist[u]+weight(mp,u,x);
			}
		topologicalSorted.pop();
	}
	return dist;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		solve();	
	return 0;
}
void solve()
{
	int v,e;
	cin>>v>>e;
	vector<int> adjacent[v];
	map<ii,int> weights;
	scanList(adjacent,e,weights);
	printList(adjacent,v);
	vi dist=shortestPathDAG(adjacent,v,weights,3);
	for(auto x:dist)
		cout<<x<<" ";
}

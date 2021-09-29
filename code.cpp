#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
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
	adjacent[b].push_back(a);
}
void scanList(vector<int> adjacent[],int v,int e)
{
	while(e--)
	{
		int a,b;
		cin>>a>>b;
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
void DFSRec(vector<int> adjacent[],int v,bool visited[])
{
	cout<<v<<" ";
	visited[v]=true;
	for(int i=0;i<adjacent[v].size();i++)
	{
		if(visited[adjacent[v][i]]==false)
			DFSRec(adjacent,adjacent[v][i],visited);
	}
}

int DFS(vector<int> adjacent[],int v)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	int connectedComponents=0;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			connectedComponents++;
			DFSRec(adjacent,i,visited);
		}
	}
	return connectedComponents;
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
	scanList(adjacent,v,e);
	printList(adjacent,v);
	int c=DFS(adjacent,v);
	cout<<c<<"\n";
}

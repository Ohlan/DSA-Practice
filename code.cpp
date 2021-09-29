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
bool DFSRec(vector<int> adjacent[],int v,bool visited[],int parent)
{
	
	visited[v]=true;
	for(int i=0;i<adjacent[v].size();i++)
	{
		if(visited[adjacent[v][i]]==false)
			return DFSRec(adjacent,adjacent[v][i],visited,v);
		else
		{
			if(adjacent[v][i]!=parent)
				return true;
		}
	}
	return false;
}

bool detectCycleUG(vector<int> adjacent[],int v)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			return DFSRec(adjacent,i,visited,-1);
		}
	}
	return false;
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
	string s=detectCycleUG(adjacent,v)?"cycle present\n":"cycle not present\n";
	cout<<s;
	
}

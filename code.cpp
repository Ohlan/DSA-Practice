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

bool cyclePresent(vector<int> adjacent[],int v)
{
	int inDegree[v]={0};
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<adjacent[i].size();j++)
			inDegree[adjacent[i][j]]++;
	}
	queue<int> q;
	for(int i=0;i<v;i++)
		if(inDegree[i]==0)
			q.push(i);
	int count=0;
	while(!q.empty())
	{
		int e=q.front();
		for(int x:adjacent[e])
		{
			if(--inDegree[x]==0)
				q.push(x);
		}
		q.pop();
		count++;
	}
	return (count!=v);
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
	cout<<cyclePresent(adjacent,v)<<"\n";
}

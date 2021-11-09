#include<bits/stdc++.h>
using namespace std;
// #define mod 1000000007
#define INF INT_MAX
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define ull unsigned long long
#define pq priority_queue<int>
#define dq deque<int>
typedef pair<int,int> ii;
void solve();

/*
 * Complete the 'numberOfWays' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY roads as parameter.
 */


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
int depth(vector<int>adj[], vi &vis, int root,int curr)
{
    vis[root]=1;
    curr++;
    int d=curr;
    for(int i=0;i<adj[root].size();i++)
    {
        if(vis[adj[root][i]]==0)
            d=max(d,depth(adj,vis,adj[root][i],curr+1));
    }
    return d;
}
int levelorder(vector<int>adj[], int root,int v)
{
    int curr=0;
    int count=adj[root].size();
    if(count>=3)
    {
        int m=INF;
        vi vis(v,0);
        for(int i=0;i<adj[root].size();i++)
        {
            int d=depth(adj,vis,adj[root][i],0);
            
            m=min(d,m);
        }
        count=(count*(count-1)*(count-2))/6;
        curr=count*m;
    }
    return curr;
}


int numberOfWays(vector<int> adj[],int v)
{   
    int ans=0;
    for(int i=0;i<v;i++)
    {
        ans+=levelorder(adj, i, v);
    }
    return ans;
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
    cout<<numberOfWays(adjacent,v)<<"\n";
}


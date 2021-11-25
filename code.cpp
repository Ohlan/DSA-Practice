#include<bits/stdc++.h>
using namespace std;
#define N 100
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define pq priority_queue<int>
#define dq deque<int>
typedef pair<int,int> ii;
bool safe(int pos,int q,vector<int> &place)
{
    int x = q, y = pos;
    for(int i=0;i<q;i++)
    {
        int k= place[i]-1;
        if(k==pos||(k+i==x+y)||(k-i==y-x))
            return false;
    }
    return true;
}

void find(int n, vector<int> &place, vector<vector<int>> &res, int q=0)
{
    if(q==n)
    {
        res.push_back(place);
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(safe(i,q,place))
        {
            place[q] = i+1;
            find(n,place,res,q+1);
            place[q] = -1;
        }
    }
}

vector<vector<int>> nQueen(int n) {
    vector<vector<int>> res;
    vector<int> place(n,-1);
    find(n,place,res);
    return res;
}


void solve();
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
    int n;
    cin>>n;
    vector<vector<int>> res= nQueen(n);
    for(auto x:res)
    {   
        for(auto i:x)
            cout<<i<<" ";
        cout<<"\n";
    }    
}
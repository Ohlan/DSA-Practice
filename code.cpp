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
void fn(vll &a,ll ex)
{
    for(auto &x:a)
    {
        x+=ex;
        x/=2;
    }
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
    int n;
    cin>>n;
    vll a(n);
    for(auto &x:a)
        cin>>x;
    ll ans=0;
    ll fg=0;
    for(ll i=0,t=1;i<64;i++)
    {
        ll c=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]%2!=0)
                c++;
        }
        if(c%2==1)
        {
            fn(a,t);
            ans=ans+t;
            
        }        
        
        t*=2;
    }
    for(int i=0;i<n;i++)
        fg=(fg^a[i]);

    
    if(fg!=0)
        cout<<"-1\n";
    else
        cout<<ans<<"\n";

}

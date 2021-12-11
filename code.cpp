#include<bits/stdc++.h>
using namespace std;
#define N 100000
#define ll long long
#define vi vector<int>
#define ull unsigned long long
#define pq priority_queue<int>
#define dq deque<int>
typedef pair<int,int> ii;
void solve();
void swap(int a[],int i,int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void heapify(int a[],int size,int i)
{
    int max = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left<size&&a[left]>a[max])
        max=left;
    if(right<size&&a[right]>a[max])
        max=right;
    if(i!=max)
    {
        swap(a,i,max);
        heapify(a,size,max);
    }
}

void heapSort(int a[],int n)
{
    for(int i = (n-2)/2;i>=0;i--)
    {
        heapify(a,n,i);
    }
    int i =n-1;
    while(i>=0)
    {
        swap(a,0,i);
        heapify(a,i,0);
        i--;
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
    int a[n];
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    heapSort(a,n);
    for(int i = 0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
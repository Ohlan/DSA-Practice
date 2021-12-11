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
struct max_heap
{
    int a[N];
    int size = 0;

    void heapify(int i)
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
            heapify(max);
        }
    }

    void push(int key)
    {
        a[size++] = key;
        int j = size-1;
        while(j>=0)
        {
            heapify(j);
            if(j-1<0)
                break;
            j = (j-1)/2;
        }
    }
    bool empty()
    {
        if(size==0)
            return true;
        return false;
    }
    int top()
    {
        if(size==0)
            return INT_MIN;
        return a[0];
    }
    void pop()
    {
        if(size==0)
            cout<<"Err... heap is empty!!!";
        else
        {
            swap(a,0,size-1);
            size--;
            heapify(0);
        }
    }
};

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
    max_heap q;
    int i;
    while(n--)
    {
        cin>>i;
        q.push(i);
    } 
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
}
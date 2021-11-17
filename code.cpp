#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void solveBT();
vector<int> singleNumber(vector<int> nums) 
    {
        int n = nums.size();
        int xo=0;
        int s1=0,s2=0;
        
        for(int i=0;i<n;i++)
            xo = (xo ^ nums[i]);
        
        xo = xo & (~(xo-1));
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] & xo)
                s1 = (s1^nums[i]);
            else
                s2 = (s2^nums[i]);
        }
        if(s1>s2)
        {
            s1=s1^s2;
            s2=s1^s2;
            s1=s1^s2;
        }
        return {s1,s2};
    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
// int helper(int idx,int s,vector<int>&vec,vector<vector<int>>&dp)
// {
//     if(s==0)return 1;
//     if(idx==-1)return 0;
//     if(dp[idx][s]!=-1)return dp[idx][s];
//     int total=0;
//     if(vec[idx]<=s)
//     {
//         total+=helper(idx,s-vec[idx],vec,dp);
//     }
//     total+=helper(idx-1,s,vec,dp);
//     return dp[idx][s]=total%MOD;
// }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,sum;
    cin>>n>>sum;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    // vector<vector<int>>dp(n,vector<int>(sum+1,0));
    // for(int i=0;i<n;i++)
    // {
    //     dp[i][0]=1;
    // }
    vector<int>prev(sum+1,0);
    prev[0]=1;
    for(int idx=0;idx<n;idx++)
    {
        vector<int>curr(sum+1,0);
        curr[0]=1;
        for(int s=1;s<=sum;s++)
        {
            if(s-vec[idx]>=0)
            {
            curr[s]=(curr[s]+curr[s-vec[idx]])%MOD;
            }
            if(idx-1>=0)
            {
            curr[s]=(curr[s]+prev[s])%MOD;
            }
        }
        prev=curr;
    }
    cout<<prev[sum]<<endl;
}
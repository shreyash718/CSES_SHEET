#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD=1e9+7;
int helper(vector<int>&vec,int m,int idx,int last, vector<vector<int>>&dp)
{
    if(idx<0)return 1;
    if(dp[idx][last]!=-1)return dp[idx][last];
    ll count=0;
    if(vec[idx]==0)
    {
        if(last+1<=m)
        {
            count+=helper(vec,m,idx-1,last+1,dp);
        }
        if(last-1>=1)
        {
            count+=helper(vec,m,idx-1,last-1,dp);
        }
        count+=helper(vec,m,idx-1,last,dp);
    }
    else
    {
        int x=abs(vec[idx]-last);
        if(x>=0 && x<=1)
        {
            count+=helper(vec,m,idx-1,vec[idx],dp);
        }
    }
    return dp[idx][last]=count;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    ll ans=0;
    // vector<vector<int>>dp(n,vector<int>(m+1,0));
    // if(vec[0]==0)
    // {
    //     for(int i=1;i<=m;i++)
    //     {
    //         dp[0][i]=1;
    //     }
    // }
    // else
    // {
    //     dp[0][vec[0]]=1;
    // }
    vector<int>prev(m+1,0);
    if(vec[0]==0)
    {
        for(int i=1;i<=m;i++)
        {
            prev[i]=1;
        }
    }
    else
    {
        prev[vec[0]]=1;
    }
    for(int idx=1;idx<n;idx++)
    {
        vector<int>curr(m+1,0);
        if(vec[idx]==0)
        {
        for(int last=1;last<=m;last++)
            {
                if(last-1>=0)curr[last]=(curr[last]+prev[last-1])%MOD;
                if(last+1<=m)curr[last]=(curr[last]+prev[last+1])%MOD;
                curr[last]=(curr[last]+prev[last])%MOD;
            }
        }
        else
        {
            if(vec[idx]-1>=0)curr[vec[idx]]=(curr[vec[idx]]+prev[vec[idx]-1])%MOD;
            if(vec[idx]+1<=m)curr[vec[idx]]=(curr[vec[idx]]+prev[vec[idx]+1])%MOD;
            curr[vec[idx]]=(curr[vec[idx]]+prev[vec[idx]])%MOD;
        }
        prev=curr;
    }
    if(vec[n-1]==0)
    {
        for(int i=1;i<=m;i++)
        {
        ans=(ans+prev[i])%MOD;
        }
    }
    else
    {
        ans=prev[vec[n-1]];
    }
    cout<<ans<<endl;
}
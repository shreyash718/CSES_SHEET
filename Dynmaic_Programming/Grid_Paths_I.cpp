#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=1e9+7;
// int helper(int i,int j,vector<string>&grid,int n,vector<vector<int>>&dp)
// {
//     if(i>=n || j>=n)return 0;
//     if(i==n-1 && j==n-1)return 1;
//     if(dp[i][j]!=-1)return dp[i][j];
//     int total=0;
//     if(j+1<n && grid[i][j+1]!='*')
//     {
//         total=(total+helper(i,j+1,grid,n,dp))%mod;
//     }
//     if(i+1<n && grid[i+1][j]!='*')
//     {
//         total=(total+helper(i+1,j,grid,n,dp))%mod;
//     }
//     return dp[i][j]=total;
// }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<string>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    if(vec[0][0]=='*' || vec[n-1][n-1]=='*')
    {
        cout<<0<<endl;
        return 0;
    }
    // vector<vector<int>>dp(n,vector<int>(n,0));
    // dp[n-1][n-1]=1;
    vector<int>prev(n,0);
    prev[n-1]=1;
    for(int i=n-1;i>=0;i--)
    {
        vector<int>curr(n,0);
        for(int j=n-1;j>=0;j--)
        {
            if(i==n-1 && j==n-1)
            {
                curr[j]=1;
                continue;
            }
            if(vec[i][j]!='*')
            {
                if(i+1<n)curr[j]=(curr[j]+prev[j])%mod;
                if(j+1<n)curr[j]=(curr[j]+curr[j+1])%mod;
            }
        }
        prev=curr;
    }
    cout<<prev[0]<<endl;
}
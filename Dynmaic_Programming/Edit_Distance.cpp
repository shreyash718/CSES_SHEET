#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// int helper(string &a,string &b,int i,int j,vector<vector<int>>&dp)
// {
//     if(i<0 && j<0)return 0;
//     if(i<0)return j+1;
//     if(j<0)return i+1;
//     if(dp[i][j]!=-1)return dp[i][j];
//     int ops=INT_MAX;
//     if(a[i]==b[j])
//     {
//         ops=min(ops,helper(a,b,i-1,j-1,dp));
//     }
//     else
//     {
//         int x=helper(a,b,i,j-1,dp);
//         int y=helper(a,b,i-1,j,dp);
//         int z=helper(a,b,i-1,j-1,dp);
//         if(x!=INT_MAX)ops=min(ops,1+x);
//         if(y!=INT_MAX)ops=min(ops,1+y);
//         if(z!=INT_MAX)ops=min(ops,1+z);
//     }
//     return dp[i][j]=ops;
// }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string a;
    string b;
    cin>>a>>b;
    int n1=a.size();
    int n2=b.size();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    for(int i=0;i<=n1;i++)
    {
        dp[i][0]=i;
    }
    for(int i=0;i<=n2;i++)
    {
        dp[0][i]=i;
    }
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            int ops=INT_MAX;
            if(a[i-1]==b[j-1])
            {   
                ops=min(ops,dp[i-1][j-1]);
            }
            else
            {
                int x=dp[i][j-1];
                int y=dp[i-1][j];
                int z=dp[i-1][j-1];
                if(x!=INT_MAX)ops=min(ops,1+x);
                if(y!=INT_MAX)ops=min(ops,1+y);
                if(z!=INT_MAX)ops=min(ops,1+z);
            }
            dp[i][j]=ops;
        }
    }
    cout<<dp[n1][n2];
}
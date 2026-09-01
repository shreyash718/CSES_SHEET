#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// int helper(int a,int b,vector<vector<int>>&dp)
// {
//     if(a==b)return 0;
//     if(dp[a][b]!=-1)return dp[a][b];
//     int steps=INT_MAX;
//     for(int i=1;i<a;i++)
//     {
//         steps=min(steps,1+helper(i,b,dp)+helper(a-i,b,dp));
//     }
//     for(int i=1;i<b;i++)
//     {
//         steps=min(steps,1+helper(a,i,dp)+helper(a,b-i,dp));
//     }
//     if(b<=a && a<=b)dp[b][a]=steps;
//     return dp[a][b]=steps;
// }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x,y;
    cin>>x>>y;
    vector dp(x+1,vector<int>(y+1,0));
    for(int a=1;a<=x;a++)
    {
        for(int b=1;b<=y;b++)
        {
            if(a==b)continue;
    int steps=INT_MAX;
    for(int i=1;i<a;i++)
    {
        steps=min(steps,1+dp[i][b]+dp[a-i][b]);
    }
    for(int i=1;i<b;i++)
    {
        steps=min(steps,1+dp[a][i]+dp[a][b-i]);
    }
    dp[a][b]=steps;
}
}
    cout<<dp[x][y]<<endl;
}
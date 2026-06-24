#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// int helper(int n,vector<int>&dp)
// {
//     if(n==0)return 0;
//     if(n<0)return INT_MAX;
//     if(dp[n]!=-1)return dp[n];
//     string s=to_string(n);
//     int mina=INT_MAX;
//     for(auto it:s)
//     {
//         if(it=='0')continue;
//         int steps=helper(n-(it-'0'),dp);
//         if(steps!=INT_MAX)
//         {
//             mina=min(1+steps,mina);
//         }
//     }
//     return dp[n]=mina;

// }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    for(int i=1;i<=n;i++)
    {
        string s=to_string(i);
        int mina=INT_MAX;
        for(auto it:s)
        {
            if(it=='0')continue;
            int steps=dp[i-(it-'0')];
            mina=min(1+steps,mina);
        }
        dp[i]=mina;
    }
    cout<<dp[n]<<endl;
}
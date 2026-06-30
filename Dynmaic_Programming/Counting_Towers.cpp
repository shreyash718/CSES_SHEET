#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=1e9+7;
// int helper(int idx,int last)
// {
//     if(idx==1)return 1;
//     ll total=0;
//     if(last==0)
//     {
//         total+=helper(idx-1,1)+2*helper(idx-1,0);
//     }
//     else
//     {
//         total+=4*helper(idx-1,1)+helper(idx-1,0);
//     }
//     return total;
// }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    vector<vector<ll>>dp(1e6+1,vector<ll>(2,0));
    dp[1][0]=1;
    dp[1][1]=1;
    for(int idx=2;idx<=1e6;idx++)
    {
        dp[idx][0]=(dp[idx-1][1]+2*dp[idx-1][0])%mod;
        dp[idx][1]=(4*dp[idx-1][1]+dp[idx-1][0])%mod;
    }
    while(t--)
    {
        int x;
        cin>>x;
        cout<<(dp[x][0]+dp[x][1])%mod<<endl;;
    }
}
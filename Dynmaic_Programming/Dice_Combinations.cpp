#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// int helper(int n)
// {
//     if(n==0)return 1;
//     ll count=0;
//     for(int i=1;i<=6;i++)
//     {
//         if(n>=i)
//         {
//             count+=helper(n-i);
//         }
//     }
//     return count;
// }
int MOD=1e9+7;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<ll>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(i>=j)
            {
                dp[i]=(dp[i]+dp[i-j])%MOD;
            }
        }
    }
    cout<<dp[n]<<endl;;

}
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll mod=1e9+7;
// ll totals(ll req,vector<ll>&vec,vector<ll>&dp)
// {
//     if(req==0)return 1;
//     if(dp[req]!=-1)return dp[req];
//     ll total=0;
//     for(auto it:vec)
//     {
//         if(it<=req)
//         {
//             total=(total+totals(req-it,vec,dp))%mod;
//         }
//     }
//     return dp[req]=(total%mod);
// }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x,y;
    cin>>x>>y;
    vector<ll>vec(x);
    for(ll i=0;i<x;i++)
    {
        cin>>vec[i];
    }
    vector<ll>dp(y+1,0);
    sort(vec.begin(),vec.end());
    dp[0]=1;
    for(ll i=1;i<=y;i++)
    {
        long long total=0;
        for(auto it:vec)
        {
            if(it>i)break;
            if(it<=i)
            {
                total=(total+dp[i-it]);
            }
        }
        dp[i]=total%mod;
    }
    cout<<dp[y]<<endl;
}
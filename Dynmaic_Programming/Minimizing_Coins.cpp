#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//Memoization approach
// ll helper(vector<ll>&vec,ll s,vector<ll>&dp)
// {
//     if(s==0)return 0;
//     if(dp[s]!=-1)return dp[s]; 
//     ll ans=LLONG_MAX;
//     for(auto it:vec)
//     {
//         if(it<=s)
//         {
//             ll cur=helper(vec,s-it,dp);
//             if(cur!=LLONG_MAX)
//             {
//                 ans=min(cur+1,ans);
//             }
//         }
        
//     }
//     return dp[s]=ans;
// }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,s;
    cin>>n>>s;
    vector<ll>vec(n);
    for(ll i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    vector<ll>dp(s+1,LLONG_MAX);
    dp[0]=0;
    for(ll sum=1;sum<=s;sum++)
    {
        for(auto it:vec)
        {
            if(sum-it>=0)
            {
                ll temp=dp[sum-it];
                if(temp!=LLONG_MAX)
                {
                dp[sum]=min(dp[sum],temp+1);
                }
            }
        }
    }
    if(dp[s]!=LLONG_MAX)cout<<dp[s]<<endl;
    else cout<<-1<<endl;
    
}
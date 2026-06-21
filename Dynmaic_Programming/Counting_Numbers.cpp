#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[2][11][20][2];

ll dp_function(string &s,bool tight,ll prev,ll idx,bool lz)
{
    if(s.size()==idx)return 1;
    if(dp[tight][prev][idx][lz]!=-1)return dp[tight][prev][idx][lz];
    ll lb=0;
    ll ub=(tight==true)?(s[idx]-'0'):9;
    ll res=0;
    for(ll dig=lb;dig<=ub;dig++)
    {
        if(dig==prev && lz==false)continue;

        res+=dp_function(s,(tight && dig==ub),dig,idx+1,(lz && dig==0));
    }
    return dp[tight][prev][idx][lz]=res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b;
    cin>>a>>b;
    string l=to_string(a-1);
    string r=to_string(b);
    memset(dp,-1,sizeof(dp));
    ll ans_l=dp_function(l,true,10,0,true);
    memset(dp,-1,sizeof(dp));
    ll ans_r=dp_function(r,true,10,0,true);
    cout<<ans_r-ans_l<<endl;;
}
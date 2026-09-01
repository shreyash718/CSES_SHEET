#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vector <ll>vec1(n+1);
    vector <ll>vec2(m+1);
    for(int i=1;i<=n;i++)cin>>vec1[i];
    for(int i=1;i<=m;i++)cin>>vec2[i];
    vector dp(n+1,vector<ll>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ll maxa=LLONG_MIN;
            if(vec1[i]!=vec2[j])
            {
                maxa=max(dp[i-1][j],dp[i][j-1]);
            }
            else
            {
                maxa=max(maxa,1+dp[i-1][j-1]);
            }
            dp[i][j]=maxa;
        }
    }
    cout<<dp[n][m]<<endl;
    vector<ll>lcs;
    int i=n;
    int j=m;
    while(i>0 && j>0)
    {
        if(vec1[i]==vec2[j])
        {
            lcs.push_back(vec1[i]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    int x=lcs.size();
    for(int i=x-1;i>=0;i--)
    {
        cout<<lcs[i]<<" ";
    }
    cout<<endl;
}
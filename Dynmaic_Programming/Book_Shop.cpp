#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int helper(vector<int>&price,vector<int>&pages,int cost,int idx,vector<vector<int>>&dp)
{
    if(cost==0)return 0;
    if(idx<0)return 0;
    if(dp[idx][cost]!=-1)return dp[idx][cost];
    int take=0;
    if(price[idx]<=cost)
    {
        take+=pages[idx]+helper(price,pages,cost-price[idx],idx-1,dp);
    }
    int nottake=helper(price,pages,cost,idx-1,dp);
    return dp[idx][cost]=max(take,nottake);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,x;
    cin>>n>>x;
    vector<int>price(n);
    vector<int>pages(n);
    for(int i=0;i<n;i++)
    {
        cin>>price[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>pages[i];
    }
    // vector<vector<int>>dp(n,vector<int>(x+1,0));
    // for(int cost=price[0];cost<=x;cost++)
    // {
    //     dp[0][cost]=pages[0];
    // }
    vector<int>prev(x+1,0);
    for(int cost=price[0];cost<=x;cost++)
    {
        prev[cost]=pages[0];
    }
    for(int idx=1;idx<n;idx++)
    {
        vector<int>curr(x+1,0);
        for(int cost=0;cost<=x;cost++)
        {
            int take=0;
            if(price[idx]<=cost)
            {
                take=pages[idx]+prev[cost-price[idx]];
            }
            int nottake=prev[cost];
            curr[cost]=max(take,nottake);
        }
        swap(prev,curr);
    }
    cout<<prev[x]<<endl;
}
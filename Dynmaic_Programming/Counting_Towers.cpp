#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int helper(int idx,int last)
{
    if(idx==0)return 1;
    ll total=0;
    total+=helper(idx-1,0);
    total+=helper(idx-1,1);
    total+=helper(idx-1,2);
    return total;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin>>x;
        cout<<helper(x,-1);
    }
}
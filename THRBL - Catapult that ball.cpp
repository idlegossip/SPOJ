#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100010][25];
ll Log[100010];
void build(ll n)
{
    for(ll j=1; j<=25; j++)
    {
        for(ll i=1; i+(1<<j)<=n; i++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
}
int main()

{
    ll n,m;
    cin>>n>>m;

    Log[1]=0;
    for(ll i=2; i<=n; i++)
    {
        ll a=i/2;
        Log[i]=Log[a]+1;
    }
    for(ll i=1; i<=n; i++)
    {
        cin>>dp[i][0];
    }
    build(n);
    ll cnt=0;
    ll l,r;
    for(ll i=1; i<=m; i++)
    {
        cin>>l>>r;
        if(l==r)
        {
            cnt++;
            continue;
        }
        ll x,y;
        if(l<r)
        {
              x=l;
              y=r-1;
        }
        else
        {
              x=r+1;
              y=l ;
        }
        ll a=Log[y-x+1];
        ll b=max(dp[x][a],dp[(y-(1<<a)+1)][a]);
        if(b<=dp[l][0])
            cnt++;

    }
    cout<<cnt<<endl;
}

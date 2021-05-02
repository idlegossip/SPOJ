#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000000][30];
ll Log[1000000];
void build(ll n)
{
    for(ll j=1; j<=25; j++)
    {
        for(ll i= 0; (i+(1<<j))<=n; i++)
        {
            dp[i][j]=min(dp[i][j-1],dp[(i+(1<<(j-1)))][j-1]) ;
        }
    }
}

int main()
{
    Log[1]=0;

    ll n;
    scanf("%lld",&n);
    for(ll i=2; i<=n; i++)
    {
          ll a=i/2;
          Log[i]=Log[a]+1;
    }
    for(ll i=0; i<n; i++)
    {
        scanf("%lld",&dp[i][0]);
    }
    ll q;
    scanf("%lld",&q);
    ll r,l;
    build(n);
    for(ll i=0; i<q; i++)
    {
        scanf("%lld %lld",&l,&r);
        ll a=Log[(r-l+1)];
      //  cout<<a<<" g  "<<endl;
        a=min(dp[l][a],dp[(r-(1<<a)+1)][a]);
        printf("%lld\n",a);
    }



}

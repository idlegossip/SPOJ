#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>primes ;
ll mx=1e6+20;
bool isPrime[1000010];

void sieve()
{
    for(ll i=2; i<=1000000; i++)isPrime[i]=true;
    for(ll i=4; i<1000000; i+=2)
        isPrime[i]=false;
    for(ll i=3; i*i<1000000; i+=2)
    {
        if(isPrime[i]==false)
            continue;
        for(ll j=2*i; j<1000000; j+=i)
            isPrime[j]=false;
    }
    primes.push_back(2);
    for(ll i=3; i<1000000; i+=2)
    {
        if(isPrime[i])
            primes.push_back(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    ll t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        ll i,j,k;

        cin>>l>>r;
        bool segprime[r-l+10];
        for(j=0; j<=r-l+4; j++)segprime[j]=true;
        if(l==1)
            segprime[0]=false;
        for(i=0; primes[i]*primes[i]<=r; i++)
        {
            ll current=primes[i];
            ll base=(ll)(l/current)*current;
            if(base<l)
                base+=current;
            for(j=base; j<=r; j+=current)
            {
                segprime[j-l]=false;
            }
            if(base==current)
                segprime[base-l]=true;
        }
        for(j=0; j<=r-l; j++)
            if(segprime[j])cout<<l+j<<endl;
        if(t)
            cout<<endl;

    }
    return 0;
}

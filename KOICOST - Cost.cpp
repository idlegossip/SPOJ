#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9;
ll parent[1000010];
ll Size[1000010];
void make_parent( ll n)
{
    for(ll i=0; i<=n; i++)
    {
        parent[i]=i;
        Size[i]=1;
    }
}
ll find_parent(ll v)
{
    if(parent[v]==v)
        return v;
  return  parent[v]=find_parent(parent[v]);
}
struct graph
{
    ll v,u,w;
    graph(ll u1,ll v1,ll w1)
    {
        u=u1;
        v=v1;
        w=w1;
    }
    bool operator<(graph const& ss)
    {
        return w>ss.w;
    }

};
int main()
{
    ll n,m;
    ll i,j,k;

    cin>>n>>m;
      make_parent(n);
    vector<graph>v;
    ll a,b,c;
    for(i=0; i<m; i++)
    {
        cin>>a>>b>>c;

        v.push_back(graph(a,b,c));
    }
    if(m==0)
    {
          cout<<0<<endl;
          return 0;
    }
    sort(v.begin(),v.end());
    ll cum[m+10]= {0};
    cum[m-1]=v[m-1].w;
    for(i=m-2; i>=0; i--)
    {
        cum[i]=cum[i+1]+v[i].w;
    }
    ll ans=0;
    for(i=0; i<m; i++)
    {

        a=v[i].u;
        b=v[i].v;
       // cout<<a<<" "<<b<<" "<<v[i].w<<endl;
        a=find_parent(a);
        b=find_parent(b);
        if(a!=b)
        {

            parent[a]=parent[b];
            ans+=cum[i]*(Size[a]*Size[b]);
            a=Size[a];
            b=Size[b];
            Size[find_parent(v[i].u)] =a+b;
          //  Size[find_parent(v[i].v)] =a+b;
        }
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}


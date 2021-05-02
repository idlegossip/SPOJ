
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>adj[100010];
ll in[100010];
ll visit[100010];
vector<ll>res;
ll n,m;
bool TopoKhans(ll u)
{
    priority_queue<ll,vector<ll>,greater<ll> >q;
    for(ll i=1; i<=n; i++)
    {
        if(in[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        ll v=q.top() ;
        res.push_back(v);
        q.pop();
        for(ll i=0; i<adj[v].size(); i++)
        {
            ll u=adj[v][i];
            in[u]--;
            if(in[u]==0)
                q.push(u);
        }
    }
    return res.size()==n;
}
int main()
{
    ll a,b;
    cin>>n>>m;
    for(ll i=0; i<m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;
    }
    if(TopoKhans(0))
    {
        for(ll i=0;i<res.size();i++)
      cout<<res[i]<<" ";
    }
    else
      cout<<"Sandro fails.";
      cout<<endl;
    return 0;
}


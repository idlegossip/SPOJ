
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>adj[1000010];
ll color[1000010];
ll fa[1000010];
ll dis[1000010];
ll diameterNode;
ll mx=0;
void dfs(ll u,ll f)
{
    fa[u]=f;
    dis[u]=dis[f]+1;
    for(ll i=0; i<adj[u].size(); i++)
    {
        ll v=adj[u][i];
        if(v!=f)
            dfs(v,u);
    }
    if(dis[u]>mx)
    {
        mx=dis[u];
        diameterNode=u;
    }
}
ll mx1=0;
void dfs1(ll u,ll f)
{
    fa[u]=f;
    dis[u]=dis[f]+1;
    for(ll i=0; i<adj[u].size(); i++)
    {
        ll v=adj[u][i];
        if(v!=f)
            dfs1(v,u);
    }
    if(dis[u]>mx1 )
    {
        mx1=dis[u];
        //diameterNode=u;
    }
}
int main()
{
    ll n;
    cin>>n;
    ll i,j,k;
    ll a,b;
    for(i=0; i<=n; i++)
        dis[i]=0;
    for(i=0; i<n-1; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for(i=0; i<=n; i++)
        dis[i]=0;
    dfs1(diameterNode,0);
    cout<<mx1-1<<endl;
    return 0;

}

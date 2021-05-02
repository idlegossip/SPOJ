#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>adj[100010];
ll in[100010];
ll visit[100010];
vector<ll>res;
ll n;
void TopoKhans()
{
    priority_queue<ll>q;
    for(ll i=1; i<=n; i++)
    {
        if(in[i]==0)
        {
            q.push(-i);

        }
    }
    while(!q.empty())
    {
        ll v=abs(q.top()) ;
        // cout<<v<<" - > ";
        res.push_back(v);
        q.pop();
        for(ll i=0; i<adj[v].size(); i++)
        {
            ll u=adj[v][i];
            // cout<<u<<endl;
            in[u]--;
            if(in[u]==0)
                q.push(-u);
        }
    }
}
int main()
{
    ll m;
    ll a,b;
    cin>>n>>m;
    for(ll i=1; i<=n; i++)
        in[i]=0;
    for(ll i=0; i<m; i++)
    {
        ll c;
        cin>>a>>b;
        for(ll j=0; j<b; j++)
        {
            cin>>c;
            adj[c].push_back(a);
            in[a]++;
        }
    }
    TopoKhans();
    for(ll i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
}



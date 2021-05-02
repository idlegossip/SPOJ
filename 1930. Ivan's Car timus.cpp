#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=1e9;
vector<ll>adj[100000];
vector<ll>d[100000];
ll dis[1000010][3];
ll res=LONG_LONG_MAX;
ll n;
void dijkstra(ll s,ll e)
{
    queue<pair<ll,pair<ll,ll> > >q;
    pair<ll,pair<ll,ll> > p;
    p= make_pair(s, make_pair(1,0)) ;

    q.push(p);
     p= make_pair(s, make_pair(0,0)) ;
    q.push(p);

    memset(dis,-1,sizeof(dis));
    dis[s][0]=0;
    dis[s][1]=0;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        ll cur_dir=p.second.first;
        ll cur_dis =p.second.second;
        ll cur_node=p.first;
        for(ll i=0; i<adj[cur_node].size(); i++)
        {
            ll to_dir=d[cur_node][i];
            ll to_node= adj[cur_node][i];
            ll to_dis=cur_dis;
            if(to_dir!=cur_dir)
                to_dis++;
            if(to_dis<dis[to_node][to_dir]||dis[to_node][to_dir]==-1)
            {
                dis[to_node][to_dir]=to_dis ;
                p=make_pair(to_node,make_pair(to_dir,to_dis));
                if(to_node==e)
                {
                    res=min(res,to_dis);
                }
                else
                    q.push(p);
            }
        }
    }
}
int main()
{
    ll m;
    cin>>n>>m;
    ll a,b;
    for(ll i=0; i<m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        d[a].push_back(0);
        adj[b].push_back(a);
           d[b].push_back(1);
    }
    cin>>a>>b;
    dijkstra(a,b);
    cout<<res<<endl;

}

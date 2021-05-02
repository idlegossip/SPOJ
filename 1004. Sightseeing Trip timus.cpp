#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll INF=1000000000000;
ll n;

int main()
{
    ll t;

    while(1)
    {
        cin>>n;
        if(n==-1)
            break;
        ll adj[110][110];
        ll len[110][110];
        ll next[110][110];
        ll path[n+10];
        ll m;
        cin>>m;
        ll a,b,c;
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=n; j++)
            {
                adj[i][j]=len[i][j]=INF;
                next[i][j]=j;
            }
        }
        for(ll i=0; i<m; i++)
        {
            cin>>a>>b>>c;
            adj[a][b]=adj[b][a]=len[a][b]=len[b][a]=min(len[a][b],c);
        }
        ll ind=1;
        ll res=INF;
        ll num=0;
        for(ll k=1; k<=n; k++)
        {
            for(ll i=1; i<k; i++)
            {
                for(ll j=i+1; j<k; j++)
                {
                    ll dis=len[i][j]+adj[i][k]+adj[k][j];
                    if(dis<res)
                    {
                        res=dis;
                        ind=0;
                        num=0;
                        ll p=i;
                        while(p!=j)
                        {
                            path[num++]=p;
                            p=next[p][j];
                        }
                        path[num++]=j;
                        path[num++]=k;
                    }
                }
            }
            for(ll i=1; i<=n; i++)
                for(ll j=1; j<=n; j++)
                {
                    if(len[i][k]+len[k][j]< len[i][j])
                    {
                        len[i][j]=len[i][k]+len[k][j];
                       next[i][j]=next[i][k]  ;
                    }

                }

        }
        if(res==INF)
            cout<<"No solution."<<endl;
        else
        {
            for(ll i=0; i<num; i++)
                cout<<path[i]<<" ";
            cout<<endl;

        }

    }
    return 0;
}

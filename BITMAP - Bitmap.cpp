#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>adj[10010];
ll n,m;
string str[10010];
ll ans[200][200];
void bfs(ll si,ll sj)
{
    queue<pair<ll,ll> >q;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
                ans[i][j]=min(ans[i][j],abs(si-i)+abs(sj-j));
        }
    }

}
int main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        memset(ans,1000000,sizeof(ans));
        cin>>n>>m;
        for(ll i=0; i<n; i++)
        {
            cin>>str[i];
        }
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                  if(str[i][j]=='1')
                        bfs(i,j);
            }
        }
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                  cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }

    }
}

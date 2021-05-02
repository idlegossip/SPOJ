#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ar[300000];
struct va
{
    ll value;
    ll prop1;
    ll prop2;
};
va tree[800000];
ll sm;
void Push_down(ll p,ll l,ll r,ll x,ll flag)
{
        if(flag==1)
           {
                 tree[p].value+=x;
           }
        else
          {
               tree[p].value=x;
          }
    ll le=2*p;
    ll mid=(l+r)/2;
    tree[p].value=tree[le].value+tree[le+1].value;
}
void Update(ll p,ll l,ll r,ll i,ll j,ll x,ll flag)
{
    if(i>r||j<l)
        return;
    if(l>=i&&r<=j)
    {

        return;
    }
     Push_down(p,l,r,x,flag);
    ll mid=(l+r)/2;
    ll le=2*p;
    Update(le,l,mid,i,j,x,flag);
    Update(le+1,mid+1,r,i,j,x,flag);
    tree[p].value=tree[le].value+tree[le+1].value;
}
void sum(ll p,ll l,ll r,ll i,ll j)
{
    if(r<i||l>j)
        return;
    if(l>=i&&r<=j)
    {
        sm+=tree[p].value;
        return ;
    }
    ll mid=(l+r)/2;
    sum(2*p,l,mid,i,j);
    sum(2*p+1,mid+1,r,i,j);
}
void build(ll p,ll l,ll r)
{
    if(l>r)
        return;
    if(l==r)
    {
        tree[p].value=ar[l];

        return;
    }
    tree[p].prop1=0;
    tree[p].prop2=0;
    ll le=2*p;
    ll mid=(l+r)/2;
    build(le,l,mid);
    build(le+1,mid+1,r);
    tree[p].value=tree[le].value+tree[le+1].value;
}
int main()
{
    ll n,q;
    cin>>n>>q;
    for(ll i=1; i<=n; i++)
    {
        cin>>ar[i];
    }
    build(1,1,n);
    ll r,l,x,f;
    while(q--)
    {
        cin>>f;
        if(f==1)
        {
            cin>>l>>r>>x;
            Update(1,1,n,l,r,x,f);
        }
        else if(f==2)
        {
            cin>>l>>r>>x;
            Update(1,1,n,l,r,x,f);
        }
        else
        {
            sm=0;
            cin>>l>>r;
            sum(1,1,n,l,r);

            cout<<sm<<endl;
        }
    }
    return 0;

}



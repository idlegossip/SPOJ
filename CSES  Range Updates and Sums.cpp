#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ar[300000];
struct va
{
    ll value;
    ll prop1;
    ll prop2;
    ll p1;
    ll p2;
};
va tree[800000];


void Check(ll p,ll x,ll flag )
{
    if(flag==1)
    {
        if( tree[p].prop2)
        {
            tree[p].p1=0;
            tree[p].p2=1;
            tree[p].prop1=0;
            tree[p].prop2+=x;
        }
        else
        {
            tree[p].p1=1;
            tree[p].prop1+=x;
        }
    }
    else
    {
        tree[p].prop1=0;
        tree[p].p1=0;
        tree[p].p2=1;
        tree[p].prop2=x;
    }
}
void Push_down(ll p,ll l,ll r)
{
    ll mid=(l+r)/2;
    ll le=2*p;
    if(tree[p].p1)
    {
        ll cur= tree[p].prop1;
        tree[p].value=(r-l+1)*cur;
        if(l!=r)
        {
            Check(le,cur,1);
            Check(le+1,cur,1);
        }
        tree[p].p1=0;
        tree[p].prop1=0;

    }
    else  if( tree[p].p2)
    {
        ll cur= tree[p].prop2;
        tree[p].value=(r-l+1)*cur;
        if(l!=r)
        {
            Check(le,cur,2);
            Check(le+1,cur,2);
        }
        tree[p].p2=0;
        tree[p].prop2=0;
    }


}
void Update(ll p,ll l,ll r,ll i,ll j,ll x,ll flag)
{
       Push_down(p,l,r);
    if(i<l||j>r)
        return;
    if(l>=i&&r<=j)
    {
          if(flag==1)
          {
                  Check(p,x,1);
                Push_down(p,l,r);
          }
          else
          {
                 Check(p,x,2);
                Push_down(p,l,r);
          }

        return;
    }
    ll mid=(l+r)/2;
    Update(2*p,l,mid,i,j,x,flag);
    Update(2*p+1,mid+1,r,i,j,x,flag);
    tree[p].value=tree[p<<1].value+tree[(p<<1)+1].value;
}
ll sum(ll p,ll l,ll r,ll i,ll j)
{
       Push_down(p,l,r);
    if(i<l||j>r)
        return 0;
    if(l>=i&&r<=j)
    {
        return tree[p].value;
    }
    ll mid=(l+r)/2;
    ll  p1=sum(2*p,l,mid,i,j);
    ll p2=sum(2*p+1,mid+1,r,i,j);
    return p1+p2;
}
void build(ll p,ll l,ll r)
{
    if(l>r)
        return;
    if(l==r)
    {
        tree[p].value=ar[l];
        tree[p].prop1=0;
        tree[p].prop2=0;
        return;
    }
    ll mid=(l+r)/2;
    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);
    tree[p].value=tree[p<<1].value+tree[(p<<1)+1].value;

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
        cin>>l>>r;
        cout<<sum(1,1,n,l,r)<<endl;
    }
    return 0;

}


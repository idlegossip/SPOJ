#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct st
{
    ll lazy;
    ll one;
    ll two;
    ll three;

};
st tree[1000010];
void build(ll p,ll l, ll r)
{
    tree[p].three= r-l+1;
    if(l==r)
    {
        tree[p].three=1;
        tree[p].two=0;
        tree[p].one=0;
        tree[p].lazy=0;
        return;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    build(le,l,mid);
    build(le+1,mid+1,r);
    tree[p].two=0;
    tree[p].one= 0;
    tree[p].lazy=0;
}
void push_down(ll p,ll l,ll r)
{
    ll le=2*p;
    if(tree[p].lazy==1)
    {
        tree[p].two= tree[p].one;
        tree[p].one= tree[p].three;
        tree[p].three=r-l+1-tree[p].two-tree[p].one;
    }
    else  if(tree[p].lazy==2)
    {
      tree[p].one= tree[p].two;
        tree[p].two= tree[p].three;

        tree[p].three=(r-l+1)-tree[p].two-tree[p].one;
    }
    if(l!=r)
    {
        tree[le].lazy=(tree[p].lazy+tree[le].lazy)%3;
        tree[le+1].lazy=(tree[p].lazy+tree[le+1].lazy)%3;
    }
    tree[p].lazy=0;
}
void update(int p,int l,int r,int i,int j)
{
    if(tree[p].lazy)
        push_down(p,l,r);;
    if(l>j||r<i)
        return;
    if(l>=i&&r<=j)
    {
        tree[p].lazy+=1;
        push_down(p,l,r);
        return;
    }
    ll le=2*p;
    ll mid=(l+r)/2;
    update(le,l,mid,i,j);
    update(le+1,mid+1,r,i,j);
    tree[p].three=tree[le].three+ tree[le+1].three;
    tree[p].two= tree[le].two+tree[le+1].two;
    tree[p].one=tree[le].one+tree[le+1].one;
}
ll query(int p,int l,int r,int i,int j)
{

    if(tree[p].lazy)
        push_down(p,l,r);
    if(r<i||l>j)
        return 0;
    if(l>=i&&r<=j)
    {
        return tree[p].three;
    }

    int le=2*p;
    int mid=(l+r)/2;
    ll p1=query(le,l,mid,i,j);
    ll p2= query(le+1,mid+1,r,i,j);
    tree[p].three=tree[le].three+ tree[le+1].three;
    tree[p].two= tree[le].two+tree[le+1].two;
    tree[p].one=tree[le].one+tree[le+1].one;
    return p1+p2;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    build(1,1,n);
    int a,b,c;
    ll cnt;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a)
        {
            cnt=query(1,1,n,b+1,c+1);
            cout<<cnt<<endl;
        }
        else
            update(1,1,n,b+1,c+1);
    }
}


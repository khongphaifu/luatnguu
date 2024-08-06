#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb  push_back  
#define ll  long long
#define el  "\n"
#define alla(a,n)  a+1,a+n+1
#define fi first
#define se second
#define all(v)  v.begin(),v.end()
#define fu(i,a,b)  for(ll i=a;i<=b;i++)
#define fud(i,a,b)  for(ll i=a;i>=b;i--)

const ll N=1e6+5,MOD=1e9+7,inf=1e18;

ll t,n;
ll a[N],b[N],st[4*N];

void build(ll id,ll l,ll r)
{
    if(l==r)
    {
        st[id]=a[l];return;
    }
    ll mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=min(st[2*id],st[2*id+1]);
}

void up(ll id,ll l,ll r,ll i,ll val)
{
    if(i<l || i>r) return;
    if(l==r)
    {
        st[id]=val;return;
    }
    ll mid=(l+r)/2;
    up(2*id,l,mid,i,val);
    up(2*id+1,mid+1,r,i,val);
    st[id]=min(st[2*id+1],st[2*id]);
}

ll get(ll id,ll l,ll r,ll val)
{
    if(l==r)
    {
        return l;
    }
    ll mid=(l+r)/2;
    if(st[2*id]>val)
    {
        return get(2*id+1,mid+1,r,val);
    }
    else return get(2*id,l,mid,val);
}

void sol()
{
    cin>>n;
    fu(i,1,n) cin>>a[i];
    fu(i,1,n) cin>>b[i];
    // ll pos=1;
    build(1,1,n);
    fu(i,1,n)
    {
        // pos=max(pos,i);
        ll pos=get(1,1,n,b[i]);
        if(a[pos]!=b[i])
        {
            // sort(a+i,a+res+1);
            // pos=res+1;
            cout<<"NO"<<el;return;
        }
        up(1,1,n,pos,inf);
    }
    cout<<"YES"<<el;
}


signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>t;
    while(t--) sol();

    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
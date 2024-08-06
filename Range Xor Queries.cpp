#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define             pb  push_back  
#define             ll  long long
#define             el  "\n"
#define      alla(a,n)  a+1,a+n+1
#define         all(v)  v.begin(),v.end()
#define      fu(i,a,b)  for(ll i=a;i<=b;i++)
#define     fud(i,a,b)  for(ll i=a;i>=b;i--)

const ll N=2e5+5,MOD=1e9+7;

ll n,q;
ll a[N],st[4*N];

void build(ll id,ll l,ll r)
{
    if(l==r)
    {
        st[id]=a[l];return;
    }
    ll mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=st[2*id]^st[2*id+1];
}

ll get(ll id,ll l,ll r,ll u,ll v)
{
    if(u>r || l>v) return 0;
    if(u<=l && r<=v) return st[id];
    ll mid=(l+r)/2;
    return get(2*id,l,mid,u,v)^get(2*id+1,mid+1,r,u,v);
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

    cin>>n>>q;
    fu(i,1,n) cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        ll x,y;cin>>x>>y;
        cout<<get(1,1,n,x,y)<<el;
    }
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
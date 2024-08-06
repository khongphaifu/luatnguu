#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb  push_back  
#define ll  int
#define el  "\n"
#define alla(a,n)  a+1,a+n+1
#define fi first
#define se second
#define all(v)  v.begin(),v.end()
#define fu(i,a,b)  for(ll i=a;i<=b;i++)
#define fud(i,a,b)  for(ll i=a;i>=b;i--)

const ll N=1e6+5,MOD=1e9+7,inf=1e9;

struct bg
{
    char s;
    ll k,x;
};
ll n,q,m;
ll a[N],bit[N];
bg b[N];
map<ll,ll> mp;

void up(ll x,ll v)
{
    for(; x<=m ; x+= x&-x ) bit[x]+=v;
}

ll get(ll x)
{
    ll res=0;
    for(; x>=1 ; x&= x-1) res+=bit[x];
    return res;
}


// void up(ll id,ll l,ll r,ll i,ll val)
// {
//     if(i<l || i>r) return;
//     if(l==r)
//     {
//         st[id]+=val;return;
//     }
//     ll mid=(l+r)/2;
//     up(2*id,l,mid,i,val);
//     up(2*id+1,mid+1,r,i,val);
//     st[id]=st[2*id+1]+st[2*id];
// }

// ll get(ll id,ll l,ll r,ll u,ll v)
// {
//     if(u>r || l>v) return 0;
//     if(u<=l && r<=v) return st[id];
//     ll mid=(l+r)/2;
//     return get(2*id,l,mid,u,v)+get(2*id+1,mid+1,r,u,v);
// }

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
    vector<ll> v;
    fu(i,1,n) cin>>a[i],v.pb(a[i]);
    fu(i,1,q)
    {
        cin>>b[i].s>>b[i].k>>b[i].x;
        if(b[i].s=='?') v.pb(b[i].k);
        v.pb(b[i].x);
    }

    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    m=v.size();
    fu(i,0,m-1)
    {
        mp[v[i]]=i+1;
    }
    fu(i,1,n) up(mp[a[i]],1);
    fu(i,1,q)
    {
        if(b[i].s=='!')
        {
            up(mp[a[b[i].k]],-1);
            up(mp[b[i].x],1);
            a[b[i].k]=b[i].x;
        }
        else cout<<get(mp[b[i].x])-get(mp[b[i].k]-1)<<el;
    }

    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
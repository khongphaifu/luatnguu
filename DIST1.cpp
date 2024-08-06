#include <bits/stdc++.h>
using namespace std;


#define           TASK  "DIST1"
#define             pl  pair<ll,ll>  
#define             pb  push_back  
#define             ll  long long
#define             db  double
#define            nnc  signed main()
#define             se  second 
#define             fi  first
#define             el  "\n"
#define         all(a)  a.begin(),a.end()
#define      alla(a,n)  a+1,a+n+1
#define     FOR(i,a,b)  for(ll i=a;i<=b;i++)
#define    FORD(i,a,b)  for(ll i=a;i>=b;i--)
#define    FORN(i,a,b)  for(ll i=a;i<b;i++)
#define   FORDN(i,a,b)  for(ll i=a;i>b;i--)
#define     print(a,n)  for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<el;
#define      printv(v)  for(auto it:v) cout<<it<<" ";cout<<el;
#define     printvp(v)  for(auto it:v) cout<<it.fi<<" "<<it.se<<el;
#define       ieozzool  cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;


ll mlt=0;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const ll N = 1e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    struct bg
    {
        ll x,v;
    };

    bool cmp(bg a,bg b)
    {
        if(a.x==b.x) return a.v<b.v;
        return a.x<b.x;
    }

    bool cmp1(bg a,bg b)
    {
        if(a.v==b.v) return a.x<b.x;
        return a.v<b.v;
    }

    ll n;
    ll st[4*N],std[4*N];
    ll f[N];
    bg a[N],b[N];

    void up(ll id,ll l,ll r,ll i,ll val)
    {
        if(i<l || r<i) return;
        if(l==r)
        {
            st[id]+=val;return;
        }
        ll mid=(l+r)/2;
        up(2*id,l,mid,i,val);
        up(2*id+1,mid+1,r,i,val);
        st[id]=st[2*id]+st[2*id+1];
    }

    ll get(ll id,ll l,ll r,ll u,ll v)
    {
        if(v<l || r<u) return 0;
        if(u<=l && r<=v) return st[id];
        ll mid=(l+r)/2;
        return get(2*id,l,mid,u,v)+get(2*id+1,mid+1,r,u,v);
    }

    void upd(ll id,ll l,ll r,ll i,ll val)
    {
        if(i<l || r<i) return;
        if(l==r)
        {
            std[id]+=val;return;
        }
        ll mid=(l+r)/2;
        upd(2*id,l,mid,i,val);
        upd(2*id+1,mid+1,r,i,val);
        std[id]=std[2*id]+std[2*id+1];
    }

    ll getd(ll id,ll l,ll r,ll u,ll v)
    {
        if(v<l || r<u) return 0;
        if(u<=l && r<=v) return std[id];
        ll mid=(l+r)/2;
        return getd(2*id,l,mid,u,v)+getd(2*id+1,mid+1,r,u,v);
    }

    void sol()
    {
        cin>>n;
        FOR(i,1,n) cin>>a[i].x;
        FOR(i,1,n) cin>>b[i].v,b[i].x=i;
        sort(alla(b,n),cmp1);
        ll res=0;
        FOR(i,1,n)
        {
            if(b[i].v!=b[i-1].v) res++;
            f[i]=res;
            // cout<<b[i].x<<" ";
        }
        FOR(i,1,n) b[i].v=f[i];
        sort(alla(b,n),cmp);
        FOR(i,1,n) a[i].v=b[i].v;
        sort(alla(a,n),cmp);
        // FOR(i,1,n) cout<<a[i].v<<" ";
        // cout<<el;
        // FOR(i,1,n) cout<<a[i].x<<" "<<a[i].v<<el;
        // FOR(i,1,n) cout<<f[i]<<" ";
        // cout<<el;
        ll ans=0;
        FOR(i,1,n)
        {
            ans+=a[i].x*getd(1,1,n,1,a[i].v)-get(1,1,n,1,a[i].v);
            up(1,1,n,a[i].v,a[i].x);upd(1,1,n,a[i].v,1);
            // +cout<<a[i].x*getd(1,1,n,1,a[i].v)-get(1,1,n,1,a[i].v)<<el;
        }
        cout<<ans;
    }
}



// "..."

nnc
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }
    bef();
    if(mlt) cin>>test;
    // cout<<test<<el;
    FOR(i,1,test)
    {
        mnp::sol();
    }
    ieozzool;
}
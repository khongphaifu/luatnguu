#include <bits/stdc++.h>
using namespace std;


#define           TASK  "CHECKPOINT"
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
    ll n,k;
    ll a[N],f[N],st[4*N];

    void build(ll id,ll l,ll r)
    {
        if(l==r)
        {
            st[id]=f[l];return;
        }
        ll mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        st[id]=min(st[2*id],st[2*id+1]);
    }

    ll get(ll id,ll l,ll r,ll u,ll v)
    {
        if(v<l || r<u) return inf;
        if(u<=l && r<=v) return st[id];
        ll mid=(l+r)/2;
        return min(get(2*id,l,mid,u,v),get(2*id+1,mid+1,r,u,v));
    }

    void sol()
    {
        cin>>n>>k;
        vector<ll> v;
        v.pb(0);
        FOR(i,1,n)
        {
            cin>>a[i];f[i]=f[i-1]+a[i];
            if(a[i]<0) v.pb(i);
        }
        build(1,0,n);
        ll ans=0,res=0,d=0;
        FOR(i,1,n)
        {
            if(a[i]<0) res++;
            if(res>k)
            {
                d++;
                res--;
            }
            ans=max(ans,f[i]-get(1,0,n,v[d],i));
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
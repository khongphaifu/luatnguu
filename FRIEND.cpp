// Program link: https://tinhoclk.com/problem/friend
// Program name: v 
#define TASK  "FRIEND"




#include <bits/stdc++.h>
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
using namespace std;


ll mlt=0;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const long long inf = 1e18;
const ll N = 1e6 + 5 , N1 = 2e3 + 5 , MOD = 1e9 , sminf = 1e9;
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
        ll id,ts;
    };

    struct cmp
    {
        bool operator() (bg a,bg b){return a.ts>b.ts;}
    };

    // bool cmp1(bg a,bg b){return a.ts>b.ts;}

    struct bg1
    {
        ll ke,ts; 
    };

    bool cmp1(bg1 a,bg1 b){return a.ke>b.ke;}

    ll n,m,Ha,Sa,Hb,Sb;
    ll f[N],dd[N],d1[N],d2[N],d3[N],d4[N],tv[N],fa[N];
    vector<bg1> g[N];

    void dij(ll s)
    {
        priority_queue<bg,vector<bg>,cmp> h;
        FOR(i,1,n)
        {
            f[i]=1e18,dd[i]=0,tv[i]=-1;
        }
        f[s]=0;h.push({s,f[s]});
        while(!h.empty())
        {
            ll u=h.top().id;h.pop();
            if(dd[u]) continue;
            dd[u]=1;
            for(auto it:g[u])
            {
                ll v=it.ke,ts=it.ts;
                if(f[v]>f[u]+ts && dd[v]==0)
                {
                    f[v]=f[u]+ts;
                    tv[v]=u;
                    h.push({v,f[v]});
                }
            }
        }
    }

    void sol()
    {
        cin>>n>>m>>Ha>>Sa>>Hb>>Sb;
        FOR(i,1,m)
        {
            ll a,b,t;cin>>a>>b>>t;
            g[a].pb({b,t});
            g[b].pb({a,t});
        }
        FOR(i,1,n)
        sort(all(g[i]),cmp1);
        // sort(all(g[i]),cmp);
        dij(Ha);
        ll u=Sa;
        fa[Sa]=f[Sa];
        map<ll,ll> mp;
        mp[Sa]=f[Sa];
        while(u!=-1)
        {
            u=tv[u];
            //cout<<u<<el;
            mp[u]=f[u];
        }
        ll ans=inf;
        dij(Hb);
        u=Sb;
        while(u!=-1)
        {
            u=tv[u];
            if(mp[u] && mp[u]==f[u]) ans=min(ans,mp[u]); 
        }
        if(ans==inf) cout<<-1;
        else cout<<ans;
    }

    void sol1()
    {
        cin>>n>>m>>Ha>>Sa>>Hb>>Sb;
        FOR(i,1,m)
        {
            ll a,b,t;cin>>a>>b>>t;
            g[a].pb({b,t});
            g[b].pb({a,t});
        }
        dij(Ha);
        FOR(i,1,n) d1[i]=f[i];
        dij(Hb);
        FOR(i,1,n) d2[i]=f[i];
        dij(Sa);
        FOR(i,1,n) d3[i]=f[i];
        dij(Sb);
        FOR(i,1,n) d4[i]=f[i];
        ll res=1e18;
        FOR(u,1,n)
        {
            if(d1[u]+d3[u]==d1[Sa] && d2[u]+d4[u]==d2[Sb] && d1[u]==d2[u]) res=min(res,d1[u]);
        }
        if(res==inf) cout<<-1;
        else cout<<res;
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
        mnp::sol1();
    }
    ieozzool;
}
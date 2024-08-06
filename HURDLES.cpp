#include <bits/stdc++.h>
using namespace std;


#define           TASK  "HURDLES"
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

const ll N = 1e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
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

    struct bg1
    {
        ll ke,ts;
    };

    struct cmp
    {
        bool operator() ( bg a, bg b) {return a.ts>b.ts;}
    };

    ll n,m,t;
    ll f[N],dd[N],dp[N1][N1];
    vector<bg1> g[N];

    void DIJ(ll s)
    {
        priority_queue<bg,vector<bg>,cmp> h;
        FOR(i,1,n)
        {
            f[i]=inf,dd[i]=0;
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
                if(f[u]!=-inf && f[v]>max(f[u],ts))
                {
                    f[v]=max(f[u],ts);
                    h.push({v,f[v]});
                }
            }
        }
    }

    void sol()
    {
        cin>>n>>m>>t;
        FOR(i,1,m)
        {
            ll u,v,w;cin>>u>>v>>w;
            g[u].pb({v,w});
            // g[v].pb({u,w});
        }
        FOR(i,1,n)
        {
            DIJ(i);
            FOR(j,1,n)
            {
                dp[i][j]=f[j];
            }
        }
        while(t--)
        {
            ll x,y;cin>>x>>y;
            if(dp[x][y]==inf) cout<<-1<<el;
            else cout<<dp[x][y]<<el;
        }
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
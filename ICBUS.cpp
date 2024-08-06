// khongphaifu - Mai Ngọc Phú - T2K33 - THPT Chuyên Lê Khiết
// VOI... 
// Program link: https://tinhoclk.com/problem/icbus
// Program name: v 
#define TASK  "ICBUS"
// sol:



#include <bits/stdc++.h>
#define             pl  pair<ll,ll>  
#define             pb  push_back  
#define             ll  int
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
const ll N = 1e6 + 5 , N1 = 5e3 + 5 , MOD = 1e9 , sminf = 1e9;
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
        ll u,t,ts;
    };

    struct cmp
    {
        bool operator()(bg u,bg v) { return u.ts>v.ts;}
    };

    
    ll n,k,w;
    ll dd[N1][N1],f[N1][N1],C[N],D[N];
    vector<ll> g[N];


    void DIJ(ll s)
    {
        priority_queue<bg,vector<bg>,cmp> h;
        FOR(i,0,n) FOR(j,0,w)
        {
            f[i][j]=1e9;dd[i][j]=0;
        }
        f[s][D[s]]=C[s];h.push({s,D[s],f[s][D[s]]});
        while(!h.empty())
        {
            ll u=h.top().u;
            ll t=h.top().t;
            h.pop();
            if(dd[u][t]==1) continue;
            dd[u][t]=1;
            if (f[u][D[u]] > f[u][t] + C[u]) {
                f[u][D[u]] = f[u][t] + C[u];
                h.push({ u, D[u], f[u][D[u]] });
            }
            if(t==0) continue;
            for(auto it:g[u])
            {
                if(!dd[it][t-1])
                {
                    if (f[it][t - 1] > f[u][t]) {
                        f[it][t - 1] = f[u][t];
                        h.push({ it, t - 1, f[it][t - 1] });
                    }
                }
            }
        }
    }

    void sol()
    {
        cin>>n>>k;
        FOR(i,1,n) cin>>C[i]>>D[i],w=max(w,D[i]);
        FOR(i,1,k)
        {
            ll x,y;cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
        DIJ(1);
        ll res=sminf;
        FOR(i,0,w) res=min(res,f[n][i]);
        cout<<res;

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
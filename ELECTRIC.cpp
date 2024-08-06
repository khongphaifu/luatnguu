

#include <bits/stdc++.h>
using namespace std;


#define           TASK  "ELECTRIC"
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

const ll N = 4e5 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
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
        ll u,v,w;
    };

    bool cmp( bg a , bg b )
    {
        return a.w<b.w;
    }

    ll n , m , q , ans;
    ll f[N] , visit[N],  dp[N1][N1] , dp1[N1][N1];
    bg e[N];
    vector<ll> g[N1];

    ll goc(ll x)
    {
        if(f[x]<0) return x;
        if(x>m) return 0;
        return f[x]=goc(f[x]);
    }

    void HN(ll x, ll y)
    {
        x=goc(x),y=goc(y);
        if(x==y)return;
        ll t=f[x]+f[y];
        if(f[x]>f[y]) f[x]=t,f[y]=x;
        else f[y]=t,f[x]=y;
    }

    void DFS(ll x,ll i)
    {
        visit[x]=i;
        for(auto it : g[x])
        {
            if(visit[it]!=i)
            {
                ans=max(ans,dp1[x][it]);
                dp[i][it]=ans;
                DFS(it,i);
            }
            ans=dp[i][it];
        }
    }
    
    void sol()
    {
        cin>>n>>m;
        FOR(i,1,m)
        {
            ll u,v,w;cin>>u>>v>>w;
            e[i]={u,v,w};
        }
        sort(alla(e,m),cmp);
        ll sum=0, sl=0;
        FOR(i,1,m) f[i]=-1;
        FOR(i,1,m)
        {
            if(goc(e[i].u)!=goc(e[i].v))
            {
                sl++;
                sum+=e[i].w;
                // cout<<e[i].u<<" "<<e[i].v<<el;
                g[e[i].u].pb(e[i].v);
                dp1[e[i].u][e[i].v]=e[i].w;
                g[e[i].v].pb(e[i].u);
                dp1[e[i].v][e[i].u]=e[i].w;
                HN(e[i].u,e[i].v);
                if(sl==n-1) break;
            }
        }
        // for(auto it:g[4]) cout<<it.fi<<" "<<it.se<<el;
        FOR(i,1,n)
        {
            ans=1;
            DFS(i,i);
        }
        cin>>q;
        // cout<<sum<<el;
        while(q--)
        {
            ll a,b;cin>>a>>b;
            cout<<sum-dp[a][b]<<el;
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


#include <bits/stdc++.h>
using namespace std;


#define           TASK  "DDK"
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
    ll n,m,timedfs,time,ans;
    vector<ll> g[N];
    ll num[N],low[N],d[N],num1[N],low1[N];

    void dfs(ll x,ll pre)
    {
        num[x]=low[x]=++timedfs;
        for(auto it:g[x])
        {
            if(it==pre) continue;
            if(!num[it])
            {
                dfs(it,x);
                low[x]=min(low[x],low[it]);
                if(num[it]==low[it])
                {
                    ans+=(n-d[it])*d[it];
                    // cout<<it<<el;
                }
            }
            else low[x]=min(num[it],low[x]);
        }
    }

    void dfs1(ll x,ll pre)
    {
        low1[x]=num1[x]=++time;
        for(auto it:g[x])
        {
            if(it==pre) continue;
            if(!num1[it])
            {
                dfs1(it,x);
                low1[x]=min(low1[x],num1[it]);
                d[x]+=d[it];
            }
            else low1[x]=min(low1[x],num1[it]);
        }
    }
    
    void sol()
    {
        cin>>n>>m;
        FOR(i,1,m)
        {
            ll x,y;cin>>x>>y;
            g[x].pb(y);g[y].pb(x);
        }
        FOR(i,1,n) d[i]=1;
        dfs1(1,1);
        dfs(1,1);
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
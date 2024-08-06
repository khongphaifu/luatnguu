#include <bits/stdc++.h>
using namespace std;


#define           TASK  "CAPITAL"
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
    ll n,m,t;
    ll num[N],low[N],joint[N];
    vector<ll> g[N];

    void dfs(ll u,ll pre)
    {
        ll child=0;
        num[u]=low[u]=++t;
        for(auto it:g[u])
        {
            if(it==pre) continue;
            if(!num[it])
            {
                dfs(it,u);
                child++;
                low[u]=min(low[u],low[it]);
                if(u==pre && child>1) joint[u]++;
                else if(low[it]>=num[u]) joint[u]++;
            }
            else low[u]=min(low[u],num[it]);
        }
    }

    void sol()
    {
        cin>>n>>m;
        FOR(i,1,m)
        {
            ll x,y;cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
        ll res=0;
        FOR(i,1,n)
        {
            if(!num[i])
            {
                joint[i]--;
                res++;
                dfs(i,0);
            }
        }
        // cout<<res<<el;
        ll ans1=-inf,ans2;
        FOR(i,1,n)
        {
            // cout<<joint[i]<<el;
            if(g[i].size()==0) joint[i]=-1;
            if(joint[i]+res>ans1)
            {
                ans1=joint[i]+res;ans2=i;
            }
        }
        cout<<ans1<<" "<<ans2;
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

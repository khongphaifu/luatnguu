#include <bits/stdc++.h>
using namespace std;


#define           TASK  "BLUEHOUSE"
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

const ll N = 5e5 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll n,m,stt,res,ans;
    ll num[N],low[N],f[N];
    vector<ll> g[N],gr[N];
    map<pair<ll,ll>,ll> mp;

    void dfs(ll u,ll pre)
    {
        num[u]=low[u]=++stt;
        for(auto it:g[u])
        {
            if(it==pre) continue;
            if(!num[it])
            {
                dfs(it,u);
                low[u]=min(low[u],low[it]);
                if(low[it]==num[it])
                {
                    mp[{u,it}]++;mp[{it,u}]++;
                }

            }
            else low[u]=min(low[u],num[it]);
        }
    }

    void dfs1(ll u,ll pre)
    {
        num[u]=low[u]=++stt;
        f[u]=res;
        for(auto it:g[u])
        {
            if(it==pre) continue;
            if(!num[it] && !mp[{it,u}])
            {
                dfs1(it,u);
                low[u]=min(low[u],low[it]);
            }
            else  low[u]=min(low[u],num[it]);
        }
    }

    void dfs2(ll u,ll pre)
    {
        num[u]=low[u]=++stt;
        if(gr[u].size()==1) ans++;
        for(auto it:gr[u])
        {
            if(it==pre) continue;
            if(!num[it])
            {
                dfs2(it,u);
                low[u]=min(low[u],low[it]);
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
            g[x].pb(y);g[y].pb(x);
        }
        FOR(i,1,n)
        {
            if(!num[i]) dfs(i,0);
        }
        // for(auto it:mp)
        // {
        //     cout<<it.fi.fi<<" "<<it.fi.se<<el;
        // }
        stt=0;
        FOR(i,1,n) num[i]=low[i]=0;
        FOR(i,1,n)
        {
            if(!num[i]) res++,dfs1(i,0);
        }
        stt=0;
        // cout<<res<<el;
        FOR(i,1,n) num[i]=low[i]=0;
        // FOR(i,1,n) cout<<f[i]<<" ";
        // cout<<el;
        FOR(i,1,n)
        {
            for(auto it:g[i])
            {
                if(f[it]!=f[i])
                {
                    // gr[f[it]].pb(f[i]);
                    gr[f[i]].pb(f[it]);
                }
            }
        }
        FOR(i,1,res)
        {
            // for(auto it:g[i]) cout<<it<<" ";
            // cout<<el;
            if(gr[i].size()==1) ans++;
        }
        // dfs2(1,0);
        cout<<(ans/2) + (ans%2!=0);

    }
}



// "..."

nnc
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(0)); 
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
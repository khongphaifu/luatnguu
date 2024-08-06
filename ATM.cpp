#include <bits/stdc++.h>
using namespace std;


#define           TASK  "ATM"
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
    ll n,m,s1,p,stt,scc;
    ll a[N],game[N],game1[N],num[N],low[N],del[N],f[N],var[N],ans[N],res[N];
    vector<ll> g[N],gr[N];
    stack<ll> s;
    queue<ll> ds;
    bool check=false;

    void dfs(ll u)
    {
        num[u]=low[u]=++stt;
        s.push(u);
        for(auto it:g[u])
        {
            if(del[it]) continue;
            if(!num[it])
            {
                dfs(it);
                low[u]=min(low[u],low[it]);
            }
            else low[u]=min(low[u],num[it]);
        }
        if(num[u]==low[u])
        {
            scc++;
            ll v;
            do
            {
                v=s.top();
                s.pop();
                del[v]=scc;
                if(game[v]) game1[scc]++;
                if(v==s1 && check==false) s1=scc,check=true;
            }
            while(u!=v);
        }
    }

    void sol()
    {
        cin>>n>>m;
        FOR(i,1,m)
        {
            ll x,y;cin>>x>>y;
            g[x].pb(y);
        }
        FOR(i,1,n) cin>>a[i];
        cin>>s1>>p;
        FOR(i,1,p)
        {
            ll x;cin>>x;game[x]++;
        }
        FOR(i,1,n)
        {
            if(!num[i]) dfs(i);
        }
        FOR(i,1,n)
        {
            f[del[i]]+=a[i];
            for(auto it:g[i])
            {
                if(del[i]!=del[it])
                {
                    gr[del[it]].pb(del[i]);
                    var[del[i]]++;
                }
            }
        }
        FOR(i,1,n)
        {
            if(!var[i]) ds.push(i);
            ans[del[i]]=f[del[i]];
        }
        ll ans1=0;
        while(!ds.empty())
        {
            ll u=ds.front();ds.pop();
            if(u==s1 && (res[u]==1 || game1[u])) ans1=max(ans1,ans[u]);
            for(auto it:gr[u])
            {
                var[it]--;
                if(res[u] || game1[u]) ans[it]=max(ans[it],ans[u]+f[it]),res[it]=1;
                if(!var[it]) ds.push(it);
            }
        }
        cout<<ans1;
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
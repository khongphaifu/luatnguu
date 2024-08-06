#include <bits/stdc++.h>
using namespace std;


#define           TASK  "CNTPATH"
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

const ll N = 1e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9 +7 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll n,m,scc,stt;
    ll num[N],low[N],del[N],var[N],f[N];
    vector<ll> g[N],gr[N];
    stack<ll> st;
    queue<ll> ds;

    void dfs(ll u)
    {
        num[u]=low[u]=++stt;
        st.push(u);
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
            ll v;
            scc++;
            do
            {
                v=st.top();
                st.pop();
                del[v]=scc;
                // dd[scc]++;
                if(v==n) f[scc]=1;
            }
            while(v!=u);
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
        FOR(i,1,n)
        {
            if(!del[i]) dfs(i);
        }
        FOR(i,1,n)
        {
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
            if(!var[del[i]]) ds.push(del[i]);
        }
        while(!ds.empty())
        {
            ll u=ds.front();ds.pop();
            for(auto it:gr[u])
            {
                var[it]--;
                f[it]=(f[it]+f[u])%MOD;
                if(!var[it]) ds.push(it);
            }
        }
        cout<<f[del[1]];
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
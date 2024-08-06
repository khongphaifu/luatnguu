#include <bits/stdc++.h>
using namespace std;


#define           TASK  "ALIAS"
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

const ll N = 1e7 + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll n,m,q;
    ll f[N],dd[N];
    ll dp[N1][N1];

    struct bg1
    {
        ll ke,ts;
    };

    struct bg
    {
        ll id,ts;
    };

    struct cmp
    {
        bool operator() (bg a,bg b) {return a.ts>b.ts;}
    };

    vector<bg1> g[N]; 

    void DIJ(ll s)
    {
        priority_queue<bg,vector<bg>,cmp> h;
        FOR(i,1,n)
        {
            dd[i]=0;f[i]=inf;
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
                    h.push({v,f[v]});
                }
            }
        }
    }


    void sol()
    {
        map<string,ll> mp;
        cin>>n>>m;
        ll res1=0;
        FOR(i,1,m)
        {
            string x,y;cin>>x>>y;
            ll res;cin>>res;
            if(mp[x]==0)
            {
                ++res1;
                mp[x]=res1;
            }
            if(mp[y]==0)
            {
                ++res1;
                mp[y]=res1;
            }
            g[mp[x]].pb({mp[y],res});
            // g[mp[y]].pb({mp[x],res});
        }
        // FOR(i,1,n)
        // {
        //     for(auto it:g[i]) cout<<it.ke<<" "<<it.ts<<" ";
        //     cout<<el;
        // }
        // DIJ(1);
        FOR(i,1,n)
        {
            // cout<<f[i]<<" ";
            DIJ(i);
            FOR(j,1,n) dp[i][j]=f[j];
        }
        cin>>q;
        while(q--)
        {
            string x,y;cin>>x>>y;
            // cout<<mp[x]<<" "<<mp[y]<<el;
            if(dp[mp[x]][mp[y]]==inf) cout<<"Roger"<<el;
            else cout<<dp[mp[x]][mp[y]]<<el;
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
    ieozzool
}
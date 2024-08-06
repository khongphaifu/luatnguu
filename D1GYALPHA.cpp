#include <bits/stdc++.h>
using namespace std;


#define           TASK  "D1GYALPHA"
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

const ll N = 1e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll n,m;
    ll f[N],dd[N],dd1[N];
    vector<ll> g[N];

    void dij(ll s,ll res)
    {
        queue<ll> h;
        FOR(i,1,n)
        {
            f[i]=inf;dd[i]=0;
        }
        f[s]=0;h.push(s);
        while(!h.empty())
        {
            ll u=h.front();h.pop();
            // if(dd[u]==1)  continue;
            // dd[u]=1;
            for(auto it:g[u])
            {
                ll v=it,ts;
                if(dd1[it]!=dd1[res]) ts=4;
                else ts=1;
                if(f[v]>f[u]+ts && dd[v]==0)
                {
                    f[v]=f[u]+ts;
                    h.push(v);
                }
            }
        }
    }

    void sol()
    {
        cin>>n>>m;
        string s;cin>>s;
        s='#'+s;
        FOR(i,1,n)
        {
            if(s[i]=='Y') dd1[i]=1;
        }
        FOR(i,1,m)
        {
            ll x,y;cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x); 
        }
        ll ansY=0,ansG=0;
        FOR(i,1,n)
        {
            dij(i,i);
            FOR(j,i+1,n)
            {
                if(dd1[i]==dd1[j])
                {
                    if(dd1[i]==1) ansY+=f[j];
                    else ansG+=f[j];
                }
            }
        }
        cout<<ansG<<" "<<ansY;
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
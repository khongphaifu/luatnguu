#include <bits/stdc++.h>
using namespace std;


#define           TASK  "EVA"
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

const ll N = 4e6 + 5 , N1 = 2e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll n,m,k;
    ll d[N],a[N],f[N];
    vector<ll> g[N];

    void bfs(ll u)
    {
        queue<ll> q;
        q.push(u);
        // d[u]=1;
        f[u]=0;
        while(!q.empty())
        {
            ll x=q.front();q.pop();
            for(auto it:g[x])
            {
                if(d[it]==2) continue;
                if(d[it])
                {
                    f[it]=0;
                    q.push(it);   
                }
                else if(!d[it] && f[it]>f[x]+1)
                {
                    f[it]=f[x]+1;
                    q.push(it);
                }
            }
            if(d[x]) d[x]=2;
        }

    }

    void sol()
    {
        cin>>n>>k;
        FOR(i,1,k)
        {
            cin>>a[i];d[a[i]]=1;
        }
        // cout<<a[1]<<el;
        cin>>m;
        // cout<<m<<el;
        FOR(i,1,n) f[i]=inf;
        FOR(i,1,m)
        {
            ll x,y;cin>>x>>y;
            g[x].pb(y);g[y].pb(x);
        }
        bfs(a[1]);
        FOR(i,1,n) cout<<f[i]<<" ";
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
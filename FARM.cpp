#include <bits/stdc++.h>
using namespace std;


#define           TASK  "FARM"
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

    struct bg
    {
        ll x,y;
    };

    bg H[N],G[N];
    ll f[1007][1007],g[1007][1007];

    ll kc(bg a,bg b)
    {
        return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    }

    void sol()
    {
        cin>>n>>m;
        FOR(i,1,n) cin>>H[i].x>>H[i].y;
        FOR(i,1,m) cin>>G[i].x>>G[i].y;
        FOR(i,0,n) FOR(j,0,m) f[i][j]=inf,g[i][j]=inf;
        f[1][0]=0;
        FOR(i,2,n) f[i][0]=f[i-1][0]+kc(H[i],H[i-1]);
        FOR(i,1,n) FOR(j,1,m)
        {
            f[i][j]=min(f[i-1][j] +kc(H[i-1],H[i]),g[i-1][j]+kc(H[i],G[j]));
            g[i][j]=min(g[i][j-1]+ kc(G[j],G[j-1]),f[i][j-1]+kc(H[i],G[j]));
        }
        cout<<f[n][m];
        
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
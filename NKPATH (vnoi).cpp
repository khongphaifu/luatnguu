#include <bits/stdc++.h>
using namespace std;


#define           TASK  "NKPATH"
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
    ll dp[107][107],f[107][107];

    void sol()
    {
        cin>>m>>n;
        FOR(i,1,m) FOR(j,1,n) cin>>dp[i][j];
        FOR(i,1,m) f[i][1]=1;
        // FOR(i,1,m)
        // {
        //     FOR(j,1,n) cout<<f[i][j]<<" ";
        //     cout<<el;
        // }
        FOR(i,1,m) FOR(j,1,n)
        {
            FOR(x,1,i) FOR(y,1,min(j,n-1)) if(gcd(dp[i][j],dp[x][y])>1) if(x+y<i+j) f[i][j]=(f[i][j]+f[x][y])%MOD;
        }
        // FOR(i,1,m)
        // {
        //     FOR(j,1,n) cout<<f[i][j]<<" ";
        //     cout<<el;
        // }
        ll ans=0;
        FOR(i,1,m) ans=(ans+f[i][n])%MOD;
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
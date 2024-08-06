#include <bits/stdc++.h>
using namespace std;


#define           TASK  "BOARD cx"
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
    ll m,n;
    ll dp[407][407],dd[407][407];

    void sol()
    {
        cin>>m>>n;
        FOR(i,1,m) FOR(j,1,n) cin>>dp[i][j];
        FOR(i,0,m+1) FOR(j,0,n) dd[i][j]=inf;
        FOR(i,1,m)
        {
            map<ll,ll> mp;
            FOR(j,1,n)
            {
                dd[i][j]=dd[i][j-1];
                if(!mp[dp[i][j]]) mp[dp[i][j]]=j;
                else dd[i][j]=min(mp[dp[i][j]]+1,dd[i][j-1]);
            }
        }
        FOR(i,1,m)
        {
            FOR(j,1,n) if(dd[i][j]==inf) dd[i][j]=0;
        }
        // FOR(i,1,m)
        // {
        //     FOR(j,1,n) cout<<dd[i][j]<<" ";
        //     cout<<el;
        // }
        ll ans=0;
        FOR(i,1,n) FOR(j,1,n)
        {
            ll res=0;
            FOR(k,1,m+1)
            {
                if(dd[k][j]<=i) res++;
                else 
                {
                    ans=max(ans,(j-i+1)*res);
                    res=0;
                }
            }
        }
        cout<<ans<<el;
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
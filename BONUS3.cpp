// Program link: https://tinhoclk.com/problem/bonus3
// Program name: v 
#define TASK  "BONUS3"




#include <bits/stdc++.h>
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
using namespace std;


ll mlt=0;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const long long inf = 1e18;
const ll N = 1e6 + 5 , N1 = 2e3 + 5 , MOD = 1e9 , sminf = 1e9;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll n;
    ll dp[107][107];

    ll HCN(ll x1,ll y1,ll x2,ll y2)
    {
        if(x1>x2 || y1>y2) return 0;
        return dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
    }

    void sol()
    {
        cin>>n;
        FOR(i,1,n) FOR(j,1,n)
        {
            ll x;cin>>x;dp[i][j]=x+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
        ll ans=-inf;
        FOR(i,1,n) FOR(j,1,n)
        {
            ll res=0;
            while(i-res>=1 && j-res>=1)
            {
                ll tmp=0;
                ll i1=i-res,j1=j-res;
                ll j2=j,i2=i;
                while(i2>=i1 && j2>=j1)
                {
                    tmp+=HCN(i1,j1,i2,j2)-HCN(i1+1,j1+1,i2-1,j2-1);
                    i1+=2,j1+=2,j2-=2,i2-=2;
                }
                res++;
                // if(tmp==31) cout<<i<<" "<<j<<" "<<res<<el;
                ans=max(ans,tmp);
            }
        }
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
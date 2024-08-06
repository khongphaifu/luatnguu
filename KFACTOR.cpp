#include <bits/stdc++.h>
using namespace std;


#define           TASK  "KFACTOR"
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

const ll N = 1e7 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll k,a,b;
    int nt[N],f[N];
    // set<ll> s[N];

    void sang()
    {
        nt[0]=nt[1]=-1;
        FOR(i,2,k)
        {
            if(nt[i]==0) for(ll j=i;j<=k;j+=i) nt[j]=i;
        }
    }

    

    void sol()
    {
        cin>>k>>a>>b;
        cout<<a<<" "<<b<<el;
        sang();
        ll ans=0;
        // FOR(i,1,k) cout<<nt[i]<<" ";
        // cout<<el;
        FOR(i,a,b) f[i-a]=i;
        // FOR(i,1,b-a+1) cout<<f[i]<<" ";
        // cout<<el;
        FOR(i,2,k)
        {
            if(nt[i]==i)
            {
                for(ll j=(i+a-1)/i *i;j<=b;j+=i)
                {
                    while(f[j-a]%i==0) f[j-a]/=i;

                }
                // cout<<(i+a-1)/i *i<<" ";
                // cout<<i<<" ";
            }
        }
        FOR(i,0,b-a)
        {
            if(f[i]<=k) ans++;
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
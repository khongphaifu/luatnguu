#include <bits/stdc++.h>
using namespace std;


#define           TASK  "VBLOCKS - Blocks"
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

const ll N = 1e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll l,s,d,k;
    ll a[N],b[N],e[N],ne[N],f[N],fac[N];
    
    void sol()  
    {
        cin>>l>>s>>d>>k;
        ll res=0;
        FOR(j,1,k)
        {
            ll i,d1;cin>>i>>d1;
            if(d1==1) e[i]++,res++;
            else ne[i]++;
        }
        FOR(i,1,l) e[i]+=e[i-1],ne[i]+=ne[i-1];
        ll ans=-1;
        FOR(i,s,l)
        {

            if(ne[i]-ne[i-s]>0)
            {
                f[i]=max(f[i],f[i-1]);fac[i]=max(fac[i],fac[i-1]);
                continue;
            }
            f[i]=f[i-s-d]+1;
            fac[i]=fac[i-s-d]+e[i]-e[i-s];
            if(fac[i]==res) ans=max(ans,f[i]);
            f[i]=max(f[i],f[i-1]);fac[i]=max(fac[i],fac[i-1]);
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
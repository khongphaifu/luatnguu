#include <bits/stdc++.h>
using namespace std;


#define           TASK  "SPSEQ"
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
    ll n;
    ll a[N],l[N],r[N],fl[N],fr[N];

    void sol()
    {
        cin>>n;
        FOR(i,1,n) cin>>a[i],fr[i]=1e18,fl[i]=1e18;
        FOR(i,1,n)
        {
            ll j=lower_bound(alla(fl,n),a[i])-fl;
            l[i]=j;
            fl[j]=a[i];
        }
        // FOR(i,1,n) cout<<l[i]<<" ";
        // cout<<el;
        FORD(i,n,1)
        {
            ll j=lower_bound(alla(fr,n),a[i])-fr;
            r[i]=j;
            fr[j]=a[i];
        }
        // FOR(i,1,n) cout<<r[i]<<" ";
        // cout<<el;
        ll ans=1;
        FOR(i,1,n) ans=max(ans,2*min(l[i],r[i])-1);
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
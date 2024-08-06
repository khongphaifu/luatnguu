#include <bits/stdc++.h>
using namespace std;


#define           TASK  "WEIGHT"
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

const ll N = 4e5 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
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
    ll a[N],R[N],L[N],x[N],y[N];
    stack<ll> s;

    void cls()
    {
        while(!s.empty()) s.pop();
    }

    void sol()
    {
        cin>>n;
        ll ans=0;
        FOR(i,1,n) cin>>a[i];
        s.push(0);
        a[0]=1e18;
        FOR(i,1,n)
        {
            while(!s.empty() && a[i]>=a[s.top()]) s.pop();
            L[i]=i-s.top();
            s.push(i);
        }
        // FOR(i,1,n) cout<<L[i]<<" ";
        // cout<<el;
        a[n+1]=1e18;
        cls();
        s.push(n+1);
        FORD(i,n,1)
        {
            while(!s.empty() && a[i]>a[s.top()]) s.pop();
            R[i]=s.top()-i;
            s.push(i);
        }
        // FOR(i,1,n) cout<<R[i]<<" ";
        // cout<<el;
        FOR(i,1,n) x[i]=L[i]*R[i];
        // cout<<ans<<el;
        a[0]=-1e18;
        cls();
        s.push(0);
        FOR(i,1,n)
        {
            while(!s.empty() && a[i]<=a[s.top()]) s.pop();
            L[i]=i-s.top();
            s.push(i);
        }
        // FOR(i,1,n) cout<<L[i]<<" ";
        // cout<<el;
        a[n+1]=-1e18;
        cls();
        s.push(n+1);
        FORD(i,n,1)
        {
            while(!s.empty() && a[i]<a[s.top()]) s.pop();
            R[i]=s.top()-i;
            s.push(i);
        }
        FOR(i,1,n) y[i]=L[i]*R[i];
        FOR(i,1,n) ans+=a[i]*(x[i]-y[i]);
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
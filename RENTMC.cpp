// Author : khongphaifu - Mai Ngọc Phú
// T2K33 THPT Chuyên Lê  

#include <bits/stdc++.h>
using namespace std;


#define           TASK  "RENTMC"
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
    struct bg
    {
        ll x,y;
    };

    bool cmp(bg a, bg b)
    {
        if(a.y==b.y) return a.x<b.x;
        return a.y<b.y;
    }

    ll n;
    ll f[N],lt[N];
    bg a[N];

    void sol()
    {
        cin>>n;
        FOR(i,1,n) cin>>a[i].x>>a[i].y;
        sort(alla(a,n),cmp);
        FOR(i,1,n) lt[i]=a[i].y;
        FOR(i,1,n)
        {
            ll j=upper_bound(lt+1,lt+i+1,a[i].x)-lt;
            j--;
            f[i]=max(f[i-1],f[j]+a[i].y-a[i].x);
        }
        cout<<f[n];
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
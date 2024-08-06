// Program link: https://tinhoclk.com/problem/hangpics
// Program name: v 
#define TASK  "HANGPICS"




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
    ll a1,a2,a3,b1,b2,b3;

    void sol()
    {
        cin>>a1>>b1>>a2>>b2>>a3>>b3;
        if(a2+a3<=a1 && max(b2,b3)<=b1) cout<<"YES";
        else if(b2+b3<=a1 && max(a2,a3)<=b1) cout<<"YES";
        else if(a2+a3<=b1 && max(b2,b3)<=a1) cout<<"YES";
        else if(b2+b3<=b1 && max(a2,a3)<=a1) cout<<"YES";
        else if(a2+b3<=a1 && max(b2,a3)<=b1) cout<<"YES";
        else if(a2+b3<=b1 && max(b2,a3)<=a1) cout<<"YES";
        else if(a3+b2<=b1 && max(b3,a2)<=a1) cout<<"YES";
        else if(a3+b2<=a1 && max(b3,a2)<=b1) cout<<"YES";
        else cout<<"NO";

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
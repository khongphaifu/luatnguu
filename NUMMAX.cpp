/**/

int mlt=0;
int test=1;

#include <bits/stdc++.h>
using namespace std;


#define           TASK  "NUMMAX"
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


ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const ll N = 5e5 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}


void bef()
{
    
}

namespace mnp
{   
    ll n,b;
    ll a[N],l[N],r[N];

    void sol()
    {
        cin>>n>>b;
        FOR(i,1,n) cin>>a[i];
        stack<ll> s;
        a[0]=1e18;
        s.push(0);
        FOR(i,1,n)
        {
            while(!s.empty() && a[i]>a[s.top()]) s.pop();
            l[i]=i-s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        a[n+1]=1e18;
        s.push(n+1);
        FORD(i,n,1)
        {
            while(!s.empty() && a[i]>=a[s.top()]) s.pop();
            r[i]=s.top()-i;
            s.push(i);
        }
        ll ans=0;
        FOR(i,1,n)
        {
            if(a[i]==b) ans+=l[i]*r[i];
        }
        cout<<ans;

    }
}



// "..."

nnc
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }
    bef();
    if(mlt)
    {
        cin>>test;
        // cin.ignore();
    }
    FOR(i,1,test)
    {
        mnp::sol();
    }
    ieozzool;
}
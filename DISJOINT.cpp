int mlt=0;
int test=1;

#include <bits/stdc++.h>
using namespace std;


#define           TASK  "DISJOINT"
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

const ll N = 1e6 + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
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
    ll a[N];
    

    
    
    void sol()
    {
        cin>>n>>m;
        FOR(i,1,m)
        {
            ll x,u,v;
            cin>>x>>u>>v;
            if(x==1)
            {
                if(a[u]==0 && a[v]==0) a[u]=a[v]=u;
                else if(a[u]==0) a[u]=a[v];
                else if(a[v]==0) a[v]=a[u];
                else
                {
                    ll tmp=a[v];
                    FOR(j,1,n)
                    {
                        if(a[j]==tmp) a[j]=a[u];
                    }
                }
            }
            else
            {
                if(a[u]==a[v] && a[u]!=0) cout<<1<<el;
                else cout<<0<<el;
            }
        }
        // FOR(i,1,n) cout<<a[i]<<" ";
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
    FOR(i,1,test)
    {
        mnp::sol();
    }
    ieozzool;
}
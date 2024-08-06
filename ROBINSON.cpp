// khongphaifu - Mai Ngọc Phú - T2K33 - THPT Chuyên Lê Khiết
// VOI... 
// Program link: https://tinhoclk.com/problem/robinson
// Program name: v 
#define TASK  "ROBINSON"
// sol: gọi f[i][j] là thời gian ngắn nhất tới i với hộ hư hại là j
//



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
    struct bg
    {
        ll id,t,h;
    };

    struct cmp
    {
        bool operator() (bg a,bg b){return a.t>b.t;}
    };

    struct bg1
    {
        ll ke,t,h;
    };

    ll k,n,m,A,B;
    ll f[N1][N1],dd[N1][N1];
    vector<bg1> g[N];

    void dij(ll s)
    {
        priority_queue<bg,vector<bg>,cmp> h;
        FOR(i,1,n) FOR(j,0,k)
        {
            f[i][j]=1e18,dd[i][j]=0;
        }
        // ll tmp=g[s].h;
        f[s][0]=0,h.push({s,f[s][0],0});
        while(!h.empty())
        {
            ll u=h.top().id;
            ll t=h.top().h;
            h.pop();
            if(dd[u][t]) continue;
            dd[u][t]=1;
            for(auto it:g[u])
            {
                ll v=it.ke,t1=it.t,h1=it.h;
                if(f[v][t+h1]>f[u][t]+t1)
                {
                    f[v][t+h1]=f[u][t]+t1;
                    h.push({v,f[v][t+h1],t+h1});
                }
            }
        }
    }

    void sol()
    {
        cin>>k>>n>>m;
        FOR(i,1,m)
        {
            ll a,b,t,h;
            cin>>a>>b>>t>>h;
            g[a].pb({b,t,h});
            g[b].pb({a,t,h});
        }
        cin>>A>>B;
        dij(A);
        // FOR(i,1,n)
        // {
        //     FOR(j,1,k) cout<<f[i][j]<<" ";
        //     cout<<el;
        // }
        ll ans=inf;
        FOR(i,0,k-1) ans=min(ans,f[B][i]);
        if(ans==inf) cout<<-1;
        else cout<<ans;
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
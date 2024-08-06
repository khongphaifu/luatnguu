// khongphaifu - Mai Ngọc Phú - T2K33 - THPT Chuyên Lê Khiết
// VOI... 
// Program link: https://tinhoclk.com/problem/kmtravel
// Program name: v 
#define TASK  "KMTRAVEL"
// sol: xây 2 cái dij :) đi từ 1 và đi từ n
// tìm cạnh có trọng số lớn nhất trong quá trình đi từ 1 đến n qua cạnh i (1 -> n)
// kqbt : min(f[i]+f1[i]-res+res/2)



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
        ll id,t;
    };

    struct cmp
    {
        bool operator() (bg a,bg b){return a.t>b.t;}
    };

    struct bg1
    {
        ll ke,ts;
    };

    ll n,m;
    ll f[N],dd[N],f1[N],dd1[N],lt1[N],lt[N];
    vector<bg1> g[N],g1[N];
    map<pair<ll,ll>,ll> mp;

    void dij(ll s)
    {
        priority_queue<bg,vector<bg>,cmp> h;
        FOR(i,1,n)
        {
            f[i]=1e18,dd[i]=0;
        }
        // ll tmp=g[s].h;
        f[s]=0,h.push({s,f[s]});
        while(!h.empty())
        {
            ll u=h.top().id;
            h.pop();
            if(dd[u]) continue;
            dd[u]=1;
            for(auto it:g[u])
            {
                ll v=it.ke,ts=it.ts;
                if(f[v]>f[u]+ts)
                {
                    f[v]=f[u]+ts;
                    lt[v]=max(lt[u],ts);
                    h.push({v,f[v]});
                }
            }
        }
    }
    void dij1(ll s)
    {
        priority_queue<bg,vector<bg>,cmp> h;
        FOR(i,1,n)
        {
            f1[i]=1e18,dd1[i]=0;
        }
        // ll tmp=g[s].h;
        f1[s]=0,h.push({s,f1[s]});
        while(!h.empty())
        {
            ll u=h.top().id;
            h.pop();
            if(dd1[u]) continue;
            dd1[u]=1;
            for(auto it:g1[u])
            {
                ll v=it.ke,ts=it.ts;
                if(f1[v]>f1[u]+ts)
                {
                    f1[v]=f1[u]+ts;
                    lt1[v]=max(lt1[u],ts);
                    h.push({v,f1[v]});
                }
            }
        }
    }

    void sol()
    {
        cin>>n>>m;
        FOR(i,1,m)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            g[x].pb({y,z});
            g1[y].pb({x,z});
            mp[{x,y}]=z;
        }
        dij(1);
        dij1(n);
        ll ans=inf;
        FOR(i,1,n)
        {
            ll res=max(lt1[i],lt[i]);
            // cout<<res<<el;
            ans=min(ans,f[i]+f1[i]-res+res/2);
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
#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb  push_back  
#define ll  long long
#define el  "\n"
#define alla(a,n)  a+1,a+n+1
#define fi first
#define se second
#define all(v)  v.begin(),v.end()
#define fu(i,a,b)  for(ll i=a;i<=b;i++)
#define fud(i,a,b)  for(ll i=a;i>=b;i--)

const ll MOD=1e9+7 ;//1234567891;
const ll inf=1e18;
const ll base = 311;
const ll N=1e6+5;
const ll N1=1e3+5;

template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

/*
-----------------------------------------
🛸    🌎    ★    🛰    °    🚀    ✯
    ★     °   ☄    ✯    ★    °    🪐
✯    🚀    •　  🌓   °    🛰　  •   ☄
_________________________________________
*/

/// ===================================== - MAIN - ===================================== ///
struct bg
{
    ll id,ts;
};

struct cmp
{
    bool operator() (bg a,bg b){return a.ts>b.ts;}
};

struct bg1
{
    ll ke,ts;
};

ll n,m;
vector<bg1> g[N];
ll f[N],dd[N],cnt[N],mi[N],ma[N];

void dij(ll s)
{

    priority_queue<bg,vector<bg>,cmp> h;
    fu(i,1,n)
    {
        f[i]=inf;
        mi[i]=inf;
        ma[i]=-inf;
    }
    f[s]=0;mi[s]=0;ma[s]=0;
    cnt[s]=1;
    h.push({s,f[s]});
    while(!h.empty())
    {
        ll u=h.top().id;
        h.pop();
        if(dd[u]) continue;
        dd[u]=1;
        for(auto it:g[u])
        {
            ll v=it.ke,ts=it.ts;
            if(f[v]>f[u]+ts && !dd[v])
            {
                f[v]=f[u]+ts;
                mi[v]=mi[u]+1;
                ma[v]=ma[u]+1;
                cnt[v]=cnt[u];
                h.push({v,f[v]});
            }
            else if(f[v]==f[u]+ts)
            {
                mi[v]=min(mi[v],mi[u]+1);
                ma[v]=max(ma[v],ma[u]+1);
                cnt[v]=(cnt[v]+cnt[u])%MOD;
            }
        }
    }
}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>m;
    fu(i,1,m)
    {
        ll u,v,w;cin>>u>>v>>w;
        g[u].pb({v,w});
    }
    dij(1);
    cout<<f[n]<<" "<<cnt[n]<<" "<<mi[n]<<" "<<ma[n];


    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
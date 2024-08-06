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

ll n,q,k;
vector<ll> g[N];
ll p[N][31],h[N];

void dfs(ll u,ll pre)
{
    for(auto it:g[u])
    {
        if(it==pre) continue;
        h[it]=h[u]+1;
        p[it][0]=u;
        dfs(it,u);
    }
}

void pre()
{
    fu(i,1,k)
    {
        fu(u,1,n) p[u][i]=p[p[u][i-1]][i-1];
    }
}

ll lca(ll u,ll v)
{
    if(h[u]<h[v]) swap(u,v);
    fud(j,k,0)
    {
        if(h[p[u][j]]>=h[v] && h[p[u][j]]>0) u=p[u][j];
    }
    fud(j,k,0)
    {
        if(p[u][j]!=p[v][j])
        {
            u=p[u][j];
            v=p[v][j];
        }
    }
    if(u==v) return u;
    return p[u][0];
}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>q;
    k=log2(n);
    fu(i,2,n)
    {
        ll x;cin>>x;
        g[x].pb(i);
        g[i].pb(x);
    }
    dfs(1,0);
    p[1][0]=1;
    pre();
    while(q--)
    {
        ll x,y;cin>>x>>y;
        cout<<lca(x,y)<<el;
    }
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
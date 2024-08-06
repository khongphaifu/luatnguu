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
    ll x,id;
};

ll n,q,d;
vector<ll> g[N];
vector<bg> v[N];
ll ans[N],dd[N];

void dfs(ll u,ll pre)
{
    d++;
    dd[d]=u;
    for(auto it:v[u])
    {
        if(d-it.x>0)ans[it.id]=dd[d-it.x];
        else ans[it.id]=-1;
    }
    for(auto it:g[u])
    {
        if(it==pre) continue;
        dfs(it,u);
    }
    dd[d]=0;
    d--;
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
    fu(i,2,n)
    {
        ll x;cin>>x;
        g[x].pb(i);
        g[i].pb(x);
    }

    fu(i,1,q)
    {
        ll x,y;cin>>x>>y;
        v[x].pb({y,i});
    }
    dfs(1,0);
    fu(i,1,q) cout<<ans[i]<<el;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
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

ll n,m,stt,scc;
vector<ll> g[N],gr[N];
ll coin[N],var[N],num[N],low[N],del[N],f[N],dd[N];
stack<ll> s;

void dfs(ll u)
{
    num[u]=low[u]=++stt;
    s.push(u);
    for(auto it:g[u])
    {
        if(del[it]) continue;
        if(!num[it])
        {
            dfs(it);
            low[u]=min(low[it],low[u]);
        }
        else low[u]=min(low[u],num[it]);
    }

    if(low[u]==num[u])
    {
        scc++;
        ll v;
        do
        {
            v=s.top();
            s.pop();
            del[v]=scc;
        }
        while(u!=v);
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
    fu(i,1,n) cin>>coin[i];
    fu(i,1,m)
    {
        ll x,y;cin>>x>>y;
        g[x].pb(y);
    }
    fu(i,1,n) if(!del[i]) dfs(i);
    fu(i,1,n)
    {
        f[del[i]]+=coin[i];
    }
    fu(i,1,scc)
    {
        dd[i]=f[i];
    }
    map<pair<ll,ll>,ll> mp;
    fu(i,1,n)
    {
        for(auto it:g[i])
        {
            ll u=del[i],v=del[it];
            if(u!=v && !mp[{u,v}])
            {
                mp[{u,v}]=1;
                mp[{v,u}]=1;
                gr[v].pb(u);
                var[u]++;
            }
        }
    }
    queue<ll> ds;
    fu(i,1,scc)
    {
        if(!var[i]) ds.push(i);
    }

    while(!ds.empty())
    {
        ll u=ds.front();
        ds.pop();
        // f[u]=
        for(auto it:gr[u])
        {
            f[it]=max(f[it],f[u]+dd[it]);
            var[it]--;
            if(!var[it]) ds.push(it);
        }
    }
    ll ans=-inf;
    fu(i,1,n) Maximize(ans,f[i]);
    cout<<ans;
        
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
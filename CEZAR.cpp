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
/*🥑*/
template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}
/*v*/
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

ll n,q,root;
ll sz[N],par[N];
vector<ll> g[N];

void dfs(ll u,ll pre)
{
    sz[u]=1;
    for(auto it:g[u])
    {
        if(it==pre) continue;
        par[it]=u;
        dfs(it,u);
        sz[u]+=sz[it];
    }
}
ll res=1e6;
ll find(ll u,ll pre,ll val)
{
    for(auto it:g[u])
    {
        if(it==pre) continue;
        if(sz[it]*2>=val)
        {
            return find(it,u,val);
        }
    }
    return u;
}

ll ans[N];

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>q;
    fu(i,1,n)
    {
        ll x;cin>>x;
        if(x==0) root=i;
        else
        {
            g[x].pb(i);
            g[i].pb(x);
        }
    }
    dfs(root,0);
    // cout<<sz[root]<<el;
    sz[n+1]=inf;
    fu(i,1,n) res=n+1,ans[i]=find(i,par[i],sz[i]);
    while(q--)
    {
        ll x;cin>>x;
        cout<<ans[x]<<" ";
    } 

    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
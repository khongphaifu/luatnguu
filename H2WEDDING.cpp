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

ll n;
vector<ll> g[N];
ll a,b,dd[N],par[N],f[N];
ll check=0;

void find(ll u,ll pre)
{
    if(u==b) check=1;
    for(auto it:g[u])
    {
        if(it==pre) continue;
        if(check) break;
        find(it,u);
    }
    if(check) dd[u]=1,par[u]=pre; 
}

void dfs(ll u,ll pre)
{
    // f[u]=1;
    for(auto it:g[u])
    {
        if(it==pre || dd[it]==1) continue;
        dfs(it,u);
        f[u]=max(f[it]+1,f[u]);
    }
}

ll res[N];
ll L[N],R[N];

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }
    cin>>n;
    fu(i,1,n-1)
    {
        ll x,y;cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    cin>>a>>b;
    find(a,0);
    fu(i,1,n) f[i]=1;
    fu(i,1,n)
    {
        if(dd[i]) dfs(i,0);
    }
    ll d=0;
    while(b!=0)
    {
        d++;
        res[d]=f[b];
        b=par[b];
    }
    ll ans=-inf;
    R[0]=R[d+1]=1;
    fu(i,1,d)
    {
        L[i]=max(L[i-1],res[i]+i-1);
    }
    fud(i,d,1)
    {
        R[i]=max(R[i+1],res[i]+d-i);
    }
    fu(i,1,d-1)
    {
        ans=max(ans,min(L[i],R[i+1]));
        // if(L[i]+R[i+1]==9)
        // {
        //     cout<<i<<el;;
        // }
    }
    cout<<ans;
    
    // số MOD bro
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb  push_back  
#define ll  int
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
const ll N=1e5+5;
const ll N1=1e3+5;
/*🥑*/
template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}
/*v*/
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll n,k,ans=0;
vector<ll> g[N];
gp_hash_table<ll,ll,custom_hash> f[N];
ll res[N];

void dfs(ll u,ll pre)
{
    f[u][0]=1;
    ll dd=0;
    for(auto it:g[u])
    {
        if(it==pre) continue;
        dfs(it,u);
    }

    for(auto it:g[u])
    {
        if(it==pre) continue;
        if(!dd)
        {
            dd++;
            f[u][0]+=f[it][k-1];
            fu(j,1,k) f[u][j]+=f[it][j-1];
        }
        else
        {
            f[u][0]+=f[it][k-1];
            fu(j,1,k) res[j] = max(f[it][j-1]+f[u][max(j,k-j)],f[u][j]+f[it][max(j-1,k-j-1)]);   
            fu(j,1,k) f[u][j]=res[j], res[j]=0;
        }
    }
    fud(i,k-1,0)
    {
        f[u][i]=max(f[u][i],f[u][i+1]);
    }
    fu(i,0,k)
    {   
        ans=max(ans,f[u][i]);
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

    cin>>n>>k;

    fu(i,1,n-1)
    {
        ll x,y;cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1,0);
    cout<<ans;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
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
    ll u,v,w;
};

ll n,m;
ll f[N];
bg e[N];

bool cmp(bg a,bg b)
{
    return a.w<b.w;
}

ll root(ll u)
{
    return (f[u]<0 ? u : f[u]=root(f[u]));
}

void HN(ll u,ll v)
{
    ll t=f[u]+f[v];
    if(f[u]>f[v])
    {
        f[u]=t;
        f[v]=u;
    }
    else
    {
        f[v]=t;
        f[u]=v;
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
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(alla(e,m),cmp);
    fu(i,1,n) f[i]=-1;
    ll ans=0;
    fu(i,1,m)
    {
        ll u=e[i].u,v=e[i].v;
        u=root(u);
        v=root(v);
        if(u!=v)
        {
            ans+=e[i].w;
            HN(u,v);
        }
    }
    ll tmp=root(1);
    ll check=0;
    fu(i,2,n)
    {
        if(root(i)!=tmp)
        {
            cout<<"IMPOSSIBLE";check=1;
            break;
        }
    }
    if(!check) cout<<ans;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
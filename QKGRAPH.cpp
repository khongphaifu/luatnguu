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

struct bg
{
    ll u,v,id;
} Q[N];

struct bg1
{
    ll u,v,w;
} E[N];

ll n,q;
ll f[N],sz[N],ans[N];

bool cmp1(bg a,bg b)
{
    return a.u>b.u;
}

bool cmp2(bg1 a,bg1 b)
{
    return a.w>b.w;
}

ll root(ll u) {return (f[u]<0 ? u : f[u]=root(f[u]));}

void HN(ll u,ll v)
{
    u=root(u);
    v=root(v);
    if(u==v) return;
    sz[u]+=sz[v];
    f[v]=u;
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
    fu(i,1,n) f[i]=-1,sz[i]=1;;
    fu(i,1,n-1) cin>>E[i].u>>E[i].v>>E[i].w;
    fu(i,1,q) cin>>Q[i].u>>Q[i].v,Q[i].id=i;
    sort(alla(E,n),cmp2);
    sort(alla(Q,q),cmp1);
    ll j=1;
    fu(i,1,q)
    {
        while(j<=n && Q[i].u<=E[j].w)
        {
            HN(E[j].u,E[j].v);
            j++;
        }
        ans[Q[i].id]=sz[root(Q[i].v)];
    }
    fu(i,1,q) cout<<ans[i]-1<<el;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
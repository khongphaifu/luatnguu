#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define             pb  push_back  
#define             ll  long long
#define             el  "\n"
#define      alla(a,n)  a+1,a+n+1
#define         all(v)  v.begin(),v.end()
#define      fu(i,a,b)  for(ll i=a;i<=b;i++)
#define     fud(i,a,b)  for(ll i=a;i>=b;i--)

const ll N=1e6+5,MOD=1e9+7;

struct bg
{
    ll x,y,w;
};

struct bg1
{
    ll x,y;
};

ll n,m;
ll f[N];
ll p[N][21],h[N],par[N],dd[N],mi[N][21];
bg e[N];
vector<bg1> g[N];

bool cmp(bg a,bg b)
{
    return a.w>b.w;
}

ll root(ll u)
{
    return (f[u]<0 ? u : f[u]=root(f[u]));
}

void dfs(ll u,ll pre)
{
    for(auto it:g[u])
    {
        if(it.x==pre) continue;
        par[it.x]=u;
        mi[it.x][0]=it.y;
        h[it.x]=h[u]+1;
        dfs(it.x,u);
    }
}

void pre()
{
    fu(i,1,n) p[i][0]=par[i];
    fu(i,1,log2(n))
    {
        fu(u,1,n) p[u][i]=p[p[u][i-1]][i-1],mi[u][i]=min(mi[u][i-1],mi[p[u][i-1]][i-1]);
    }
}

ll lca(ll u,ll v)
{
    ll mii=1e9;
    if(h[u]<h[v]) swap(u,v);
    ll k=log2(n);
    fud(j,k,0)
    {
        if(h[p[u][j]]>=h[v] && h[p[u][j]]>0)
        {
            mii=min(mii,mi[u][j]);
            u=p[u][j];
        }
    }
    fud(j,k,0)
    {
        if(p[u][j]!=p[v][j])
        {
            mii=min({mii,mi[u][j],mi[v][j]});
            u=p[u][j];
            v=p[v][j];
        }
    }
    if(u==v) return mii;
    mii=min({mii,mi[u][0],mi[v][0]});
    return mii;
}

void HN(ll x,ll y,ll i)
{
    x=root(x);
    y=root(y);
    if(x==y) return;
    ll t=f[x]+f[y];
    dd[i]=1;
    g[e[i].x].pb({e[i].y,e[i].w});
    g[e[i].y].pb({e[i].x,e[i].w});
    if(f[x]>f[y])
    {
        f[x]=t;
        f[y]=x;
    }
    else
    {
        f[y]=t;
        f[x]=y;
    }

}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>m;
    fu(i,1,m)
    {
        cin>>e[i].x>>e[i].y>>e[i].w;
    }
    sort(alla(e,m),cmp);
    fu(i,1,n) f[i]=-1;
    fu(i,1,m) dd[i]=0;
    fu(i,1,m)
    {
        HN(e[i].x,e[i].y,i);
    }
    fu(i,1,n) h[i]=1;
    dfs(1,-1);
    pre();
    ll ans=0;
    fu(i,1,m)
    {
        if(!dd[i])
        {
            // cout<<i<<" ";
            // cout<<lca(e[i].x,e[i].y)<<el;
            ans+=abs(lca(e[i].x,e[i].y)-e[i].w);
        }
    }
    cout<<ans;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
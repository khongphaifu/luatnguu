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

struct bg
{
    ll ke,ts;
};


struct bg1
{
    ll u,v,w;
}e[N];

struct bg3
{
    ll id,w;
};

ll n,q;
bg3 Q[N];
vector<bg> g[N];

namespace sub1
{
    ll h[N];
    void dfs(ll u,ll pre)
    {
        for(auto it:g[u])
        {
            if(it.ke==pre) continue;
            h[it.ke]=h[u]+it.ts;
            dfs(it.ke,u);
        }
    }

    void sol()
    {
        fu(i,1,q)
        {

            fu(i,1,n) g[i].clear();
            ll id=Q[i].id,w=Q[i].w;
            e[id].w=w;
            fu(i,1,n-1)
            {
                ll u=e[i].u,v=e[i].v,w=e[i].w;
                g[u].pb({v,w});
                g[v].pb({u,w});
            }
            ll d;
            h[1]=0;
            dfs(1,0);
            ll res=-inf;
            fu(i,1,n)
            {
                if(res<h[i])
                {
                    res=h[i];
                    d=i;
                }
            }
            h[d]=0;
            ll ans=-inf;
            dfs(d,0);
            fu(i,1,n) ans=max(ans,h[i]);
            cout<<ans<<el;
        }
    }
}

namespace sub2
{
    ll h[N];
    // vector<bg> g1[N],g2[N];
    void dfs(ll u,ll pre,ll d)
    {

        for(auto it:g[u])
        {
            if(it.ke==pre || it.ke==d) continue;
            h[it.ke]=h[u]+it.ts;
            dfs(it.ke,u,d);
        }
    }
    void sol()
    {
        ll res=Q[1].id;
        ll uu=e[res].u,vv=e[res].v;
        fu(i,1,n-1)
        {
            ll u=e[i].u,v=e[i].v,w=e[i].w;
            g[u].pb({v,w});
            g[v].pb({u,w});
        }
        dfs(uu,0,vv);
        res=-inf;
        ll d;
        fu(i,1,n)
        {
            if(h[i]>res)
            {
                res=h[i];
                d=i;
            }
        }
        ll h1=res;
        fu(i,1,n) h[i]=0;
        dfs(d,0,vv);
        ll ans1=*max_element(alla(h,n));
        fu(i,1,n) h[i]=0;
        dfs(vv,0,uu);
        res=-inf;
        fu(i,1,n)
        {
            if(h[i]>res)
            {
                res=h[i];
                d=i;
            }
        }
        ll h2=res;
        fu(i,1,n) h[i]=0;
        dfs(d,0,uu);
        ll ans2=*max_element(alla(h,n));
        // cout<<ans1<<" "<<ans2<<el;
        fu(i,1,q)
        {
            ll w=Q[i].w;
            cout<<max({ans1,ans2,h1+h2+w})<<el;
        }

    }
}

namespace sub3
{

    ll f[N],par[N],res[N],h[N];
    void dfs(ll u,ll pre)
    {
        for(auto it:g[u])
        {
            if(it.ke==pre) continue;
            par[it.ke]=u;
            h[it.ke]=h[u]+1;
            dfs(it.ke,u);
            res[u]=max(res[u],res[it.ke]);
            res[u]=max(res[u],f[it.ke]+it.ts+f[u]);
            f[u]=max(f[u],f[it.ke]+it.ts);
        }
    }

    void sol()
    {
        fu(i,1,n-1)
        {
            ll u=e[i].u,v=e[i].v,w=e[i].w;
            g[u].pb({v,w});
            g[v].pb({u,w});
        }
        dfs(1,-1);
        // cout<<res[1]<<el;
        fu(i,1,q)
        {
            ll id=Q[i].id,w=Q[i].w;
            ll u=e[id].u,v=e[id].v;
            ll hehe;
            if(h[u]>h[v]) swap(u,v);
            // u=hehe; q
            fu(j,0,g[u].size()-1)
            {
                if(g[u][j].ke==v)
                {
                    g[u][j].ts=w;
                    break;
                }
            }
            while(u!=0)
            {
                res[u]=0;
                f[u]=0;
                for(auto it:g[u])
                {
                    if(it.ke==par[u]) continue;
                    res[u]=max(res[u],res[it.ke]);
                    res[u]=max(res[u],f[it.ke]+it.ts+f[u]);
                    f[u]=max(f[u],f[it.ke]+it.ts);
                }
                u=par[u];
            }
            cout<<res[1]<<el;
        }
    }
}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".inp" ,"r",stdin) ; freopen(TASK".out" ,"w",stdout);
    }

    cin>>n>>q;
    fu(i,1,n-1)
    {
        ll u,v,w;cin>>u>>v>>w;
        e[i]={u,v,w};
        // g[u].pb({v,w});
        // g[v].pb({u,w});
    }

    ll checksub2=1;
    fu(i,1,q)
    {
        cin>>Q[i].id>>Q[i].w;
        if(i>=2 && Q[i].id!=Q[i-1].id) checksub2=0;
    }
    if(n<=3e3 && q<=3e3) sub1::sol();
    else if(checksub2)
    sub2::sol();
    else
    sub3::sol();
    
    // số MOD bro
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
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
const ll N=2e5+5;
const ll N1=1e3+5;
/*🥑*/
template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}
/*v*/
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

ll n,q;
ll a[N],type[N],u[N],v[N],c[N];
vector<ll> g[N];

namespace sub1
{
    ll k;
    ll h[N];
    ll p[N][32];
    ll f[N],par[N];
    void dfs(ll u,ll pre)
    {
        for(auto it:g[u])
        {
            if(it==pre) continue;
            h[it]=h[u]+1;
            p[it][0]=u;
            par[it]=u;
            dfs(it,u);
        }
    }

    void pre()
    {
        fu(i,1,k) fu(u,1,n) p[u][i]=p[p[u][i-1]][i-1];
    }

    ll lca(ll u,ll v)
    {
        if(h[u]<h[v]) swap(u,v);
        fud(j,k,0)
        {
            if(h[p[u][j]]>0 && h[p[u][j]]>=h[v]) u=p[u][j];
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

    ll ans=0;

    void get(ll u,ll pre,ll c)
    {
        if(f[u]==c) ans+=a[u];
        for(auto it:g[u])
        {
            if(it==pre) continue;
            get(it,u,c);
        }
    }

    void sol()
    {
        k=log2(n);
        dfs(1,0);
        p[1][0]=1;
        // par[1]=1;
        pre();
        // p[1][0]=1;
        // par[1]=1;
        h[0]=-1;
        fu(i,1,q)
        {
            // ll type;cin>>type;
            if(type[i]==1)
            {
                // ll u,v,c;cin>>u>>v>>c;
                ll p=lca(u[i],v[i]);
                // cout<<p<<el;
                while(h[u[i]]>=h[p])
                {
                    if(!f[u[i]])f[u[i]]=c[i];
                    ll res=u[i];
                    u[i]=par[u[i]];
                    par[res]=par[p];
                }
                u[i]=v[i];
                while(h[u[i]]>=h[p])
                {
                    if(!f[u[i]])f[u[i]]=c[i];
                    ll res=u[i];
                    u[i]=par[u[i]];
                    par[res]=par[p];
                }           
            }
            else
            {
                ans=0;
                // ll u,c;cin>>u>>c;
                // fu(i,1,n) if(f[u]==c) cout<<i<<" ";
                // cout<<el;
                get(u[i],p[u[i]][0],c[i]);
                cout<<ans<<el;
            }
        }
    }
}

namespace sub2
{
    ll k;
    ll h[N];
    ll p[N][32];
    ll f[N],par[N];
    void dfs(ll u,ll pre)
    {
        for(auto it:g[u])
        {
            if(it==pre) continue;
            h[it]=h[u]+1;
            p[it][0]=u;
            par[it]=u;
            dfs(it,u);
        }
    }

    void pre()
    {
        fu(i,1,k) fu(u,1,n) p[u][i]=p[p[u][i-1]][i-1];
    }

    ll lca(ll u,ll v)
    {
        if(h[u]<h[v]) swap(u,v);
        fud(j,k,0)
        {
            if(h[p[u][j]]>0 && h[p[u][j]]>=h[v]) u=p[u][j];
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

    ll ans=0;
    unordered_map<ll,ll> mp[N];
    unordered_map<ll,ll> huhu;
    vector<pair<ll,ll>> vi[N];
    ll cnt[N];

    void get(ll u,ll pre)
    {
        // if(f[u]==c) ans+=a[u];
        if(f[u] && huhu[f[u]]) mp[u][f[u]]+=a[u];
        for(auto it:g[u])
        {
            if(it==pre) continue;
            get(it,u);
            if(mp[u].size()<mp[it].size()) swap(mp[u],mp[it]);
            for(auto it1:mp[it]) mp[u][it1.fi]+=it1.se;
            mp[it].clear();
        }
        // ans[u]=mp[u];
        for(auto it:vi[u])
        {
            cnt[it.fi]=mp[u][it.se];
        }
    }

    void sol()
    {
        k=log2(n);
        dfs(1,0);
        p[1][0]=1;
        // par[1]=1;
        pre();
        // p[1][0]=1;
        // par[1]=1;
        h[0]=-1;
        ll hehe;
        fu(i,1,q)
        {
            // ll type;cin>>type;
            if(type[i]==1)
            {
                // ll u,v,c;cin>>u>>v>>c;
                ll p=lca(u[i],v[i]);
                // cout<<p<<el;
                while(h[u[i]]>=h[p])
                {
                    if(!f[u[i]])f[u[i]]=c[i];
                    ll res=u[i];
                    u[i]=par[u[i]];
                    par[res]=par[p];
                }
                u[i]=v[i];
                while(h[u[i]]>=h[p])
                {
                    if(!f[u[i]])f[u[i]]=c[i];
                    ll res=u[i];
                    u[i]=par[u[i]];
                    par[res]=par[p];
                }           
            }
            else
            {
                hehe=i;
                break;
            }           
        }
        fu(i,hehe,q) huhu[c[i]]++,vi[u[i]].pb({i,c[i]});
        get(1,0);
        fu(i,hehe,q) cout<<cnt[i]<<el;
    }
}

namespace sub3
{
    ll par[N],h[N],f[N];
    unordered_map<ll,ll> bit[N];

    void up(ll x,ll v,ll c)
    {
        for(;x<=n;x+= x&-x) bit[c][x]+=v;
    }

    ll get(ll x,ll c)
    {
        ll res=0;
        for(;x>0; x&=x-1) res+=bit[c][x];
        return res; 
    }

    void sol()
    {
        fu(i,1,n) par[i]=i-1,h[i]=i;
        fu(i,1,q)
        {
            // ll type;cin>>type;
            if(type[i]==1)
            {
                // ll u,v,c;cin>>u>>v>>c;
                ll p=min(u[i],v[i]);
                // cout<<p<<el;
                while(h[u[i]]>=h[p])
                {
                    if(!f[u[i]])
                    {
                        f[u[i]]=c[i];
                        up(1,a[u[i]],c[i]);
                        up(u[i]+1,-a[u[i]],c[i]);
                    }
                    ll res=u[i];
                    u[i]=par[u[i]];
                    par[res]=par[p];
                }
                u[i]=v[i];
                while(h[u[i]]>=h[p])
                {
                    if(!f[u[i]])
                    {
                        f[u[i]]=c[i];
                        up(1,a[u[i]],c[i]);
                        up(u[i]+1,-a[u[i]],c[i]);
                    }
                    ll res=u[i];
                    u[i]=par[u[i]];
                    par[res]=par[p];
                }           
            }
            else
            {
                cout<<get(u[i],c[i])<<el;
            }           
        }
    }
}

namespace sub4
{
    ll k,d,m;
    ll h[N];
    ll p[N][32];
    ll f[N],par[N],in[N],out[N];


    void dfs(ll u,ll pre)
    {
        m++;
        in[u]=m;
        // cnt[u]=1;
        for(auto it:g[u])
        {
            if(it==pre) continue;
            h[it]=h[u]+1;
            p[it][0]=u;
            par[it]=u;
            dfs(it,u);
            // cnt[u]+=cnt[it];
        }
        m++;
        out[u]=m;
    }

    void pre()
    {
        fu(i,1,k) fu(u,1,n) p[u][i]=p[p[u][i-1]][i-1];
    }

    ll lca(ll u,ll v)
    {
        if(h[u]<h[v]) swap(u,v);
        fud(j,k,0)
        {
            if(h[p[u][j]]>0 && h[p[u][j]]>=h[v]) u=p[u][j];
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

    
    unordered_map<ll,ll> bit[N];

    void up(ll x,ll v,ll c)
    {
        for(;x<=m;x+= x&-x) bit[c][x]+=v;
    }

    ll get(ll x,ll c)
    {
        ll res=0;
        for(;x>0; x&=x-1) res+=bit[c][x];
        return res; 
    }


    void sol()
    {
        k=log2(n);
        dfs(1,0);
        p[1][0]=1;
        // par[1]=1;
        pre();
        // p[1][0]=1;
        // par[1]=1;
        h[0]=-1;
        fu(i,1,q)
        {
            // ll type;cin>>type;
            if(type[i]==1)
            {
                // ll u,v,c;cin>>u>>v>>c;
                ll p=lca(u[i],v[i]);
                // cout<<p<<el;
                while(h[u[i]]>=h[p])
                {
                    if(!f[u[i]])
                    {
                        f[u[i]]=c[i];
                        up(in[u[i]]+1,-a[u[i]],c[i]);
                        up(1,a[u[i]],c[i]);
                    }
                    ll res=u[i];
                    u[i]=par[u[i]];
                    par[res]=par[p];
                }
                u[i]=v[i];
                while(h[u[i]]>=h[p])
                {
                    if(!f[u[i]])
                    {
                        f[u[i]]=c[i];
                        up(in[u[i]]+1,-a[u[i]],c[i]);
                        up(1,a[u[i]],c[i]);
                    }
                    ll res=u[i];
                    u[i]=par[u[i]];
                    par[res]=par[p];
                }           
            }
            else
            {
                cout<<get(in[u[i]],c[i])-get(out[u[i]]+1,c[i])<<el;
            }           
        }
        
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
    cin>>n>>q;
    fu(i,1,n) cin>>a[i];
    ll checksub3=1;
    fu(i,1,n-1)
    {
        ll x,y;cin>>x>>y;
        if(abs(x-y)!=1) checksub3=0;
        g[x].pb(y);
        g[y].pb(x);
    }
    ll checksub2=1;
    ll check=0;
    fu(i,1,q)
    {
        cin>>type[i];
        if(type[i]==1)
        {
            cin>>u[i]>>v[i]>>c[i];
            if(check) checksub2=0;
        }
        else
        {
            cin>>u[i]>>c[i];check=1;
        }
    }
    sub4::sol();

    
    // số MOD bro
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
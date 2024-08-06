// Program link: https://tinhoclk.com/problem/inctree
// Program name: v 
#define TASK  "INCTREE"
// sol: 



#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
#define             pl  pair<ll,ll>  
#define             pb  push_back  
#define             ll  long long
#define             db  double
#define            nnc  signed main()
#define             se  second 
#define             fi  first
#define             el  "\n"
#define         all(a)  a.begin(),a.end()
#define      alla(a,n)  a+1,a+n+1
#define     FOR(i,a,b)  for(ll i=a;i<=b;i++)
#define    FORD(i,a,b)  for(ll i=a;i>=b;i--)
#define    FORN(i,a,b)  for(ll i=a;i<b;i++)
#define   FORDN(i,a,b)  for(ll i=a;i>b;i--)
#define     print(a,n)  for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<el;
#define      printv(v)  for(auto it:v) cout<<it<<" ";cout<<el;
#define     printvp(v)  for(auto it:v) cout<<it.fi<<" "<<it.se<<el;
#define       ieozzool  cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
using namespace std;
// using namespace __gnu_pbds;

ll mlt=0;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const long long inf = 1e18;
const ll N = 1e6 + 5 , N1 = 1e3 + 5 , MOD = 1e9 +7 , sminf = 1e9;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

struct bg
{
    ll x,y;
};

ll n,m,q;
vector<ll> g[N];
ll h[N],p[N][21],par[N],f[N];


void befout()
{
    cin>>n>>m>>q;
    FOR(i,1,n-1)
    {
        ll x,y;cin>>x>>y;
        g[x].pb(y);g[y].pb(x);
    }
}
    
void befin()
{
    

}

namespace mnp
{   

    void dfs(ll u,ll pre)
    {
        for(auto it:g[u])
        {
            if(it==pre) continue;
            par[it]=u;
            h[it]=h[u]+1;
            dfs(it,u);
        }
    }  

    void pre()
    {
        FOR(i,1,n) p[i][0]=par[i];
        FOR(i,1,log2(n))
        {
            FOR(u,1,n) p[u][i]=p[p[u][i-1]][i-1];
        }
    }

    ll lca(ll u,ll v)
    {
        if(h[u]<h[v]) swap(u,v);
        ll k1=log2(n);
        FORD(j,k1,0)
        {
            if(h[p[u][j]]>0 && h[p[u][j]]>=h[v]) u=p[u][j];
        }
        FORD(j,k1,0)
        {
            if(p[u][j]!=p[v][j])
            {
                u=p[u][j],v=p[v][j];
            }
        }
        if(u==v) return u;
        return par[u];
    }

    void dfs1(ll u,ll pre)
    {
        for(auto it:g[u])
        {
            if(it==pre) continue;
            dfs1(it,u);
            f[u]+=f[it];
        }
    }

    void dfs2(ll u,ll pre)
    {
        for(auto it:g[u])
        {
            if(it==pre) continue;
            f[it]+=f[u];
            dfs2(it,u);
        }
    }

    ll dist(ll u,ll v)
    {
        return f[u]+f[v]-2*f[lca(u,v)];
    }
    


    void sol()
    {
        par[1]=1;
        dfs(1,0);
        pre();
        // cout<<lca(1,3)<<el;
        while(m--)
        {
            ll a,b,c,d; cin>>a>>b>>c>>d;
            ll p=lca(a,b),p1=lca(c,d);
            f[b]++;f[a]++;
            f[p]-=2;
            ll a1=lca(a,c);
            // cout<<p<<" "<<p1<<el;
            if(lca(a1,d)==p1 && lca(a1,b)==p)
            {
                f[a1]--;
                if(h[p1]>h[p]) f[p1]++;
                else f[p]++;
                // cout<<1<<el;
            }
            a1=lca(a,d);
            // cout<<a1<<el;
            if(lca(a1,c)==p1 && lca(a1,b)==p)
            {
                f[a1]--;
                if(h[p1]>h[p]) f[p1]++;
                else f[p]++;
                // cout<<2<<el;
            }
            a1=lca(b,c);
            // cout<<a1<<el;
            if(lca(a1,d)==p1 && lca(a1,a)==p)
            {
                f[a1]--;
                if(h[p1]>h[p]) f[p1]++;
                else f[p]++;
                // cout<<3<<el;
            }
            a1=lca(b,d);
            if(lca(a1,c)==p1 && lca(a1,a)==p)
            {
                f[a1]--;
                if(h[p1]>h[p]) f[p1]++;
                else f[p]++;
                // cout<<4<<el;
            }
            // FOR(i,1,n) cout<<i<<" "<<f[i]<<el;
        }
        // cout<<f[3]<<el;
        dfs1(1,0);
        // cout<<f[2]<<el;
        dfs2(1,0);
        // cout<<f[4]<<el;
        while(q--)
        {
            ll x,y;cin>>x>>y;
            cout<<dist(x,y)<<el;
        }
        
    }       
}

    

// "..."

nnc
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }
    if(mlt) cin>>test;
    befout();
    FOR(i,1,test)
    {
        // while(cin>>n)
        befin();
        mnp::sol();
    }
    ieozzool;
}
/*
                  ▒▒▒▒▒▒▒▒▒▒▒▒                                            
                ▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒                                          
              ▓▓▒▒▒▒░░░░░░░░░░▓▓▓▓                                        
            ░░▒▒▒▒░░▓▓░░░░░░░░░░▓▓                                        
            ░░▒▒▒▒░░▒▒░░░░░░  ░░▓▓▒▒                                      
        ░░▓▓░░▒▒▒▒▒▒░░░░░░░░░░░░▒▒▓▓                                      
  ░░░░░░░░░░░░▒▒▒▒▒▒▒▒░░░░▒▒▒▒░░░░▓▓                                      
                    ▒▒▓▓▓▓▒▒▒▒░░▒▒▓▓                                      
                        ▓▓▒▒░░░░▒▒▓▓                                      
                        ▓▓▒▒░░░░▒▒                                        
                      ▓▓▒▒░░  ░░▒▒                                        
                  ▓▓▓▓▒▒░░░░░░▓▓                                          
              ▓▓▒▒▒▒▒▒▒▒▒▒░░▒▒                                            
            ▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓                                              
          ▓▓██▓▓▓▓        ▓▓▒▒▒▒▒▒▒▒                                      
        ██▓▓▒▒▓▓▓▓▓▓▓▓██▓▓██░░░░░░▒▒▒▒▒▒▒▒                                
      ▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓████░░░░░░░░░░░░░░▓▓▓▓▓▓                            
      ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▒▒▒▒▒▒░░░░░░  ▓▓▓▓                        
    ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒░░▓▓▓▓▓▓▓▓▒▒▒▒▒▒░░░░░░  ▓▓▓▓                    
    ██▒▒▓▓▓▓▓▓▓▓██▒▒▒▒▒▒▒▒▒▒░░░░████▓▓▓▓▒▒▒▒▒▒▒▒░░░░  ▓▓▓▓                
    ██▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░████▓▓▓▓▒▒▒▒▒▒░░░░    ▓▓              
    ██▓▓▓▓▓▓██▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░██████████▓▓▓▓░░░░  ▓▓▓▓          
    ██▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░████████████▒▒▓▓░░░░▓▓        
    ██▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░  ████████░░░░▓▓▓▓    ▓▓    
    ████▓▓██▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░    ██░░██████▓▓██    ██  
      ██████▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░  ▓▓████████▓▓▓▓▓▓    
      ░░████▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒░░            ░░  ░░░░░░
          ▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░██████░░░░░░░░░░░░  
            ▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░████▓▓▓▓          
              ▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                  
                  ▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                              
                            ▓▓▓▓▓▓▓▓▓▓                                    
                            ▒▒▓▓▒▒▓▓▒▒                                    
                              ▒▒  ▒▒                                      
                              ▒▒  ▒▒                                      
                              ▒▒  ▒▒                                      
                              ▒▒  ▒▒                                      
                    ▒▒▒▒▒▒▒▒  ▒▒  ▒▒                                      
                ░░░░▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒   
*/
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

ll n,m;
vector<ll> g[N];
ll f[N];

void dfs(ll u,ll pre,ll d)
{
    f[u]=d;
    for(auto it:g[u])
    {
        if(it==pre) continue;
        if(f[it]!=-1)
        {
            if(f[it]!=1-d)
            {
                cout<<"IMPOSSIBLE";
                exit(0);
            }
            else continue;
        }
        dfs(it,u,1-d);
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
        ll x,y;cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    fu(i,1,n) f[i]=-1;
    fu(i,1,n) if(f[i]==-1) dfs(i,0,0);
    fu(i,1,n) cout<<f[i]+1<<" ";
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
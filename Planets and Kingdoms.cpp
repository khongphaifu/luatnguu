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

const ll N=1e6+5,MOD=1e9+7,inf=1e18;

ll n,m,scc,stt;
vector<ll> g[N];
ll num[N],low[N],del[N];
stack<ll> s;

void dfs(ll u,ll pre)
{
    num[u]=low[u]=++stt;
    s.push(u);
    for(auto it:g[u])
    {
        if(del[it]) continue;
        if(!num[it])
        {
            dfs(it,u);
            low[u]=min(low[u],low[it]);
        }
        else low[u]=min(low[u],num[it]);
    }

    if(num[u]==low[u])
    {
        scc++;
        ll v;
        do
        {
            v=s.top();
            s.pop();
            del[v]=scc;
        }
        while(u!=v);
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
    }
    fu(i,1,n) if(!del[i]) dfs(i,0);
    cout<<scc<<el;
    fu(i,1,n) cout<<del[i]<<" ";
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
#include <bits/stdc++.h>
using namespace std;


#define           TASK  "QFOODS"
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


ll mlt=0;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const ll N = 1e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll n,m,scc,stt;
    ll num[N],low[N],del[N],food[N],var[N],f[N],res[N],visit[N];
    vector<ll> g[N],gr[N];
    stack<ll> st;
    map<pair<ll,ll>,ll> mp;

    void dfs(ll u)
    {
        num[u]=low[u]=++stt;
        st.push(u);
        for(auto it:g[u])
        {
            if(del[it]) continue;
            if(!num[it])
            {
                dfs(it);
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
                v=st.top();
                st.pop();
                del[v]=scc;
                // for(auto it:g[v])
                // {
                //     if(del[it]==del[v]) continue;
                //     if(mp[{del[v],del[it]}]) continue;
                //     gr[del[v]].pb(del[it]);
                //     mp[{del[v],del[it]}]=1;
                //     // cout<<del[i]<<" "<<del[it]<<el;
                //     // var[del[it]]++;
                // }
            } 
            while(u!=v);
        }
    }

    void dfs1(ll u)
    {
        visit[u]=1;
        for(auto it:gr[u])
        {
            if(visit[it]!=1)
            {
                dfs1(it);
                res[u]=max(res[u],res[it]+f[it]);
            }
        }
        visit[u]=2;

    }
    

    void sol()
    {
        cin>>n>>m;
        FOR(i,1,n) cin>>food[i];
        FOR(i,1,m)
        {
            ll x,y;cin>>x>>y;
            g[x].pb(y);
        }
        FOR(i,1,n)
        {
            if(!del[i])
            {
                dfs(i);
            }
        }
        // FOR(i,1,n) cout<<del[i]<<" ";
        // cout<<el;
        map<pair<ll,ll>,ll> mp;
        FOR(i,1,n) // có thể TLE
        {
            // num[i]=low[i]=0;
            for(auto it:g[i])
            {
                if(del[it]!=del[i] && !mp[{del[it],del[i]}])
                {
                    mp[{del[it],del[i]}]=1;
                    gr[del[it]].pb(del[i]);
                    var[del[i]]++;
                    // cout<<del[it]<<" "<<del[i]<<el;
                }
            }
            f[del[i]]+=food[i];
        }
        // stt=0;
        queue<ll> ds;
        // FOR(i,1,scc) cout<<var[i]<<" ";
        // cout<<el;
        // FOR(i,1,n) cout<<res[i]<<" ";
        FOR(i,1,scc)
        {
            if(!var[i]) ds.push(i);
            res[i]=f[i];
            // for(auto it:gr[i]) cout<<it<<" ";
            // cout<<el;
            // cout<<var[i]<<" ";
            // res[i]=f[i];
        }
        while(!ds.empty())
        {
            ll u=ds.front();ds.pop();
            // cout<<u<<el;
            for(auto it:gr[u])
            {
                var[it]--;
                res[it]=max(res[it],res[u]+f[it]);
                if(!var[it]) ds.push(it);
            }
            // cout<<res[u]<<el;
        }
        // FOR(i,1,scc)
        // {
        //     if(!visit[i]) dfs1(i);
        // }
        FOR(i,1,n) cout<<res[del[i]]<<" ";

    }
}



// "..."

nnc
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }
    bef();
    if(mlt) cin>>test;
    // cout<<test<<el;
    FOR(i,1,test)
    {
        mnp::sol();
    }
    ieozzool;
}


#include <bits/stdc++.h>
using namespace std;


#define           TASK  "GRAPH"
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
    ll n,m,t1,t2,ans;    
    vector<ll> g[N];
    ll low1[N],low2[N],num1[N],num2[N],d[N],joint[N],visit[N];

    void dfs1(ll u,ll pre)
    {
        ll child=0;
        // visit[u]=res;
        num1[u]=low1[u]=++t1;

        for(auto it:g[u])
        {
            if(it==pre )
            {
                continue;
            }
            if(it==u) joint[u]--;
            if(!num1[it] )
            {
                dfs1(it,u);
                low1[u]=min(low1[u],low1[it]);
                // if(low1[it]==num1[it])
                // {
                //     dp[it][u]=1,dp[it][u]=1;
                // }
                child++;
                if(u==pre)
                {
                    if(child>1) joint[u]++;
                }
                else if(low1[it]>=num1[u]) joint[u]++;
            }
            else low1[u]=min(low1[u],num1[it]);
        }
    }

    // void dfs2(ll u,ll pre,ll res)
    // {
    //     num2[u]=low2[u]=++t2;
    //     for(auto it:g[u])
    //     {
    //         if(it==pre || it==res) continue;
    //         if(!num2[it])
    //         {
    //             dfs2(it,u,res);
    //             low2[u]=min(low2[u],low2[it]);
    //         }
    //         else low2[u]=min(low2[u],num2[it]);
    //     }
    // }


    
    void sol()
    {
        cin>>n>>m;
        FOR(i,1,m)
        {
            ll x,y;cin>>x>>y;
            // if(x==y) joint[x]--;
            g[x].pb(y);
            g[y].pb(x);
        }
        // FOR(i,1,n) d[i]=1;
        FOR(i,1,n)
        {
            if(!num1[i])
            {
                ans++;
                dfs1(i,i);
            }
        }
        // cout<<joint[4]<<el;
        FOR(i,1,n)
        {
                if(g[i].size()==0) cout<<ans-1<<el;
                else cout<<ans+joint[i]<<el;
            
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
    bef();
    if(mlt) cin>>test;
    // cout<<test<<el;
    FOR(i,1,test)
    {
        mnp::sol();
    }
    ieozzool;
}
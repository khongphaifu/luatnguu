// khongphaifu - Mai Ngọc Phú - T2K33 - THPT Chuyên Lê Khiết
// VOI... 
// Program link: https://tinhoclk.com/problem/distk
// Program name:  v 
#define TASK   "DISTK"
// sol: 
// 2 FOR + dfs + qhd
int mlt=0;
int test=1;

#include <bits/stdc++.h>
using namespace std;


#define             pl  pair<ll,ll>  
#define             pb  push_back  
#define             ll  int
#define             db  double
#define            nnc  signed main()
#define             se  second 
#define             fi  first
#define             el  "\n"
#define         all(a)  a.begin(),a.end()
#define      alla(a,n)  a+1,a+n+1
#define     FOR(i,a,b)  for(ll i=a;i<=b;i++)
#define    FORD(i,a,b)  for(ll i=a;i>=b;i--)
#define     print(a,n)  for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<el;
#define      printv(v)  for(auto it:v) cout<<it<<" ";cout<<el;
#define     printvp(v)  for(auto it:v) cout<<it.fi<<" "<<it.se<<el;
#define           endp  cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;

const long long inf = 1e18 ;
const ll N = 1e6 + 5 , N1 = 3e3 + 5 , MOD = 1e9 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}




void bef()
{
    
}

namespace mnp 
{
    ll n,k,stt,ma;
    vector<ll> g[N];
    // ll dp[N1][N1];
    map<ll,map<ll,ll>> mp;
    ll visit[N],d[N],num[N],low[N],f[N];
    ll ans=0;

    void bfs(ll u,ll i)
    {
        queue<ll> q;
        q.push(u);
        visit[u]=i;d[u]=1;
        while(!q.empty())
        {
            ll v=q.front();q.pop();
            for(auto it:g[v])
            {
                if(visit[it]!=i)
                {
                    q.push(it);
                    visit[it]=i;
                    d[it]=d[v]+1;
                    ma=max(ma,d[it]);
                }
            }
        }
    }

    void dfs(ll u,ll pre)
    {
        num[u]=low[u]=++stt;
        mp[u][d[u]]++;
        // dp[u][d[u]]++;
        for(auto it:g[u])
        {
            if(u==pre) continue;
            if(!num[it])
            {
                dfs(it,u);
                FOR(i,1,k-1)
                {
                    ans+=mp[u][d[u]+i]*mp[it][k-i+d[u]]; // chọn các đoạn không thuộc nhánh chính
                    // else break;
                    // ans+=dp[u][d[u]+i]*dp[it][k-i+d[u]];
                }
                for(auto it1:mp[it]) mp[u][it1.fi]+=it1.se;
                // FOR(i,1,n) dp[u][i]+=dp[it][i];
                low[u]=min(low[u],low[it]);
            }
            else low[u]=min(low[u],num[it]);
        }
        if(d[u]+k<=ma)ans+=mp[u][d[u]+k]; // chọn các đoạn thuộc nhánh chính 
        // ans+=dp[u][d[u]+k];
    }

    void sol()
    {
        cin>>n>>k;
        ll tmp;
        FOR(i,1,n)
        {
            ll x;cin>>x;
            if(x!=0)
            {
                g[i].pb(x);
                g[x].pb(i);
            }
            else tmp=i;
        }
        bfs(tmp,1);
        dfs(tmp,0);
        // FOR(i,1,n)
        // {
        //     for(auto it:mp[i]) cout<<it.fi<<" "<<it.se<<el;
        //     cout<<"----"<<el;
        // }
        cout<<ans;
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
    endp
}
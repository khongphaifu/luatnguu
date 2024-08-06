#include <bits/stdc++.h>
using namespace std;


#define           TASK  "SUMMAX1"
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
    ll n,tmp,ans=0;
    ll f[N],visit[N],a[N];
    vector<ll> g[N];

    void bfs(ll u)
    {
        queue<pair<ll,ll>> q;
        q.push({u,0});
        visit[u]=1;
        f[u]=a[u];
        while(!q.empty())
        {
            ll x=q.front().fi,pre=q.front().se;q.pop();
            for(auto it:g[x])
            {
                if(!visit[it])
                {
                    f[it]=max(f[x],f[pre]+a[it]+f[it]);
                    q.push({it,x});
                    visit[it]=1;
                }
            }
        }
    }

    void sol()
    {
        cin>>n;
        FOR(i,1,n) cin>>a[i]; 
        FOR(i,1,n)
        {  
            ll x;cin>>x;
            if(x)
            {
                g[i].pb(x);
                g[x].pb(i);
            }
            else tmp=i;
        }
        FOR(i,1,n)
        {
            if(g[i].size()==1)
            {
                tmp=i;break;
            }
        }
        cout<<tmp<<el;
        bfs(tmp);
        cout<<f[tmp];
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
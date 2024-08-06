int mlt=0;
int test=1;

#include <bits/stdc++.h>
using namespace std;


#define           TASK  "4"
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




ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const ll N = 1e6 + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e18;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{

    ll n,q;
    ll a[N];
    vector<ll> g[N];
    ll visit[N];
    ll d[N];

    ll bfs(ll v,ll i)
    {
        
        queue<ll> q;
        q.push(v);visit[v]=i;
        d[v]=0;
        while(!q.empty())
        {
            ll x=q.front();
            q.pop();
            if(a[x]==1) return d[x];
            for(auto it:g[x])
            {
                if(visit[it]!=i)
                {
                    visit[it]=i;
                    d[it]=d[x]+1;
                    q.push(it);
                }
            }
        }
        return -1;
    }
    
    
    void sol()
    {
        cin>>n>>q;
        FOR(i,1,n-1)
        {
            ll x,y;cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
        a[1]=1;
        ll i=1;
        while(q--)
        {
            ll x,y;cin>>x>>y;
            if(x==1)
            {
                a[y]=1;
            }
            else
            {
                cout<<bfs(y,i)<<el;
            }
            i++;
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
    FOR(i,1,test)
    {
        mnp::sol();
    }
    ieozzool;
}
#include <bits/stdc++.h>
using namespace std;


#define           TASK  "GCLEAR"
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
    ll n,m,hx,hy,cx,cy;
    ll visit[107][107],dp[107][107],dp1[107][107];

    void bfs(ll x1,ll y1)
    {
        queue<pair<ll,ll>> q;
        q.push({x1,y1});
        visit[x1][y1]=1;
        while(!q.empty())
        {
            ll x=q.front().fi;
            ll y=q.front().se;
            FOR(i,0,3)
            {
                ll sx=x+dx[i];
                ll sy=y+dy[i];
                if(sx>=1 && sx<=n && sy>=1 && sy<=m && !dp[sx][sy] && !visit[sx][sy])
                {
                    visit[sx][sy]=1;
                    dp1[sx][sy]=dp1[x][y]+1;
                    q.push({sx,sy});
                }
            }
            q.pop();
        }
    }

    void sol()
    {
        cin>>n>>m;
        FOR(i,1,n) FOR(j,1,m)
        {
            char x;cin>>x; dp[i][j]=(x=='1');
        }
        cin>>hx>>hy;
        string s;cin>>s;
        cin>>cx>>cy;
        bfs(cx,cy);
        // FOR(i,1,n)
        // {
        //     FOR(j,1,m) cout<<dp1[i][j]<<" ";
        //     cout<<el;
        // }
        ll size=s.size();
        s='#'+s;
        ll res=0;
        FOR(i,1,size)
        {
            if(s[i]=='U') hx--;
            else if(s[i]=='D') hx++;
            else if(s[i]=='L') hy--;
            else if(s[i]=='R') hy++;
            res++;
            if(dp1[hx][hy]<=res && (res-dp1[hx][hy])%2==0)
            {
                cout<<res;return;
            }
        }
        cout<<-1;



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
#include <bits/stdc++.h>
using namespace std;


#define           TASK  "P9KNIGHTS"
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


ll mlt=1;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const ll N = 5e5 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

ll dp[10][10];

void bef()
{
    dp[1][1]=1;
    dp[1][2]=1;
    dp[1][3]=1;
    dp[1][4]=1;
    dp[1][5]=1;
    dp[2][2]=1;
    dp[2][3]=1;
    dp[2][4]=1;
    dp[2][5]=1;
    dp[3][4]=1;
    dp[3][5]=1;
    dp[4][5]=1;
    dp[3][3]=-1;
}

namespace mnp
{   
    ll ans;
    ll dp1[10][10],var[10][10];
    ll dxx[]={2,2,1,1,-1,-1,-2,-2};
    ll dyy[]={-1,1,-2,2,-2,2,-1,1};

    bool check()
    {
        FOR(i,1,5) FOR(j,1,5) if(dp1[i][j]!=dp[i][j]) return 0;
        return 1;
    }

    void dfs(ll x,ll y,ll res)
    {
        if(dp1[3][3]==-1 && check()) ans=min(ans,res);
        FOR(i,0,7)
        {
            ll x1=x+dxx[i];
            ll y1=y+dyy[i];
            if(x1>0 && x1<=5 && y1>0 && y1<=5 && res+1<=10)
            {
                swap(dp1[x][y],dp1[x1][y1]);
                dfs(x1,y1,res+1);
                swap(dp1[x][y],dp1[x1][y1]);
            }
        }
        // cout<<res<<el;
        // FOR(i,1,5)
        // {
        //     FOR(j,1,5) cout<<dp1[i][j]<<" ";
        //     cout<<el;
        // }
        // cout<<el;
    }   

    void sol()
    {
        ll x,y;
        // cin.ignore();
        FOR(i,1,5) FOR(j,1,5) dp1[i][j]=0,var[i][j]=0;
        FOR(i,1,5)
        {
            // cin.ignore();
            string s;getline(cin,s);
            // cout<<s<<el;
            if(s.size()==4)
            {
                dp1[i][5]=-1,x=i,y=5;
            }
            // for(char it:s) cout<<it<<" ";
            // cout<<el;    
            ll j=0;
            for(char it:s)
            {
                j++;
                if(it=='1') dp1[i][j]=1;
                else if(it==' ') dp1[i][j]=-1,x=i,y=j; 
            }       
        }
        // FOR(i,1,5)
        // {
        //     FOR(j,1,5) cout<<dp[i][j]<<" ";
        //     cout<<el;
        // }
        // cout<<x<<y<<el;
        // FOR(i,1,5)
        // {
        //     FOR(j,1,5) cout<<dp1[i][j]<<" ";
        //     cout<<el;
        // }
        ans=inf;
        dfs(x,y,0);
        if(ans==inf) cout<<"123456789"<<el;
        else cout<<ans<<el;
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
    if(mlt)
    {
        cin>>test;
        cin.ignore();
    }
    // cout<<test<<el;
    FOR(i,1,test)
    {
        mnp::sol();
    }
    ieozzool;
}
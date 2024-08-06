#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb  push_back  
#define ll  long long
#define el  "\n"
#define alla(a,n)  a+1,a+n+1
#define fi first
#define se second
#define all(v)  v.begin(),v.end()
#define fu(i,a,b)  for(ll i=a;i<=b;i++)
#define fud(i,a,b)  for(ll i=a;i>=b;i--)

const ll N=1e5+5,MOD=1e9+7,inf=1e18;

ll n,m;
ll a[N];
ll dp[107][N];

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
    fu(i,1,n) cin>>a[i];
    if(a[1])
    {
        dp[a[1]][1]=1;
    }
    else
    {
        fu(i,1,m) dp[i][1]=1;
    }
    fu(j,2,n)
    {
        if(a[j]==0)
        {
            fu(i,1,m) dp[i][j]=(dp[i][j]+dp[i][j-1]+dp[i+1][j-1]+dp[i-1][j-1])%MOD;
        }
        else
        {
            dp[a[j]][j]=(dp[a[j]][j]+dp[a[j]][j-1]+dp[a[j]+1][j-1]+dp[a[j]-1][j-1])%MOD;
        }
    }
    if(a[n]) cout<<dp[a[n]][n];
    else
    {
        ll ans=0;
        fu(i,1,m) ans=(ans+dp[i][n])%MOD;
        cout<<ans;
    }
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
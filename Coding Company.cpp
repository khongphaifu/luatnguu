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

const ll N=100+5,MOD=1e9+7,inf=1e18;

/*
-----------------------------------------
🛸    🌎    ★    🛰    °    🚀    ✯
    ★     °   ☄    ✯    ★    °    🪐
✯    🚀    •　  🌓   °    🛰　  •   ☄
_________________________________________
*/
//https://cses.fi/problemset/task/1665

ll n,x;
ll a[N];
ll dp[N][N][5007]; // i nguoi j nhom k phat

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>x;
    fu(i,1,n) cin>>a[i];
    sort(alla(a,n));
    a[0]=a[1];
    dp[0][0][0]=1;
    fu(i,1,n) fud(j,n,0) fud(k,x,0)
    {
        ll cnt=dp[i-1][j][k];
        ll res=k+j*(a[i]-a[i-1]);
        if(res>x) continue;
        dp[i][j][res]=(dp[i][j][res]+(j+1)*cnt)%MOD;
        if(j!=n) dp[i][j+1][res]=(dp[i][j+1][res] + cnt)%MOD;
        if(j) dp[i][j-1][res]=(dp[i][j-1][res] + j*cnt)%MOD;
    }
    ll ans=0;
    fu(i,0,x) ans=(ans+dp[n][0][i])%MOD;
    cout<<ans;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
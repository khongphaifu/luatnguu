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

const ll MOD=1e9+7 ;//1234567891;
const ll inf=1e18;
const ll base = 311;
const ll N=3e3+5;
const ll N1=1e3+5;

template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

/*
-----------------------------------------
🛸    🌎    ★    🛰    °    🚀    ✯
    ★     °   ☄    ✯    ★    °    🪐
✯    🚀    •　  🌓   °    🛰　  •   ☄
_________________________________________
*/

/// ===================================== - MAIN - ===================================== ///

ll n,k;
ll a[N],sum[N];
ll dp[N][N],best[N][N];

ll cal(ll i,ll j)
{
    if(i>j) return 0;
    return (sum[j]-sum[i-1])*(sum[j]-sum[i-1]);
}

void cdt(ll k,ll L,ll R,ll opL,ll opR)
{
    if(L>R) return;
    ll mid=(L+R)/2;
    dp[k][mid]=inf;
    fu(i,opL,opR)
    {
        ll cost=dp[k-1][i]+cal(i+1,mid);
        if(cost<dp[k][mid])
        {
            dp[k][mid]=cost;
            best[k][mid]=i;
        }
    }
    cdt(k,L,mid-1,opL,best[k][mid]);
    cdt(k,mid+1,R,best[k][mid],opR);
}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>k;
    fu(i,1,n) cin>>a[i];
    fu(i,1,n) sum[i]=sum[i-1]+a[i];
    // fu(i,1,k) fu(j,1,n) dp[i][j]=inf;
    fu(i,1,n) dp[1][i]=cal(1,i);
    fu(i,2,k)
    {
        cdt(i,1,n,1,n);
    }
    cout<<dp[k][n];
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
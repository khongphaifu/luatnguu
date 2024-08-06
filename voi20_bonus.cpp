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
const ll N=300+5;
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


ll n,K;
ll a[N];
ll f[N][N][N],dd[N][N][N];

ll cal(ll i,ll j,ll k)
{
    if(i>=j )
    {
        if(k==K) return 0;
        return -inf;

    }
    if(dd[i][j][k]) return f[i][j][k];
    dd[i][j][k]=1;
    f[i][j][k]=max({cal(i+1,j,k),cal(i,j-1,k)});
    if(k+1<=K) f[i][j][k]=max({f[i][j][k],cal(i,j-2,k+1)+abs(a[j-1]-a[j]),cal(i+2,j,k+1)+abs(a[i]-a[i+1]),cal(i+1,j-1,k+1)+abs(a[i]-a[j])});
    return f[i][j][k];
}


signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>K;
    fu(i,1,n) cin>>a[i];
    cout<<cal(1,n,0);
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
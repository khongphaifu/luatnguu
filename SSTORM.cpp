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
const ll N=5e2+5;
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

ll n,m,q,k;
ll dp[N][N];
ll f[N][1005];
vector<pair<ll,ll>> v;
map<pair<ll,ll>,ll> mp;

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>m>>q>>k;
    fu(i,1,n) fu(j,1,m) cin>>dp[i][j];
    fu(res,1,q)
    {
        ll x,y;cin>>x>>y;
        v.pb({x,y});
        mp[{x,y}]=res;
    }
    fu(i,1,k)
    {
        ll w,R1,R2,x,y;
        cin>>w>>R1>>R2>>x>>y;
        f[mp[{x,y}]][R2]+=w;
        f[mp[{x,y}]][R1+1]-=w;
    }
    fu(res,1,q)
    {
        fu(i,1,1000) f[res][i]+=f[res][i-1];
    }
    // fu(res,1,q)
    // {
    //     fu(i,1,10) cout<<f[res][i]<<" ";
    //     cout<<el;
    // }
    ll ans=0;
    for(auto it:v)
    {
        ll x=it.fi,y=it.se;
        ll tmp=mp[{x,y}];
        fu(i,1,n) fu(j,1,m)
        {
            ll res=abs(x-i)+abs(y-j);
            // if(res>1000) continue;
            if(dp[i][j]>f[tmp][res])
            {
                ans+=f[tmp][res];
                dp[i][j]-=f[tmp][res];
            }
            else
            {
                ans+=dp[i][j];
                dp[i][j]=0;
            }
        }
    }
    cout<<ans;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
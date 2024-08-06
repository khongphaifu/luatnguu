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
const ll N=1e6+5;
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

struct bg
{
    ll x,ts,d;
};

struct cmp
{
    bool operator() (bg a,bg b) { return a.ts>b.ts;}
};

ll n;
ll a[N];
ll dd[1007][1007],f[1007][1007];

void dij(ll s)
{
    priority_queue<bg,vector<bg>,cmp> h;
    fu(i,1,n) fu(j,1,n) f[i][j]=inf;
    h.push({s,a[2],1});
    f[s][1]=a[s];
    while(!h.empty())
    {
        ll s=h.top().x;
        ll d=h.top().d;
        if(s==n)
        {
            cout<<h.top().ts;
            return;
        }
        h.pop();
        if(dd[s][d]) continue;
        dd[s][d]=1;
        if(s-d>0 && f[s-d][d]> f[s][d]+a[s-d] && !dd[s-d][d])
        {
            f[s-d][d]=f[s][d]+a[s-d];
            h.push({s-d,f[s-d][d],d});
        }
        // s++;
        if(s+d <=n && f[s+d+1][d+1]>f[s][d]+a[s+d+1] && !dd[s+d+1][d+1])
        {
            f[s+d+1][d+1]=f[s][d]+a[s+d+1];
            h.push({s+d+1,f[s+d+1][d+1],d+1});
        }
    }

}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n;
    fu(i,1,n) cin>>a[i];
    // cal(1,1);
    ll ans=inf;
    dij(2);
    // fu(i,1,n) ans=min(ans,f[n][i]);
    // cout<<ans<<el;
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
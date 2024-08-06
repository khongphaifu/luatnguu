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
    ll x,y;
};

bool cmp(bg a,bg b)
{
    return a.x<b.x;
}

ll n,m;
ll a[N],sum[N],f[N];
bg b[N];
ll id1[N],id2[N];

ll cal(ll i,ll j)
{
    return sum[j]-sum[i-1];
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
    fu(i,1,n) sum[i]=sum[i-1]+a[i];
    cin>>m;
    fu(i,1,m) cin>>b[i].x>>b[i].y;
    sort(alla(b,m),cmp);
    fu(i,1,m) id1[i]=b[i].x,id2[i]=b[i].y;
    ll tmp=0,res=1;
    fu(i,id1[res],n)
    {
        if(i==id1[res+1]) res++;
        ll uwu=i-id2[res]+1;
        // if(uwu<=id1[res-1]) f[i]=f[i-1];
        if(uwu<=id1[res] && uwu>id1[res-1]) f[i]=max(f[i-1],f[uwu-1]+cal(uwu,i));
        else f[i]=f[i-1];
    }
    cout<<f[n];

    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}

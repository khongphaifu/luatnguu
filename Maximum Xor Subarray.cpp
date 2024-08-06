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
const ll N=5e6+5;
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

ll test,n,nodes=1;
ll t[N][2];

void add(ll x)
{
    ll r=1;
    fud(i,32,0)
    {
        ll j=((x>>i)&1);
        if(t[r][j]==-1) t[r][j]=++nodes;
        r=t[r][j];
    }
}

ll get(ll x)
{
    ll r=1,ans=0;
    fud(i,32,0)
    {
        ll j=((x>>i)&1);
        if(t[r][1-j]!=-1)
        {
            r=t[r][1-j];
            ans+=(1<<i);
        }
        else r=t[r][j];
    }
    return ans;
}

void sol()
{
    memset(t,-1,sizeof t);
    cin>>n;
    ll ma=0,bx=0;
    add(0);
    fu(i,1,n)
    {
        ll x;cin>>x;
        bx^=x;
        add(bx);
        ma=max(get(bx),ma);
    }
    cout<<ma<<el;
}


signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    test=1;
    while(test--)
    {
        sol();
    }
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
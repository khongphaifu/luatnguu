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

ll n,m;
vector<ll> g[N];
ll var[N];

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>m;
    fu(i,1,m)
    {
        ll x,y;cin>>x>>y;
        g[x].pb(y);
        var[y]++;
    }
    queue<ll> ds;
    fu(i,1,n) if(!var[i]) ds.push(i);
    // if(ds.empty())
    // {
    //     cout<<"IMPOSSIBLE";
    // }
    vector<ll> v;
    while(!ds.empty())
    {
        ll u=ds.front();
        ds.pop();
        v.pb(u);
        // cout<<u<<" ";
        for(auto it:g[u])
        {
            var[it]--;
            if(!var[it]) ds.push(it);
        }
    }
    if(v.size()!=n) cout<<"IMPOSSIBLE";
    else
    {
        for(auto it:v) cout<<it<<" ";
    }
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
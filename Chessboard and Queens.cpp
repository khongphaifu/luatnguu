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
const ll N=8+5;
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

ll dp[N][N];
map<ll,ll> cp,ct,dong,cot;
ll ans=0;

void sol(ll d)
{
    fu(i,1,8)
    {
        if(d+1<=8)
        {
            if(!cp[d-i] && !ct[d+i] && !cot[i] && !dong[d] && !dp[d][i])
            {
                cp[d-i]=1;ct[d+i]=1;cot[i]=1;dong[d]=1;
                sol(d+1);
                cp[d-i]=0;ct[d+i]=0;cot[i]=0;dong[d]=0;
            }
        }
        else
        {
           if(!cp[d-i] && !ct[d+i] && !cot[i] && !dong[d] && !dp[d][i])
            {
                ans++;
            } 
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

    fu(i,1,8)
    {
        fu(j,1,8)
        {
            char x;cin>>x;
            dp[i][j]=(x=='*');
        }
    }

    sol(1);
    cout<<ans;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
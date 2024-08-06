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

string s;
ll pw[N],Hash[N];

ll get(ll i,ll j)
{
    return (Hash[j]-Hash[i-1]*pw[j-i+1] +MOD*MOD)%MOD;
}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>s;
    ll n=s.size();
    s=' '+s;
    pw[0]=1;
    fu(i,1,n) Hash[i]=(Hash[i-1]*base+s[i]-'a'+1)%MOD;
    fu(i,1,n) pw[i]=(pw[i-1]*base)%MOD;
    // cout<<get(2,2)<<el;
    fu(i,1,n)
    {
        ll check=0;
        ll tmp=get(1,i);
        for(ll j=2*i;j<=n;j+=i)
        {
            if(tmp!=get(j-i+1,j))
            {
                check=1;
                break;
            }
        }
        if(check) continue;
        ll res=n%i;
        if(get(1,res)!=get(n-res+1,n)) continue;
        cout<<i<<" ";
    }
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
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
ll dp[507][507],dd[507][507];

ll check(ll i,ll j)
{
    if(s[i]=='?' && s[j]=='?') return 3;
    if(s[i]=='?' )
    {
        if((s[j]==')' || s[j]==']' || s[j]=='}')) return 1;
        else return 0;
    }
    if(s[j]=='?')
    {
        if((s[i]=='(' || s[i]=='{' || s[i]=='['))return 1;
        else return 0;
    }
    if(s[i]=='(' && s[j]==')') return 1;
    if(s[i]=='{' && s[j]=='}') return 1;
    if(s[i]=='[' && s[j]==']') return 1;
    return 0;
}

ll sol(ll i,ll j)
{
    if(i>j)
    {
        dp[i][j]=1;
        return 1;
    }
    if((j-i+1)%2!=0) return 0;
    if((j-i)==1) return dp[i][j]=check(i,j);
    if(dd[i][j]) return dp[i][j];
    dd[i][j]=1;
    ll res=check(i,j)*sol(i+1,j-1) %MOD;
    for(ll k=i+1;k<=j-1;k+=2)
    {
        if(check(i,k)>0)res=(res+check(i,k)*sol(i+1,k-1) %MOD *sol(k+1,j) %MOD)%MOD;
    }
    dp[i][j]=res;
    return res;
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
    // cout<<n<<el;
    cout<<sol(1,n);
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
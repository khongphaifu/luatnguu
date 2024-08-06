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

ll n,k;

bool check(ll x)
{
    ll cnt=0;
    fu(j,0,n-1)
    {
        if((x&(1<<j))) cnt++;
        else cnt--;
        if(cnt<0) return 1;
    }
    return cnt!=0;
}

void sub1()
{
    ll tt=(1<<n)-1;
    ll cnt=0;
    fu(x,0,tt)
    {
        // cnt=0;
        if(check(x)) cnt++;
        if(cnt==k)
        {
            string s="";
            fu(j,0,n-1)
            {
                if((x&(1<<j))) s+=')';
                else s+='(';
            }
            reverse(all(s));
            cout<<s;
            return;
        }
    }
}

ll f[127][10005][2];
ll dd[127][10005][2];
char x[N];

ll cal(ll i,ll c,ll ok)
{
    if(i>n) 
    {
        if(c!=n/2) return 0;
        else return (ok);
    }
    if(dd[i][c][ok]) return f[i][c][ok];
    dd[i][c][ok]=1;
    ll cnt=cal(i+1,c+1,ok)+cal(i+1,c,(ok||(c<(i-c))));
    f[i][c][ok]=cnt;
    return cnt;
}

void riel(ll i,ll c,ll ok)
{
    if(i>n) return;
    if(cal(i+1,c+1,ok)<k)
    {
        k-=cal(i+1,c+1,ok);
        x[i]=')';
        riel(i+1,c,(ok||(c<(i-c))));
    }
    else
    {
        x[i]='(';
        riel(i+1,c+1,ok);
    }
    // if(ok|| c!=n/2)
    
    // f[i][c][ok]=cal(i+1,c+1,ok)+cal(i+1,c,ok||(c<(i-c)));
}

void sub2()
{
    riel(1,0,0);
    fu(i,1,n) cout<<x[i];
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
    n*=2;
    sub2();
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
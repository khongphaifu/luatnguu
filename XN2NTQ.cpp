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


ll n;
ll nt[2*N],dd[N];
map<ll,ll> mp;

void sang()
{
    nt[0]=nt[1]=-1;
    fu(i,2,2e6)
    {
        if(nt[i]==0)
        {
            // mp[i]++;
            for(ll j=i;j<=2e6;j+=i) nt[j]=i;
        }
    }
}

struct bg
{
    ll x,id;
};

bg a[N];

bool cmp(bg a,bg b)
{
    return a.x<b.x;
}

void sol()
{
    cout<<n/2<<el;
}

// ll dd[N];

void sol1()
{
    ll ans=0;
    fu(i,1,n)
    {
        fud(j,i-1,1)
        {
            if(nt[a[i].x+a[j].x]==a[i].x+a[j].x && !dd[i] && !dd[j])
            {
                dd[i]=1;
                dd[j]=1;
                ans++;
            }
        }
    }
    cout<<ans;
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
    fu(i,1,n)
    {
        cin>>a[i].x;
        a[i].id=i;
    }
    sang();
    sort(alla(a,n),cmp);
    ll check=0;
    fu(i,1,n)
    {
        if(i!=a[i].x)
        {
            check=1;break;
        }
    }
    // cout<<check<<el;
    if(!check) sol();
    else sol1();

    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
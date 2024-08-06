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

ll n;
ll a[N];

namespace sub1
{
    void sol()
    {
        ll ans=-inf;
        ll tt=(1<<n)-1;
        fu(x,0,tt)
        {
            ll res=0;
            ll dem=0;
            fu(i,1,n)
            {
                if((x&(1<<(i-1)))!=0)
                {
                    dem++;
                    if(dem%2==0) res-=a[i];
                    else res+=a[i];
                }
            }
            ans=max(ans,res);
        }
        cout<<ans;
    }
}

namespace sub2
{
    ll f[3][N];
    void sol()
    {
        fu(i,1,n)
        {
            f[1][i]=max(f[1][i-1],f[2][i-1]+a[i]);
            f[2][i]=max(f[2][i-1],f[1][i-1]-a[i]);
        }
        cout<<max(f[1][n],f[2][n]);
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
    fu(i,1,n)cin>>a[i];
    if(n<=20)
    sub1::sol();
    else
    sub2::sol();
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
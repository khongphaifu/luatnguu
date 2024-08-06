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
/*🥑*/
template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}
/*v*/
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

ll n,m;
struct bg
{
    ll t,r;
} a[N];

namespace sub1
{
    ll f[N],sum[N],cnt[N];
    bool cmp(bg a,bg b)
    {
        return a.t>b.t;
    }

    void sol()
    {
        // a[n+1].t=a[n+1].r=0;
        // n++;
        sort(alla(a,n),cmp);
        // fu(i,1,n) cout<<a[i].t<<" "<<a[i].r<<el;
        fu(i,1,n) f[i]=f[i-1]+a[i].t*a[i].r,sum[i]=sum[i-1]+a[i].t*a[i].r,cnt[i]=cnt[i-1]+a[i].r;
        // cout<<sum[2]-sum[1-1]-(cnt[2]-cnt[1-1])*a[2].t<<el;
        ll cur=1;
        fu(i,1,n)
        {
            // ll tmp=f[i];
            f[i]=f[i-1]+a[i].t*a[i].r;
            fu(j,cur,i)
            {
                if(sum[i]-sum[j-1]-(cnt[i]-cnt[j-1])*a[i].t+m+f[j-1]<f[i])
                {
                    f[i]=min(f[i],sum[i]-sum[j-1]-(cnt[i]-cnt[j-1])*a[i].t+m+f[j-1]);
                    cur=j;
                }
            }
            // cout<<f[i]<<el;
        }
        cout<<f[n];
    }   
}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".inp" ,"r",stdin) ; freopen(TASK".out" ,"w",stdout);
    }

    cin>>n>>m;
    fu(i,1,n) cin>>a[i].t>>a[i].r;
    sub1::sol();
    
    // số MOD bro
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
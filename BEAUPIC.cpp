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

ll n,k;
ll a[N],rmq1[32][N],rmq2[32][N];

void build_rmq()
{
    fu(i,1,n) rmq1[0][i]=a[i],rmq2[0][i]=a[i];
    fu(i,1,30)
    {
        fu(u,1,n+1-(1<<i))
        {
            rmq1[i][u]=min(rmq1[i-1][u],rmq1[i-1][u+(1<<(i-1))]);
            rmq2[i][u]=max(rmq2[i-1][u],rmq2[i-1][u+(1<<(i-1))]);
        }
    }
}

ll get1(ll l,ll r)
{
    ll k=log2(r-l+1);
    return min(rmq1[k][l],rmq1[k][r-(1<<k)+1]);
}

ll get2(ll l,ll r)
{
    ll k=log2(r-l+1);
    return max(rmq2[k][l],rmq2[k][r-(1<<k)+1]);
}

ll check(ll l,ll r)
{
    return get2(l,r)-get1(l,r)<=k;
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
    fu(i,1,n) cin>>a[i];
    build_rmq();
    ll ans=0;
    fu(i,1,n)
    {
        ll l=i,r=n;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(check(i,mid)) l=mid+1;
            else r=mid-1;
        }
        ans+=l-i;
    }
    cout<<ans;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
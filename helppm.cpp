#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb  push_back  
#define ll  int
#define el  "\n"
#define alla(a,n)  a+1,a+n+1
#define fi first
#define se second
#define all(v)  v.begin(),v.end()
#define fu(i,a,b)  for(ll i=a;i<=b;i++)
#define fud(i,a,b)  for(ll i=a;i>=b;i--)

const ll MOD=1e9+7 ;//1234567891;
const ll inf=1e9;
const ll base = 311;
const ll N=1e6+5;
const ll N1=1e3+5;

template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

ll n,m,k;
ll dp[507][507];
ll s[N];

ll HCN(ll x1,ll y1,ll x2,ll y2)
{
    return dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>m>>k;
    fu(i,1,n) fu(j,1,m)
    {
        ll x;cin>>x;
        dp[i][j]=x+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
    }

    ll ans=inf;
    ll x1,y1,x2,y2;
    fu(i,1,n) fu(j,i,n)
    {
        ll xx=1;
        fu(x,1,m)
        {
            s[x]=s[x-1]+HCN(x,i,x,j);
            if(s[x]<k) continue;
            while(s[x]-s[xx]>=k) xx++;
            ll res=(x-xx+1)*(j-i+1);
            if(res<ans)
            {
                ans=res;
                x1=xx,y1=i;
                x2=x,y2=j;
            }
        }
    }
    if(ans==inf)
    {
        cout<<-1;
    }
    else cout<<ans<<el<<x1<<" "<<y1<<" "<<x2<<" "<<y2;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
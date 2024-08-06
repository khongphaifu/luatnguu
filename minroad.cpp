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

struct bg
{
    ll d,k;
};

ll n,a,b;
ll sa[N],sb[N];
bg tri[N];

bool cmp(bg a,bg b)
{
    return a.d<b.d;
}

namespace subfull
{
    void sol()
    {
        fu(i,1,n)
        {
            sa[i]=sa[i-1];
            sb[i]=sb[i-1];
            if(tri[i].k==1) sa[i]++;
            else sb[i]++;
        }
        // fu(i,1,n) cout<<sa[i]<<" ";
        // cout<<el;
        ll ans=inf;
        fu(i,1,n)
        {
            if(sa[i]>=a && sb[i]>=b)
            {
                ll j=upper_bound(alla(sa,n),sa[i]-a)-sa;
                ll k=upper_bound(alla(sb,n),sb[i]-b)-sb;
                j=min(j,k);
                ans=min(ans,tri[i].d-tri[j].d);
                // if(i==n) cout<<j<<el;
            }
        }
        cout<<(ans==inf ? -1: ans);
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

    cin>>n>>a>>b;
    fu(i,1,n) cin>>tri[i].d>>tri[i].k;
    sort(alla(tri,n),cmp);
    // fu(i,1,n) cout<<tri[i].d<<" "<<tri[i].k<<el;
    subfull::sol();
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
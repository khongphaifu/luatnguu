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

ll n,m;
ll a[N],b[N],st[4*N];

void build(ll id,ll l,ll r)
{
    if(l==r)
    {
        st[id]=a[l];return;
    }
    ll mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=max(st[2*id],st[2*id+1]);
}

void up(ll id,ll l,ll r,ll i,ll val)
{
    if(i<l || i>r) return;
    if(l==r)
    {
        st[id]+=val;return;
    }
    ll mid=(l+r)/2;
    up(2*id,l,mid,i,val);
    up(2*id+1,mid+1,r,i,val);
    st[id]=max(st[2*id+1],st[2*id]);
}

ll get(ll id,ll l,ll r,ll u,ll v)
{
    if(u>r || l>v) return -inf;
    if(u<=l && r<=v) return st[id];
    ll mid=(l+r)/2;
    return max(get(2*id,l,mid,u,v),get(2*id+1,mid+1,r,u,v));
}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>m;
    fu(i,1,n) cin>>a[i];
    fu(j,1,m) cin>>b[j];
    build(1,1,n);
    fu(i,1,m)
    {
        ll l=1,r=n;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(get(1,1,n,1,mid)>=b[i]) r=mid-1;
            else l=mid+1;
        }
        ll ans=r+1;
        up(1,1,n,ans,-b[i]);
        cout<<(ans<=n ? ans : 0)<<" ";
    }
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
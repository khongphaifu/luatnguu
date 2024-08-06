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
ll a[N],st[4*N];

void up(ll id,ll l,ll r,ll i,ll val)
{
    if(i<l || i>r) return;
    if(l==r)
    {
        st[id]=val;return;
    }
    ll mid=(l+r)/2;
    up(2*id,l,mid,i,val);
    up(2*id+1,mid+1,r,i,val);
    st[id]=st[2*id+1]+st[2*id];
}

ll get(ll id,ll l,ll r,ll u,ll v)
{
    if(u>r || l>v) return 0;
    if(u<=l && r<=v) return st[id];
    ll mid=(l+r)/2;
    return get(2*id,l,mid,u,v)+get(2*id+1,mid+1,r,u,v);
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
    unordered_map<ll,ll> mp;
    ll ans=0;
    fu(i,1,n)
    {
        up(1,1,n,i,1);
        up(1,1,n,mp[a[i]],0);
        ll l=1,r=i;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(get(1,1,n,mid,i)<=k) r=mid-1;
            else l=mid+1;
        }
        ans+=i-(r+1)+1;
        // if(i==2)
        // {
        //     cout<<get(1,1,n,2,2)<<"hehe"<<r<<el;
        // }
        // cout<<ans<<el;
        mp[a[i]]=i;
    }
    cout<<ans;    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
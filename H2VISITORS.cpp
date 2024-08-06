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
const ll N=1e5+5;
const ll N1=1e3+5;
/*🥑*/
template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}
/*v*/
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

ll n;
ll a[N],f[N];

// namespace sub1
// {
//     void sol()
//     {
//         ll x1=0,x2=0;
//         fu(i,1,n)
//         {
//             if(abs(x1-a[i])<=abs(x2-a[i]))f[i]=f[i-1]+abs(x1-a[i]),x1=a[i];
//             else f[i]=f[i-1]+abs(x2-a[i]),x2=a[i];
//         }

//         cout<<f[n];
//     }
// }

// namespace sub2
// {

//     const ll N=2e3+5;

//     ll w[N][N],sum[N];

//     void sol()
//     {
    
//         fu(i,1,n) fu(j,i+1,n) w[i][j]=w[i][j-1]+abs(a[j-1]-a[j]);
//         fu(i,1,n) f[i]=inf;
//         // f[0]
//         f[1]=abs(a[1]);
//         ll ans=inf;
//         fu(i,2,n)
//         {
//             fud(j,i-1,1)
//             {
//                 f[i]=min(f[i],f[j]+abs(a[i]-a[j-1])+w[j][i-1]) // sum[i-1] - sum[j-1];
//                 // if(a[i]>a[j-1]) f[j]+a[i]-a[j-1]+sum[i-1]-sum[j-1];
//                 // else f[j]+a[j-1]-a[i]+sum[i-1]-sum[j-1];
//             }
//             ans=min(ans,f[i]+w[i][n]);
//         }
//         cout<<ans;
//     }
// }

namespace sub3
{

    ll sum[N],h[4*N],g[4*N];
    
    void up(ll id,ll l,ll r,ll i,ll val,ll st[4*N])
    {
        if(i<l || i>r) return;
        if(l==r)
        {
            st[id]=min(val,st[id]);return;
        }
        ll mid=(l+r)/2;
        up(2*id,l,mid,i,val,st);
        up(2*id+1,mid+1,r,i,val,st);
        st[id]=min(st[2*id+1],st[2*id]);
    }
    
    ll get(ll id,ll l,ll r,ll u,ll v,ll st[4*N])
    {
        if(u>r || l>v) return inf;
        if(u<=l && r<=v) return st[id];
        ll mid=(l+r)/2;
        return min(get(2*id,l,mid,u,v,st),get(2*id+1,mid+1,r,u,v,st));
    }
    map<ll,ll> mp;

    void sol()
    {
        vector<ll> v;
        fu(i,0,n) v.pb(a[i]);
        sort(all(v));
        v.resize(unique(all(v))-v.begin());
        fu(i,0,v.size()-1)
        {
            mp[v[i]]=i+1;
        }
        ll m=v.size();
        fu(i,1,n) sum[i]=sum[i-1]+abs(a[i]-a[i-1]);
        // f[1]=abs(a[1]);
        f[1]=abs(a[1]);
        ll ans= inf ;
        fu(i,1,4*m) h[i]=g[i]=inf;
        up(1,1,m,mp[0],f[1] - sum[1] + a[0] , h) ;
        up(1,1,m,mp[0],f[1] - sum[1] - a[0] , g) ;

        fu(i,2,n) {
            f[i] = get(1,1,m,mp[a[i]],m,h) + sum[i-1] - a[i] ;
            f[i] = min( get(1,1,m,1,mp[a[i]],g) + sum[i-1] + a[i] , f[i] ) ; 
            up(1,1,m,mp[a[i-1]],f[i] + a[i-1] - sum[i],h) ; 
            up(1,1,m,mp[a[i-1]],f[i] - a[i-1] - sum[i],g) ; 
            ans = min(ans , f[i] + sum[n] - sum[i]) ;
        }

        cout<<ans;

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
    fu(i,1,n) cin>>a[i];
    sub3::sol();
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
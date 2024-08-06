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
const ll N=5e2+5;
const ll N1=1e6+5;
/*🥑*/
template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}
/*v*/
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
ll n,m,t;
ll h[N][N],s[N][N];
// vector<pair<ll,ll>> start;

// namespace sub1
// {
//     ll dd[N][N];

//     bool inside(ll x,ll y)
//     {
//         return (x>=1 && x<=n && y>=1 && y<=m);
//     }

//     ll check(ll mid,ll x,ll y,ll d)
//     {
//         ll res=0;
//         queue<pair<ll,ll>> q;
//         q.push({x,y});
//         dd[x][y]=d;
//         res++;
//         if(res>=t) return 1;
//         while(!q.empty())
//         {
//             x=q.front().fi;
//             y=q.front().se;
//             q.pop();
//             fu(i,0,3)
//             {
//                 ll sx=x+dx[i];
//                 ll sy=y+dy[i];
//                 if(inside(sx,sy) && dd[sx][sy]!=d && abs(h[sx][sy]-h[x][y])<=mid)
//                 {
//                     dd[sx][sy]=d;
//                     res++;
//                     if(res>=t) return 1;
//                     q.push({sx,sy});
//                 }
//             }
//         }
//         return res>=t;
//     }

//     void sol()
//     {
//         ll ans=0;
//         ll d=0;
//         for(auto it:start)
//         {
//             ll l=0,r=1e9;
//             while(l<=r)
//             {
//                 d++;
//                 ll mid=(l+r)/2;
//                 if(check(mid,it.fi,it.se,d)) r=mid-1;
//                 else l=mid+1;
//             }
//             // cout<<r+1<<el;
//             ans+=r+1;
//         }
//         cout<<ans;
//     }
// }

namespace sub2
{
    ll f[N1],a[N1],sz[N1];
    ll ans=0;

    struct bg
    {
        ll u,v,w;
    };

    bg e[(ll)1e6];

    bool inside(ll x,ll y)
    {
        return (x>=1 && x<=n && y>=1 && y<=m);
    }

    ll root(ll x) {return (f[x]<0? x : f[x]=root(f[x]));}

    void HN(ll u,ll v,ll res)
    {
        u=root(u),v=root(v);
        if(u==v) return;
        f[v]=u;
        sz[u]+=sz[v];
        a[u]+=a[v];
        if(a[u] && sz[u]>=t)
        {
            ans+=res*a[u];
            a[u]=0;
        }
    }

    ll change(ll i,ll j)
    {
        return j+(i-1)*m;
    }

    bool cmp(bg a,bg b)
    {
        return a.w<b.w;
    }

    void sol()
    {
        ll d=0;
        fu(i,1,n) fu(j,1,m)
        {
            ll id1=change(i,j);
            a[id1]=s[i][j];
            fu(k,0,3)
            {
                ll x=i+dx[k];
                ll y=j+dy[k];
                if(inside(x,y))
                {
                    d++;
                    ll id2=change(x,y);
                    e[d]={id1,id2,abs(h[x][y]-h[i][j])};
                }
            }
        }
        n*=m;
        fu(i,1,n) f[i]=-1,sz[i]=1;
        sort(alla(e,d),cmp);
        fu(i,1,d)
        {
            HN(e[i].u,e[i].v,e[i].w);

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

    cin>>n>>m>>t;
    fu(i,1,n) fu(j,1,m) cin>>h[i][j];
    fu(i,1,n) fu(j,1,m)
    {
        ll x;cin>>x;
        s[i][j]=x;
        // if(x==1) start.pb({i,j});
    }

    sub2::sol();

    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
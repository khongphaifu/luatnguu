#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define             pb  push_back  
#define             ll  long long
#define             el  "\n"
#define      alla(a,n)  a+1,a+n+1
#define         all(v)  v.begin(),v.end()
#define      fu(i,a,b)  for(ll i=a;i<=b;i++)
#define     fud(i,a,b)  for(ll i=a;i>=b;i--)

const ll N=1e6+5,MOD=1e9+7,inf=1e18;

struct bg
{
    ll x,y,z,id;
};
ll n;
ll f[N];
ll ans;
struct bg1
{
    ll x,y,w;
};

bool cmp(bg1 a,bg1 b){return a.w<b.w;}
bool cmp1(bg a,bg b){return a.x<b.x;}
bool cmp2(bg a,bg b){return a.y<b.y;}
bool cmp3(bg a,bg b){return a.z<b.z;}

ll root(ll u)
{
    return (f[u]<0 ? u : f[u]=root(f[u]));
}

void HN(ll x,ll y)
{
    ll t=f[x]+f[y];
    if(f[x]>f[y])
    {
        f[x]=t;
        f[y]=x;
    }
    else
    {
        f[y]=t;
        f[x]=y;
    }
}

bg a[N];

bg1 e[N];

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n;
    fu(i,1,n) cin>>a[i].x>>a[i].y>>a[i].z,a[i].id=i;
    ll d=0;
    sort(alla(a,n),cmp1);
    fu(i,2,n)
    {
        ll u=a[i-1].id;
        ll v=a[i].id;
        ll ts=(a[i].x-a[i-1].x);
        d++;
        e[d]={u,v,ts};
    }
    sort(alla(a,n),cmp2);
    fu(i,2,n)
    {
        ll u=a[i-1].id;
        ll v=a[i].id;
        ll ts=(a[i].y-a[i-1].y);
        d++;
        e[d]={u,v,ts};
    }
    sort(alla(a,n),cmp3);
    fu(i,2,n)
    {
        ll u=a[i-1].id;
        ll v=a[i].id;
        ll ts=(a[i].z-a[i-1].z);
        d++;
        e[d]={u,v,ts};
    }
    fu(i,1,d) f[i]=-1;
    sort(alla(e,d),cmp);
    fu(i,1,d)
    {
        ll u=e[i].x;
        ll v=e[i].y;
        u=root(u);
        v=root(v);
        if(u!=v)
        {
            ans+=e[i].w;
            HN(u,v);
        }
    }
    cout<<ans;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
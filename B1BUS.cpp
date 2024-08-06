// khongphaifu - Mai Ngọc Phú - T2K33 - THPT Chuyên Lê Khiết
// VOI... 
// Program link: https://tinhoclk.com/problem/b1bus
// Program name: v 
#define TASK  "B1BUS"
// sol: nén số + it + qhd



#include <bits/stdc++.h>
#define             pl  pair<ll,ll>  
#define             pb  push_back  
#define             ll  long long
#define             db  double
#define            nnc  signed main()
#define             se  second 
#define             fi  first
#define             el  "\n"
#define         all(a)  a.begin(),a.end()
#define      alla(a,n)  a+1,a+n+1
#define     FOR(i,a,b)  for(ll i=a;i<=b;i++)
#define    FORD(i,a,b)  for(ll i=a;i>=b;i--)
#define    FORN(i,a,b)  for(ll i=a;i<b;i++)
#define   FORDN(i,a,b)  for(ll i=a;i>b;i--)
#define     print(a,n)  for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<el;
#define      printv(v)  for(auto it:v) cout<<it<<" ";cout<<el;
#define     printvp(v)  for(auto it:v) cout<<it.fi<<" "<<it.se<<el;
#define       ieozzool  cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
using namespace std;


ll mlt=0;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const ll N = 1e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll m,n,k;
    ll st[4*N],f[N],dd[N];

    struct bg
    {
        ll x,y,z;
    };

    bool cmp(bg a,bg b)
    {
        if(a.y==b.y) return a.x<b.x;
        return a.y<b.y;
    }

    bool cmp1(bg a, bg b)
    {
        if(a.x==b.x) return a.y<b.y;
        return a.x<b.x;    
    }

    bg a[N],b[N];

    void up(ll id,ll l ,ll r,ll i,ll val)
    {
        if(i<l || i>r) return;
        if(l==r)
        {
            st[id]=val;return;
        }
        ll mid=(l+r)/2;
        up(2*id,l,mid,i,val);
        up(2*id+1,mid+1,r,i,val);
        st[id]=max(st[2*id],st[2*id+1]);
    }

    ll get(ll id,ll l,ll r,ll u,ll v)
    {
        if(u>r || l>v) return -inf;
        if(u<=l && r<=v) return st[id];
        ll mid=(l+r)/2;
        return max(get(2*id,l,mid,u,v),get(2*id+1,mid+1,r,u,v));
    }

    void sol()
    {
        cin>>m>>n>>k;
        FOR(i,1,k) cin>>a[i].x>>a[i].y>>a[i].z;
        sort(alla(a,k),cmp);
        // FOR(i,1,k) cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<el;
        FOR(i,1,k) b[i].x=a[i].x,b[i].y=i;
        // FOR(i,1,k) cout<<b[i].x<<" "<<b[i].y<<el;
        sort(alla(b,k),cmp1);
        // FOR(i,1,k) cout<<b[i].x<<" "<<b[i].y<<el;
        ll res=1;
        dd[1]=1;
        FOR(i,2,k)
        {
            if(b[i].x!=b[i-1].x) res++;
            dd[i]=res;
        }
        FOR(i,1,k) b[i].x=dd[i];
        // FOR(i,1,k) cout<<b[i].x<<" "<<b[i].y<<el;
        sort(alla(b,k),cmp);
        // FOR(i,1,k) cout<<b[i].x<<" "<<b[i].y<<el;
        FOR(i,1,k) a[i].x=b[i].x;
        // FOR(i,1,k) cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<el;
        ll ans=0;
        FOR(i,1,k)
        {
            f[i]=a[i].z+get(1,1,res,1,a[i].x);
            up(1,1,res,a[i].x,f[i]);
            ans=max(ans,f[i]);
        }
        cout<<ans;
    }
}



// "..."

nnc
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }
    bef();
    if(mlt) cin>>test;
    // cout<<test<<el;
    FOR(i,1,test)
    {
        mnp::sol();
    }
    ieozzool;
}
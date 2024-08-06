int mlt=0;
int test=1;

#include <bits/stdc++.h>
using namespace std;


#define           TASK  "TRAVEL"
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




ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const ll N = 2e3 + 5 , N1 = 2e3 + 5 , MOD = 1e9 + 7 , inf = 1e18;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{

    struct bg
    {
        ll x,y;
    };

    bool cmp(bg a, bg b)
    {
        if(a.y==b.y) return a.x<b.x;
        return a.y<b.y;
    }

    bool cmp1(bg a,bg b)
    {
        if(a.x==b.x) return a.y<b.y; 
        return a.x<b.x;
    }

    ll n;
    bg a[N],b[N];
    ll f[N],st[4*N];
    ll dp[N1][N1];

    void reset(ll id,ll l,ll r)
    {
        if(l==r)
        {
            st[id]=0;return;
        }
        ll mid=(l+r)/2;
        reset(2*id,l,mid);
        reset(2*id+1,mid+1,r);
        st[id]=st[2*id]+st[2*id+1];
    }    

    void up(ll id,ll l,ll r,ll i,ll val)
    {
        if(i<l || r<i) return;
        if(l==r)
        {
            st[id]=(st[id]+val)%MOD;return;
        }
        ll mid=(l+r)/2;
        up(2*id,l,mid,i,val);
        up(2*id+1,mid+1,r,i,val);
        st[id]=(st[2*id]+st[2*id+1])%MOD;
    }

    ll get(ll id,ll l,ll r,ll u,ll v)
    {
        if(v<l || r<u) return 0;
        if(u<=l && r<=v) return st[id];
        ll mid=(l+r)/2;
        return (get(2*id,l,mid,u,v)+get(2*id+1,mid+1,r,u,v))%MOD;
    }

    void sol()
    {
        cin>>n;
        FOR(i,1,n) cin>>a[i].x;
        FOR(i,1,n) cin>>a[i].y;
        sort(alla(a,n),cmp);
        FOR(i,1,n)
        {
            b[i].x=a[i].x;b[i].y=i;
        }
        sort(alla(b,n),cmp1);
        FOR(i,1,n) b[i].x=i;
        sort(alla(b,n),cmp);
        // FOR(i,1,n) cout<<b[i].x<<" ";
        // cout<<el;
        FOR(i,1,n) dp[1][i]=1;
        cout<<n<<" ";
        FOR(i,2,n)
        {
            ll ans=0;
            reset(1,1,n);
            FOR(j,i-1,n)
            {
                dp[i][j]=get(1,1,n,b[j].x+1,n);
                up(1,1,n,b[j].x,dp[i-1][j]);
                ans=(ans+dp[i][j])%MOD;
            }
            cout<<ans<<" ";
        }
        // cout<<el;
        // FOR(i,1,n)
        // {
        //     FOR(j,1,n) cout<<dp[i][j]<<" ";
        //     cout<<el;
        // }


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
    FOR(i,1,test)
    {
        mnp::sol();
    }
    ieozzool;
}

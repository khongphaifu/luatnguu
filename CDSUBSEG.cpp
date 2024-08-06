#include <bits/stdc++.h>
using namespace std;


#define           TASK  "GOS"
#define             pl  pair<ll,ll>  
#define             pb  push_back  
#define             ll  int
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


ll mlt=1 ;
ll test=1 ;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const ll N = 1e6 + 5 , N1 = 2e3 + 5 , MOD = 1e9 + 7 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll n,res;
    ll a[N],st[20][N];

    void pre()
    {
        FOR(i,1,n) st[0][i]=a[i];
        FOR(j,1,19) for(ll i=1;i+(1<<j) -1 <=n;i++) st[j][i]=gcd(st[j-1][i],st[j-1][i+(1<<(j-1))]); 
    }

    ll get(ll l,ll r)
    {
        ll k=__lg(r-l+1);
        return gcd(st[k][l],st[k][r-(1<<k)+1]);
    }

    bool check(ll i,ll mid)
    {
        // ll tmp=0;
        // FOR(j,i,mid) tmp=gcd(tmp,a[j]);
        // return (tmp==1);
        return (get(i,mid)==1);
    }

    ll tknp(ll l,ll r,ll i)
    {
        while(l+1<r)
        {
            ll mid=(l+r)/2;
            if(check(i,mid)) r=mid;
            else l=mid;
        }
        // if(check(i,r+1) && r+1<=n) return r+1;
        if(!check(i,r)) return r;
        else if(!check(i,l)) return l;
        else return i-1;
    }

    void sol()
    {
        cin>>n;
        // FOR(i,1,n) a[i]=0;
        // FOR(i,1,4*n) st[i]=0;
        FOR(i,0,20) FOR(j,1,n) st[i][j]=0;
        ll res=0;
        FOR(i,1,n) 
        {
            cin>>a[i],a[i]=abs(a[i]);
            if(a[i]==1) res++;
        }
        if(res==n)
        {
            cout<<0<<el;return;
        }
        pre();
        // cout<<get(1,6)<<el;
        ll ans=1;
        FOR(i,1,n)
        {
            res=i+ans;
            if(res>n) break;
            ans=max(ans,tknp(res,n,i)-i+1);
        }
        cout<<ans<<el;
        
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
        // full::sol();
    }
    ieozzool;
}
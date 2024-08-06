#include <bits/stdc++.h>
using namespace std;


#define           TASK  "D1CONTACT"
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


ll mlt=0;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const ll N = 1e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9 +7, inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll n,m;
    ll a[N],st1[N*4],st2[N*4];

    void up1(ll id,ll l,ll r,ll i,ll val)
    {
        if(i<l || i>r) return;
        if(l==r)
        {
            st1[id]+=val;return;
        }
        ll mid=(l+r)/2;
        up1(2*id,l,mid,i,val);
        up1(2*id+1,mid+1,r,i,val);
        st1[id]=st1[2*id]+st1[2*id+1];
    }

    ll get1(ll id,ll l,ll r,ll u,ll v)
    {
        if(v<l || r<u) return 0;
        if(u<=l && r<=v) return st1[id];
        ll mid=(l+r)/2;
        return get1(2*id,l,mid,u,v)+get1(2*id+1,mid+1,r,u,v);
    }

    void up2(ll id,ll l,ll r,ll i,ll val)
    {
        if(i<l || i>r) return;
        if(l==r)
        {
            st2[id]+=val;return;
        }
        ll mid=(l+r)/2;
        up2(2*id,l,mid,i,val);
        up2(2*id+1,mid+1,r,i,val);
        st2[id]=st2[2*id]+st2[2*id+1];
    }

    ll get2(ll id,ll l,ll r,ll u,ll v)
    {
        if(v<l || r<u) return 0;
        if(u<=l && r<=v) return st1[id];
        ll mid=(l+r)/2;
        return get2(2*id,l,mid,u,v)+get2(2*id+1,mid+1,r,u,v);
    }

    ll pw(ll a,ll b)
    {
        if(b==0) return 1;
        ll tmp=pw(a,b/2);
        if(b%2==0) return tmp*tmp%MOD;
        else return tmp*tmp %MOD *a %MOD;
    }

    void sol()
    {
        cin>>n>>m;
        FOR(i,1,m)
        {
            ll p,q,l;
            cin>>p>>q>>l;
            // if(p>q) swap(p,q);
            FOR(j,p,p+l-1)
            {
                if(!a[j]) a[j]=1;
                else a[q+(j-p)]=1;
            }
        }
        ll res=0;
        FOR(i,1,n)
        {
            // a[i]+=a[i-1];
            if(!a[i]) res++;
        }
        cout<<pw(2,res)%MOD;
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
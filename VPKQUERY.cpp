int mlt=0;
int test=1;

#include <bits/stdc++.h>
using namespace std;


#define           TASK  "VPKQUERY"
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

const ll N = 1e6 + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e18;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{

    ll n,q;
    ll a[N];
    vector<ll> st[4*N];

    void build(ll id,ll l,ll r)
    {
        if(l==r)
        {
            st[id].pb(a[l]);return;
        }
        ll mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        st[id]=st[2*id];
        for(auto it:st[2*id+1]) st[id].pb(it);
            sort(all(st[id]));
    }

    ll get(ll id ,ll l, ll r,ll u,ll v,ll k)
    {
        if(u>r || l>v) return 0;
        if(u<=l && r<=v)
        {
            ll tmp=upper_bound(all(st[id]),k)-st[id].begin();
            return st[id].size()-tmp;
        }
        ll mid=(l+r)/2;
        return get(2*id,l,mid,u,v,k)+get(2*id+1,mid+1,r,u,v,k);
    }
    
    
    void sol()
    {
        cin>>n>>q;
        FOR(i,1,n) cin>>a[i];
        build(1,1,n);
        // FOR(i,1,4*n)
        // {
        //     for(auto it:st[i]) cout<<it<<" ";
        //         cout<<el;
        // }
        while(q--)
        {
            ll i,j,k;cin>>i>>j>>k;
            ll ans=get(1,1,n,i,j,k);
            cout<<ans<<el;
        }


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

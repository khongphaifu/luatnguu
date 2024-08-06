#include <bits/stdc++.h>
using namespace std;


#define           TASK  "FPOINT"
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

const ll N = 1e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll n;
    ll x[N],y[N],sx[N],sy[N],sxi[N],syi[N],xi[N],yi[N];
    
    void sol()
    {
        cin>>n;
        ll sumx=0,sumy=0,ans=inf,ans1=inf,ans2=inf;
        FOR(i,1,n) cin>>x[i]>>y[i],sumx+=x[i],sumy+=y[i];
        sort(alla(x,n));sort(alla(y,n));
        FOR(i,1,n) sx[i]=sx[i-1]+x[i],sy[i]=sy[i-1]+y[i],xi[i]=x[i]-i,yi[i]=y[i]-i;
        sort(alla(xi,n));sort(alla(yi,n));
        FOR(i,1,n) sxi[i]=sxi[i-1]+xi[i],syi[i]=syi[i-1]+yi[i];
        ll mid1=sumy/n,mid2=sumx/n,res;
        if(sumx%n!=0) mid2++;
        if(sumy%n!=0) mid1++;
        ll mid=lower_bound(alla(y,n),mid1)-y;
        // cout<<mid1<<el;
        // sort(alla(sxi,n));sort(alla(syi,n
        // FOR(i,1,n) cout<<yi[i]<<" ";
        // cout<<el;
        FOR(i,1,n)
        {
            ll tmp=y[i]-i;
            ll j=upper_bound(alla(yi,n),tmp)-yi;
            j--;
            ans1=min(ans1,j*tmp-syi[j]+(syi[n]-syi[j])-(n-j)*tmp);
            // cout<<tmp<<el;
            // if(i==4) cout<<j*tmp-syi[j]+(syi[n]-syi[j])-(n-j)*tmp<<el;
        }
        FOR(i,1,n)
        {
            ll tmp=x[i]-i;
            ll j=upper_bound(alla(xi,n),tmp)-xi;
            j--;
            ans2=min(ans2,j*tmp-sxi[j]+(sxi[n]-sxi[j])-(n-j)*tmp);
        }
        // ans1=0,ans2=0;
        // FOR(i,1,mid)
        // {
        //     ans1+=abs(y[mid]-abs(mid-i)-y[i]);
        //     // cout<<ans1<<el;
        // }
        // // cout<<y[mid]<<el;
        // // cout<<ans1<<el;
        // FOR(i,mid,n)
        // {
        //     ans1+=abs(y[mid]+abs(mid-i)-y[i]);
        // }
        // // cout<<ans1<<el;
        // mid=lower_bound(alla(x,n),mid2)-x;
        // FOR(i,1,mid)
        // {
        //     ans2+=abs(x[mid]-abs(mid-i)-x[i]);
        // }
        // FOR(i,mid,n)
        // {
        //     ans2+=abs(x[mid]+abs(mid-i)-x[i]);
        // }
        // cout<<ans1<<" "<<ans2<<el;
        // cout<<mid1<<" "<<mid2<<el;
        FOR(i,1,n)
        {
            ans=min(ans,i*x[i]-(sx[i])+(sx[n]-sx[i])-(n-i)*x[i]+ans1);
            ans=min(ans,i*y[i]-(sy[i])+(sy[n]-sy[i])-(n-i)*y[i]+ans2);
            // if(ans==-1) cout<<i<<el;
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
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

ll n;
ll a[N],b[N];

ll pw(ll a,ll b)
{
    if(b==0) return 1;
    ll tmp=pw(a,b/2);
    if(b%2==0) return tmp*tmp%MOD;
    else return tmp*tmp%MOD * a%MOD;
}

ll C(ll k,ll n)
{
    return a[n]*b[k] %MOD * b[n-k] %MOD;
}

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
    a[0]=1;
    fu(i,1,1e6) a[i]=(a[i-1]*i)%MOD;
    fu(i,1,1e6) b[i]=pw(a[i],MOD-2);
    b[0]=1;
    while(n--)
    {
        ll a,b;cin>>a>>b;
        cout<<C(b,a)<<el;
    }
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
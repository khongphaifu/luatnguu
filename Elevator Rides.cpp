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

const ll N=(1<<21),MOD=1e9+7;

ll n,w;
ll a[N],f[N],h[N];

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>w;
    fu(i,1,n) cin>>a[i];
    ll tt=(1<<n) -1;
    fu(x,1,tt) f[x]=1e18,h[x]=1e18;
    fu(x,0,tt)
    {
        fu(i,1,n)
        {
            if((x&(1<<(i-1)))==0)
            {
                ll p=x|(1<<(i-1));
                ll res1=f[x],res2=0;
                if(f[x]+a[i]>w)
                {
                    res2=1;
                    res1=a[i];
                }
                else res1+=a[i];
                if(h[x]+res2<h[p])
                {
                    h[p]=h[x]+res2;
                    f[p]=res1;
                }
                else if(h[x]+res2==h[p])
                {
                    f[p]=min(f[p],res1);
                }
            }
        }
    }
    cout<<h[tt]+(f[tt]!=0);


    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
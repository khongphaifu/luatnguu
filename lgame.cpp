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

const int N=1e3+5 ,MOD=1e9+7;

ll n,s;
ll a[N],f[N];
ll R[N][(ll)1e4 +7],L[N][(ll)1e4 +7];

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>s;
    fu(i,1,n) cin>>a[i];
    // fu(i,1,n) fu(j,0,s) R[i][j]=1e18,L[i][j]=1e18;
    R[n+1][0]=1;
    fud(i,n,1) fu(j,0,s)
    {
        R[i][j]=R[i+1][j];
        if(j>=a[i]) R[i][j]=(R[i][j]+R[i+1][j-a[i]])%MOD;
    }
    L[0][0]=1;
    fu(i,1,n) fu(j,0,s)
    {
        L[i][j]=L[i-1][j];
        if(j>=a[i]) L[i][j]=(L[i][j]+L[i-1][j-a[i]])%MOD;
    }

    fu(i,1,n)
    {
        ll res=0;
        fu(j,0,s) if(s-a[i]-j >=0) res=(res+ L[i-1][j]*R[i+1][s-a[i]-j]%MOD)%MOD;
        cout<<res<<" ";
    }

    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
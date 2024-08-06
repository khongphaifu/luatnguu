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
 
const int N=2207 +10,MOD=998244353;
 
ll m,n,h;
ll a[N][N];
 
// namespace sub1
// {
 
//     ll f[N][N];
 
//     void sol()
//     {
//         fu(i,0,m+1) fu(j,0,n+1) f[i][j]=-1e18;
//         fu(i,1,m) f[i][1]=a[i][1];
//         fu(j,2,n) fu(i,1,m) f[i][j]=a[i][j]+max({f[i][j-1],f[i-1][j-1],f[i+1][j-1]});
//         ll ans=-1e18;
//         fu(i,1,m) ans=max(ans,f[i][n]);
//         cout<<ans;
//     }
// }
 
namespace sub2
{

    ll f[N][N];
    ll mc[N][2],mu[N][2],bestc[N],bestu[N];
 
    void sol()
    {
        ll ans=-1e18;
        fu(i,0,m+1) fu(j,0,n+1)
        {
            f[i][j]=-1e18;
        }
        fu(i,1,m) f[i][1]=a[i][1];
        // fu(i,1,m) mu[i][0]=-1e18,mu[i][1]=-1e18;
        // fu(i,1,n) mc[i][0]=-1e18,mc[i][1]=-1e18;
        fu(j,2,n) fu(i,1,m) f[i][j]=a[i][j]+max({f[i][j-1],f[i-1][j-1],f[i+1][j-1]});
        fu(i,1,m) ans=max(ans,f[i][n]);
        fu(i,1,m) fu(j,1,n)
        {
            if(i==1) mc[j][0]=f[i][j],mc[j][1]=-1e18,bestc[j]=i;
            else
            {
                if(f[i][j]>=mc[j][0])
                {
                    mc[j][1]=mc[j][0];
                    mc[j][0]=f[i][j];
                    bestc[j]=i;
                }
                else if(f[i][j]>mc[j][1]) mc[j][1]=f[i][j];
            }
            if(j==1) mu[i][0]=f[i][j],mu[i][1]=-1e18,bestu[i]=j;
            else
            {
                if(f[i][j]>=mu[i][0])
                {
                    mu[i][1]=mu[i][0];
                    mu[i][0]=f[i][j];
                    bestu[i]=j;
                }
                else if(f[i][j]>mu[i][1]) mu[i][1]=f[i][j];
            }
        }
        // cout<<bestc[2]<<el;
        fu(K,1,h)
        {
            fu(i,1,m) fu(j,1,n)
            {
                ll ma1=mu[i][0];
                ll ma2=mc[j][0];
                if(bestc[j]==i) ma2=mc[j][1];
                if(bestu[i]==j) ma1=mu[i][1];
                f[i][j]=a[i][j]+max(ma1,ma2);
            }
            // fu(i,1,m)
            // {
            //     fu(j,1,n) cout<<f[i][j][K]<<" ";
            //     cout<<el;
            // }
            // fu(i,1,m) f[i][1][K]+=a[i][1];
            fu(j,2,n) fu(i,1,m) f[i][j]=max(a[i][j]+max({f[i][j-1],f[i-1][j-1],f[i+1][j-1]}),f[i][j]);
            fu(i,1,m) ans=max(ans,f[i][n]);
            // fu(i,1,m) mu[i][0]=-1e18,mu[i][1]=-1e18;
            // fu(i,1,n) mc[i][0]=-1e18,mc[i][1]=-1e18;
            // fu(i,1,m)
            // {
            //     fu(j,0,1) cout<<mc[i][j]<<" ";
            //     cout<<el;
            // }
            fu(i,1,m) fu(j,1,n)
            {
                if(i==1) mc[j][0]=f[i][j],mc[j][1]=-1e18,bestc[j]=i;
                else
                {
                    if(f[i][j]>=mc[j][0])
                    {
                        mc[j][1]=mc[j][0];
                        mc[j][0]=f[i][j];
                        bestc[j]=i;
                    }
                    else if(f[i][j]>mc[j][1]) mc[j][1]=f[i][j];
                }
                if(j==1) mu[i][0]=f[i][j],mu[i][1]=-1e18,bestu[i]=j;
                else
                {
                    if(f[i][j]>=mu[i][0])
                    {
                        mu[i][1]=mu[i][0];
                        mu[i][0]=f[i][j];
                        bestu[i]=j;
                    }
                    else if(f[i][j]>mu[i][1]) mu[i][1]=f[i][j];
                }
            }
        }
        cout<<ans;
    }
 
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
    
    cin>>m>>n>>h;
    fu(i,1,m) fu(j,1,n) cin>>a[i][j];
    sub2::sol();
 
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
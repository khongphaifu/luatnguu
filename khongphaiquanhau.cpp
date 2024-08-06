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

const ll N=227 + 5,MOD=998244353;

ll r,c,n;
ll a[N][N],sumc[N],sumh[N],sumcc[2*N],sumrr[2*N];

void sol()
{
    fu(i,1,r) fu(j,1,c)
    {
        a[i][j]=1;
    }
    ll sum=0;
    fu(i,1,r) fu(j,1,c)
    {
        sum=(sum+a[i][j])%MOD;
        sumh[i]=(sumh[i]+a[i][j])%MOD;
        sumc[j]=(sumc[j]+a[i][j])%MOD;
        sumcc[i+j]=(sumcc[i+j]+a[i][j])%MOD;
        sumrr[i-j+N]=(sumrr[i-j+N]+a[i][j])%MOD;
    }
    // cout<<sum<<el;
    // fu(i,1,r)
    // {
    //     cout<<
    // }
    // cout<<r<<" "<<c<<el;
    // cout<<sumcc[1+3]<<el;
    fu(k,1,n)
    {
        // fu(i,1,r) fu(j,1,c) copya[i][j]=a[i][j];
        fu(i,1,r) fu(j,1,c)
        {
            ll copysum=sum;
            // cout<<copysum<<el;
            // if(i==r && j==c) cout<<sumc[i]<<" "<<sumh[j]
            copysum=(copysum-sumc[j]-sumh[i]-sumcc[i+j]-sumrr[i-j+N]+3*a[i][j]+4*MOD)%MOD;
            a[i][j]=copysum;
            // cout<<copysum<<el;
        }
        fu(i,1,r) fu(j,1,c)
        {
            sum=0;
            sumh[i]=0;
            sumc[j]=0;
            sumcc[i+j]=0;
            sumrr[i-j+N]=0;
        }
        fu(i,1,r) fu(j,1,c)
        {
            sum=(sum+a[i][j])%MOD;
            sumh[i]=(sumh[i]+a[i][j])%MOD;
            sumc[j]=(sumc[j]+a[i][j])%MOD;
            sumcc[i+j]=(sumcc[i+j]+a[i][j])%MOD;
            sumrr[i-j+N]=(sumrr[i-j+N]+a[i][j])%MOD;
        }
    }
    // fu(i,1,r)
    // {
    //     fu(j,1,c) cout<<a[i][j]<<" ";
    //     cout<<el;
    // }
    cout<<sum;
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

    cin>>r>>c>>n;
    sol();
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
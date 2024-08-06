
#define TASK     "4"
// sol: 
// 
int mlt=0;
int test=1;

#include <bits/stdc++.h>
using namespace std;


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
#define     print(a,n)  for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<el;
#define      printv(v)  for(auto it:v) cout<<it<<" ";cout<<el;
#define     printvp(v)  for(auto it:v) cout<<it.fi<<" "<<it.se<<el;
#define           endp  cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;

const ll N = 1e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9  ;
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
    ll dd[307][307][307],f[5007][5007],ddd[307][307][307];
    ll a[N];
    

    // int Cal(int i,int j,int l)
    // {
    //     if(i>j) return 0;
    //     if(dd[i][j][l]) return f[i][j][l];
    //     dd[i][j][l]=1;
    //     int maxi=-1e9;
    //     if(Cal(i,j-1,0)+(l+1)*(l+1)>maxi)
    //     {
    //         ddd[i][j][l]=ddd[i][j-1][0]+1;
    //     }
    //     maxi=max(maxi,Cal(i,j-1,0)+(l+1)*(l+1));
    //     if(Cal(i,j,0)+l*l>maxi)
    //     {
    //         ddd[i][j][l]=ddd[i][j][0]+1;
    //     }
    //     maxi=max(maxi,Cal(i,j,0)+l*l);
    //     for (int k=i;k<j;k++)
    //     {
    //         if(a[k]==a[j])
    //         {
    //             maxi=max(maxi,Cal(i,k,l+1)+Cal(k+1,j-1,0));
    //             if(Cal(i,k,l+1)+Cal(k+1,j-1,0)>maxi)
    //             {
    //                 ddd[i][j][l]=ddd[i][k][l+1]+ddd[k+1][j-1][0];
    //             }
    //         }
    //         else
    //         {

    //         }
    //     }
    //     f[i][j][l]=maxi;
    //     return f[i][j][l];
    // }
    ll b[N];

    void sol()
    {
        cin>>n;
        // FOR(i,1,n) FOR(j,1,n) FORD(l,1,307) f[i][j][l]=0;
        FOR(i,1,n) cin>>a[i];
        ll d=1;
        b[1]=a[1];
        FOR(i,2,n)
        {
            if(a[i]!=a[i-1])
            {
                d++;
                b[d]=a[i];
            }
        }
        n=d;
        FOR(i,1,n) a[i]=b[i];
        // cout<<Cal(1,n,0);
        // cout<<ddd[1][n][0]<<el;
        FOR(i,1,n) FOR(j,1,n) f[i][j]=1e9;
        FOR(i,1,n) f[i][i]=0,f[i][i+1]=(a[i]!=a[i+1]);
        FOR(len,3,n)
        {
            FOR(i,1,n-len+1)
            {
                ll j=i+len-1;
                if(a[i]==a[j])
                {
                    f[i][j]=min(f[i][j],1+f[i+1][j-1]);
                }
                f[i][j]=min({f[i][j],1+f[i+1][j],1+f[i][j-1]});
            }
        }
        cout<<f[1][n];
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
    endp
}
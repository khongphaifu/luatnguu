// khongphaifu - Mai Ngọc Phú - T2K33 - THPT Chuyên Lê Khiết
// VOI... 
// Program link: https://tinhoclk.com/problem/del
// Program name:   v 
#define TASK     "DEL"
// sol: 
// 
int mlt=0;
int test=1;

#include <bits/stdc++.h>
using namespace std;


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
    ll dd[307][307],f[307][307],ddd[307][307][307];
    ll a[N];
    

    ll Cal(ll i,ll j)
    {
        if(i==j) {f[i][j]=0;return 0;}
        if(dd[i][j]) return f[i][j];
        dd[i][j]=1;
        ll tmp=1e9;
        for (ll k=i;k<j;k++)
        {
            if(a[k]==a[j])
            {
                tmp=min(tmp,Cal(i,k)+Cal(k+1,j));
                // if(Cal(i,k,l+1)+Cal(k+1,j-1,0)>maxi)
                // {
                //     ddd[i][j][l]=ddd[i][k][l+1]+ddd[k+1][j-1][0];
                // }
            }
            else
            {
                tmp=min(tmp,1+Cal(i,k)+Cal(k+1,j));
            }
        }
        f[i][j]=tmp;
        return f[i][j];
    }

    void sol()
    {
        cin>>n;
        // FOR(i,1,n) FOR(j,1,n) FORD(l,1,307) f[i][j][l]=0;
        FOR(i,1,n) cin>>a[i];
        cout<<Cal(1,n)+1;
        // cout<<ddd[1][n][0]<<el;
        // FOR(i,1,n) FOR(j,1,n) f[i][j]=1e9;
        // FOR(i,1,n) f[i][i]=0;
        // FORD(i,n-1,1)
        // {
        //     FOR(j,i+1,n)
        //     {
        //         FOR(k,i,j-1)
        //         {
        //             if(a[i]==a[k+1])
        //             {
        //                 f[i][j]=min(f[i][j],f[i][k]+f[k+1][j-1]);
        //             }
        //             else
        //             {
        //                 f[i][j]=min(f[i][j],1+f[i][k]+f[k+1][j-1]);
        //             }
        //         }
        //     }
        // }
        // cout<<f[1][n]+1;
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
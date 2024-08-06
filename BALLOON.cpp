// khongphaifu - Mai Ngọc Phú - T2K33 - THPT Chuyên Lê Khiết
// VOI... 
// Program link: https://tinhoclk.com/problem/balloon
// Program name:   v 
#define TASK   "BALLOON"
// sol: 
// 
int mlt=1;
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

const long long inf=1e18;
const ll N = 1e6 + 5 , N1 = 1e3 + 5 , MOD = 1e9  ;
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
    string s;
    ll f[207][207][207],dd[207][207][207];

    ll cal(ll i,ll j,ll l)
    {
        if(i>j)
        {
            f[i][j][l]=0;
            return 0;
        }
        if(i==j && l==0) // 0 xóa 1 
        {
            f[i][j][l]=-inf;
            return -inf;
        }
        if(dd[i][j][l])
        {
            return f[i][j][l];
        }
        dd[i][j][l]=1;
        ll tmp=-inf;
        // ll res=cal(i,j-1,0);
        // if(l>0) res+=(l+1)*(l+1);
        // tmp=max(tmp,res); 
        if(l>=2) tmp=max(tmp,cal(i,j,0)+(l)*(l));
        if(l>=1) tmp=max(tmp,cal(i,j-1,0)+(l+1)*(l+1));
        FOR(k,i,j-1)
        {
            if(s[k]==s[j])
            {
                tmp=max(tmp,cal(k+1,j-1,0)+cal(i,k,l+1));
            }
            // else
            // {
            //     tmp=max(tmp,1+cal(i,k,0)+cal(k+1,j-1,0));
            // }
        }
        f[i][j][l]=tmp;
        return f[i][j][l];
    }

    void sol()  
    {
        FOR(i,0,n) FOR(j,0,n) FOR(l,0,n) f[i][j][l]=-inf,dd[i][j][l]=0;
        cin>>s;
        // cout<<s<<el;
        n=s.size();
        s='#'+s;
        cout<<max(0ll,cal(1,n,0))<<el; 
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
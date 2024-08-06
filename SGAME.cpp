// khongphaifu - Mai Ngọc Phú - T2K33 - THPT Chuyên Lê Khiết
// VOI... 
// Program link: https://tinhoclk.com/problem/sgame
// Program name:   v 
#define TASK   "SGAME"
// sol: 
// 
int mlt=1;
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
    ll n,k;
    ll f[351][351][351],dd[351][351][351],r[N];

    ll cal(ll i,ll j,ll m)
    {
        if(m>=k)
        {
            f[i][j][m]=0;return 0;
        }
        if(dd[i][j][m])
        {
            return f[i][j][m];
        }
        dd[i][j][m]=1;
        ll b= r[n]-m-(r[j]-r[i-1]);
        if(b>=k){f[i][j][m]=1;return 1;}
        if(cal(i+1,j,b)==0){f[i][j][m]=1;return 1;}
        if(cal(i,j-1,b)==0){f[i][j][m]=1;return 1;}
        f[i][j][m]=0;
        return 0;
    }

    void sol()
    {
        cin>>n>>k;
        string s;cin>>s;
        s='#'+s;

        FOR(i,1,n)
        {
            r[i]=r[i-1];
            if(s[i]=='R') r[i]++;
        }
        FOR(i,1,n) FOR(j,1,n) FOR(m,0,r[n]) f[i][j][m]=0,dd[i][j][m]=0;
        if(cal(1,n,0)) cout<<"YES"<<el;
        else cout<<"NO"<<el;
        
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
// khongphaifu - Mai Ngọc Phú - T2K33 - THPT Chuyên Lê Khiết
// VOI... 
// Program link: https://tinhoclk.com/problem/deleseq1
// Program name:   v 
#define TASK   "DELESEQ1"
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
    ll dd[200][200][200],f[200][200][200];
    ll a[N],f1[N];
    string s;
    

    ll Cal(ll i,ll j,ll l)
    {
        if(i>j) {return 0;}
        if(dd[i][j][l]) return f[i][j][l];
        dd[i][j][l]=1;
        ll tmp=-1e9;
        tmp=max(tmp,Cal(i,j-1,0)+a[l+1]);
        tmp=max(tmp,Cal(i,j,0)+a[l]);
        for(ll k=i;k<j;k++)
        {
            if(s[k]==s[j])
            {
                tmp=max(tmp,Cal(i,k,l+1)+Cal(k+1,j-1,0));
                // if(Cal(i,k,l+1)+Cal(k+1,j-1,0)>maxi)
                // {
                //     ddd[i][j][l]=ddd[i][k][l+1]+ddd[k+1][j-1][0];
                // }
            }
            // else
            // {
            //     tmp=max(tmp,a[1]+Cal(i,k,l+1)+Cal(k+1,j,0));
            // }
        }
        f[i][j][l]=tmp;
        return f[i][j][l];
    }

    void sol()
    {
        cin>>n;
        // FOR(i,1,n) FOR(j,1,n) FORD(l,1,307) f[i][j][l]=0;
        cin>>s;
        s="*"+s;
        ll res=1;
        char tmp=s[1];
        FOR(i,2,n) if(s[i]==tmp) res++;
        FOR(i,1,n) cin>>a[i];
        if(res==n)
        {
            f1[1]=a[1];
            FOR(i,2,n)
            {
                f1[i]=a[i];
                FORD(j,i-1,1) f1[i]=max(f1[i],f1[j]+a[i-j]);
            }
            cout<<f1[n];return;
        }
        cout<<Cal(1,n,0);
        
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
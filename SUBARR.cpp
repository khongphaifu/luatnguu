// Program link: https://tinhoclk.com/problem/subarr
// Program name: v 
#define TASK  "SUBARR"
// sol: 



#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
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
#define    FORN(i,a,b)  for(ll i=a;i<b;i++)
#define   FORDN(i,a,b)  for(ll i=a;i>b;i--)
#define     print(a,n)  for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<el;
#define      printv(v)  for(auto it:v) cout<<it<<" ";cout<<el;
#define     printvp(v)  for(auto it:v) cout<<it.fi<<" "<<it.se<<el;
#define       ieozzool  cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
using namespace std;
// using namespace __gnu_pbds;

ll mlt=0;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const long long inf = 1e18;
const ll N = 2e5 + 5 , N1 = 1e3 + 5 , MOD = 1e9 , sminf = 1e9;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

ll n,k,p;
ll a[N],f[N],pre[N],ans[N],st[4*N];
string s;


void befout()
{
    cin>>n>>k>>p;
    FOR(i,1,n) cin>>a[i];
    cin>>s;
}
    
void befin()
{
    
}

namespace mnp
{     
    void build(ll id,ll l,ll r)
    {
        if(l==r)
        {
            st[id]=pre[l];return;
        }
        ll mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        st[id]=max(st[2*id],st[2*id+1]);\
    }

    ll get(ll id,ll l,ll r,ll u,ll v)
    {
        if(u>r || l>v) return -inf;
        if(u<=l && r<=v) return st[id];
        ll mid=(l+r)/2;
        return max(get(2*id,l,mid,u,v),get(2*id+1,mid+1,r,u,v));
    }

    void sol()
    {
        if(k>n) k=n;
        FOR(i,n+1,2*n) a[i]=a[i-n];
        ll n1=2*n;
        FOR(i,1,n1) f[i]=f[i-1]+a[i];
        FOR(i,k,n1) pre[i]=f[i]-f[i-k];
        build(1,1,n1);
        FOR(i,1,n+1)
        {
            ans[i]=get(1,1,n1,i+k-1,i+n-1);
        }
        // FOR(i,1,n+1) cout<<ans[i]<<el;
        ll res=n+1;
        for(char it:s)
        {
            if(it=='?') cout<<ans[res]<<el;
            else
            {
                res--;
                if(!res) res=n+1;
            }
        }
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
    if(mlt) cin>>test;
    befout();
    FOR(i,1,test)
    {
        befin();
        mnp::sol();
    }
    ieozzool;
}
/*
                  ▒▒▒▒▒▒▒▒▒▒▒▒                                            
                ▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒                                          
              ▓▓▒▒▒▒░░░░░░░░░░▓▓▓▓                                        
            ░░▒▒▒▒░░▓▓░░░░░░░░░░▓▓                                        
            ░░▒▒▒▒░░▒▒░░░░░░  ░░▓▓▒▒                                      
        ░░▓▓░░▒▒▒▒▒▒░░░░░░░░░░░░▒▒▓▓                                      
  ░░░░░░░░░░░░▒▒▒▒▒▒▒▒░░░░▒▒▒▒░░░░▓▓                                      
                    ▒▒▓▓▓▓▒▒▒▒░░▒▒▓▓                                      
                        ▓▓▒▒░░░░▒▒▓▓                                      
                        ▓▓▒▒░░░░▒▒                                        
                      ▓▓▒▒░░  ░░▒▒                                        
                  ▓▓▓▓▒▒░░░░░░▓▓                                          
              ▓▓▒▒▒▒▒▒▒▒▒▒░░▒▒                                            
            ▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓                                              
          ▓▓██▓▓▓▓        ▓▓▒▒▒▒▒▒▒▒                                      
        ██▓▓▒▒▓▓▓▓▓▓▓▓██▓▓██░░░░░░▒▒▒▒▒▒▒▒                                
      ▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓████░░░░░░░░░░░░░░▓▓▓▓▓▓                            
      ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▒▒▒▒▒▒░░░░░░  ▓▓▓▓                        
    ██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒░░▓▓▓▓▓▓▓▓▒▒▒▒▒▒░░░░░░  ▓▓▓▓                    
    ██▒▒▓▓▓▓▓▓▓▓██▒▒▒▒▒▒▒▒▒▒░░░░████▓▓▓▓▒▒▒▒▒▒▒▒░░░░  ▓▓▓▓                
    ██▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░████▓▓▓▓▒▒▒▒▒▒░░░░    ▓▓              
    ██▓▓▓▓▓▓██▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░██████████▓▓▓▓░░░░  ▓▓▓▓          
    ██▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░████████████▒▒▓▓░░░░▓▓        
    ██▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░  ████████░░░░▓▓▓▓    ▓▓    
    ████▓▓██▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░    ██░░██████▓▓██    ██  
      ██████▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░  ▓▓████████▓▓▓▓▓▓    
      ░░████▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒░░            ░░  ░░░░░░
          ▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░██████░░░░░░░░░░░░  
            ▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░████▓▓▓▓          
              ▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                  
                  ▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒                              
                            ▓▓▓▓▓▓▓▓▓▓                                    
                            ▒▒▓▓▒▒▓▓▒▒                                    
                              ▒▒  ▒▒                                      
                              ▒▒  ▒▒                                      
                              ▒▒  ▒▒                                      
                              ▒▒  ▒▒                                      
                    ▒▒▒▒▒▒▒▒  ▒▒  ▒▒                                      
                ░░░░▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒   
*/
// Program link: https://tinhoclk.com/problem/dna1
// Program name: v 
#define TASK  "DNA1"
// sol: 



#include <bits/stdc++.h>
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


ll mlt=0;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const long long inf = 1e18;
const ll N = 1e6 + 5 , N1 = 1e3 + 5 , MOD = 1e9 , sminf = 1e9;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

string a,b;
ll n;
map<string,ll> mp;

void bef()
{
    cin>>a>>b;
    n=a.size();
    a="#"+a;
    b="#"+b;
}

namespace mnp
{
    string daoxau(string a1,ll l,ll r)
    {
        string a=a1;
        while(l<=r)
        {
            char x=a[l];
            a[l]=a[r];
            a[r]=x;
            l++;r--;
        }
        return a;
    }

    void sol()
    {
        // string tmp=daoxau(a,1,n);
        if(a==b)
        {
            cout<<"Similar";return;
        }
        // cout<<tmp<<el;
        // cout<<a<<el;
        FOR(i,1,n)
        {
            FOR(j,i,n)
            {
                string a1=daoxau(a,i,j);;
                // daoxau(a1,i,j);
                // cout<<a1<<el;
                mp[a1]++;
                FOR(i1,1,n)
                {
                    FOR(j1,i1,n)
                    {
                        string a2=daoxau(a1,i1,j1);
                        daoxau(a2,i1,j1);
                        mp[a2]++;
                    }
                }
            }
        } 
        // cout<<a<<el;
        if(mp[b])
        {
            cout<<"Similar";return;
        }
        FOR(i,1,n)
        {
            FOR(j,i,n)
            {
                string b1=daoxau(b,i,j);
                if(mp[b1] || mp[b])
                {
                    cout<<"Similar";return;
                }
                FOR(i1,1,n)
                {
                    FOR(j1,i1,n)
                    {
                        string b2=daoxau(b1,i1,j1);
                        if(mp[b2] || mp[b])
                        {
                            cout<<"Similar";return;
                        }
                    }
                }
            }
        } 
        if(mp[b])
        {
            cout<<"Similar";return;
        }

        cout<<"Different";
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
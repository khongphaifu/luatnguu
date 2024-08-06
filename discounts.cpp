#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#define             pb  push_back  
#define             ll  long long
#define             se  second 
#define             fi  first
#define             el  "\n"
#define      alla(a,n)  a+1,a+n+1
#define         all(v)  v.begin(),v.end()
#define      fu(i,a,b)  for(ll i=a;i<=b;i++)
#define     fud(i,a,b)  for(ll i=a;i>=b;i--)
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const long long inf = 1e18;
const ll N = 3e5 + 5 , N1 = 1e3 + 5 , MOD = 1e9+7 /*1234567891*/ , base =311 ;

ll omg,n,k;

struct bg
{
    ll x,t,i;
};

bg a[N];

void doc()
{
    cin>>omg>>n>>k;
    fu(i,1,n)
    {
        cin>>a[i].x>>a[i].t;
        a[i].i=i;
    }    
}

bool cmp(bg a,bg b)
{
    if(a.x==b.x) a.t<b.t;
    return a.x<b.x;
}
    
void pre()
{
    
}

vector<ll> v[N];
ll sum[N];

void sol()
{
    sort(alla(a,n),cmp);
    fu(i,1,n) sum[i]=sum[i-1]+(a[i].t==1);
    if(sum[n]==0)
    {
        double ans=0;
        ll k1=k;
        fud(i,n,1)
        {
            if(i==k)
            {
                v[k].pb(a[i].i);
                if(a[i].t==1) ans+=double(a[i].x)/2;
                else ans+=double(a[i].x);
                k--;
            }
            else if(!sum[i] && k>1)
            {
                v[k].pb(a[i].i);
                k--;
                ans+=double(a[i].x);
            }
            else if(a[i].t==1 && k>1)
            {
                v[k].pb(a[i].i);
                k--;
                ans+=double(a[i].x)/2;
            }
            else v[k].pb(a[i].i),ans+=double(a[i].x);
        }
        cout<<fixed<<setprecision(1)<<ans<<el;
        fu(i,1,k1)
        {
            cout<<v[i].size()<<" ";
            for(auto it:v[i]) cout<<it<<" ";
            cout<<el;
        }
        return;
    }
    double ans=0;
    ll k1=k;
    fud(i,n,2)
    {
        if(i==k)
        {
            v[k].pb(a[i].i);
            if(a[i].t==1) ans+=double(a[i].x)/2;
            else ans+=double(a[i].x);
            k--;
        }
        else if(!sum[i] && k>1)
        {
            v[k].pb(a[i].i);
            k--;
            ans+=double(a[i].x);
        }
        else if(a[i].t==1 && k>1)
        {
            v[k].pb(a[i].i);
            k--;
            ans+=double(a[i].x)/2;
        }
        else v[k].pb(a[i].i),ans+=double(a[i].x);
    }
    if(k1<=sum[n] || a[1].t==1)ans+=double(a[1].x)/2,v[k].pb(a[1].i);
    else ans+=double(a[1].x),v[k].pb(a[1].i);
    cout<<fixed<<setprecision(1)<<ans<<el;
    fu(i,1,k1)
    {
        cout<<v[i].size()<<" ";
        for(auto it:v[i]) cout<<it<<" ";
        cout<<el;
    }

}

int mlt=0;
int test=1;
signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }
    if(mlt) cin>>test;
    doc();
    fu(i,1,test)
    {
        pre();
        sol();
    }
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
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
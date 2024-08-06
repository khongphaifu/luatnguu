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
//indexed_set giống như set nhưng nó có chỉ mục giống như mảng
//Hàm find_by_order trả về một iterator trỏ đến phần tử tại 1 vị trí xác định
//Hàm order_of_key trả về vị trí của một phần tử xác định

const long long inf = 1e18;
const ll N = 2e5 + 5 , N1 = 1e3 + 5 , MOD = 1e9+7 /*1234567891*/ , base =311 ;

ll n,m,q,stt;
ll w[N],u[N],v[N],f[N],L[N],res[N];

ll goc(ll x)
{
    while(f[x]>0) x=f[x];
    return x;
}

void doc()
{
    cin>>n>>m>>q;
    fu(i,1,n) cin>>w[i];
    fu(i,1,m)
    {
        cin>>u[i]>>v[i];
    }    
}
    
void pre()
{
    
}

struct bg
{
    char t;
    ll x,y;
};
bg a[N];

ll dd[N];

// gọi Li là tổng trọng số của cây gốc i
// fi<0 |fi|= tổng đỉnh cây gốc i
// fi>0 fi là tổng 

stack<ll> s[N];

multiset<ll> se;

void HN(ll u,ll v)
{
    u=goc(u);
    v=goc(v);
    if(u==v) return;
    else
    {
        ll sum=(L[u]+L[v]);
        ll t=f[u]+f[v];
        se.erase(se.find(L[u]));
        se.erase(se.find(L[v]));
        se.insert(sum);
        if(abs(f[u])>abs(f[v]))
        {
            f[u]=t;f[v]=u;L[u]=sum;
        }
        else
        {
            f[v]=t;f[u]=v;L[v]=sum;
        }
    }
}

void sol()
{
    fu(i,1,n) s[i].push(w[i]);
    fu(i,1,q)
    {
        cin>>a[i].t;
        if(a[i].t=='D')
        {
            cin>>a[i].x;
            dd[a[i].x]=1;
        }
        else
        {
            cin>>a[i].x>>a[i].y;
            s[a[i].x].push(a[i].y);
        }
    }
    fu(i,1,n) f[i]=-1,L[i]=s[i].top(),se.insert(s[i].top());
    fu(i,1,m) if(!dd[i]) HN(u[i],v[i]);
    res[q]=*se.rbegin();
    fud(i,q,2)
    {
        if(a[i].t=='D')
        {
            ll j=a[i].x;
            HN(u[j],v[j]);
        }
        else
        {
            ll x=a[i].x;
            ll r=goc(x);
            ll vl=s[x].top();
            s[x].pop();
            se.erase(se.find(L[r]));
            L[r]=L[r]-vl+s[x].top();
            se.insert(L[r]);
        }
        res[i-1]=*se.rbegin();
    }
    fu(i,1,q) cout<<res[i]<<el;
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
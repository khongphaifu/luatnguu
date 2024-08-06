// Program link: https://tinhoclk.com/problem/vtree1
// Program name: v 
#define TASK  "VTREE1"
// sol: 

int mlt=0;
int test=1;

#include <bits/stdc++.h> 
#define             pb  push_back  
#define             ll  long long
#define             se  second 
#define             fi  first
#define             el  "\n"
#define     FOR(i,a,b)  for(ll i=a;i<=b;i++)
#define    FORD(i,a,b)  for(ll i=a;i>=b;i--)
using namespace std;

const long long inf = 1e18;
const ll N = 1e6 + 5 , N1 = 1e3 + 5 , MOD = 1e9 +7;
const double PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

struct bg
{
    ll ke,w; 
};

ll n,q,d;
ll a[N],h[N],f[N],st1[4*N],st2[4*N],b[N];
vector<ll> g[N];


void befout()
{
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n-1)
    {
        ll x,y;cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
    
void befin()
{
    
}

//////////////////////////

void build(ll id,ll l,ll r)
{
    if(l==r)
    {
        st1[id]=b[l];
        st2[id]=b[l];
        return;
    }
    ll mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st1[id]=st1[2*id]+st1[2*id+1];
    st2[id]=min(st2[2*id],st2[2*id+1]);
}

void up(ll id,ll l,ll r,ll i,ll val)
{
    if(i<l || i>r) return;
    if(l==r)
    {
        st1[id]=val;
        st2[id]=val;
        return;
    }
    ll mid=(l+r)/2;
    up(2*id,l,mid,i,val);
    up(2*id+1,mid+1,r,i,val);
    st1[id]=st1[2*id]+st1[2*id+1];
    st2[id]=min(st2[2*id],st2[2*id+1]);
}

ll get1(ll id,ll l,ll r,ll u,ll v)
{
    if(r<u || v<l) return 0;
    if(u<=l && r<=v) return st1[id];
    ll mid=(l+r)/2;
    return get1(2*id,l,mid,u,v)+get1(2*id+1,mid+1,r,u,v);
}

ll get2(ll id,ll l,ll r,ll u,ll v)
{
    if(r<u || v<l) return inf;
    if(u<=l && r<=v) return st2[id];
    ll mid=(l+r)/2;
    return min(get2(2*id,l,mid,u,v),get2(2*id+1,mid+1,r,u,v));
}

void dfs(ll u,ll pre)
{
    d++;
    h[u]=d;f[u]=1;
    for(auto it:g[u])
    {
        if(it==pre) continue;
        dfs(it,u);
        f[u]+=f[it];
    }
}

void sol()
{
    dfs(1,0);
    FOR(i,1,n) b[h[i]]=a[i];
    // FOR(i,1,n) cout<<i<<" "<<h[i]<<el;
    // FOR(i,1,n) cout<<b[i]<<" ";
    // cout<<el;
    build(1,1,n);
    while(q--)
    {
        string s;cin>>s;
        if(s=="SUM")
        {
            ll x;cin>>x;
            cout<<get1(1,1,n,h[x],h[x]+f[x]-1)<<el;
        }
        else if(s=="MIN")
        {
            ll x;cin>>x;
            cout<<get2(1,1,n,h[x],h[x]+f[x]-1)<<el;
        }
        else
        {
            ll x,y;cin>>x>>y;
            b[h[x]]=y;
            up(1,1,n,h[x],y);
            // cout<<b[4]<<el;
        }
    }
    
}

    

// "..."

signed main(void)
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
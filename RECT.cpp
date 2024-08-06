int mlt=0;
int test=1;

#include <bits/stdc++.h>
using namespace std;


#define           TASK  "RECT"
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




ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const ll N = 1e6 + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e18;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{

    ll n,m;
    ll dp[N1][N1],dp1[N1][N1],a[N],f[N],r[N],l[N],mi[N];
    
    ll HCN(ll x1,ll y1,ll x2,ll y2)
    {
        return dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
    }
    
    
    void sol()
    {
        cin>>m>>n;
        ll tmp=1;
        FOR(i,1,m) FOR(j,1,n)
        {
            ll x;cin>>x;dp[i][j]=x+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            dp1[i][j]=x;
        } 
        ll ans=-inf;
        FOR(i,1,n)
        { 
            FOR(j,i,n)
                {
                    a[0]=f[0]=mi[0]=-inf;
                    a[m+1]=f[m+1]=mi[m+1]=-inf;
                    FOR(k,1,m)
                    {
                        if(i==j) mi[k]=dp1[k][i];
                        else mi[k]=min(mi[k],dp1[k][j]);
                        mi[k]=min(mi[k],dp[k][j]);
                        a[k]=HCN(k,i,k,j);
                        f[k]=f[k-1]+a[k];
                    }
                    stack<ll> st;
                    st.push(0);
                    FOR(k,1,m)
                    {
                        while(!st.empty() && mi[k]<=mi[st.top()]) st.pop();
                        l[k]=st.top();
                        st.push(k);
                    }
                    while(!st.empty()) st.pop();
                    st.push(m+1);
                    FORD(k,m,1)
                    {
                        while(!st.empty() && mi[k]<=mi[st.top()]) st.pop();
                        r[k]=st.top();
                        st.push(k);
                    }
                    FOR(k,1,m) ans=max(ans,mi[k]*(f[r[k]-1]-f[l[k]]));
                    // if(ans==300)
                    // {
                    //     cout<<i<<" "<<j<<el;
                    //     return;
                    // }
                }
        }
        cout<<ans;

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
    FOR(i,1,test)
    {
        mnp::sol();
    }
    ieozzool;
}

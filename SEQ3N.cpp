//furiel?
/**  /\_/\
*   (= ._.)
*   / >?? \>??
**/

#include <bits/stdc++.h>
using namespace std;


#define           TASK  ""
#define             ll  long long
#define             db  double
#define            nnc  signed main()
#define             se  second 
#define             fi  first
#define     FOR(i,a,b)  for(ll i=a;i<=b;i++)
#define    FORD(i,a,b)  for(ll i=a;i>=b;i--)
#define    FORN(i,a,b)  for(ll i=a;i<b;i++)
#define   FORDN(i,a,b)  for(ll i=a;i>b;i--)


ll mlt=0,test=1;


const ll N = 3e5+5 , N1 = 1e3 + 7 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;

//"..."

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.fi==b.fi) return a.se < b.se;
    return a.fi > b.fi;
}

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a,ll b) /* a^b */
{
    if(b==0) return 1;
    ll x=bp(a,b/2);
    if(b%2==0) return ( x * x ) % MOD  *  a % MOD ;
    else return  ( x * x ) % MOD;
}

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

ll n,m,k,x,y,q,p,ans=-oo,    a[N],b[N],c[N],d[N],   dp[N1][N1],dp1[N1][N1],dp2[N1][N1]  ;



void chau()
{
    cin>>n;
    ll sum=0;
    priority_queue<ll , vector<ll> , greater<ll>> q1;
    FOR(i,1,3*n)
    {
        cin>>a[i];
        sum+=a[i];
        q1.push(a[i]);
        if(q1.size()>n)
        {
            sum-=q1.top();q1.pop();
        }
        b[i]=sum;
    }
    sum=0;
    priority_queue<ll> q2;
    FORD(i,3*n,1)
    {
        sum+=a[i];
        q2.push(a[i]);
        if(q2.size()>n)
        {
            sum-=q2.top();q2.pop();
        }
        c[i]=sum;
        if(i>n && i<=2*n+1) ans=max(ans,b[i-1]-c[i]);
    }
    cout<<ans;
}
    
nnc
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    // if(fopen(TASK".INP","r"))
    // {
    //     freopen(TASK".INP" ,"r",stdin) ;
    //     freopen(TASK".OUT" ,"w",stdout);
    // }
    if(mlt) cin>>test;
    while(test--) chau();
    cerr<<"Time: "<<0.001*clock()<<"ms"<<endl;
    return 0;
}
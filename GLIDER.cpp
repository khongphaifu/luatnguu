//furiel?
/**  /\_/\
*   (= ._.)
*   / >?? \>??
**/

#include <bits/stdc++.h>
using namespace std;


#define           TASK  ""
#define             pl  pair<ll,ll>  
#define             pb  push_back  
#define             ll  long long
#define             db  double
#define            nnc  signed main()
#define             se  second 
#define             fi  first
#define             el  "\n"
#define         all(a)  a.begin(),a.end()
#define        alla(a,n)  a+1,a+n+1
#define     FOR(i,a,b)  for(ll i=a;i<=b;i++)
#define    FORD(i,a,b)  for(ll i=a;i>=b;i--)
#define    FORN(i,a,b)  for(ll i=a;i<b;i++)
#define   FORDN(i,a,b)  for(ll i=a;i>b;i--)
#define     print(a,n)  for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<el;
#define      printv(v)  for(auto it:v) cout<<it<<" ";cout<<el;
#define     printvp(v)  for(auto it:v) cout<<it.fi<<" "<<it.se<<el;


ll mlt=0;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const ll N = 1e6 + 5 , N1 = 2e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}


ll n,h;
ll dp[N1][N1],a[N],T[N],Tabs[N];

ll HCN(ll x1, ll y1 , ll x2 , ll y2)
{
    return dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
}

void chau()
{
    cin>>n>>h;
    vector<pair<ll,ll>> v;
    FOR(i,1,n)
    {
        ll x1,x2;cin>>x1>>x2;
        v.pb(pair<ll,ll>(x1,1));
        v.pb(pair<ll,ll>(x2,-1));
    }
    ll tmp=1;
    sort(all(v));
    ll j=1,res=v[0].fi;
    FOR(i,1,v.size()-1)
    {
        tmp+=v[i].se;
        if(tmp==0)
        {
            a[j]=v[i].fi-res;j++;
            res=v[i].fi;
        }
        else if(tmp==1)
        {
            a[j]=-(v[i].fi-res);j++;
            res=v[i].fi;
        }
    }
    j--;ll k=0,ans=0;
    FOR(i,1,j)
    {
        //cout<<a[i]<<" ";
        T[i]=T[i-1];
        if(a[i]<0) T[i]-=a[i]; 
        //cout<<T[i]<<" ";
        Tabs[i]=Tabs[i-1]+abs(a[i]);
        while(T[i]-T[k]>=h) k++;
        ans=max(ans,Tabs[i]-Tabs[k]+h-(T[i]-T[k]));
    }
    cout<<ans;
}
void xuly()
{
    

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
    FOR(i,1,test)
    {
        chau();
    }
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
    return 0;
}
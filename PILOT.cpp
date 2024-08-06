//furiel?
/**  /\_/\
*   (= ._.)
*   / >?? \>??
**/

#include <bits/stdc++.h>
using namespace std;


#define           TASK  "PILOT"
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


ll mlt=0;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const ll N = 1e6 + 5 , N1 = 5e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

namespace mnp
{

    struct td
    {
        ll x,l,r;
    };

    ll n,q,x;
    ll f[N],H[N];
    td a[N];

    ll cal(ll x)
    {
        return x*(x+1)/2;
    }

    void hmm()
    {
        cin>>n>>q;
        map<ll,vector<ll>> mp;
        FOR(i,1,n)
        {
            cin>>x;mp[x].pb(i);
        }
        ll k=1;
        ll ans=0;
        for(auto it:mp)
        {
            H[k]=it.fi;
            for(auto it1:it.se)
            {
                ll tmp=a[it1-1].x+a[it1+1].x+1;
                ans+=cal(tmp)-cal(a[it1-1].x)-cal(a[it1+1].x);
                a[it1].x=tmp;
                a[it1].l=it1;
                a[it1].r=it1;
                if(a[it1-1].x!=0 && a[it1+1].x!=0)
                {
                    a[a[it1-1].l].x=tmp;
                    a[a[it1-1].l].r=a[a[it1+1].r].r;
                    a[a[it1+1].r].x=tmp;
                    a[a[it1+1].r].l=a[a[it1-1].l].l;
                }
                else if(a[it1-1].x==0 && a[it1+1].x==0)
                {
                    a[it1].x=tmp;
                    a[it1].l=it1;
                    a[it1].r=it1;
                }
                else if(a[it1-1].x!=0 && a[it1+1].x==0)
                {
                    a[a[it1-1].l].x=tmp;
                    a[it1].x=tmp;
                    a[a[it1-1].l].r=a[it1].r;
                    a[it1].l=a[a[it1-1].l].l;
                }
                else
                {
                    a[a[it1+1].r].x=tmp;
                    a[it1].x=tmp;
                    a[a[it1+1].r].l=a[it1].l;
                    a[it1].r=a[a[it1+1].r].r;
                }
                // FOR(i,1,n) cout<<a[i].x<<" ";
                // cout<<el;
                // FOR(i,1,n) cout<<a[i].l<<" ";
                // cout<<el;
                // FOR(i,1,n) cout<<a[i].r<<" ";
                // cout<<el;
            }   
            f[k]=ans;k++;
        }
        k--;
        while(q--)
        {
            cin>>x;
            ll j=upper_bound(alla(H,k),x)-H;
            j--;
            cout<<f[j]<<el;
        }
    }
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
    xuly();
    FOR(i,1,test)
    {
        mnp::hmm();
    }
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
    return 0;
}
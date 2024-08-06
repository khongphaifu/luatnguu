#include <bits/stdc++.h>
using namespace std;


#define           TASK  "KNIGHT"
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


ll mlt=0;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const ll N = 5e5 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
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
    ll diem[N];
    vector<ll> v[N];

    void sol()
    {
        cin>>n>>m;
        set<ll> s;
        FOR(i,1,m)
        {
            ll x,y;cin>>x>>y;
            v[x].pb(i),v[y].pb(i);
            cin>>diem[i];
        }
        // FOR(i,1,n)
        // {
        //     for(auto it:v[i]) cout<<it<<" ";
        //     cout<<el;
        // }
        map<ll,ll> mp;
        FOR(i,1,n)
        {
            for(auto it:v[i])
            {
                mp[it]++;
                if(mp[it]==1) s.insert(it);
            }
            if(diem[*s.begin()]==i)
            {
                ll check=1;
                for(auto it:s)
                {
                    if(diem[it]!=i)
                    {
                        cout<<diem[it]<<" ";check=0;break;
                    }
                }
                if(check) cout<<0<<" ";
            }
            else cout<<diem[*s.begin()]<<" ";
            for(auto it:v[i])
            {
                if(mp[it]==2) s.erase(it);
            }
        }
    }
}



// "..."

nnc
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(0)); 
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
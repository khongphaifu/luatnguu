#include <bits/stdc++.h>
using namespace std;


#define           TASK  "REP"
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

const ll N = 3e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll n;

    

    ll a[N],f[N],dd[N];

    void sol()
    {
        cin>>n;
        stack<pair<ll,ll>> st;
        stack<ll> st1;
        map<ll,vector<ll>> mp;
        vector<pair<ll,ll>> v;
        FOR(i,1,n)
        {
            ll x,y;cin>>x>>y;
            v.pb({y+(ll)1e6,i});
            dd[x+(ll)1e6]=1;
            mp[x].pb(i);
        }
        sort(all(v));
        ll ans=0;
        FORD(i,n-1,0) st.push({v[i].fi,v[i].se});
        FOR(i,0,2e6)
        {
            ll check=0;
            if(st.empty()) break;
            while(!st.empty() && f[st.top().se]==2) st.pop();
            if(st.top().fi==i)
            {
                ll tmp=2-f[st.top().se];
                stack<ll> st2;
                while(!st1.empty())
                {
                    f[st1.top()]+=tmp;st2.push(st1.top());st1.pop();
                }
                while(!st2.empty())
                {
                    if(f[st2.top()]<2)
                    {
                        st1.push(st2.top());
                    }
                    st2.pop();
                }
                ans+=tmp;
                while(!st.empty() && f[st.top().se]>=2) st.pop();
                check=1;
            }
            if(dd[i])
            {
                for(auto it:mp[i-(ll)1e6])
                {
                    st1.push(it);
                    if(check) f[it]=1;
                }
            }
            // if(i>1e6) cout<<i-(ll)1e6<<" "<<ans<<el;
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
    // cout<<test<<el;
    FOR(i,1,test)
    {
        mnp::sol();
    }
    ieozzool;
}
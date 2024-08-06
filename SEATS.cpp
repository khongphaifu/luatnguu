#include <bits/stdc++.h>
using namespace std;


#define           TASK  "SEATS"
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

const ll N = 1e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll n,q;

    void sol()
    {
        cin>>n>>q;
        set<ll> s;
        map<ll,ll> mp;
        ll i=1;
        while(q--)
        {
            ll x;cin>>x;
            if(x==1)
            {
                if(s.empty()) s.insert(1),mp[i]=1,i++,cout<<1<<el;
                else if(s.size()==1)
                {
                    auto it=s.begin();
                    if(*it-1>=n-*it)
                    {
                        s.insert(1);mp[i]=1,i++;
                        cout<<1<<el;
                    }
                    else 
                    {
                        s.insert(n);mp[i]=n,i++;
                        cout<<n<<el;
                    }
                }
                else
                {
                    auto it=s.begin();
                    ll tmp=*it;
                    ll ans=tmp-1;
                    for(auto it1:s)
                    {
                        if(it1==tmp) continue;
                        else
                        {
                            ans=max(ans,(ll)((it1-tmp)/2));
                            tmp=it1;
                        }
                    }
                    ans=max(ans,(n-tmp));
                    tmp=*it;
                    if(ans==tmp-1)
                    {
                        s.insert(1);mp[i]=1,i++;
                        cout<<1<<el;continue;
                    }
                    // cout<<"*"<<ans<<el;
                    
                    for(auto it1:s)
                    {
                        if(it1==tmp) continue;
                        else
                        {
                            if((ll)((it1-tmp)/2)==ans)
                            {
                                s.insert(tmp+(ll)((it1-tmp)/2));
                                cout<<tmp+(ll)((it1-tmp)/2)<<el;
                                mp[i]=tmp+(ll)((it1-tmp)/2);
                                i++; 
                                break;
                            }
                            tmp=it1;
                        }
                    }
                    if(ans==(n-tmp))
                    {
                        mp[i]=n;i++;s.insert(n);
                        cout<<n<<el;continue;
                    }

                }

            }
            else
            {
                ll j;cin>>j;s.erase(mp[j]);
            }
        }
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
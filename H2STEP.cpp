#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb  push_back  
#define ll  long long
#define el  "\n"
#define alla(a,n)  a+1,a+n+1
#define fi first
#define se second
#define all(v)  v.begin(),v.end()
#define fu(i,a,b)  for(ll i=a;i<=b;i++)
#define fud(i,a,b)  for(ll i=a;i>=b;i--)

const ll MOD=1e9+7 ;//1234567891;
const ll inf=1e18;
const ll base = 311;
const ll N=1e6+5;
const ll N1=1e3+5;
/*🥑*/
template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}
/*v*/
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

ll n,q;
ll f[N],Q[N];

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }
    cin>>n>>q;
    set<ll> s;
    multiset<ll> sm;
    map<ll,ll> mp;
    s.insert(0);
    s.insert(n+1);
    sm.insert(n);
    fu(i,1,q)
    {
        ll x;cin>>x;
        Q[i]=x;
        mp[x]++;
        if(mp[x]%2!=0)
        {
            auto it=s.upper_bound(x);
            auto it1=s.upper_bound(x);
            it1--;
            // cout<<*it<<" "<<*it1<<el;
            sm.erase(sm.find(*it-*it1-1));
            sm.insert(x-*it1-1);
            sm.insert(*it-x-1);
            s.insert(x);
        }
        else
        {
            auto it=s.upper_bound(x);
            auto it1=s.lower_bound(x);
            it1--;
            sm.erase(sm.find(x-*it1-1));
            sm.erase(sm.find(*it-x-1));
            sm.insert(*it-*it1-1);
            s.erase(x);
        }
        f[i]=*sm.rbegin();
        if(q<=N1)
        {
            ll d=0,res=0,ans=1;
            // s1.insert(0);
            for(auto it:s)
            {
                d++;
                if(it==n+1) continue;
                if(d>=3)
                {
                    if(it-res==1) ans++;
                    else ans=1;
                }
                if(d>=2) res=it;
                
            }
            f[i]=max(ans,f[i]);
        }
    }
    fu(i,1,q) cout<<f[i]<<el;    


    
    // số MOD bro
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
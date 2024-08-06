#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define             pb  push_back  
#define             ll  int
#define             el  "\n"
#define      alla(a,n)  a+1,a+n+1
#define         all(v)  v.begin(),v.end()
#define      fu(i,a,b)  for(ll i=a;i<=b;i++)
#define     fud(i,a,b)  for(ll i=a;i>=b;i--)

const ll N=(1<<21),MOD=1e9+7,inf=1e9;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll n,hehe;
ll a[N],b[N];
int fa[N],fb[N];
// unordered_map<ll,ll> mp;
gp_hash_table<ll,ll,custom_hash> mp;

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }
    cin>>n>>hehe;
    ll n1=n/2;
    ll n2=n-n1;
    fu(i,1,n1) cin>>a[i];
    sort(alla(a,n1),greater<ll>());
    fu(i,1,n2) cin>>b[i];
    sort(alla(b,n2),greater<ll>());
    ll tt=(1<<n1)-1;
    long long ans=0;
    fu(x,0,tt)
    {
        long long res=0;
        fu(i,1,n1)
        {
            if((x&(1<<(i-1)))!=0)
            {
                ll p=(x^(1<<(i-1)));
                res=fa[p]+a[i];
                break;
            }
        }
        if(res>hehe)
        {
            fa[x]=inf;
            continue;
        }
        fa[x]=res;
        mp[res]++;
        // if(res==x) ans++;
    }
    tt=(1<<n2)-1;
    fu(x,0,tt)
    {
        long long res=0;
        fu(i,1,n2)
        {
            if((x&(1<<(i-1)))!=0)
            {
                ll p=(x^(1<<(i-1)));
                res=fb[p]+b[i];
                break;
            }
        }

        if(res>hehe)
        {
            fb[x]=inf;
            continue;
        }
        fb[x]=res;
        if(mp.find(hehe-res)!=mp.end())ans+=mp[hehe-res];
        // if(res==x) ans++;
    }
    cout<<ans;


    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
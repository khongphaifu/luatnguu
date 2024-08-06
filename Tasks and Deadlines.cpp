#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define             pb  push_back  
#define             ll  long long
#define             el  "\n"
#define      alla(a,n)  a+1,a+n+1
#define         all(v)  v.begin(),v.end()
#define      fu(i,a,b)  for(ll i=a;i<=b;i++)
#define     fud(i,a,b)  for(ll i=a;i>=b;i--)

const ll N=2e5+5,MOD=1e9+7;

struct bg
{
    ll x,y;
};

ll n;
bg a[N];

bool cmp(bg a,bg b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n;
    fu(i,1,n) cin>>a[i].x>>a[i].y;
    sort(alla(a,n),cmp);
    ll res=0,ans=0;
    // fu(i,1,n) cout<<a[i].x<<" "<<a[i].y<<el;
    fu(i,1,n)
    {
        res+=a[i].x;
        ans+=a[i].y-res;
    }
    cout<<ans;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
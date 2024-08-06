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

const ll N=1e6+5,MOD=1e9+7;

ll n,L,m;


struct bg
{
    ll x,w,h,t;
};

bg a[N];

bool cmp(bg a,bg b)
{
    return a.x<b.x;
}

bool cmp1(bg a,bg b)
{
    return a.t<b.t;
}

pair<ll,ll> p[N];
ll s[N],b[N],T[N];

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>L>>m;

    fu(i,1,n)
    {
        cin>>a[i].x>>a[i].w>>a[i].h;
        if(a[i].h==0) a[i].t=a[i].x;
        else a[i].t=L-a[i].x;
    }

    sort(alla(a,n),cmp);
    deque<ll> q;
    fu(i,1,n) q.pb(a[i].w);
    sort(alla(a,n),cmp1);
    fu(i,1,n)
    {
        if(a[i].h==0)
        {
            ll w=q.front();
            q.pop_front();
            p[i]={a[i].t,w};
        }
        else 
        {
            ll w=q.back();
            q.pop_back();
            p[i]={a[i].t,w};
        }
    }
    fu(i,1,n) s[i]=s[i-1]+p[i].second,b[i]=p[i].first;
    fu(i,1,m) cin>>T[i];
    fu(i,1,m)
    {
        ll j=upper_bound(alla(b,n),T[i])-b;
        j--;
        cout<<s[j]<<" ";
    }


    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}   
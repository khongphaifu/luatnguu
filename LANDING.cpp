// khongphaifu - Mai Ngọc Phú - T2K33 - THPT Chuyên Lê Khiết
// VOI... 
// Program link: https://tinhoclk.com/problem/landing
// Program name: v 
#define TASK  "LANDING"
// sol: cnp + ctdl



#include <bits/stdc++.h>
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
using namespace std;


ll mlt=0;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const long long inf = 1e18;
const ll N = 1e6 + 5 , N1 = 5e3 + 5 , MOD = 1e9 , sminf = 1e9;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    struct bg
    {
        ll l,r;
    };

    bool cmp(bg a,bg b)
    {
        if(a.l==b.l) return a.r<b.r;
        return a.l<b.l;
    }

    // struct cmp1
    // {
    //     bool operator() (bg a,bg b)
    //     {
    //         if(a.l==b.l) return a.r<b.r;
    //         return a.l<b.l;
    //     }
    // }

    ll n,k,x,sl=0;
    bg a[N];

    ll check()
    {

    }

    void sol()
    {
        cin>>n>>k>>x;
        FOR(i,1,n) cin>>a[i].l>>a[i].r;
        sort(alla(a,n),cmp);
        priority_queue<ll,vector<ll>,greater<>> h;
        FOR(i,1,k) h.push(0);
        FOR(i,1,n)
        {
            while(a[i].l>h.top())
            {
                h.pop();
                h.push(a[i].l);
            }
            if(a[i].r>=h.top())
            {
                ll tmp=h.top();
                h.pop();
                h.push(tmp+x);
                sl++;
            }
        }
        cout<<sl<<" ";
        ll l=x,r=1e18;
        ll ans=0;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            priority_queue<ll,vector<ll>,greater<>> h1;
            FOR(i,1,k) h1.push(0);
            ll sl1=0;
            FOR(i,1,n)
            {
                while(a[i].l>h1.top())
                {
                    h1.pop();
                    h1.push(a[i].l);
                }
                if(a[i].r>=h1.top())
                {
                    ll tmp=h1.top();
                    h1.pop();
                    h1.push(tmp+mid);
                    sl1++;
                }
            }
            if(sl1<sl) r=mid-1;
            else l=mid+1,ans=mid;
        }
        if(ans==1e18) cout<<-1;
        else cout<<ans;
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
#include <bits/stdc++.h>
using namespace std;


#define           TASK  "FINE"
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
    ll n;

    struct bg
    {
        ll x,t;
    };
    
    bool cmp(bg a,bg b)
    {
        return a.x<b.x;
    }
    bg a[N];

    void sol()
    {
        cin>>n;
        FOR(i,1,n) cin>>a[i].x>>a[i].t;
        sort(alla(a,n),cmp);
        ll ans=0,res=a[1].x;
        priority_queue<ll ,vector<ll>, greater<>> q;
        // q.push(1),q.push(2);
        // while(!q.empty())
        // {
        //     cout<<q.top();q.pop();
        // }

        q.push(a[1].t);
        FOR(i,2,n)
        {
            if(a[i].x-(res+q.top())<0)
            {
                ll tmp=q.top();
                q.pop();
                q.push(tmp-(a[i].x-res));
                ans+=(a[i].x-res)*q.size();
                res=a[i].x;
                q.push(a[i].t);
            }
            else
            {
                while(a[i].x-(res+q.top())>=0 && !q.empty())
                {
                    ans+=q.top()*q.size();
                    res=res+q.top();
                    q.pop();
                }
                if(q.empty())
                {
                    res=a[i].x;
                    q.push(a[i].t);
                }
                else if(a[i].x-(res+q.top())<0)
                {
                    ll tmp=q.top();
                    q.pop();
                    if(tmp-(a[i].x-res)>0) q.push(tmp-(a[i].x-res));
                    ans+=(a[i].x-res)*q.size();
                    res=a[i].x;
                    q.push(a[i].t);
                }
                
            }

        }
        while(!q.empty())
        {   
            // cout<<q.top()<<" ";
            ans+=q.top()*q.size();q.pop();
        }
        // cout<<el;
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
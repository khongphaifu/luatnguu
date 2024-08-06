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

struct point
{
    ll x,y;
} a[N];

ll n;

ll ccw(point a,point b,point c)
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y) ;
}

namespace sub1
{
    ll S(point a , point b, point c)
    {
        ll res=abs((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
        if(res==0) return -1;
        else return res;
    }

    void sol()
    {
        ll ans=0;
        fu(i,1,n)
        {
            fu(j,i+1,n)
            {
                fu(k,j+1,n)
                {
                    if((S(a[i],a[0],a[j])+S(a[i],a[k],a[0])+S(a[j],a[k],a[0]))==S(a[i],a[j],a[k])) ans++;
                }
            }
        }
        cout<<ans;
    }
}

namespace sub2
{

    bool cmp(point a,point b)
    {
        if(a.y==b.y) return a.x<b.x;
        return a.y<b.y;
    }
    ll d1,d2;
    point l[N],d[N];
    void sol()
    {
        ll resx=a[0].x,resy=a[0].y;
        fu(i,0,n) a[i].x-=resx,a[i].y-=resy;
        // sort(alla(a,n),cmp);
        vector<ll> v;
        ll ans=0;
        fu(i,1,n)
        {
            if(a[i].y==0)
            {
                v.pb(a[i].x);
                d1++;
                l[d1]=a[i];
                d2++;
                d[d2]=a[i];
            }
            else if(a[i].y>0)
            {
                d1++;
                l[d1]=a[i];
            }
            else
            {
                d2++;
                d[d2]=a[i];
            }
        }
        fu(i,1,d1)
        {
            ll res1=0,res2=0;
            fu(j,1,d2)
            {
                if(ccw(l[i],a[0],d[j])>0) res1++;
                else if(ccw(l[i],a[0],d[j])<0) res2++;
            }
            ans+=res1*res2;
        }
        // d1=0;
        // d2=0;
        // fu(i,1,n)
        // {
        //     if(a[i].y>0)
        //     {
        //         d1++;
        //         l[d1]=a[i];
        //     }
        //     else
        //     {
        //         d2++;
        //         d[d2]=a[i];
        //     }
        // }
        fu(i,1,d2)
        {
            ll res1=0,res2=0;
            fu(j,1,d1)
            {
                if(ccw(l[j],a[0],d[i])>0) res1++;
                else if(ccw(l[j],a[0],d[i])<0) res2++;
            }
            ans+=res1*res2;
        }
        sort(all(v));
        ll res=0;
        for(auto it:v)
        {
            if(it<0) res++;
            else break;
        }
        ll tmp=res*(v.size()-res);
        cout<<ans-(tmp *(d1-v.size() + d2-v.size()));
    }
}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".inp" ,"r",stdin) ; freopen(TASK".out" ,"w",stdout);
    }

    cin>>n;
    fu(i,0,n) cin>>a[i].x>>a[i].y;
    // if(n<=200) sub1::sol();
    // else if(n<=2000)
    sub2::sol();

    
    // số MOD bro
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
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

ll n,k,R,test;
ll a[N];

namespace sub1
{
    ll check(ll mid,ll res)
    {
        ll tmp=0;
        fu(i,1,R+res)
        {
            tmp+=min(mid,a[i]);
        }
        return tmp>=k*mid;
    }

    void sol()
    {
        ll tmp=n-R;
        fu(i,1,tmp)
        {
            ll l=0,r=1e17;
            while(l<=r)
            {
                ll mid=(l+r)/2;
                if(check(mid,i)) l=mid+1;
                else r=mid-1;
            }
            cout<<l-1<<" ";
        }
        cout<<el;
    }
}

namespace sub2
{

    ll bit1[N],bit2[N];

    void up(ll x,ll v,ll bit[N])
    {
        for(; x<=n ;x += x & -x) bit[x]+=v;
    }

    ll get(ll x,ll bit[N])
    {
        ll res=0;
        for(; x>0 ;x&=x-1) res+=bit[x];
        return res;
    }

    struct bg
    {
        ll x,y;
    };

    bg b[N];

    bool cmp(bg a,bg b)
    {
        if(a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    }

    ll c[N];

    ll check(ll mid)
    {
        // ll tmp=0;
        ll j=upper_bound(alla(a,n),mid)-a;
        // j--;
        ll tmp=get(j-1,bit1)+(get(n,bit2)-get(j-1,bit2))*mid;
        return tmp>=k*mid;
    }


    void sol()
    {
        fu(i,1,n) bit1[i]=bit2[i]=0;
        fu(i,1,n) b[i].x=a[i],b[i].y=i;
        sort(alla(a,n));
        sort(alla(b,n),cmp);
        fu(i,1,n) c[b[i].y]=i;
        fu(i,1,n) up(i,a[i],bit1),up(i,1,bit2);
        vector<ll> v;
        // cout<<get(0,bit2)<<el;
        // cout<<check(6)<<el;
        fud(i,n,R+1)
        {
            ll l=0,r=1e14;
            while(l<=r)
            {
                ll mid=(l+r)/2;
                if(check(mid)) l=mid+1;
                else r=mid-1;
            }
            v.pb(l-1);
            ll j=c[i];
            up(j,-b[j].x,bit1);
            up(j,-1,bit2);
        }

        fud(i,v.size()-1,0) cout<<v[i]<<" ";
        cout<<el;

    }

}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }
    cin>>test;
    while(test--)
    {
        cin>>n>>k>>R;
        fu(i,1,n) cin>>a[i];
        sub2::sol();
    }


    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
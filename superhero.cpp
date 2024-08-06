//watborindahood was here
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

struct bg
{
    ll m,p,id;
} a[N];
ll n;

namespace sub1
{
    pair<ll,ll> b[N];
    void sol()
    {
        fu(i,1,n) b[i].fi=a[i].m,b[i].se=a[i].p;
        ll ans=0;
        sort(alla(b,n));
        do
        {
            ll l=0,r=0;
            ll i=1,j=n;
            // ll ans=0;
            while(i<=n && j>=1 && i<j)
            {
                l+=b[i].fi;
                r+=b[j].se;
                if(l>=r) ans=max(ans,i);
                i++;
                j--;
            }
            // fu(i,1,n) cout<<b[i].fi<<" ";
            // cout<<el;
            // cout<<ans;
        } while(next_permutation(alla(b,n)));
        cout<<ans;
    }
}

namespace sub2
{
    ll f[N],g[N];
    bool cmp1(bg u,bg v)
    {
        return u.p<v.p;
    }
    void sol()
    {
        ll tt=(1<<n)-1;
        ll ans=0;
        sort(alla(a,n),cmp1);
        fu(x,0,tt)
        {
            ll res=0;
            ll cnt=0;
            vector<ll> v;
            fu(i,1,n)
            {
                if((x&(1<<(i-1)))!=0)
                {
                    cnt++;
                    res+=a[i].m;
                }
                else v.pb(a[i].p);
            }
            if(v.size()<cnt) continue;
            ll res1=0;
            fu(i,0,cnt-1) res1+=v[i];
            if(res1<=res)
            {
                ans=max(ans,cnt);
            }
        }
        cout<<ans;
    }
}

namespace sub3
{
    ll pre[N],suf[N];
    ll check(ll mid)
    {
        priority_queue<ll,vector<ll>> h;
        priority_queue<ll,vector<ll>,greater<>> h1;
        pre[0]=0;
        fu(i,1,n)
        {
            h1.push(a[i].m);
            pre[i]=pre[i-1]+a[i].m;
            if(h1.size()>mid)
            {
                pre[i]-=h1.top();
                h1.pop();
            }
        }
        suf[n+1]=0;
        fud(i,n,1)
        {
            h.push(a[i].p);
            suf[i]=suf[i+1]+a[i].p;
            if(h.size()>mid)
            {
                suf[i]-=h.top();
                h.pop();
            }
        }
        fu(i,mid,n-mid) if(pre[i]-suf[i+1]>=0) return 1;
        return 0;
    }

    bool cmp(bg a,bg b)
    {
        return a.m+a.p>b.m+b.p;
    }

    void sol()
    {
        sort(alla(a,n),cmp);
        ll l=0,r=n/2;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(check(mid)) l=mid+1;
            else r=mid-1;
        }
        cout<<l-1;
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
    fu(i,1,n) cin>>a[i].m;
    fu(i,1,n) cin>>a[i].p;
    if(n<=10) sub1::sol();
    else if(n<=20)sub2::sol();
    else 
    sub3::sol();
    
    // số MOD bro
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}

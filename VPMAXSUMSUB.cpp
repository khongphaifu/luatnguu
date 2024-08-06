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

template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

struct bg
{
    ll x,w;
};

ll n,q;
ll a[N],sum[N],L[N],R[N],ma[N],res[N],st1[4*N],st2[4*N];
bg e[N];

void build(ll id,ll l,ll r)
{
    if(l==r)
    {
        st1[id]=sum[l];
        st2[id]=sum[l];
        return;
    }
    ll mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st1[id]=min(st1[2*id],st1[2*id+1]);
    st2[id]=max(st2[2*id],st2[2*id+1]);
}

ll getmin(ll id,ll l,ll r,ll u,ll v)
{
    if(u>r || l>v) return inf;
    if(u<=l && r<=v) return st1[id];
    ll mid=(l+r)/2;
    return min(getmin(2*id,l,mid,u,v),getmin(2*id+1,mid+1,r,u,v));
}

ll getmax(ll id,ll l,ll r,ll u,ll v)
{
    if(u>r || l>v) return -inf;
    if(u<=l && r<=v) return st2[id];
    ll mid=(l+r)/2;
    return max(getmax(2*id,l,mid,u,v),getmax(2*id+1,mid+1,r,u,v));
}

ll getsum(ll l,ll r,ll i)
{
    return getmax(1,0,n,i,r)-getmin(1,0,n,l-1,i-1);
}

bool cmp(bg a,bg b)
{
    return a.x<b.x;
}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>q;
    fu(i,1,n)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    build(1,0,n);
    stack<ll> s;
    s.push(0);
    a[0]=a[n+1]=inf;
    fu(i,1,n)
    {
        while(!s.empty() && a[s.top()]<=a[i]) s.pop();
        L[i]=s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    s.push(n+1);
    fud(i,n,1)
    {
        while(!s.empty() && a[s.top()]<=a[i]) s.pop();
        R[i]=s.top();
        s.push(i);
    }

    fu(i,1,n)
    {
        e[i].x=a[i];
        e[i].w=getsum(L[i]+1,R[i]-1,i);
    }
    sort(alla(e,n),cmp);
    ma[0]=-inf;
    fu(i,1,n)
    {
        res[i]=e[i].x;
        ma[i]=max(ma[i-1],e[i].w);
    }
    while(q--)
    {
        ll x;cin>>x;
        ll j=upper_bound(alla(res,n),x)-res;
        j--;
        if(j) cout<<ma[j]<<el;
        else cout<<"No Solution"<<el;
    }


    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
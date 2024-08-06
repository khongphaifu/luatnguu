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
    ll x1,x2,y;
};

ll n;
bg a[N];
map<ll,ll> mp;

bool cmp(bg a,bg b)
{
    return a.y<b.y;
}

ll st[4*N],node[4*N];

void down(ll id)
{
    ll t=node[id];
    if(t==0) return;
    node[2*id]=t;
    st[2*id]=t;
    st[2*id+1]=t;
    node[2*id+1]=t;
    node[id]=0;
}

void up(ll id,ll l,ll r,ll u,ll v,ll val)
{
    if(v<l || u>r) return;
    if(u<=l && r<=v)
    {
        st[id]=val;
        node[id]=val;
        return;
    }
    ll mid=(l+r)/2;
    down(id);
    up(2*id,l,mid,u,v,val);
    up(2*id+1,mid+1,r,u,v,val);
}

ll get(ll id,ll l,ll r,ll i)
{
    if(i<l || i>r) return 0;
    if(l==r)
    {
        return st[id];
    }
    ll mid=(l+r)/2;
    down(id);
    return get(2*id,l,mid,i)+get(2*id+1,mid+1,r,i);
}


signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n;
    vector<ll> v;
    // fu(i,1,4*N) node[i]=-1;
    fu(i,1,n) cin>>a[i].x1>>a[i].x2>>a[i].y,v.pb(a[i].x1),v.pb(a[i].x2);
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    fu(i,0,v.size()-1)
    {
        mp[v[i]]=i+1;
    }
    ll m=v.size();
    sort(alla(a,n),cmp);
    ll ans=0;
    fu(i,1,n)
    {
        ll x1=a[i].x1;
        ll x2=a[i].x2;
        ans+=2*a[i].y-get(1,1,m,mp[x1])-get(1,1,m,mp[x2]);
        // cout<<get(1,1,m,mp[x1])<<el;
        up(1,1,m,mp[x1],mp[x2],a[i].y);
    }
    cout<<ans;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
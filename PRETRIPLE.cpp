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
const ll N=3e5+5;
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
    ll x,y;
};

ll n;
bg a[N];

ll cal(bg a,bg b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

namespace sub1
{
    ll dmin[N];

    void sol()
    {

        fu(i,1,n) dmin[i]=inf;
        fu(i,1,n) fu(j,1,n)
        {
            if(i!=j)
            {
                dmin[i]=min(dmin[i],cal(a[i],a[j]));
            }
        }
        ll ans=0;
        fu(i,1,n) fu(j,i+1,n) fu(k,j+1,n)
        {
            if(cal(a[i],a[j])==cal(a[j],a[k]) && cal(a[j],a[k])==cal(a[i],a[k]) && cal(a[i],a[k])==dmin[i] && dmin[i]==dmin[j] && dmin[j]==dmin[k]) ans++;
        }
        cout<<ans;
    }
}

namespace sub2
{

    ll dmin[N];
    vector<ll> g[N];
    bool cmp(bg a,bg b)
    {
        if(a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    }

    void sol()
    {
        sort(alla(a,n),cmp);
        fu(i,1,n) dmin[i]=inf;
        fu(i,1,n) fu(j,1,n)
        {
            if(i!=j)
            {
                dmin[i]=min(dmin[i],cal(a[i],a[j]));
            }
        }
        fu(i,1,n) cout<<dmin[i]<<" ";
        cout<<el;
        fu(i,1,n) fu(j,i+1,n)
        {
            if(dmin[i]==dmin[j] && dmin[j]==cal(a[i],a[j])) g[i].pb(j);
        }
        ll ans=0;
        fu(i,1,n)
        {
            // cout<<g[i].size()<<el;
            if(g[i].size()==0) continue;
            fu(j,0,g[i].size()-1)
            {
                fu(k,j+1,g[i].size()-1)
                {
                    if(cal(a[g[i][j]],a[g[i][k]])==dmin[g[i][j]]) ans++;
                }
            }
        }
        cout<<ans;
    }
}

namespace sub34
{

    // struct custom_hash
    // {
    //     static uint32_t splitmix64(uint32_t x)
    //     {
    //         // http://xorshift.di.unimi.it/splitmix64.c
    //         x += 0x9e3779b97f4a7c15;
    //         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    //         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    //         return x ^ (x >> 31);
    //     }
     
    //     size_t operator()(uint32_t x) const
    //     {
    //         static const uint32_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    //         return splitmix64(x + FIXED_RANDOM);
    //     }
    // };
    ll dmin[N],low[4*N],high[4*N];
    vector<ll> g[N];
    map<ll,vector<pair<ll,ll>>> row;

    void add(ll u , vector<pair<ll,ll>>&a ,ll l ,ll r )
    {
        ll L = lower_bound(all(a),l,[](pair<ll,ll> x ,ll val){return x.se<val;})-a.begin();
        ll R = upper_bound(all(a),r,[](ll val , pair<ll,ll> x){return val<x.se;})-a.begin()-1 ;
        fu(i,L,R)if(a[i].fi!=u)g[u].pb(a[i].fi) ; 
    }

    bool cmp(bg a,bg b)
    {
        if(a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    }
    
    
    void up(ll id,ll l,ll r,ll i,ll val,ll st[])
    {
        if(i<l || i>r) return;
        if(l==r && l==i)
        {
            st[id]=min(st[id],val);return;
        }
        ll mid=(l+r)>>1;
        up(id<<1,l,mid,i,val,st);
        up(id<<1|1,mid+1,r,i,val,st);
        st[id]=min(st[id<<1|1],st[id<<1]);
    }
    
    ll get(ll id,ll l,ll r,ll u,ll v,ll st[])
    {
        if(u>r || l>v) return inf;
        if(u<=l && r<=v) return st[id];
        ll mid=(l+r)>>1;
        return min(get(id<<1,l,mid,u,v,st),get(id<<1|1,mid+1,r,u,v,st));
    }


    vector<ll> v;
    void sol()
    {
        sort(alla(a,n),cmp);
        fu(i,1,n)
        {
            // v.pb(a[i].x);
            v.pb(a[i].y);
        }
        sort(all(v));
        v.resize(unique(all(v))-v.begin());
        ll m=v.size();
        // fu(i,1,m)
        // {
        //     mp[v[i-1]]=i;
        // }
        // fu(i,1,n) cout<<a[i].x<<" "<<a[i].y<<el;
        fu(i,1,n) dmin[i]=inf;
        fu(i,1,4*m) low[i]=high[i]=inf;
        fu(i,1,n)
        {
            // cout<<mp[a[i].y]<<el;
            ll u = upper_bound(all(v),a[i].y)-v.begin() ;
            if(i>1)
            {
                dmin[i]=min(dmin[i],a[i].x+a[i].y+get(1,1,m,1,u,low));
                dmin[i]=min(dmin[i],a[i].x-a[i].y+get(1,1,m,u+1,m,high));
            }
            up(1,1,m,u,-(a[i].y+a[i].x),low);
            up(1,1,m,u,-(a[i].x-a[i].y),high);
        }
        // fu(i,1,n) cout<<dmin[i]<<" ";
        // cout<<el;
        fu(i,1,4*m) low[i]=high[i]=inf;
        fud(i,n,1)
        {
            ll u = upper_bound(all(v),a[i].y)-v.begin() ;
            if(i<n)
            {
                dmin[i]=min(dmin[i],-a[i].x+a[i].y+get(1,1,m,1,u,low));
                dmin[i]=min(dmin[i],-a[i].x-a[i].y+get(1,1,m,u+1,m,high));
            }
            // cout<<mp[a[i].y]<<el;
            up(1,1,m,u,-(a[i].y-a[i].x),low);
            up(1,1,m,u,-(-a[i].x-a[i].y),high);
        }
        map<ll,vector<ll>> mp1;
        // fu(i,1,n) cout<<dmin[i]<<" ";
        // cout<<el;
        fu(i,1,n)
        {
            // for(auto it:mp[dmin[i]]) if(cal(a[i],a[it])==dmin[i]) g[it].pb(i);
            mp1[dmin[i]].pb(i);
        }
        ll ans=0;
        for(auto it:mp1)
        {
            for(auto x:it.se)
            {
                row[a[x].x-a[x].y].pb({x,a[x].x+a[x].y});
            }
            ll d=it.fi;
            for(auto x:row)
            {
                vector<pair<ll,ll>> up,down;
                if(row.count(x.fi-d))up=row[x.fi-d] ; 
                if(row.count(x.fi+d))down=row[x.fi+d] ;
                for(auto u : x.se)
                {
                    ll id = u.fi ;
                    add(id,up,u.se-d,u.se+d);
                    add(id,down,u.se-d,u.se+d) ; 
                }
            }
            row.clear();
            for(auto x:it.se)
            {
                row[a[x].x+a[x].y].pb({x,a[x].x-a[x].y});
            }
            for(auto x:row)
            {
                vector<pair<ll,ll>> up,down;
                if(row.count(x.fi-d))up=row[x.fi-d] ; 
                if(row.count(x.fi+d))down=row[x.fi+d] ;
                for(auto u : x.se)
                {
                    ll id = u.fi ;
                    add(id,up,u.se-d,u.se+d);
                    add(id,down,u.se-d,u.se+d) ; 
                }
            }
            row.clear();
        }
        fu(i,1,n)
        {
            // cout<<g[i].size()<<el;
            sort(all(g[i]));
            g[i].resize(unique(all(g[i]))-g[i].begin());
            if(g[i].size()==0) continue;
            fu(j,0,g[i].size()-1)
            {
                fu(k,j+1,g[i].size()-1)
                {
                    if(cal(a[g[i][j]],a[g[i][k]])==dmin[g[i][j]]) ans++;
                }
            }
        }
        cout<<ans/3;
        // cout<<ans;

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
    fu(i,1,n) cin>>a[i].x>>a[i].y;
    // if(n<=300) sub1::sol();
    // else
    // if(n<=3000)sub2::sol();
    // else
    sub34::sol();
    
    // số MOD bro
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
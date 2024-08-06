// khongphaifu - Mai Ngọc Phú - T2K33 - THPT Chuyên Lê Khiết
// VOI... 
// Program link: https://tinhoclk.com/problem/qtravel1
// Program name: v 
#define TASK  "4"
// sol: dfs + cnp + QHD trên cây 
// 1.Tìm thành phần liên thông mạnh
// 2.Nếu 1 cạnh thuộc tpltm thì ans+= virus-res (res=(i+1)*i/2 với i chạy từ 1 tới (res>virus)) (tối ưu bằng cnp) 
// 3.Ngược lại thì ans+=virus
int mlt=0;
int test=1;

#include <bits/stdc++.h>
using namespace std;


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
#define     print(a,n)  for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<el;
#define      printv(v)  for(auto it:v) cout<<it<<" ";cout<<el;
#define     printvp(v)  for(auto it:v) cout<<it.fi<<" "<<it.se<<el;
#define            end  cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;

const ll N = 1e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9 , inf = 1e18 ;
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
        ll ke,virus;
    };

    bool check1=1;
    ll m,n,s,scc,stt;
    ll num[N],low[N],del[N],f[N],ans[N],visit[N];
    vector<bg> g[N],gr[N];
    map<ll,ll> mp;
    stack<ll> st;
    queue<ll> ds;

    ll cal(ll x)
    {
        return x*(x+1)/2;
    }

    bool check(ll mid,ll x)
    {
        return cal(mid)<=x;
    }

    ll tinh(ll x)
    {
        ll l=1,r=100000;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(check(mid,x)) l=mid+1;
            else r=mid-1;
        }
        ll tmp=r;
        // cout<<r<<el;
        ll res=0;
        FOR(i,1,r) res+=cal(i);
        return (tmp+1)*x-res;
    }


    void dfs(ll u)
    {
        num[u]=low[u]=++stt;
        st.push(u);
        for(auto it:g[u])
        {
            if(del[it.ke]) continue;
            if(!num[it.ke])
            {
                dfs(it.ke);
                low[u]=min(low[u],low[it.ke]);
            }
            else low[u]=min(low[u],num[it.ke]);
        }
        if(low[u]==num[u])
        {
            ll v;
            ++scc;
            do
            {
                v=st.top();
                st.pop();
                del[v]=scc;
                mp[scc]++;
                if(v==s && check1) s=scc,check1=0;
            }
            while(u!=v);
        }
    }

    void dfs1(ll u)
    {
        visit[u]=1;
        for(auto it:gr[u])
        {
            // if(!visit[it.ke])
            // {
                dfs1(it.ke);
                ans[u]=max(ans[u],ans[it.ke]+it.virus+f[u]);
            // }
        }
    }


    void sol()
    {
        cin>>n>>m;
        FOR(i,1,m)
        {
            ll x,y,virus;cin>>x>>y>>virus;
            g[x].pb({y,virus});
        }
        cin>>s;
        FOR(i,1,n)
        {
            if(!del[i]) dfs(i);
        }
        FOR(i,1,n)
        {
            for(auto it:g[i])
            {
                if(del[i]==del[it.ke]) f[del[i]]+=tinh(it.virus);
            }
        }
        // cout<<tinh(4)<<el;
        FOR(i,1,n)
        {
            for(auto it:g[i])
            {
                if(del[it.ke]!=del[i])
                {
                    gr[del[i]].pb({del[it.ke],it.virus});
                }
            }
        }
        FOR(i,1,n)
        {
            ans[del[i]]=f[del[i]];
        }
        dfs1(s);
        cout<<ans[s];
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
    end
}
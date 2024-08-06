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
const ll N=2e3+5;
const ll N1=1e3+5;
/*🥑*/
template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}
/*v*/
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
char dc[]={'v','^','>','<'};

struct bg
{
    ll x,y,ts;
};

struct cmp
{
    bool operator()(bg a,bg b){return a.ts>b.ts;}
};

ll n,m,stx,sty,enx,eny;
char dp[N][N];
ll f[N][N],dd[N][N];
pair<ll,ll> par[N][N];

bool inside(ll i,ll j)
{
    return (i>=1 && i<=n && j>=1 && j<=m);
}

void dij(ll x,ll y)
{
    priority_queue<bg,vector<bg>,cmp> h;
    fu(i,1,n) fu(j,1,m) f[i][j]=inf,dd[i][j]=0;
    h.push({x,y,0});
    f[x][y]=0;
    dd[x][y]=1;
    fu(i,0,3)
    {
        ll sx=x+dx[i];
        ll sy=y+dy[i];
        if(inside(sx,sy))
        {
            par[sx][sy]={x,y};
            h.push({sx,sy,0});
            f[sx][sy]=0;
        }
    }
    while(!h.empty())
    {
        x=h.top().x;
        y=h.top().y;
        h.pop();
        if(dd[x][y]==1) continue;
        dd[x][y]=1;
        fu(i,0,3)
        {
            ll sx=x+dx[i];
            ll sy=y+dy[i];
            char res=dc[i];
            if(inside(sx,sy) && f[sx][sy]>f[x][y]+(res!=dp[x][y]) && !dd[sx][sy])
            {
                f[sx][sy]=f[x][y]+(res!=dp[x][y]);
                par[sx][sy]={x,y};
                h.push({sx,sy,f[sx][sy]});    
            }
        }
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

    cin>>n>>m;
    fu(i,1,n) fu(j,1,m)
    {
        cin>>dp[i][j];
        if(dp[i][j]=='o') stx=i,sty=j;
        if(dp[i][j]=='x') enx=i,eny=j;
    }
    dij(stx,sty);
    cout<<f[enx][eny]<<el;
    par[stx][sty]={-1,-1};
    ll x=enx,y=eny;
    // cout<<x<<" "<<y<<el;
    // cout<<par[x][y].fi<<" "<<par[x][y].se<<el;
    while(y!=-1 && x!=-1)
    {
        ll sx=par[x][y].fi;
        ll sy=par[x][y].se;
        ll res1=x-sx;
        ll res2=y-sy;
        if(res1==1) dp[sx][sy]='v';
        else if(res1==-1) dp[sx][sy]='^';
        else if(res2==1) dp[sx][sy]='>';
        else if(res2==-1) dp[sx][sy]='<';
        x=sx;
        y=sy;
    }
    dp[stx][sty]='o';
    fu(i,1,n)
    {
        fu(j,1,m) cout<<dp[i][j];
        cout<<el;
    }
    // số MOD bro
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
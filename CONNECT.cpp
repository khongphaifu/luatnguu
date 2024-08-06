#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb  push_back  
#define ll  short
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
const ll N=5e2+5;
const ll N1=1e3+5;

template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

ll n,m,ans=inf;
ll a[N][N],L[N][N],R[N][N],f[N][N][2][2],b[N][N];

void init()
{
    cin>>n>>m;
    fu(i,1,n) fu(j,1,m)
    {
        char x;cin>>x;
        a[i][j]=x-'0';
    }
}

struct bg1
{
    ll x,y;
};

struct bg2
{
    ll x,y,l,r;
};

bool inside(ll x,ll y)
{
    return (x>=1 && x<=n && y>=1 && y<=m);
}

void pre(ll f[N][N],ll res)
{
    queue<bg1> h[9007];
    fu(i,1,n)
    {
        f[i][res]=b[i][res];
        h[b[i][res]].push({i,res});
    }
    fu(cp,0,9000)
    {
        if(cp>ans) break;
        while(!h[cp].empty())
        {
            ll x=h[cp].front().x;
            ll y=h[cp].front().y;
            h[cp].pop();
            if(f[x][y]<cp) continue;
            fu(i,0,3)
            {
                ll sx=x+dx[i];
                ll sy=y+dy[i];
                if(inside(sx,sy) && f[sx][sy]>cp+b[sx][sy])
                {
                    f[sx][sy]=cp+b[sx][sy];
                    h[f[sx][sy]].push({sx,sy});
                }
            }
        }
    }
}

void dij()
{
    queue<bg2> h[9007];
    fu(i,1,m)
    {
        f[1][i][0][0] = b[1][i] ;  
        h[b[1][i]].push({1,i,0,0});
    }
    fu(cp,0,9000)
    {
        if(cp>ans) break;
        while(!h[cp].empty())
        {
            ll x=h[cp].front().x;
            ll y=h[cp].front().y;
            ll l=h[cp].front().l;
            ll r=h[cp].front().r;
            h[cp].pop();
            if(f[x][y][l][r]<cp) continue;
            fu(i,0,3)
            {
                ll sx=x+dx[i];
                ll sy=y+dy[i];
                if(inside(sx,sy) && f[sx][sy][l][r]>cp+b[sx][sy])
                {
                    f[sx][sy][l][r]=cp+b[sx][sy];
                    h[f[sx][sy][l][r]].push({sx,sy,l,r});
                }
            }
            if(!l && f[x][y][1][r]>cp-b[x][y]+L[x][y])
            {
                f[x][y][1][r]=cp-b[x][y]+L[x][y];
                h[f[x][y][1][r]].push({x,y,1,r});
            }
            if(!r && f[x][y][l][1]>cp-b[x][y]+R[x][y])
            {
                f[x][y][l][1]=cp-b[x][y]+R[x][y];
                h[f[x][y][l][1]].push({x,y,l,1});
            }
        }
    }
}

void sol()
{
    fu(x,0,9)
    {
        fu(i,1,n)fu(j,1,m)
        {
            b[i][j] = abs(x-a[i][j]) ;
            L[i][j] = inf ; 
            R[i][j] = inf ; 
            fu(l,0,1)fu(r,0,1)f[i][j][l][r] = inf; 
        }
        pre(L,1) ; 
        pre(R,m) ;
        dij() ; 
        fu(i,1,m) ans=min(ans,f[n][i][1][1]);
    }
    cout<<ans;
}



signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    init();
    sol();
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
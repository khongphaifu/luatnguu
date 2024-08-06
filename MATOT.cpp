#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define             pb  push_back  
#define             ll  long long
#define             el  "\n"
#define      alla(a,n)  a+1,a+n+1
#define         all(v)  v.begin(),v.end()
#define      fu(i,a,b)  for(ll i=a;i<=b;i++)
#define     fud(i,a,b)  for(ll i=a;i>=b;i--)

ll n,m,xm,ym,xt,yt;
ll f[107][107][5],ff[107][107][5],dp[107][107],f1[107][107],f2[107][107];
ll dx[]={1,1,1,-1,-1,-1,0,0};
ll dy[]={1,0,-1,1,0,-1,1,-1};
ll dxx[]={-2,-2,-1,-1,1,1,2,2};
ll dyy[]={-1,1,-2,2,2,-2,1,-1};

struct bg
{
    ll x,y;
};

struct bg1
{
    ll x,y,dem;
};

bool inside(ll x,ll y)
{
    return (x>=1 && x<=n && y>=1 && y<=m && !dp[x][y]);
}


void bfst(ll x,ll y)
{
    queue<bg1> q;
    fu(i,1,n) fu(j,1,m) fu(t,0,1) f[i][j][t]=1e18;
    q.push({x,y,0});
    f[x][y][0]=0;
    while(!q.empty())
    {
        x=q.front().x;
        y=q.front().y;
        ll w=q.front().dem;
        q.pop();
        fu(i,0,7)
        {
            ll sx=x+dx[i];
            ll sy=y+dy[i];
            ll res=1-w;
            if(inside(sx,sy) && f[sx][sy][res]>f[x][y][w]+1)
            {
                f[sx][sy][res]=f[x][y][w]+1;
                q.push({sx,sy,res});
            }
        }
    }
}

void bfsm(ll x,ll y)
{
    queue<bg1> q;
    q.push({x,y,0});
    fu(i,1,n) fu(j,1,m) fu(t,0,1) ff[i][j][t]=1e18;
    // ll res=dd[x][y]-1;
    ff[x][y][0]=0;

    // if(dd)
    while(!q.empty())
    {
        x=q.front().x;
        y=q.front().y;
        ll w=q.front().dem;
        q.pop();
        fu(i,0,7)
        {
            ll sx=x+dxx[i];
            ll sy=y+dyy[i];
            ll res=1-w;
            if(inside(sx,sy) && ff[sx][sy][res]>ff[x][y][w]+1)
            {
                ff[sx][sy][res]=ff[x][y][w]+1;
                q.push({sx,sy,res});
            }
            // if(inside(sx,sy)) f2[x][y]=1;
        }
    }

}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }
    cin>>n>>m;
    fu(i,1,n) fu(j,1,m)
    {
        char x;cin>>x;
        dp[i][j]=(x=='#');
        if(x=='M') xm=i,ym=j;
        if(x=='T') xt=i,yt=j;
    }    

    fu(x,1,n) fu(y,1,m) fu(i,0,7)
    {
        ll sx=x+dxx[i];
        ll sy=y+dyy[i];
        if(inside(sx,sy) && !dp[x][y] ) f2[x][y]=1; 
        sx=x+dx[i];
        sy=y+dy[i];
        if(inside(sx,sy) && !dp[x][y]) f1[x][y]=1; 
    }
    // fu(i,1,n)
    // {
    //     fu(j,1,m)  cout<<f2[i][j]<<" ";cout<<"\n";
    // }
    // cout<<n<<" "<<m<<el;
    bfst(xt,yt);
    bfsm(xm,ym);
    // fu(i,1,n)
    // {
    //     fu(j,1,m) cout<<f[i][j][1]<<" ";
    //     cout<<el;
    // }
    ll ans=1e18;
    fu(i,1,n) fu(j,1,m) fu(t,0,1) if(!dp[i][j] && f[i][j][t]!=1e18 && ff[i][j][t]!=1e18)
    {
        if(f[i][j][t]==ff[i][j][t]) ans=min(ans,f[i][j][t]);
        else if(f1[i][j] == f2[i][j]) ans=min(ans,max(f[i][j][t],ff[i][j][t]));
    }
    cout<<(ans==1e18 ? -1 : ans);

    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
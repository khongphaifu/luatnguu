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

const ll N=1e3+5,MOD=111539786,inf=1e18;
ll n;
string s,t;

struct bg
{
    ll x,y;
};

bg a[N],b[N];
ll id[N];
ll f[N][N],dd1[N],dd2[N];
ll sa[N][N],sb[N][N],g[N][N];

void sol()
{
    cin>>s>>t;
    ll k=s.size();
    s='0'+s+'#';
    ll res=0;
    ll d=0;
    fu(i,1,k+1)
    {
        if(isdigit(s[i]))
        {
            res=res*10+s[i]-'0';
        }
        else
        {
            a[d].y=res;
            res=0;
            d++;
            a[d].x=s[i]-'a'+1;
        }
    }
    d--;
    k = t.size();
    t='0'+t+'#';
    res=0;
    ll d1=0;
    fu(i,1,k+1)
    {
        if(isdigit(t[i]))
        {
            res=res*10+t[i]-'0';
        }
        else
        {
            b[d1].y=res;
            res=0;
            d1++;
            b[d1].x=t[i]-'a'+1;
        }
    }
    d1--;
    a[0]={0,1};
    b[0]={0,1};
    // unordered_map<ll,ll> mp;
    // fu(i,1,d)
    // {
    //     dd1[i]=mp[a[i].x];
    //     mp[a[i].x]=i;
    // }
    // unordered_map<ll,ll> mp1;
    // fu(i,1,d1)
    // {
    //     dd2[i]=mp1[b[i].x];
    //     mp1[b[i].x]=i;
    // }
    fu(c,1,26) fu(i,1,d) sa[c][i]=sa[c][i-1]+a[i].y*(a[i].x==c);
    fu(c,1,26) fu(i,1,d1) sb[c][i]=sb[c][i-1]+b[i].y*(b[i].x==c); 
    fu(c,1,26) id[c]=0;
    fu(i,1,d)
    {
        dd1[i]=id[a[i].x];id[a[i].x]=i;
    }
    fu(c,1,26) id[c]=0;
    fu(i,1,d1)
    {
        dd2[i]=id[b[i].x];id[b[i].x]=i;
    }
    // f[0][0]=1;
    res=-inf;
    // fu(i,0,d) fu(j,0,d1) f[i][j]=inf;
    // fu(i,1,d) f[i][0]=0;
    // fu(i,1,d1) f[0][i]=0;
    fu(i,1,d)
    {
        fu(j,1,d1)
        {
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i].x==b[j].x)
            {
                ll u=i,v=j,c=a[i].x;
                while(true)
                {
                    f[i][j]=max(f[i][j],f[u-1][v-1]+min(sb[a[i].x][j]-sb[a[i].x][v-1],sa[a[i].x][i] - sa[a[i].x][u-1]));
                    if(sb[a[i].x][j]-sb[a[i].x][v-1] < sa[a[i].x][i] - sa[a[i].x][u-1] )
                    {
                        v=dd2[v];
                        if(!v) break;
                    }
                    else
                    {
                        u=dd1[u];
                        if(!u) break;
                    }
                }
            }
            res=max(res,f[i][j]);

        }
    }
    cout<<res<<el;
    res=0;
    fu(i,1,d) fu(j,1,d1)
    {
        if(a[i].x==b[j].x)
        {
            g[i][j]+=min(a[i].y,b[j].y);
            // if(a[i].y==b[j].y)
            // {
                ll u=i-1,v=j-1;
                while(a[u].x==b[v].x && u>=1 && v>=1)
                {
                    g[i][j]+=min(a[u].y,b[v].y);
                    if(a[u].y==b[v].y) {u--;v--;}
                    else break;
                }
            // }
        }
        res=max(res,g[i][j]);
    }
    cout<<res;
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
    n=1;
    while(n--)sol();
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
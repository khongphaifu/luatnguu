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

const ll N=1e6+5,MOD=111539786,inf=1e18;
ll n;
string s;

struct bg
{
    ll x,y;
};

bg a[N];
ll f[N],dd[N];

void sol()
{
    cin>>s;
    ll k=s.size();
    s='0'+s+'#';
    ll res=0;
    ll d=0;
    fu(i,1,k+1)
    {
        if(isdigit(s[i]))
        {
            res=(res*10+s[i]-'0')%MOD;
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
    a[0]={0,1};
    fu(i,1,d) f[i]=0;
    // fu(i,1,d) cout<<a[i].x<<" "<<a[i].y<<el;
    f[0]=1;
    fu(i,0,d)
    {   
        fu(x,1,26) dd[x]=0;
        fu(j,i+1,d)
        {
            if(dd[a[j].x]) continue;
            dd[a[j].x]=1;
            if(a[i].x==a[j].x) f[j]=(f[j]+f[i])%MOD;
            else f[j]=(f[j]+((f[i]*a[i].y) %MOD))%MOD;
        }
    }
    ll ans=0;
    fu(i,1,d) ans=(ans+((f[i]*a[i].y)%MOD))%MOD;
    cout<<ans<<el;
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

    cin>>n;
    while(n--)sol();
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
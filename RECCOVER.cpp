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
    ll x,y;
};
ll n;
bg a[N];
bool cmp(bg a,bg b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
ll b[N],f[N];

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n;
    fu(i,1,n) cin>>a[i].x>>a[i].y,a[i].x=abs(a[i].x),a[i].y=abs(a[i].y);
    sort(alla(a,n),cmp);   
    stack<ll> s;
    s.push(1);
    fu(i,2,n)
    {
        while(!s.empty() && a[s.top()].y<=a[i].y) s.pop();
        s.push(i);
    }                   
    ll d=s.size();
    n=s.size();
    while(!s.empty())
    {
        b[d]=s.top();
        d--;
        s.pop();
    }
    fu(i,1,n)
    {
        f[i]=inf;
        fud(j,i,1) f[i]=min(f[i],f[j-1]+a[b[i]].x*a[b[j]].y);
    }

    cout<<f[n]*4;

    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
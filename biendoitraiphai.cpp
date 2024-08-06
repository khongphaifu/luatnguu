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

ll n;
ll a[N],b[N];
ll L[N],R[N];
struct bg
{
    ll type,l,r;
};

vector<bg> v;

vector<pair<ll,ll>> B,C;
ll c[N];

void sol()
{
    c[1]=b[1];
    ll m=1;
    fu(i,2,n)
    {
        if(b[i]!=b[i-1]) c[++m]=b[i];
    }
    ll j=1;
    fu(i,1,n)
    {
        if(a[i]==c[j]) j++;
    }
    if(j<=m)
    {
        cout<<-1;return;
    }
    j=1;
    fu(i,1,n)
    {
        ll k=j;
        while(k<=n && b[k]==a[i]) k++;
        ll L=j,R=k-1;
        if(L>R) continue;
        if(i<=L) B.pb({i,R});
        else if(i>=R) C.pb({L,i});
        else
        {
            C.pb({L,i});
            B.pb({i,R});
        }
        j=k;
    }
    // reverse(all(C));
    reverse(all(B));
    // sol();
    for(auto it:C)
    {
        if(it.fi!=it.se) v.pb({2,it.fi,it.se});
    }
    for(auto it:B)
    {
        if(it.fi!=it.se) v.pb({1,it.fi,it.se});
    }
    cout<<v.size()<<el;
    for(auto it:v)
    {
        cout<<it.type<<" "<<it.l<<" "<<it.r<<el;
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
    fu(i,1,n) cin>>a[i];
    fu(i,1,n) cin>>b[i];
    sol();
    
    // số MOD bro
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
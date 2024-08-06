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

const ll MOD=1e9+9 ;//1234567891;
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

ll n,m,k;
ll nen[N][2];
ll nt[N];

void snt()
{
    nt[0]=nt[1]=-1;
    fu(i,2,N) if(nt[i]==0)
    {
        for(ll j=i;j<=N;j+=i) nt[j]=i;
    }
}

void phantich(ll u,ll tp)
{
    while(u>1)
    {
        ll res=nt[u];
        while(u%res==0)
        {
            nen[res][tp]++;
            u/=res;
        }
    }
}

ll pw(ll a,ll b)
{
    if(b==0) return 1;
    ll tmp=pw(a,b/2);
    if(b%2==0) return tmp*tmp%MOD;
    else return tmp*tmp%MOD *a %MOD;
}

void sol()
{
    fu(i,1,1e6)
    {
        if(nen[i][0]>nen[i][1]) return void(cout<<0);
    }
    ll res=1;
    fu(i,1,1e6)
    {
        if(nen[i][0]!=nen[i][1])
        {
            ll u=nen[i][1]-nen[i][0]+1;
            ll tmp=(pw(u,k)+pw(u-2,k))%MOD;
            tmp=(tmp-(2*pw(u-1,k)%MOD)+ 2*MOD)%MOD;
            res=(res*tmp)%MOD;
        }
    }
    cout<<res;
}

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".inp" ,"r",stdin) ; freopen(TASK".out" ,"w",stdout);
    }
    cin>>n>>m>>k;
    k%=MOD-1;
    snt();
    fu(i,1,n)
    {
        ll x;cin>>x;
        phantich(x,0);
    }
    fu(i,1,m)
    {
        ll x;cin>>x;
        phantich(x,1);
    }
    sol();

    
    // số MOD bro
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
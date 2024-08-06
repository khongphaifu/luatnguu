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

template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

string s;
ll k,nodes=1;
ll t[N][27] , ans[N];
vector<ll> f[N];

void add(string s,ll i)
{
    ll r=1;
    fu(i,0,s.size()-1)
    {
        ll j=s[i]-'a';
        if(t[r][j]==-1) t[r][j]=++nodes;
        r=t[r][j];
    }
    f[r].pb(i);
}



signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }


    memset(t,-1,sizeof t);
    // cout<<t[0][0]<<el;
    cin>>s;
    ll n=s.size();
    s=' '+s;
    cin>>k;
    fu(i,1,k)
    {
        string x;cin>>x;
        // reverse(all(x));
        add(x,i);
    }
    if(k==1)
    {
        cout<<"NO"<<el;
        return 0;
    }
    // cout<<n<<el;
    fu(i,1,n)
    {
        ll r=1;
        fu(j,i,n)
        {
            ll res=s[j]-'a';
            if(t[r][res]==-1) break;
            r=t[r][res];
            if(f[r].size())
            {
                for(auto it:f[r])
                {
                    ans[it]=1;
                }
                f[r].clear();
            }
        }   
    }
    fu(i,1,k) cout<<(ans[i]==0 ? "NO": "YES")<<el;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
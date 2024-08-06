#include <bits/stdc++.h>
/**  /\_/\
*   (= ._.)
*   / >?? \>??
**/
#define TASK ""
#define ll int
#define nnc signed main()
using namespace std;
const ll MOD=1e9 + 7;
const ll N1=1e3 ;
const ll N=1e7 +5 ;
void tep()
        {
           ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
            if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
        }
struct hh{
    ll sum,k;
};
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll gt(ll a){
    if(a==0) return 1;
    return a*gt(a-1);
}
ll khoi=0;
ll a[N],b[N],d[N],e[N];
ll n,m,k,c,x,y;
ll dp2[N1][N1];
ll dp3[N1][N1];
// map<ll,ll> mp;
ll dx[]={0,1,-1,0};
ll dy[]={1,0,0,-1};
ll nt[N];
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    if(a.second==b.second) return a.first>b.first;
    return a.second<b.second;
}

ll bp(ll k, ll n)
{
    if(n == 0) return 1;
    ll temp = bp(k,n/2);
    if(n & 1) return (1ll * temp * temp) % MOD * k % MOD;
    return (1ll * temp * temp) % MOD;
}
ll C(ll n,ll k){
    return 1ll*a[n] * b[k] % MOD * b[n-k] %MOD;
}
void chau(){               
    cin>>n>>x>>y;
    a[0]=b[0]=1;
    for(ll i=1;i<=n;i++) a[i]=1ll*a[i-1]*i % MOD;
    b[n]=bp(a[n],MOD-2);
    for(ll i=n-1;i>=0;i--) b[i]=1ll*b[i+1]*(i+1)%MOD;
    m=n-y;
    ll ans=0;
    while(x<=m){
        ans+=C(n,x);
        x++;
        if(ans>MOD) ans-=MOD;
    }
    cout<<ans;
}
ll lapw=0;
nnc{
    tep();
    ll t=1;
    //xuli();
    if(lapw) cin>>t;
    while(t--) chau();
    cerr<<"Time: "<<clock()<<"ms"<<endl;
    return 0;
}
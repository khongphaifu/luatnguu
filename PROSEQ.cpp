//furiel?
#include <bits/stdc++.h>
/**  /\_/\
*   (= ._.)
*   / >?? \>??
**/
#define TASK ""
#define ll long long
#define nnc signed main()
#define se second 
#define fi first
using namespace std;
const ll MOD=1e9 + 7;
const ll N1=1e3 ;
const ll N=1e5 +5 ;
const ll oo=1e18;
const ll o=1e9;
void TLE(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
    if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
}
struct st{
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
ll a[N],b[N],c[N],d[N],e[N];
ll n,m,k,x,y;
ll dp2[N1][N1];
ll dp3[N1][N1];
// map<ll,ll> mp;
ll dx[]={0,1,-1,0};
ll dy[]={1,0,0,-1};
ll nt[N];
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    if(a.fi==b.fi) return a.se<b.se;
    return a.fi<b.fi;
}

ll bp(ll k, ll n) // k^n;
{
    if(n == 0) return 1;
    ll temp = bp(k,n/2);
    if(n & 1) return (1ll * temp * temp) % MOD * k % MOD;
    return (1ll * temp * temp) % MOD;
}
ll C(ll n,ll k){
    return 1ll*a[n] * b[k] % MOD * b[n-k] %MOD;
}
ll work(ll a){
    ll temp=a;
    while(temp>=10){
        ll temp1=1;
        while(temp>0){
            ll k=temp%10;temp/=10;
            if(k!=0) temp1*=k;
        }
        temp=temp1;
    }
    return temp;
}
void lor(){
    for(ll i=0;i<=1e6;i++) nt[i]=work(i);
}
void chau(){               
    cin>>x>>m>>y>>k>>n;
    cout<<x<<" "<<m<<" "<<y<<" "<<k<<" "<<n<<endl;
    if(k>m){
        ll temp1=k,temp2=y;
        y=x;k=m;
        x=temp2;m=temp1;
    }
    ll i=1;
    while(x){
        a[i]+=m;
        i++;
        if(i==n+1) i=1;
        x--;
    }
    
    sort(a+1,a+n+1);
    ll ans=1e18;
    while(y){
        a[1]+=k;
        y--;
        sort(a+1,a+n+1);
        
    }
    for(ll i=1;i<=n;i++) ans=min(ans,a[i]);
    cout<<ans;
}
ll lapw=0;
nnc{
    TLE();
    ll t=1;
    //xuli();
    if(lapw) cin>>t;
    while(t--) chau();
    cerr<<"Time: "<<clock()<<"ms"<<endl;
    return 0;
}
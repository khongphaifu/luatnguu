#include <bits/stdc++.h>
/**  /\_/\
*   (= ._.)
*   / >?? \>??
**/
#define TASK ""
using namespace std;
#define ll long long
const ll MOD=1000000007;
const ll N1=1e6*7 ;
const ll N=5e6 ;
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
ll nt[56]={0,1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99,111,222,333,444,555,666,777,888,999,1111,2222,3333,4444,5555,6666,7777,8888,9999,11111,22222,33333,44444,55555,66666,77777,88888,99999,111111,222222,333333,444444,555555,666666,777777,888888,999999,1111111};
ll a[N],b[N],c[N],d[N];
ll p(ll n){
    map<ll,ll> mp;
    mp[n%10]++;
    n/=10;
    while(n>0){
        if(mp[n%10]==0) return 0;
        mp[n%10]++;
        n/=10;
    }
    return 1;
}
void xuli(){
    
}
ll f[N];
void chau(){
    ll n,d;cin>>n>>d;
    ll maxvl=-1e18;
    for(ll i=1;i<=n;i++){
        ll x;cin>>x;
        a[i]=a[i-1]+x;
        if(i<d){
            f[i]=a[i];
        }
        if(i>=d){
            f[i%d]=min(f[i%d],a[i-d]);
            maxvl=max(maxvl,a[i]-f[i%d]);
        }
    }
    cout<<maxvl;
}
ll lapw=0;
int main(){
    tep();
    ll t=1;
    xuli();
    if(lapw) cin>>t;
    while(t--) chau();
    cerr<<"Time: "<<clock()<<"ms"<<endl;
    return 0;
}
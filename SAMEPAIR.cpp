#include <bits/stdc++.h>
/**  /\_/\
*   (= ._.)
*   / >?? \>??
**/
#define TASK ""
#define ll long long
using namespace std;
const ll MOD=1000000007;
const ll N1=1e3*7 ;
const ll N=1e6  ;
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
ll a[N],b[N],c[N],d[N];
ll n,m,k;
vector<pair<ll,ll>> v;
ll dx[2]={0,1};
ll dy[2]={1,0};
ll maxvl=0;
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return (k-a.first)*b.second<a.second*(k-b.first);
}
bool cmp1(pair<ll,ll> a,pair<ll,ll> b){
    return a.first*b.second>a.second*b.first;
}
ll p(ll x){
    ll temp=0;
    for(ll i=0;i<n;i++){
        if(v[i].second==0) return true;
        temp+=(x-v[i].first)/v[i].second;
        temp++;
    }
    return temp>=k;
}
ll nt[N];
void xuli(){
    for(ll i=2;i<=N;i++){
        if(nt[i]==0){
            nt[i]=i;
            for(ll j=i*2;j<=N;j+=i){
                if(nt[j]==0) nt[j]=1;
                nt[j]*=i;
            }
        }
    }
}

void chau(){
    xuli();               
    ll l,r;cin>>l>>r;
    map<ll,ll> mp;
    ll ans=0;
    for(ll i=l;i<=r;i++){
        ans+=mp[nt[i]];
        mp[nt[i]]++;
    }
    cout<<ans;
}
ll lapw=0;
int main(){
    tep();
    ll t=1;
    //xuli();
    if(lapw) cin>>t;
    while(t--) chau();
    cerr<<"Time: "<<clock()<<"ms"<<endl;
    return 0;
}
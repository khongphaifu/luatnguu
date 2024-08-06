#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll giaithua(ll n){
    if(n==0) return 1;
    return n*giaithua(n-1);
}
ll ngto(ll n){
    if(n<2) return false;
    for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll ngto1(ll n){
    for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
ll sums(ll n){
    ll sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
ll cp(ll n){
    ll k=sqrt(n);
    return (k*k==n);
}
const ll res=1000000007;
ll power(ll n,ll m){
    if(m==1) return n;
    return n %  res * power(n,m-1) % res;
}
const ll N=3e6+5;
ll a[N];
void inc(){
    
}
bool flags[N];
void chauuu(){
    ll n;cin>>n;
    for(ll i=0;i<n;i++){
        ll c;cin>>c;
        flags[c]=true;
    }
    ll ans=0;
    for(ll i=1;i<N;i++){
        ll d=0;
        for(ll j=i;j<N;j+=i){
            if(flags[j]) d=gcd(d,j);
        }
        if(d==i) ans++;
    }
    cout<<ans;
}
int main(){
    chauuu();
    cerr<<"Time: "<<clock()<<"ms"<<endl;
    return 0;
}
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
void chauuu(){
    ll n;cin>>n;
    //if(n==40000734736205) cout<<734736205;
    map<ll,ll> mp;
    ll tich=1;
    for(ll i=2;i<=n;i++){
        ll q=i;
        while(q%2==0){
            mp[2]++;
            if(mp[2]%2==0) tich*=2*2;
            q/=2;
            tich%=res;
        }
        for(ll j=3;j<=q;j+=2){
            while(q%j==0 && q>0){
                mp[j]++;
                if(mp[j]%2==0) tich*=j*j;
                q/=j;
                tich%=res;
            }
        }
    }
    cout<<tich;
}
int main(){
    chauuu();
    cerr<<"Time: "<<clock()<<"ms"<<endl;
    return 0;
}
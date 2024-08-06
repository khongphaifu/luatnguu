#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
bool ngto(ll n){
    if(n==2) return true;
    if(n%2==0) return false;
    for(ll i=3;i<=sqrt(n);i+=2){
        if(n%i==0) return false;
    }
    return true;
}
ll gt(ll n){
    if(n==0) return 1;
    return n*gt(n-1);
}
ll ds(char n){
    return n-'0';
}
void chauuu(){
    ll n,k;cin>>n>>k;
    ll res=0;
    map<ll,ll> mp;
    while(n--){
        ll x;cin>>x;
        mp[x]++;
        res+=mp[k-x*x];
    }
    cout<<res;
}
int main(){
    chauuu();
    return 0;
}
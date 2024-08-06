#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define M 10000
ll powe(ll x, ll n) {
    if (n == 0) return 1;
    ll temp = powe(x, n/2);
    if (n % 2 == 0) return temp * temp % M;
    return temp * temp % M * x % M;
}
int main(){
    ll n,x;cin>>n>>x;
    cout<<powe(n,x);
    return 0;
}
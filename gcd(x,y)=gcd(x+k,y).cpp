#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int calculateK(int x, int y)
{
 
    // Find gcd
    int g = gcd(x, y);
    int n = y / g;
    int res = n;
 
    // Calculating value of totient
    // function for n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res -= (res / i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n != 1)
        res -= (res / n);
    return res;
}
int main(){
    ll t;cin>>t;
    while(t--){
        ll x,y;cin>>x>>y;
        cout<<calculateK(x,y)<<endl;
    }
    return 0;
}
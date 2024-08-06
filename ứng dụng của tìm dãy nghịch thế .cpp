#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll merge(ll a[], ll l ,ll r ,ll m){
    vector<ll> x(a+l,a+m+1);
    vector<ll> y(a+m+1,a+r+1);
    ll i=0,j=0,cnt=0;
    while(i<x.size() && j<y.size()){
        if(x[i]<=y[j]){
            cnt+=y.size()-j;
            a[l]=x[i];l++;i++;
        }
        else{
            a[l]=y[j];l++;j++;
        }
    }
    while(i<x.size()){
        a[l]=x[i];l++;i++;
    }
    while(j<y.size()){
        a[l]=y[j];l++;j++;
    }
    return cnt;
}
ll meme(ll a[],ll l,ll r){
    ll dem=0;
    if(l<r){
    ll m=(l+r)/2;
    dem+=meme(a,l,m);
    dem+=meme(a,m+1,r);
    dem+=merge(a,l,r,m);
}
    return dem;
}
void burh(){
    ll n,m;cin>>n>>m;
    ll a[n];
    ll b[n+1];
    b[0]=0;
    for(ll i=1;i<=n;i++){
        ll x;cin>>x;
        a[i]=x-m;
        if(i>1) b[i]=b[i-1]+a[i];
        else b[i]=a[i];
    }
    //for(ll i=0;i<=n;i++) cout<<b[i]<<" ";
    cout<<meme(b,0,n);
    // ll n;cin>>n;
    // ll a[n];
    // for(ll i=0;i<n;i++) cin>>a[i];
    // meme(a,0,n-1);
    // for(ll i=0;i<n;i++) cout<<a[i]<<" ";
}
int main(){
    burh();
    return 0;
}
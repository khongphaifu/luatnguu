#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void burh(){
    ll n;cin>>n;
    ll a[n];
    ll tong=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];tong+=a[i];
        //cout<<a[i]<<" ";
    }
    if((tong%3)!=0) cout<<-1;
    else{
        ll temp=tong/3,res=0,dem=0;
        for(ll i=0;i<n;i++){
            res+=a[i];
            if(res==temp) {cout<<i<<" ";res=0;dem++;}
            if(dem==2) break;
        }
        if(dem==0) cout<<-1;
    }
}
int main(){
    burh();
    return 0;
}
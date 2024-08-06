#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll giaithua(ll n){
    if(n==0) return 1;
    return n*giaithua(n-1);
}
ll demuoc(ll n){
    ll k=2;
    ll q=sqrt(n);
    for(ll i=2;i<q;i++){
        if(n%i==0) k+=2;
    }
    if(q*q==n) k++;
    return k;
}
ll cp(ll n){
    ll k=sqrt(n);
    return (k*k==n);
}
void chauuu(){
    ll k;cin>>k;
    ll n=sqrt(abs(k));
    if(n*n==abs(k)){
        if(k>0) cout<<n;
        else cout<<0;    
    }
    else{
        ll temp=n;
        while((k%temp!=0 || (((k/temp)+temp)%2)!=0) && temp>1 ) temp--;
        ll n1=k/temp,n2=k/n1;
        ll a=abs(n1+n2);
        //cout<<a<<endl;
        if(a%2!=0) cout<<"none";
        else{
            a/=2;
            cout<<a;

        }

    }
}
int main(){
    chauuu();
    cerr<<"Time: "<<clock()<<"ms"<<endl;
    return 0;
}
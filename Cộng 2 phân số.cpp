#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
struct PhanSo{
    ll tu,mau;
};
void nhap(PhanSo &p){
    cin>>p.tu>>p.mau;
}
void rg(PhanSo &p){
    ll c= gcd(p.tu,p.mau);
    p.tu/=c;
    p.mau/=c;
}
PhanSo tong(PhanSo &p,PhanSo &q){
    PhanSo b;
    b.tu=p.tu * q.mau + p.mau * q.tu;
    b.mau=q.mau * p.mau;
    rg(b);
    return b;
}
void in(PhanSo q){
    cout<<q.tu<<"/"<<q.mau<<endl;
}
int main(){
    PhanSo p,q;
    nhap(p);nhap(q);
    PhanSo t = tong(p,q);
    in(t);
    return 0;
}
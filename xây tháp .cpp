#include <bits/stdc++.h>
using namespace std;
using ll = long long;
# define pi 3.1415926
struct sd{
    ll x,y,z;
};
bool cmp(sd a,sd b){
    return a.x*a.y<b.x*b.y;
}
sd a[100000];
void bruh(){
    ll n;cin>>n;
    for(ll i=1;i<=n;i++){
        ll temp[3];cin>>temp[0]>>temp[1]>>temp[2];
        sort(temp,temp+3);
        a[i].x=temp[2];a[i].y=temp[1];a[i].z=temp[0];
    }
    sort(a+1,a+n+1,cmp);
    //for(ll i=1;i<=n;i++) cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
    ll f[n];
    for(ll i=1;i<=n;i++){
        f[i]=a[i].z;
        for(ll j=1;j<i;j++){
            if(a[j].x<=a[i].x && a[j].y<=a[i].y) f[i]=max(f[i],f[j]+a[i].z);
        }
    }
    ll maxvl=-1e18;
    for(ll i=1;i<=n;i++) maxvl=max(maxvl,f[i]);
    cout<<maxvl;
}
int main(){
    bruh();
    cerr<<"Time:"<<" "<<clock()<<"ms"<<endl;
    return 0;
}
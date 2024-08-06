#include <bits/stdc++.h>
using namespace std;
using ll = long long;
# define pi 3.1415926
bool ngto(ll n){
    if(n<2) return false;
    if(n==2) return true;
    for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
void bruh(){
    ll n,k;cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    ll i=0,j=1;
    while(abs(a[j]-a[i])>k && i<n && j<n){
        i++;j++;
    }
    //cout<<i<<" "<<j<<endl;
    //l=a[i];r=a[j];
    ll nn,ln,xnn,xln;
    if(a[i]>a[j]){
        ln=a[i];nn=a[j];xnn=j;xln=i;
    }
    else{
        ln=a[j];nn=a[i];xnn=i;xln=j;
    }
    if(j==n && abs(a[j-1]-a[i-1])>k) {cout<<1;return;} 
    //cout<<xnn<<" "<<xln<<endl;
    ll maxvl=2;
    while(i<n && j<n-1){
        if(a[j+1]>=nn && a[j+1]<=ln) j++;
        else if(a[j+1]<nn){
            nn=a[j+1];j++;xnn=j;
            ll temp=xnn-1;
            ll maxvl1=a[temp],xmaxvl=temp;
            while(a[temp]-a[xnn]<=k && xln<=temp){
                if(a[temp]>maxvl1){
                    maxvl1=a[temp];
                    xmaxvl=temp;
                }
                temp--;
            }
            if(temp==xnn-1){
                i=xnn;j=i+1;
                while(abs(a[j]-a[i])>k && i<n && j<n){
                    i++;j++;
                }
                //cout<<i<<" "<<j<<endl;
                //l=a[i];r=a[j];
                if(a[i]>a[j]){
                    ln=a[i];nn=a[j];xnn=j;xln=i;
                }
                else{
                    ln=a[j];nn=a[i];xnn=i;xln=j;
                }
                if(j==n && abs(a[j-1]-a[i-1])>k) {cout<<maxvl;return;} 
            }
            else if(temp!=xln-1){
                xln=xmaxvl;ln=maxvl1;
                i=temp+1;
            }
        }
        else if (a[j+1]>ln){
            ln=a[j+1];j++;xln=j;
            ll temp=xln-1;
            ll maxvl1=a[temp],xmaxvl=temp;
            while(a[xln]-a[temp]<=k && xnn<=temp){
                if(a[temp]<maxvl1){
                    maxvl1=a[temp];
                    xmaxvl=temp;
                }
                temp--;
            }
            if(temp==xln-1){
                i=xln;j=i+1;
                while(abs(a[j]-a[i])>k && i<n && j<n){
                    i++;j++;
                }
                //cout<<i<<" "<<j<<endl;
                //l=a[i];r=a[j];
                if(a[i]>a[j]){
                    ln=a[i];nn=a[j];xnn=j;xln=i;
                }
                else{
                    ln=a[j];nn=a[i];xnn=i;xln=j;
                }
                if(j==n && abs(a[j-1]-a[i-1])>k) {cout<<maxvl;return;} 
            }
            else if(temp!=xnn-1){
                xnn=xmaxvl;nn=maxvl1;
                i=temp+1;
            }
        }
        //cout<<maxvl<<endl;
        maxvl=max(maxvl,j-i+1);
    }
    cout<<maxvl;
}
int main(){
    bruh();
    cerr<<"Time:"<<" "<<clock()<<"ms"<<endl;
    return 0;
}
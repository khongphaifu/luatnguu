#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dem=0;
char a[101][101];
ll check(ll i,ll j,ll n){
    ll l=0;
    if(a[i][j]=='#'){
        i++;ll m=1;
        while(i<n){
            for(ll v=j-m;v<=(m+j);v++){
                if(a[i][v]!='#') return l;
            }
            l++;m++;i++;
        }
    }
    return l;
}
void chauuu(){
    ll n;cin>>n;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++) {
            cin>>a[i][j];
            
            if(a[i][j]=='#') dem++;
    }
    cin.ignore();
}
cin.ignore();
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++) {
            
                 dem+=check(i,j,n);
             
            // cout<<a[i][j]<<" ";
    }
    //cout<<endl;
}
    cout<<dem<<endl;
}
int main(){
    chauuu();
    return 0;
}
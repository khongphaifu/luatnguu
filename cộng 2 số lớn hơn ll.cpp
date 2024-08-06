#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void chauuu(){
    string a,b;cin>>a>>b;
    a="0"+a;b="0"+b;
    if(a.size()>b.size()){
        while(a.size()!=b.size()) b="0"+b;
    }
    else if(b.size()>a.size()){
        while(a.size()!=b.size()) a="0"+a;
    }

    ll nho = 0;
    string res="";
    for(ll i= a.size()-1;i>=0;i--){
        ll k=a[i]-'0'+b[i]-'0'+nho;
        nho=0;
        if(k>=10){
            nho+=k/10;res+=to_string(k%10);
        }
        else res+=to_string(k);
    }
    reverse(res.begin(),res.end());
    if(res[0]=='0') res=res.substr(1,res.size()-1);
    cout<<res;
}
int main(){
    chauuu();
    return 0;
}
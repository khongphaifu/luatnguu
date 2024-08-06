#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll lapw=0;
const ll MOD=1000000007;
const ll N=3e6+5;
ll nt[N];
ll dx[9]={0,0,1,-1,1,1,-1,-1,0};
ll dy[9]={1,-1,0,0,1,-1,1,-1,0};
void xuli(){

}
void chau(){
    map<pair<ll,ll>,ll> mp;
    ll x,y;cin>>x>>y;
    for(ll i=0;i<9;i++){
        ll x1=x+dx[i];
        ll y1=y+dy[i];
        mp[make_pair(x1,y1)]++;
    }
    //for(auto it:mp) cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
    string n;cin>>n;
    ll dem=0;
    ll a=0,b=0;
    if(mp[make_pair(a,b)]==1) {cout<<0<<endl;dem++;}
    for(ll i=0;i<n.size();i++){
        if(n[i]=='D') b--;
        else if(n[i]=='L') a--;
        else if(n[i]=='U') b++;
        else if(n[i]=='R') a++;
        if(mp[make_pair(a,b)]==1) {cout<<i+1<<endl;dem++;}
    }
    if(!dem) cout<<-1;
}
int main(){
    ll t=1;
    xuli();
    if(lapw) cin>>t;
    while(t--) chau();
    cerr<<"Time: "<<clock()<<"ms"<<endl;
    return 0;
}
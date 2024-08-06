#include <bits/stdc++.h>
#define TASK ""
using namespace std;
#define ll long long
const ll MOD=1000000007;
const ll N1=1e6*7 ;
const ll N=1e7 +7;
void tep()
	    {
	       ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
	        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
	    }

void xuli(){

}
void burh(){

}
ll a[N];
void chau(){
	ll n,m;cin>>n>>m;
	map<ll,ll> mp,k;
	for(ll i=1;i<=n;i++){
		ll x;cin>>x;
		mp[x%m]++;
		k[x%m]=1;
	}
	ll ans=0;
	if(mp[0]>0) {ans++;k[0]=0;}
	if(m%2==0 && mp[m/2]>0) {ans++;k[m/2]=0;}
	for(auto it:mp) {
		if(k[it.first]){
			ans+=max(mp[it.first],mp[m-it.first]);
			k[it.first]=0;k[m-it.first]=0;
		}
	}
	cout<<ans;
}
ll lapw=0;
int main(){
	tep();
	ll t=1;
	//xuli();
	if(lapw) cin>>t;
	while(t--) chau();
	cerr<<"Time: "<<clock()<<"ms"<<endl;
	return 0;
}
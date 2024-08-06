#include <bits/stdc++.h>
#define TASK ""
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
const ll MOD=1000000007;
const ll N=1e7 +5;
void tep()
	    {
	        fast 
	        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
	    }
struct hh{
	ll sum,k;
};
bool cmp(ll a,ll b){

}
ll nt[N],nt1[N];
void xuli(){
	// for(ll i=1;i<=1e6;i++){
	// 	for(ll j=i;j<=1e6;j+=i) nt[j]+=i;
	// 	if(nt1[nt[i]]==0) nt1[nt[i]]=i;
	// }
}
void burh(){

}
ll a[N],b[N],c[N];
void chau(){
	ll n,m;cin>>n>>m;
	while(m--){
		ll u,v,q;cin>>u>>v>>q;
		a[u]+=q;a[v+1]-=q;
	}
	for(ll i=2;i<=n;i++) a[i]+=a[i-1];
	cout<<*max_element(a+1,a+n+1);
	
}
ll lapw=0;
int main(){
	tep();
	ll t=1;
	xuli();
	if(lapw) cin>>t;
	while(t--) chau();
	cerr<<"Time: "<<clock()<<"ms"<<endl;
	return 0;
}
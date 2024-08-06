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
void xuli(){

}
void burh(){

}
ll a[N];
void chau(){
	ll n,k;cin>>n>>k;
	ll a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<ll>());
	ll j=0,sum=a[0];
	for(ll i=1;i<n;i++){
		if(a[i]+k<=a[j]) j++;
		else sum+=a[i];
	}
	cout<<sum;
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
#include <bits/stdc++.h>
#define TASK ""
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
const ll MOD=1000000007;
const ll N=3*1e6 +5;
void tep()
	    {
	        fast 
	        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
	    }
struct hh{
	ll sum,k;
};
bool cmp(hh a,hh b){
	if(a.sum==b.sum) return a.k>b.k;
	return a.sum<b.sum;
}
void xuli(){

}
void burh(){
	
}
//ll a[N],b[N],f[N];
void chau(){
	ll n;cin>>n;
	hh a[n+1];a[0].sum=0;a[0].k=0;
	ll b[n+1];b[0]=0;
	for(ll i=1;i<=n;i++){
		ll x;cin>>x;
		b[i]=b[i-1]+x;
		a[i].sum=b[i];
		a[i].k=i;
		//cout<<b[i]<<" ";
	}
	sort(a,a+n+1,cmp);
	//for(ll i=0;i<=n;i++) cout<<a[i].sum<<" ";
	ll mi[n+1];
	mi[0]=a[0].k;
	ll res=0;
	for(ll i=1;i<=n;i++){
		mi[i]=min(mi[i-1],a[i].k);
		if(a[i].k>mi[i-1]) res=max(res,a[i].k-mi[i-1]);
	}
	cout<<res;
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
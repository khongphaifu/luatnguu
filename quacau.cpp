#include <bits/stdc++.h>
/**  /\_/\
*   (= ._.)
*   / >?? \>??
**/
#define TASK ""
using namespace std;
#define ll long long
const ll MOD=1000000007;
const ll N1=1e3*7 ;
const ll N=5e6 ;
void tep()
	    {
	       ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
	        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
	    }
struct hh{
	ll sum,k;
};
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll gt(ll a){
	if(a==0) return 1;
	return a*gt(a-1);
}
ll a[N],b[N],c[N],d[N];
map<pair<ll,pair<ll,ll>>,ll> mp;
ll dx[9]={1,1,1,0,0,0,-1,-1,-1};
ll dy[9]={1,0,-1,1,0,-1,1,0,-1};
void xuli(){
	
}
void chau(){
	ll n;cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	b[1]=a[1];b[2]=a[2];b[3]=a[1]+a[2]+a[3];
	for(ll i=4;i<=n;i++) b[i]=min(b[i-1]+a[i]+a[1],b[i-2]+a[1]+a[i]+2*a[2]);
	cout<<b[n];
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
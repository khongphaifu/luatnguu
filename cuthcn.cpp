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
const ll N=2e5  ;
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
ll n,k;
map<pair<ll,pair<ll,ll>>,ll> mp;
ll dx[2]={0,1};
ll dy[2]={1,0};
ll maxvl=0;
void xuli(){
	
}
void chau(){
	ll a,b;
	while(cin>>a>>b){
		ll f[a+1][b+1]={0};
		for(ll i=1;i<=a;i++){
			for(ll j=1;j<=b;j++){
				if(i==j){
					f[i][j]=1;continue;
				}
				ll minvl=1e18;
				for(ll k=1;k<i;k++) minvl=min(minvl,f[k][j]+f[i-k][j]);
				for(ll k=1;k<j;k++) minvl=min(minvl,f[i][k]+f[i][j-k]);
				f[i][j]=minvl;
			}
		}
		cout<<f[a][b]<<endl;
	}
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
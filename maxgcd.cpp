#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000007;
const ll N=1e6+5;
ll nt[N];
ll dx[8]={0,0,1,-1,1,1,-1,-1};
ll dy[8]={1,-1,0,0,1,-1,1,-1};
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
struct td{
	ll x,y;
};
void inp(td &a){
	cin>>a.x>>a.y;
}
float DT(td a, td b, td c){
	return abs((b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y))/2;
}
float DT1(td a,td b,td c,td d){
	return min(DT(a,b,c)+DT(b,c,d),DT(b,a,c)+DT(d,a,c));
}
ll d[300][300];
ll dp(ll i,ll j,ll dem){

}
void snt(){
	nt[0]=nt[1]=-1;
	for(ll i=2;i<=1e6;i++){
		if(nt[i]==0){
			nt[i]=i;
			for(ll j=i*2;j<=1e6;j+=i) nt[j]=i;
		}
	}
}
bool cmpstr(string a,string b){
	if(a=="" || b=="") return a.size()>b.size();
	if(a.size()!=b.size()) return a.size()<b.size();
	else{
		for(ll i=0;i<a.size();i++){
			if(a[i]!=b[i]) return a[i]-'0'<b[i]-'0';
		}
	}
}
bool cmp(ll a,ll b){
	
}
ll luythua(ll a, ll n, ll t)
{
	if (n==0) return 1;
	if (n==1) return a%t;
	ll tmp=luythua(a, n/2,t);
	if (n%2==0) return (tmp*tmp)%t;
	return (((tmp*tmp)%t)*a)%t;
}
bool check(string a){
	for(ll i=0;i<a.size();i++){
		if(!isdigit(a[i])) return 0;
		if(i==0 && a[i]=='0') return 0;
	}
	return 1;
}
ll f[N];
void xuli(){

}
ll a[N],l[N],r[N];
void chau(){               
	ll n;cin>>n;
	l[0]=0;r[n+1]=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		l[i]=gcd(l[i-1],a[i]);
	}
	ll res=0;
	for(ll i=n;i>=1;i--){
		r[i]=gcd(a[i],r[i+1]);
		res=max(res,gcd(l[i-1],r[i+1]));
	}
	cout<<res;
}
ll lapw=0;
int main(){
	ll t=1;
	xuli();
	if(lapw) cin>>t;
	while(t--) chau();
	cerr<<"Time: "<<clock()<<"ms"<<endl;
	return 0;
}
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
bool check(ll a,ll b,ll c){
	return (a+b>c && b+c>a && a+c>b);
}
string cong(string a,string b){
	a="0"+a;
	b="0"+b;
	while(a.size()>b.size()) b="0"+b;
	while(b.size()>a.size()) a="0"+a;
	ll dem=0;
	string res="";
	for(ll i=a.size()-1;i>=0;i--){
		ll c=a[i]-'0'+b[i]-'0'+dem;
		if(dem==1) dem--;
		if(c>9){
			dem++;
			res+=to_string(c%10);
		}
		else res+=to_string(c);
	}
	reverse(res.begin(), res.end());
	if((res[0]=='0')) res=res.substr(1,res.size()-1);
	return res;
}
ll merge(ll a[], ll l ,ll r ,ll m){
    vector<ll> x(a+l,a+m+1);
    vector<ll> y(a+m+1,a+r+1);
    ll i=0,j=0,cnt=0;
    while(i<x.size() && j<y.size()){
        if(x[i]<=y[j]){
            a[l]=x[i];l++;i++;
        }
        else{
        	cnt+=x.size()-i;
            a[l]=y[j];l++;j++;
        }
    }
    while(i<x.size()){
        a[l]=x[i];l++;i++;
    }
    while(j<y.size()){
        a[l]=y[j];l++;j++;
    }
    return cnt;
}
ll meme(ll a[],ll l,ll r){
    ll dem=0;
    if(l<r){
    ll m=(l+r)/2;
    dem+=meme(a,l,m);
    dem+=meme(a,m+1,r);
    dem+=merge(a,l,r,m);
	}
    return dem;
}
bool check(ll p,ll n){
	ll temp = p,cnt=0,f=5;
	while(f<=temp){
		cnt+=temp/f;
		f*=5;
	}
	return (cnt>=n);
}
ll burh(ll n){
	if(n==1) return 5;
	ll l=0,r=5*n;
	while(l<r){
		ll mid=(l+r)/2;
		if(check(mid,n)) r=mid;
		else l=mid+1;
	}
	return l;
}
ll n,m;
ll a[N];
void xuli(){

}
void chau(){               
	cin>>n;
	cout<<burh(n)<<endl;

}
ll lapw=1;
int main(){
	ll t=1;
	xuli();
	if(lapw) cin>>t;
	while(t--) chau();
	cerr<<"Time: "<<clock()<<"ms"<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
# define pi 3.1415926
ll n,s;
bool chauu(ll q ,ll k,ll a[]){
	ll d[s+1]={0};
	d[0]=1;
	for(ll i=q;i<q+k;i++){
		for(ll j=s;j>=a[i];j--){
			if(d[j-a[i]]==1) d[j]=1;
			if(d[s]==1) return true;
		}
	}
	return false;
}
void bruh(){
	cin>>n>>s;
	ll a[n];
	for(ll i=0;i<n;i++) cin>>a[i];
	ll k=1;
	while(k<=n){
		ll q=0;
		while(q+k<=n){
			if(chauu(q,k,a)){cout<<k;return;}
			q++;
		}
		k++;
	}
	cout<<-1;
}
int main(){
	bruh();
	return 0;
}
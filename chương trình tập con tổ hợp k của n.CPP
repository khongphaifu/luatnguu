#include <bits/stdc++.h>
using namespace std;
using ll= long long;
int n,k,a[100],ok;
void ktai(){
	for(int i=1;i<=n;i++) a[i]=i;
}
void solve(){
	int i=k;
	while(i>0 && a[i]==n-k+i) i--;
	if(i==0) ok=0;
	else{
		a[i]++;
		for(int j=i+1;j<=k;j++) a[j]=a[j-1]+1;
	}
}
int main(){
	cin>>n>>k;
	ok=1;
	ktai();
	while(ok){
		for(int i=1;i<=k;i++) cout<<a[i];
		solve();
	cout<<endl;
	}
	return 0;
}
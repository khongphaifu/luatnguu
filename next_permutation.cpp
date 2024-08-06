#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[100],ok;
void ktao(){
	for(int i=1;i<=n;i++) a[i]=i;
}
void sing(){
	int i=n-1;
	while(i>0 && a[i]>a[i+1]) i--;
	if(i==0) ok=0;
	else {
		for(int j=n;j>=i+1;j--){
			if(a[j]>a[i]) {
				swap(a[i],a[j]);
				break;
			}
		}
		sort(a+i+1,a+n+1);
	}
}
int main(){
	cin>>n;
	ok=1;
	ktao();
	while(ok){
		for(int i=1;i<=n;i++) cout<<a[i];
		sing();
	cout<<endl;
	}
	return 0;
}
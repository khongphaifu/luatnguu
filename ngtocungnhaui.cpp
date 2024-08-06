#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;cin>>n>>m;
	int k=0;
	for(int i=2;i< min(m,n);i++){
		if(m%i==0 && n%i==0) k++;
	}
	if(k==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
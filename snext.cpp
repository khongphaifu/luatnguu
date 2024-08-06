#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int k=0;
	int p=sqrt(n);
	for(int i=2;i<p;i++){
		if (n%i==0) k++;
	}
	if(k==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

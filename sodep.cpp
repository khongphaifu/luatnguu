#include <bits/stdc++.h>
using namespace std;
bool check(string k ){
	string t=k;
	reverse(t.begin(),t.end());
	if(t!=k) return false;
	for(char x:k){
		if((x)%2==1) return false;
	}
	return true;
}
int main(){
	int t;cin >>t;
	while(t--){
		string n;cin>>n;
		if (check(n)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}
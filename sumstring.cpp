#include <bits/stdc++.h>
using namespace std;
bool check(string n,int l,int size1,int size2){
	string s1=n.substr(l,size1);
	string s2=n.substr(l+size1,size2);
	int i1=stoi(s1)+stoi(s2);
	string s3; s3=to_string(i1);
	if(s3.size()>(n.size()-size1-size2-l)) return false;
	if(s3==n.substr(size1+size2+l,s3.size())){
		if(n.size()==(l+size1+size2+s3.size())) return true;
		return check(n,size1+l,size2,s3.size());
	}
	return false;
}
void solve(){
	string n;cin>>n;
	for(int i=1;i<n.size();i++){
			for(int j=1;j<=n.size()-i;j++){
				if(check(n,0,i,j)) {cout<<"YES"<<endl;
				return;}
			}
		}
	
	cout<<"NO"<<endl;
}
int main(){
	int t;cin>>t;cin.ignore();
	while(t--){
		solve();
		}
	
	return 0;
}
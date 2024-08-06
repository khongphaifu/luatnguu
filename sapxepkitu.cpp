#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >>t;cin.ignore();
	while(t--){
		string n;cin>>n;
		map<char,int> mp;
		for(char it:n) mp[it]++;
		int maxvl=-1e9;
		for(auto it:mp) maxvl=max(maxvl,it.second);
		if((maxvl-1)<=(n.size())-maxvl) cout<<1<<endl;
		else cout<<0<<endl;
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >>t;cin.ignore();
	while(t--){
		string n;cin>>n;
		int p;p=atoi(n.c_str());
		int maxvl=-1e9;
		for(int i=0;i<n.size()-1;i++){
			for(int j=i+1;j<n.size();j++){
				string t=n;
				swap(t[i],t[j]);
				int k=atoi(t.c_str());
				if(k<p) maxvl=max(maxvl,k);
			}
		}
		if(maxvl==-1e9) cout<<-1<<endl;
		else cout<<maxvl<<endl;
	}
	
	return 0;
}
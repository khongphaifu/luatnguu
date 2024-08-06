#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	cin.ignore();
	while(t--){
		string s; getline(cin,s);
		for(int i=0;i<s.size();i++){
			s[i]=tolower(s[i]);
		}
		stringstream ss(s);
		string k;
		vector<string> v;
		while(ss>>k){
			v.push_back(k);
		}
		cout<<v[v.size()-1];
		for(int i=0;i<v.size()-1;i++){
			cout<<v[i][0];
		}
		cout<<"@gmail.com"<<endl;
		}
	return 0;
}
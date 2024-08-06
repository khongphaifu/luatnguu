#include <bits/stdc++.h>
using namespace std;
void b(string n){
	string res="";
	for(char x:n){
		if (x=='4') res+="322";
		else if (x=='6') res+="35";
		else if (x=='8') res+="2227";
		else if (x=='9') res+="3327";
		else if (x!='1' && x!='0') res+=x;
	}
	sort(res.begin(),res.end(),greater<char>());
	cout<<res<<endl;
}
int main(){
	int t;cin>>t;cin.ignore();
	while(t--){
		int k;cin>>k;
		string n;cin>>n;
		b(n);
	}
	
	return 0;
}
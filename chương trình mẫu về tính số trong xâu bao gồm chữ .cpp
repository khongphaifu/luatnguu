#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >>t;cin.ignore();
	while(t--){
		string n;cin>>n;
		int maxvl=-1e9;
		int m=0;
		n+="a";
		for(char x:n){
			if(isdigit(x)) m=m*10 + x -'0';
			else{maxvl=max(maxvl,m);m=0;}
		}
		cout<<maxvl<<endl;
	}
	
	return 0;
}
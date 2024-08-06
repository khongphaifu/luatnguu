#include<bits/stdc++.h>
using namespace std;
#define int long long 
long long n,T;
const int N= 1e4+5;
long long f[N][52];
struct bg
{
	long long a,t;
};
bool cmp(bg a , bg b)
{
	return a.t<b.t;
}
bg c[N];
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	long long maxvl=0;
	for(int i=1;i<=n;i++) {cin>>c[i].a>>c[i].t;maxvl=max(maxvl,c[i].t);c[i].t++;}
	sort(c+1,c+n+1,cmp);
	for(int j=1;j<=maxvl+1;j++)
	{
		for(int i=1;i<=n;i++)  
		{
			f[i][j] = max(f[i-1][j],f[i][j-1]) ; 
			if(j<=c[i].t) 
			{
				f[i][j]=max(f[i][j],c[i].a+f[i-1][j-1]);	
			}
		}
	}
	long long res=-1e18;
	cout<<f[n][maxvl+1];
//	cout<<res;
}
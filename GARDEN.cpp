#define TASK "text"
#include<bits/stdc++.h>
using namespace std; 

bool multitest =  false ;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
#define ll long long 
#define db long double
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define FOR(i,a,b) for(int i =a ;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORN(i,a,b) for(int i= a ;i<b;i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a);
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
#define el '\n' 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(a%b,a);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
    void tep()
    {
        fast 
        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
    }
const int N=1e6+5; ll oo=-1e18,o=1e18;
int xx[]={0,-1,0,1,0,-1,-1,1,1};
int yy[]={0,0,1,0,-1,-1,1,1,-1};
ll n,a[N],b[N],k;
ll check(ll x)
{
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<x)
		{
			ll u=x-a[i];
			ll j=u/b[i];
			res+=j;
			if(u%b[i]!=0)res++;
		}
	}
	return res<=k;
}
void read()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	ll l=1, r=1e18,ans=0;
	while(l<=r)	
	{
		ll mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
}
void solve()
{

}
int main()
{
    tep() ; 
    int test =1 ; 
    if(multitest)cin>>test;
    while(test--)
    {
        read() ; 
        solve() ;
    }
}
#define TASK "XEPHCN"
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
ll n,f[N];
struct bg
{
	long long dai,rong;
};
bg a[N];
bool cmp(bg x,bg y)
{
	if(x.dai==y.dai) return x.rong>y.rong;
	return x.dai<y.dai;
}
void read()
{
	f[0]=0;
	f[1]=1;
	for(int i=1;i<=n;i++) f[i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i-1;j++)
			if(a[i].rong>a[j].rong) f[i]=max(f[i],f[j]+1);
	}
	cout<<f[n];
}
ll tknp(ll x)
{
	ll l=1,r=n;
	ll ans;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(f[mid]>=x)
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return ans;
}
void solve()
{
	//f[k]=a[i] là phần tử nhỏ nhất trong dãy con của j
	ll res=1;
	f[res]=a[res].rong;
	FOR(i,2,n) f[i]=1e18;
	FOR(i,2,n)
	{
		ll j=tknp(a[i].rong);
		// ll k=a[i].rong;
		// ll j=lower_bound(f+1,f+1+n,k)-f; 
		f[j]=a[i].rong;
		res=max(res,j);
	}
	cout<<res;
}
int main()
{
    tep() ; 
    int test =1 ; 
    if(multitest)cin>>test;
    while(test--)
    {
    	cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].dai>>a[i].rong;
		for(int i=1;i<=n;i++) if(a[i].dai>a[i].rong) swap(a[i].dai,a[i].rong);
		sort(a+1,a+1+n,cmp);
        // read() ; 
        solve() ;
    }
}
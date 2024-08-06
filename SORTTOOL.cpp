#define TASK "text"
#include<bits/stdc++.h>
using namespace std; 

#define ll  long long 
#define db    long double
#define pi       pair<int,int> 
#define pl         pair<ll,ll>
#define vi           vector<int>
#define vl             vector<ll> 
#define tl               map<ll,ll>
#define pb                 push_back 
#define po                   pop_back 
#define FOR(i,a,b) for(int i =a ;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORN(i,a,b) for(int i= a ;i<b;i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a);
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
#define el '\n'  
    void TLE()
    {
        ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;

        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
    }
const int N = 1e6+5;

const int N1 = 1e3+5;

const ll sm = 1e9+7;

ll oo = -1e18, o = 1e18;

int xx[] = {0,-1,0,1,0,-1,-1,1,1};

int yy[] = {0,0,1,0,-1,-1,1,1,-1};

struct po
{
    ll x,y;
};
ll DT(po A,po B,po C)
{
    return abs((B.x-A.x)*(C.y-B.y)-(C.x-B.x)*(B.y-A.y));
}

ll n,a[N];
tl m,b;
bool cmp(ll u, ll v)
{
	if(m[u] == m[v]) return b[u] < b[v];
	return m[u] > m[v];
}
void dam()
{
	cin>>n;
	FOR(i,1,n) cin>>a[i];
	vl v;
	FOR(i,1,n)
	{
		if(m[a[i]] == 0)
		{
			v.pb(a[i]);
		}
		m[a[i]]++;
	}
	ll i = 1;
	for(auto x:v)
	{
		b[x] = i;
		i++;
	}
	sort(all(v),cmp);
	for(auto x:v)
	{
		FOR(j,1,m[x])
		{
			cout<<x<<" ";
		}
	}
}
void da()
{

}
bool tachi = false;
signed main()
{
    TLE() ; 
    int test =1 ; 
    if(tachi)cin>>test;
    while(test--)
    {
        dam() ; 
        da() ;
    }
    cerr<<"Time:"<<" "<<clock()<<"ms"<<el;
}
#include <bits/stdc++.h>
using namespace std;


#define           TASK  "SCODE"
#define             pl  pair<ll,ll>  
#define             pb  push_back  
#define             ll  long long
#define             db  double
#define            nnc  signed main()
#define             se  second 
#define             fi  first
#define             el  "\n"
#define         all(a)  a.begin(),a.end()
#define      alla(a,n)  a+1,a+n+1
#define     FOR(i,a,b)  for(ll i=a;i<=b;i++)
#define    FORD(i,a,b)  for(ll i=a;i>=b;i--)
#define    FORN(i,a,b)  for(ll i=a;i<b;i++)
#define   FORDN(i,a,b)  for(ll i=a;i>b;i--)
#define     print(a,n)  for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<el;
#define      printv(v)  for(auto it:v) cout<<it<<" ";cout<<el;
#define     printvp(v)  for(auto it:v) cout<<it.fi<<" "<<it.se<<el;
#define       ieozzool  cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;


ll mlt=0;
ll test=1;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

const ll N = 1e7 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , inf = 1e18 ;
const db PI = asin(1) * 2;

ll gcd(ll a,ll b){return __gcd(a,b);}
ll bp(ll a){return a*a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}



void bef()
{
    
}

namespace mnp
{
    ll ans=0;

    void lv(string s)
    {
        ll n=s.size();
        if(n%2==0 || n<3) return;
        s='#'+s;
        string s1=s.substr(1,n/2),s11=s.substr(n/2+1,n-n/2);
        string s2=s.substr(1,n/2+1),s22=s.substr(n/2+2,n-n/2-1);
        // cout<<s2<<" "<<s22<<el;
        if(s1+s11[s11.size()-1]==s11 || s11[0]+s1==s11)
        {
            if(s1+s11[s11.size()-1]==s11) ans++,lv(s11);
            if(s11[0]+s1==s11) ans++,lv(s11);
        }
        if(s22+s2[s2.size()-1]==s2 || s2[0]+s22==s2)
        {
            if(s22+s2[s2.size()-1]==s2) ans++,lv(s2);
            if(s2[0]+s22==s2) ans++,lv(s2); 
        }
    }

    void sol()
    {
        string s;getline(cin,s);

        lv(s);
        cout<<ans;
    }
}



// "..."

nnc
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }
    bef();
    if(mlt) cin>>test;
    // cout<<test<<el;
    FOR(i,1,test)
    {
        mnp::sol();
    }
    ieozzool;
}
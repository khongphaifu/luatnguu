//furiel?
        /**  /\_/\
        *   (= ._.)
        *   / >?? \>??
        **/

        #include <bits/stdc++.h>
        using namespace std;


        #define           TASK  ""
        #define             pl  pair<ll,ll>  
        #define             pb  push_back
        #define             pf  push_front
        #define            ppb  pop_back()
        #define            ppf  pop_front() 
        #define             ll  long long
        #define             db  double
        #define            nnc  signed main()
        #define             se  second 
        #define             fi  first
        #define             el  "\n"
        #define         all(a)  a.begin(),a.end()
        #define        alla(a)  a+1,a+n+1
        #define     FOR(i,a,b)  for(ll i=a;i<=b;i++)
        #define    FORD(i,a,b)  for(ll i=a;i>=b;i--)
        #define    FORN(i,a,b)  for(ll i=a;i<b;i++)
        #define   FORDN(i,a,b)  for(ll i=a;i>b;i--)
        #define     print(a,n)  for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<el;
        #define      printv(v)  for(auto it:v) cout<<it<<" ";cout<<el;
        #define     printvp(v)  for(auto it:v) cout<<it.fi<<" "<<it.se<<el;


        ll mlt=0;
        ll test=1;

        ll dx[]={1,-1,0,0};
        ll dy[]={0,0,1,-1};

        const ll N = 2e6+5 , N1 = 3e3 + 5 , MOD = 1e9+7  , o = INT_MAX , oo = LLONG_MAX;
        const db PI = asin(1) * 2;

        ll gcd(ll a,ll b){return __gcd(a,b);}
        ll bp(ll a){return a*a;}
        ll lcm(ll a,ll b){return a*b/gcd(a,b);}
        
        ll n,h;
        ll a[N],f[N];

        ll check(ll x,ll len)
        {
            if(x==0) return 1;
            ll sum=0;
            FOR(i,1,len) sum+=a[i]/x;
            return sum>=n;
        }

        void chau()
        {
            cin>>n>>h;
            ll ans=0;
            FOR(i,1,n)
            {
                cin>>a[i];
                FOR(j,1,i-2)
                {
                    if(abs(a[i]-a[j])<=h) f[i]=max(f[i],f[j]+1);
                    ans=max(ans,f[i]);
                }
            }
            if(ans==0) cout<<0;
            else cout<<ans+1;
        }
        void xuly()
        {

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
            if(mlt) cin>>test;
            FOR(i,1,test)
            {
                chau();
                //xuly();
            }
            cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
            return 0;
        }

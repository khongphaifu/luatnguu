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
        #define             ll  long long
        #define             db  double
        #define            nnc  signed main()
        #define             se  second 
        #define             fi  first
        #define             el  "\n"
        #define         all(a)  a.begin(),a.end()
        #define        alla(a,n)  a+1,a+n+1
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

        const ll N = 1e6 + 5 , N1 = 5e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
        const db PI = asin(1) * 2;

        ll gcd(ll a,ll b){return __gcd(a,b);}
        ll bp(ll a){return a*a;}
        
        struct td{
            ll vt,id;
        };

        ll n,m;
        ll dp[N1][N1],a[N];
        
        void chau()
        {
            cin>>m>>n;
            ll ans=0;
            if(m==1)
            {
                FOR(i,1,n) cin>>a[i];
                ll ans=0;
                FOR(i,1,n/2) if(a[i]!=a[n-i+1]) ans++;
                cout<<ans;return;
            }
            FOR(i,1,m) FOR(j,1,n) cin>>dp[i][j];
            FOR(i,1,m/2) FOR(j,1,n/2)
            {
                map<ll,ll> mp;
                mp[dp[i][j]]++;mp[dp[m-i+1][j]]++;mp[dp[m-i+1][n-j+1]]++;mp[dp[i][n-j+1]]++;
                ll tmp=-oo;
                for(auto it:mp) tmp=max(tmp,it.se);
                ans+=4-tmp;
            }
            if(m%2!=0)
            {
                ll i=m/2 +1;
                FOR(j,1,n/2) if(dp[i][j]!=dp[i][n-j+1]) ans++;
            }
            if(n%2!=0)
            {
                ll j=n/2 +1;
                FOR(i,1,m/2) if(dp[i][j]!=dp[m-i+1][j]) ans++;
            }
            cout<<ans;
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
            }
            cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
            return 0;
        }
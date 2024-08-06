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
            #define      alla(a,n)  a+1,a+n+1
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

            const ll N = 1e6 + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
            const db PI = asin(1) * 2;

            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}

            ll m,n,k;
            ll dp[N1][N1];

            ll HCN(ll x1 , ll y1 , ll x2 , ll y2)
            {
                return dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
            }
                        
            void hmmm()
            { 
                cin>>m>>n>>k;
                FOR(i,1,m) FOR(j,1,n)
                {
                    char x;cin>>x;dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+ (x=='1');
                }
                // FOR(i,1,m)
                // {
                //     FOR(j,1,n) cout<<dp[i][j]<<" ";
                //     cout<<el;
                // }
                vector<pair<ll,ll>> v;
                for(ll i=1;i<=k;i++)
                {
                    if(k%i==0) v.pb(pair<ll,ll>(i,k/i));
                }
                // for(auto it:v) cout<<it.fi<<" "<<it.se<<el;
                ll ans=oo;
                FOR(i,1,m) FOR(j,1,n)
                {
                    for(auto it:v)
                    {
                        if(i-it.fi+1>=1 && j-it.se+1>=1) ans=min(ans,HCN(i-it.fi+1,j-it.se+1,i,j));
                    }
                }
                if(ans==oo) cout<<-1;
                else cout<<ans;

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
                xuly();
                FOR(i,1,test)
                {
                    hmmm();
                }
                cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
                return 0;
            }

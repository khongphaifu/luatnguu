//furiel?
            /**  /\_/\
            *   (= ._.)
            *   / >?? \>??
            **/

            #include <bits/stdc++.h>
            using namespace std;


            #define           TASK  "DIVA"
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

            const ll N = 3e6  + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
            const db PI = asin(1) * 2;

            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}

            struct td{
                ll x,y;
            };

            bool cmp(td a, td b)
            {
                if(a.x==b.x) return a.y<b.y;
                return a.x<b.x;
            }

            ll n;
            ll a[N], dp[(ll)2e3+5][(ll)2e3+5];
            vector<ll> v[(ll)2e3+5];

            // ll HCN(ll x1, ll y1 , ll x2 ,ll y2)
            // {
            //     return dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
            // }

            void sang()
            {
                FOR(i,1,2e3)
                {
                    for(ll j=i;j<=2e3;j+=i) v[i].pb(j);
                }
            }
                        
            void hmmm()
            { 
                cin>>n;
                FOR(i,1,n) cin>>a[i];
                ll ans=oo;
                FOR(i,1,n) FOR(j,1,2e3) dp[i][j]=1e18;
                FOR(i,1,n) FOR(j,1,2e3)
                {
                    for(auto it:v[j]) dp[i][it]=min(dp[i][it],dp[i-1][j]+abs(a[i]-it));
                }
                FOR(i,1,2e3) ans=min(ans,dp[n][i]);
                cout<<ans;
            }



            void xuly()
            {
                sang();
                
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
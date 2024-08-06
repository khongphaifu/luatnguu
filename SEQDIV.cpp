//furiel?
            /**  /\_/\
            *   (= ._.)
            *   / >?? \>??
            **/

            #include <bits/stdc++.h>
            using namespace std;


            #define           TASK  "SEQDIV"
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

            const ll N =  5e5  + 7 , N1 = 1e3 + 7 , MOD = 1e9 + 7 , inff = INT_MAX , inf = LLONG_MAX;
            const db PI = asin(1) * 2;
 
            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}


            ll n,k;
            ll dp[107][20007],a[N];
            vector<ll> uoc[N],boi[N];

            void sang()
            {
                FOR(i,1,20000)
                {
                    for(ll j=i*2;j<=20000;j+=i)
                    {
                        boi[i].pb(j);uoc[j].pb(i);
                    }
                }
            }

            void hmmm()
            { 
                cin>>n>>k;
                FOR(i,1,k) dp[1][i]=1;
                //for(auto it:boi[1]) cout<<it<<" ";
                FOR(i,2,n) FOR(j,1,k)
                {
                    for(auto it:uoc[j]) dp[i][j]=(dp[i][j]+dp[i-1][it])%MOD;
                    for(auto it:boi[j]) dp[i][j]=(dp[i][j]+dp[i-1][it])%MOD;
                }
                
                ll ans=0;
                FOR(i,1,k) ans=(ans+dp[n][i])%MOD;
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

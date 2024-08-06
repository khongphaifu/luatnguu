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

        const ll N = 1e6 + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
        const db PI = asin(1) * 2;

        ll gcd(ll a,ll b){return __gcd(a,b);}
        ll bp(ll a){return a*a;}
        
        struct td{
            ll vt,id;
        };

        ll n,m;
        ll dp[N1][N1],dp1[N1][N1];

        ll HCN(ll x1, ll y1 ,ll x2 , ll y2)
        {
            return dp1[x2][y2]-dp1[x1-1][y2]-dp1[x2][y1-1]+dp1[x1-1][y1-1];
        }
        
        void chau()
        {
            cin>>m>>n;
            FOR(i,1,m) FOR(j,1,n)
            {
                cin>>dp[i][j];dp1[i][j]=dp[i][j]+dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1];
            }
            ll ans=oo;
            FOR(i,1,m)
            {
                ll S1,S2,S3,S4,min1=oo,min2=oo;
                FOR(j,1,n-1)
                {
                    if(abs(HCN(1,1,i,j)-HCN(1,j+1,i,n))<min1) S1=HCN(1,1,i,j),S2=HCN(1,j+1,i,n),min1=abs(HCN(1,1,i,j)-HCN(1,j+1,i,n));
                    if(abs(HCN(i+1,1,m,j)-HCN(i+1,j+1,m,n))<min2) S3=HCN(i+1,1,m,j),S4=HCN(i+1,j+1,m,n),min2=abs(HCN(i+1,1,m,j)-HCN(i+1,j+1,m,n));
                }
                ans=min(ans,max({S1,S2,S3,S4})-min({S1,S2,S3,S4}));
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

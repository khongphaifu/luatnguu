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

            const ll N = 1e6 + 5 , N1 = 3e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
            const db PI = asin(1) * 2;

            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}

            ll m,n;
            ll dp[N1][N1],f[N],l[N],dp1[N1][N1];

            ll HCN(ll x1 , ll y1 , ll x2 , ll y2)
            {
                return dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
            }
                        
            void hmmm()
            {
                cin>>m>>n;
                FOR(i,1,m) FOR(j,1,n)
                {
                    char x;cin>>x;dp[i][j]= (x=='1');
                }
                ll ans=0;            
                FOR(i,1,m)
                {
                    f[0]=-1,f[m+1]=-1;
                    FOR(j,1,n)
                    {
                        if(dp[i][j]) f[j]++;
                        else f[j]=0;
                    }
                    stack<ll> s;
                    FOR(j,1,n)
                    {
                        while(!s.empty() && f[s.top()]>=f[j]) s.pop();
                        if(s.empty()) l[j]=1;
                        else l[j]=s.top()+1;
                        s.push(j);
                    }
                    FOR(j,1,n)
                    {
                        if(dp[i][j]) dp1[i][j]=f[j]*(j-l[j]+1) +dp1[i][l[j]-1];
                        else dp1[i][j]=0;
                        ans+=dp1[i][j];
                    }
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
                xuly();
                FOR(i,1,test)
                {
                    hmmm();
                }
                cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
                return 0;
            }
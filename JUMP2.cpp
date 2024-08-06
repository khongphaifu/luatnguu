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

                const ll N = 4e3 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
                const db PI = asin(1) * 2;

                ll gcd(ll a,ll b){return __gcd(a,b);}
                ll bp(ll a){return a*a;}
                ll lcm(ll a,ll b){return a*b/gcd(a,b);}

                struct td{
                    ll x,y;
                };

                ll n,m,k;
                ll f1[N1][N1],f2[N1][N1],a[N],b[N];
                ll dp[N1][N1];

                ll HCN(ll x1, ll y1, ll x2 , ll y2 , ll a[N1][N1])
                {
                    return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
                }
                            
                void hmmm()
                { 
                    cin>>m>>n>>k;
                    FOR(i,1,m) cin>>a[i];
                    FOR(i,1,n) cin>>b[i];
                    dp[m][n]=f1[m][n]=f2[m][n]=1;
                    FORD(i,m,1)
                    { 
                        FORD(j,n,1)
                        {
                            ll val=(a[i]+b[j])%k;
                            dp[i][j]+=f1[i][j+1]-f1[i][min(n+1,j+val+2)]+MOD;
                            dp[i][j]+=f2[i+1][j]-f2[min(m+1,i+val+2)][j]+MOD;
                            dp[i][j]%=MOD;
                            f1[i][j]=(f1[i][j+1]+dp[i][j])%MOD;
                            f2[i][j]=(f2[i+1][j]+dp[i][j])%MOD;
                            

                        }
                        
                    }
                    // FOR(i,1,m) 
                    // {
                    //     FOR(j,1,n) cout<<dp[i][j]<<" ";
                    //     cout<<el;
                    // }
                    cout<<dp[1][1];
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
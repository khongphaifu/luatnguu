//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "D1LISYS"
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

                const ll N = 1e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
                const db PI = asin(1) * 2;

                ll gcd(ll a,ll b){return __gcd(a,b);}
                ll bp(ll a){return a*a;}
                ll lcm(ll a,ll b){return a*b/gcd(a,b);}

                ll n,m,s;
                ll a[N],f[N];

                ll pw(ll a, ll b)
                {
                    if(b==0) return 1;
                    ll tmp=pw(a,b/2);
                    if(b%2==0) return tmp*tmp;
                    else return tmp*tmp*a;
                }

                void hmmm()
                { 
                    cin>>m>>n>>s;
                    ll dp[m+5][n+5],dp1[m+5][n+5],dp2[m+5][n+5];
                    FOR(i,1,m) FOR(j,1,n) cin>>dp[i][j],dp1[i][j]=0,dp2[i][j]=0;
                    while(s--)
                    {
                        ll x;cin>>x;
                        if(x>m)
                        {
                            dp1[1][x-m]++;
                        }
                        else
                        {
                            dp2[x][1]++;
                        }
                    }
                    ll ans=0;
                    FOR(i,1,n) dp1[0][i]=0,dp2[0][i]=0;
                    FOR(i,1,m) dp1[i][0]=0,dp2[i][0]=0;
                    FOR(i,1,m) FOR(j,1,n)
                    {
                        dp1[i][j]+=dp1[i-1][j];
                        dp2[i][j]+=dp2[i][j-1];
                        dp[i][j]+=dp1[i][j]+dp2[i][j];
                        if(dp[i][j]%3==0) ans++;
                    }
                    // FOR(i,1,m)
                    // {
                    //     FOR(j,1,n) cout<<dp[i][j]<<" ";
                    //     cout<<el;
                    // }
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
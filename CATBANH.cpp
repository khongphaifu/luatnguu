//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "CATBANH"
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

                const ll N = 1e6 + 5 , N1 = 5e2 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
                const db PI = asin(1) * 2;

                ll gcd(ll a,ll b){return __gcd(a,b);}
                ll bp(ll a){return a*a;}
                ll lcm(ll a,ll b){return a*b/gcd(a,b);}

                namespace mnp
                {
                    ll n,k;
                    ll dp[N1][N1],sumthang[N1][N1],sumngang[N1][N1],sumcheo[N1][N1],sum[N1][N1],sumtx[N1][N1],sumxt[N1][N1],sumtp[N1][N1],sumpt[N1][N1];
                    ll a[N];

                    ll HCN(ll x1 , ll y1 , ll x2 , ll y2)
                    {
                        return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
                    } 

                    void hmm()
                    {
                        cin>>n>>k;
                        FOR(i,1,n) FOR(j,1,n)
                        {
                            cin>>dp[i][j];
                            sum[i][j]=dp[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
                            sumthang[i][j]=sumthang[i-1][j]+dp[i][j];
                            sumngang[i][j]=sumngang[i][j-1]+dp[i][j];
                            sumcheo[i][j]=sumcheo[i-1][j-1]+dp[i][j];
                        }
                        FOR(i,1,n) FOR(j,1,n)
                        {
                            sumtx[i][j]=sumtx[max(i-1,1ll)][j-1]+sumngang[i][n]-sumngang[i][j-1];
                            sumtp[i][j]=sumtp[max(i-1,1ll)][j-1]+sumthang[n][j]-sumthang[i-1][j];
                        }
                        FORD(i,n,1) FORD(j,n,1)
                        {
                            sumxt[i][j]=sumxt[i+1][min(j+1,n)]+sumngang[i][j];
                            sumpt[i][j]=sumpt[i+1][min(j+1,n)]+sumthang[i][i];
                        }
                        ll tmp=1;
                        // FOR(i,1,n)
                        // {
                        //     FOR(j,1,n) cout<<sumtp[i][j]<<" ";
                        //     cout<<el;
                        // }
                        FOR(i,1,n)
                        {
                            a[tmp]=a[tmp-1]+sumcheo[n][i];tmp++;
                        }
                        FORD(i,n-1,1)
                        {
                            a[tmp]=a[tmp-1]+sumcheo[i][n];tmp++;
                        }
                        ll ans=-oo;
                        //cout<<a[2+2-3+4]<<" "<<sumxt[4][min(2+k+1,n)]<<" "<<sumtp[max(3-k-1,1ll)][2-1]<<" "<<HCN(4,1,4,1)<<el;
                        FOR(i,1,n) FOR(j,1,n)
                        {
                            if(i-k>0 && j+k<=n)
                            {
                                ll i1=i-k,j1=j+k;
                                ans=max(ans,a[j1-i+n]-sumxt[i+1][min(j1+1,n)]-sumtp[max(i1-1,1ll)][j-1]+HCN(i+1,1,n,j-1));
                            }
                        }
                        cout<<ans;
                    }
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
                        mnp::hmm();
                    }
                    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
                    return 0;
                }
                int mlt=0;
                int test=1;

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "PROBE"
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
                #define       ieozzool  cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;


            

                ll dx[]={1,-1,0,0};
                ll dy[]={0,0,1,-1};

                const ll N = 1e6 + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
                const db PI = asin(1) * 2;

                ll gcd(ll a,ll b){return __gcd(a,b);}
                ll bp(ll a){return a*a;}
                ll lcm(ll a,ll b){return a*b/gcd(a,b);}



                void bef()
                {
                    
                }

                namespace mnp
                {
                    ll n,m,k;
                    ll dp[N1][N1],dp1[N1][N1],dp2[N1][N1];
                    bool visit[N1][N1];

                    ll HCN(ll x1,ll y1,ll x2,ll y2)
                    {
                        return dp1[x2][y2]-dp1[x1-1][y2]-dp1[x2][y1-1]+dp1[x1-1][y1-1];
                    }

                    void bfs(ll x, ll y)
                    {
                        queue<pair<ll,ll>> q;
                        visit[x][y]=true;
                        q.push({x,y});
                        while(!q.empty())
                        {
                            ll u=q.front().fi,v=q.front().se;
                            q.pop();
                            FOR(i,0,3)
                            {
                                ll x1=u+dx[i];
                                ll y1=v+dy[i];
                                if(x1>=1 && x1<=m-k+1 && y1>=1 && y1<=n-k+1 && !visit[x1][y1] && dp[x1][y1]==0 && !HCN(x1,y1,x1+k-1,y1+k-1))
                                {
                                    q.push({x1,y1});
                                    visit[x1][y1]=true;
                                }
                            }

                        }

                    }

                    void sol()
                    {
                        cin>>m>>n>>k;
                        FOR(i,1,m) FOR(j,1,n)
                        {
                            cin>>dp[i][j];dp1[i][j]=dp[i][j]+dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1];
                        }
                        ll ans=0;
                        FOR(i,1,m-k+1) FOR(j,1,n-k+1)
                        {
                            if(!dp[i][j] && !HCN(i,j,i+k-1,j+k-1) && !visit[i][j])
                            {
                                bfs(i,j);ans++;
                                // cout<<i<<" "<<j<<el;
                            }
                        }
                        // cout<<HCN(1,2,3)
                        cout<<ans;

                    }
                    
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
                    bef();
                    if(mlt) cin>>test;
                    FOR(i,1,test)
                    {
                        mnp::sol();
                    }
                    ieozzool;
                }
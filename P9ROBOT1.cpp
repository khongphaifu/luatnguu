//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "P9ROBOT1"
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


                ll mlt=0;
                ll test=1;

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
                    ll w,h,k;
                    ll dp[N1][N1],dp1[N1][N1],dp2[N1][N1];
                    bool visit[N1][N1];

                    bool bfs()
                    {
                        queue<pair<ll,ll>> q;
                        q.push({1,1});
                        visit[1][1]=true;
                        while(!q.empty())
                        {
                            ll x1=q.front().fi;
                            ll y1=q.front().se;
                            q.pop();
                            if(x1==h && y1==w) return 0;
                            FOR(i,0,3)
                            {
                                ll x=x1+dx[i];
                                ll y=y1+dy[i];
                                if(x>=1 && x<=h && y>=1 && y<=w && !visit[x][y] && !dp2[x][y])
                                {
                                    visit[x][y]=true;
                                    q.push({x,y});
                                }
                            }
                        }
                        return 1;
                    }

                    ll HCN(ll x1,ll y1,ll x2,ll y2)
                    {
                        return dp1[x2][y2]-dp1[x1-1][y2]-dp1[x2][y1-1]+dp1[x1-1][y1-1];
                    }

                    void sol()
                    {
                        cin>>w>>h;
                        FOR(i,1,h)
                        {
                            FOR(j,1,w)
                            {
                                char x;cin>>x;
                                if(x=='#') dp[i][j]=1;
                                dp1[i][j]=dp[i][j]+dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1];
                            }
                        }
                        // FOR(i,1,h)
                        // {
                        //     FOR(j,1,w) cout<<dp[i][j]<<" ";
                        //     cout<<el;
                        // }
                        if(bfs())
                        {
                            cout<<0;return;
                        }
                        ll res=1;
                        while(res<=min(w,h))
                        {
                            FOR(i,1,h-res+1) FOR(j,1,w-res+1)
                            {
                                if(!dp[i][j] && !HCN(i,j,i+res-1,j+res-1) && !(i==1 && j==1) && !(i+res-1==h && j+res-1==w))
                                {
                                    FOR(i1,1,h) FOR(j1,1,w) dp2[i1][j1]=dp[i1][j1],visit[i1][j1]=false;
                                    FOR(i1,i,i+res-1) FOR(j1,j,j+res-1) dp2[i1][j1]=1;
                                    // cout<<i<<" "<<j<<el;
                                    if(bfs())
                                    {
                                        cout<<res;return;
                                    }
                                }
                            }
                            res++;
                        }
                        cout<<"Impossible";

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
//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "TPATH+ALLOW"
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

                ll dx[]={1,-1,0,0,1,1,-1,-1};
                ll dy[]={0,0,1,-1,1,-1,1,-1};

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
                    ll x0,y0,x1,y1,n;
                    map<pair<ll,ll>,ll> visit,allow,d;

                    void bfs()
                    {
                        queue<pair<ll,ll>> q;
                        q.push({x0,y0});
                        visit[{x0,y0}]=1;
                        while(!q.empty())
                        {
                            ll x=q.front().fi;
                            ll y=q.front().se;
                            if(x==x1 && y==y1) return;
                            q.pop();
                            FOR(i,0,7)
                            {
                                ll x2=x+dx[i];
                                ll y2=y+dy[i];
                                if(x2>=1 && x2<=1e5 && y2>=1 && y2<=1e5 && !visit[{x2,y2}] && allow[{x2,y2}])
                                {
                                    visit[{x2,y2}]=1;
                                    d[{x2,y2}]=d[{x,y}]+1;
                                    q.push({x2,y2});
                                    // cout<<x2<<" "<<y2<<el;
                                }
                            }

                        }
                    }

                    void sol()
                    {
                        cin>>x0>>y0>>x1>>y1>>n;
                        // cout<<x0<<" "<<y0<<el;
                        FOR(i,1,n)
                        {
                            ll a,b,r;cin>>r>>a>>b;
                            FOR(j,a,b) allow[{r,j}]=1;
                        }
                        bfs();
                        if(d[{x1,y1}]==0) cout<<-1;
                        else cout<<d[{x1,y1}];

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
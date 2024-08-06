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
                #define       ieozzool  cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;


                ll mlt=0;
                ll test=1;

                ll dx[]={1,-1,0,0,1,1,-1,-1};
                ll dy[]={0,0,1,-1,1,-1,1,-1};

                const ll N = 1e6 + 5 , N1 = 3e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
                const db PI = asin(1) * 2;

                ll gcd(ll a,ll b){return __gcd(a,b);}
                ll bp(ll a){return a*a;}
                ll lcm(ll a,ll b){return a*b/gcd(a,b);}

                void bef()
                {

                }

                namespace mnp
                {
                    struct td
                    {
                        ll x1,y1,x2,y2;
                    };

                    ll n;
                    td a[N];
                    vector<ll> g[N];
                    bool visit[N];
                    ll d[N];

                    bool check(ll x1 ,ll y1 , ll x2 , ll y2 , ll x3 ,ll y3 , ll x4 ,ll y4)
                    {
                        ll tmp1=min(x2,x4)-max(x1,x3);
                        ll tmp2=min(y2,y4)-max(y1,y3);
                        if(tmp1<=0 || tmp2<=0) return 0;
                        return 1;
                    }

                    void bfs(ll s)
                    {
                        queue<ll> q;
                        q.push(s);
                        visit[s]=true;
                        while(!q.empty())
                        {
                            ll u=q.front();
                            q.pop();
                            for(auto it:g[u])
                            {
                                if(!visit[it])
                                {
                                    q.push(it);
                                    visit[it]=true;
                                    d[it]=d[u]+1;
                                }
                            }
                        }
                    }


                    void sol()
                    {
                        cin>>n;
                        FOR(i,1,n)
                        {
                            ll x,y,z,t;
                            cin>>x>>y>>z>>t;
                            x=2*x-z;y=2*y-t;
                            if(z>x) a[i].x1=x,a[i].y1=y,a[i].x2=z,a[i].y2=t;
                            else a[i].x2=x,a[i].y2=y,a[i].x1=z,a[i].y1=t;
                        }
                        FOR(i,1,n)
                        {
                            FOR(j,i+1,n)
                            {
                                if(check(a[i].x1,a[i].y1,a[i].x2,a[i].y2,a[j].x1,a[j].y1,a[j].x2,a[j].y2))
                                {
                                    g[i].pb(j);g[j].pb(i);
                                }
                            }
                        }
                        //for(auto it:g[2]) cout<<it<<el;
                        bfs(1);
                        if(d[n]==0) cout<<-1;
                        else cout<<d[n];

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
                    
                    if(mlt) cin>>test;
                    FOR(i,1,test)
                    {
                        mnp::sol();
                    }
                    ieozzool;
                }

//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "GOS"
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
                    
                    struct bg
                    {
                        ll ts,id;
                    };

                    struct cmp
                    {
                        bool operator()(bg u,bg v) { return u.ts>v.ts;}
                    };

                    struct bg1
                    {
                        ll ts,ke;
                    };

                    
                    ll n,m;
                    ll dd[N],f[N],r[N];
                    vector<bg1> g[N];


                    void DIF(ll s)
                    {
                        priority_queue<bg,vector<bg>,cmp> h;
                        FOR(i,1,n)
                        {
                            f[i]=1e14;dd[i]=0;
                        }
                        f[s]=0;h.push({f[s],s});
                        while(!h.empty())
                        {
                            ll u=h.top().id;h.pop();
                            if(dd[u]==1) continue;
                            dd[u]=1;
                            for(ll j=0;j<g[u].size();j++)
                            {
                                ll v=g[u][j].ke,ts=g[u][j].ts;
                                if(f[v]>f[u]+ts && dd[v]==0)
                                {
                                    f[v]=f[u]+ts;
                                    h.push({f[v],v});
                                }
                            }
                        }
                    }

                    void sol()
                    {
                        cin>>n>>m;
                        FOR(i,1,m)
                        {
                            ll a,b,c;cin>>a>>b>>c;
                            g[a].pb({c,b});
                            g[b].pb({c,a});
                        }
                        FOR(i,1,n)
                        {
                            DIF(i);
                            FOR(j,1,n) r[i]+=f[j];
                        }
                        ll mi=1e14;
                        FOR(i,1,n) mi=min(mi,r[i]);
                        ll sl=0; FOR(i,1,n) if(r[i]==mi) sl++;
                        cout<<mi<<" "<<sl<<el;
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
                    // cout<<test<<el;
                    FOR(i,1,test)
                    {
                        mnp::sol();
                    }
                    ieozzool;
                }
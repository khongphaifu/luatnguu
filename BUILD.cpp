                int mlt=0;
                int test=1;

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "BUILD"
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

                    struct bg
                    {
                        ll id,ts;
                    };

                    struct cmp
                    {
                        bool operator() (bg a, bg b) {return a.ts>b.ts;}
                    };

                    struct bg1
                    {
                        ll ke,ts;
                    };

                    ll n,m,k,ok=1;
                    vector<bg1> g[N];
                    ll dd[N],f[N],res[N],qhd[N];
                    ll dp[10005][1005];

                    void DIF(ll s)
                    {
                        priority_queue<bg,vector<bg>,cmp> h;
                        FOR(i,1,n)
                        {
                            f[i]=1e18;dd[i]=0;
                        }
                        f[s]=0;
                        h.push({s,f[s]});
                        while(!h.empty())
                        {
                            ll u=h.top().id;h.pop();
                            if(dd[u]==1) continue;
                            dd[u]=1;
                            FOR(j,0,g[u].size()-1)
                            {
                                ll v=g[u][j].ke,ts=g[u][j].ts;
                                if(f[v]>f[u]+ts && dd[v]==0)
                                {
                                    f[v]=f[u]+ts;
                                    h.push({v,f[v]});
                                }
                            }
                        }
                    }

                    void hoanvi()
                    {
                        ll i=k-1;
                        while(i>0 && res[i]>=res[i+1]) i--;
                        if(i==0) ok=0;
                        else
                        {
                            FORD(j,k,i+1)
                            {
                                if(res[i]<res[j])
                                {
                                    swap(res[i],res[j]);break;
                                }
                            }
                            sort(res+i+1,res+k+1);
                        }
                    }
                    
                    void sol()
                    {
                        cin>>n>>m>>k;
                        map<ll,ll> mp;

                        FOR(i,1,k) cin>>res[i],mp[res[i]]++;
                        FOR(i,1,m)
                        {
                            ll x,y,z;cin>>x>>y>>z;
                            g[x].pb({y,z});
                            g[y].pb({x,z});
                        }
                        FOR(i,1,k)
                        {
                            DIF(res[i]);
                            FOR(j,1,n) dp[j][res[i]]=f[j];
                        }
                        // FOR(i,1,n)
                        // {
                        //     FOR(j,1,k) cout<<dp[i][j]<<" ";
                        //     cout<<el;
                        // }
                        // cout<<5*4*3*2*1;
                        ll ans=oo;
                        FOR(i,1,n)
                        {   
                            ok=1;   
                            sort(alla(res,k));
                            if(!mp[i])
                            {
                                while(ok)
                                {

                                    qhd[1]=dp[i][res[1]];
                                    // cout<<res[1]<<" ";
                                    FOR(j,2,k)
                                    {
                                        qhd[j]=qhd[j-1]+dp[res[j-1]][res[j]];
                                        // cout<<res[j]<<" ";
                                    }
                                    // cout<<el;
                                    ans=min(ans,qhd[k]+dp[i][res[k]]);
                                    hoanvi();
                                }
                            }
                        }
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
                int mlt=0;
                int test=1;

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "SCOM"
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
                    ll n,m,timedfs=0,scc=0;
                    vector<ll> g[N];
                    bool deleted[N],in[N];
                    ll low[N],num[N],ltm[N];
                    stack<ll> st;
                    pair<ll,ll> r[N];


                    void dfs(ll s)
                    {
                        low[s]=num[s]=++timedfs;
                        st.push(s);
                        for(auto it:g[s])
                        {
                            if(!num[it])
                            {
                                dfs(it);
                                low[s]=min(low[s],low[it]);
                            }
                            else low[s]=min(low[s],num[it]);
                        }
                        if(low[s]==num[s])
                        {
                            scc++;
                            ll v;
                            do
                            {
                                v=st.top();
                                st.pop();
                                ltm[v]=scc;
                                num[v]=low[v]=oo;
                                
                            }
                            while(v!=s);
                        }
                    }

                    void sol()
                    {
                        cin>>n>>m;
                        FOR(i,1,m)
                        {
                            ll x,y;cin>>x>>y;
                            g[y].pb(x);
                            r[i]=make_pair(x,y);
                        }
                        // FOR(i,1,m) cout<<r[i].fi<<" "<<r[i].se<<el;
                        
                        FOR(i,1,n)
                        {
                            if(!num[i])
                            {
                                
                                dfs(i);
                                // ans+=res;
                            }
                        }
                        FOR(i,1,m)
                        {
                            if(ltm[r[i].fi]!=ltm[r[i].se]) in[ltm[r[i].se]]=true;
                        }
                        ll res=0;
                        FOR(i,1,scc) if(!in[i]) res++;
                        cout<<res;

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
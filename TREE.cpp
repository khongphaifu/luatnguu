//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "TREE"
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

                const ll N = 1e6 + 5 , N1 = 3e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
                const db PI = asin(1) * 2;

                ll gcd(ll a,ll b){return __gcd(a,b);}
                ll bp(ll a){return a*a;}
                ll lcm(ll a,ll b){return a*b/gcd(a,b);}

                namespace mnp
                {
                    struct td
                    {
                        ll c,v,w;
                    };

                    bool cmp(pair<ll,ll> a, pair<ll,ll> b)
                    {
                        return (db)((db)a.fi/(db)a.se)>(db)((db)b.fi/(db)b.se);
                    }

                    ll n,m;
                    td a[N];
                    td f[N];
                    ll dp[N1][N1];


                    void hmm()
                    {
                        cin>>n>>m;
                        //cout<<(db)((db)4/(db)5)<<el;
                        FOR(i,1,n) cin>>a[i].c>>a[i].v>>a[i].w;
                        vector<pair<ll,ll>> v;
                        v.pb(pair<ll,ll>(1e18,1));
                        FOR(i,1,n)
                        {
                            ll tmp=a[i].v;
                            while(tmp>0)
                            {
                                v.pb(pair<ll,ll>(tmp,a[i].c));
                                tmp-=a[i].w;
                            }
                        }
                        sort(all(v),cmp);
                        //for(auto it:v) cout<<it.fi<<" "<<it.se<<el;
                        while(m--)
                        {
                            ll x;cin>>x;
                            ll res=min((ll)v.size()-1,3000ll);
                            FOR(i,1,res) FOR(j,1,x) dp[i][j]=0;
                            FOR(i,1,res) FOR(j,1,x)
                            {
                                dp[i][j]=dp[i-1][j];
                                if(j>=v[i].se) dp[i][j]=max(dp[i][j],dp[i-1][j-v[i].se]+v[i].fi);
                            }
                            cout<<dp[res][x]<<" ";
                        }
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
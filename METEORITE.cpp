    //furiel?
                    /**  /\_/\
                    *   (= ._.)
                    *   / >?? \>??
                    **/

                    #include <bits/stdc++.h>
                    using namespace std;


                    #define           TASK  "METEORITE"
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

                    const ll N = 2e5 + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
                    const db PI = asin(1) * 2;

                    ll gcd(ll a,ll b){return __gcd(a,b);}
                    ll bp(ll a){return a*a;}
                    ll lcm(ll a,ll b){return a*b/gcd(a,b);}



                    void bef()
                    {
                        
                    }

                    namespace mnp
                    {
                        
                        ll n,m,q;
                        ll f[N],ui[N],vi[N],c[N],e[N],ans[N],dd[N];


                        ll goc(ll x)
                        {
                            if(f[x]<0) return x;
                            return f[x]=goc(f[x]);
                        }

                        void HN(ll r1,ll r2)
                        {
                            r1=goc(r1),r2=goc(r2);
                            if(r1==r2) return;
                            ll t=f[r1]+f[r2];
                            if(f[r1]>f[r2])
                            {
                                f[r1]=t,f[r2]=r1;
                            }
                            else
                            {
                                f[r2]=t;f[r1]=r2;
                            }
                        }

                        void sol()
                        {
                            cin>>n>>m>>q;
                            FOR(i,1,m) cin>>ui[i]>>vi[i];
                            FOR(i,1,q)
                            {
                                cin>>e[i]>>c[i];
                                if(dd[e[i]]==1) e[i]=-1;
                                dd[e[i]]=1;
                            }
                            FOR(i,1,n) f[i]=-1;
                            FOR(i,1,m)
                            {
                                if(dd[i]==1) continue;
                                HN(ui[i],vi[i]);
                            }
                            FORD(i,q,1)
                            {
                                ll tmp=goc(c[i]);
                                ans[i]=-f[tmp];
                                if(e[i]!=-1) HN(ui[e[i]],vi[e[i]]);
                            }
                            FOR(i,1,q) cout<<ans[i]<<el;

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
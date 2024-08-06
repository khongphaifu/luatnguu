//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "PAY2"
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

                const ll N = 1e6 + 5 , N1 = 5e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
                const db PI = asin(1) * 2;

                ll gcd(ll a,ll b){return __gcd(a,b);}
                ll bp(ll a){return a*a;}
                ll lcm(ll a,ll b){return a*b/gcd(a,b);}

                namespace mnp
                {
                    ll n,k;
                    ll a[N],f[N],sum[N],minx[N];

                    void hmm()
                    {
                        cin>>n>>k;
                        FOR(i,1,n)
                        {
                            cin>>a[i];sum[i]=a[i]+sum[i-1];
                        }
                        multiset<ll> s;
                        ll res=1;
                        FOR(i,1,n)
                        {
                            s.insert(a[i]);
                            if(i>=k)
                            {
                                minx[i]=*s.begin();
                                s.erase(s.find(a[res]));res++;
                            }
                        }
                        FOR(i,1,n)
                        {
                            if(i<k) f[i]=sum[i];
                            else f[i]=min(sum[i]-sum[i-k]-minx[i]+f[i-k],f[i-1]+a[i]);
                            //cout<<f[i]<<" ";
                        }
                        cout<<f[n];
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
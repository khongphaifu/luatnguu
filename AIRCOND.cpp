//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "AIRCOND"
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

                const ll N = 1e6 + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
                const db PI = asin(1) * 2;

                ll gcd(ll a,ll b){return __gcd(a,b);}
                ll bp(ll a){return a*a;}
                ll lcm(ll a,ll b){return a*b/gcd(a,b);}

                ll n,k;
                ll a[N],t[N],v[N],L[N],R[N];

                void hmmm()
                { 
                    cin>>n>>k;
                    FOR(i,0,n+1) L[i]=1e18,R[i]=1e18;
                    FOR(i,1,k) cin>>a[i];
                    FOR(i,1,k) 
                    {
                        cin>>t[i];
                        R[a[i]]=t[i]+a[i];
                        L[a[i]]=t[i]-a[i];
                    }
                    // FOR(i,1,n) cout<<R[i]<<" ";
                    // cout<<el;
                    FOR(i,1,n) L[i]=min(L[i-1],L[i]);
                    // FOR(i,1,n) cout<<L[i]<<" ";
                    // cout<<el;
                    FORD(i,n,1) R[i]=min(R[i+1],R[i]);
                    // FOR(i,1,n) cout<<R[i]<<" ";
                    // cout<<el;
                    FOR(i,1,n)
                    {
                        cout<<min(R[i]-i,L[i]+i)<<" ";
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
                        hmmm();
                    }
                    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
                    return 0;
                }
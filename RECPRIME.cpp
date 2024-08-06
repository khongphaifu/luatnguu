//furiel?
            /**  /\_/\
            *   (= ._.)
            *   / >?? \>??
            **/

            #include <bits/stdc++.h>
            using namespace std;


            #define           TASK  "RECPRIME"
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

            const ll N = 1e6  + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
            const db PI = asin(1) * 2;

            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}

            struct td{
                ll val,x,y;
            };

            ll n,m;
            ll a[N],dp[305][305],nt[N];

            void sang()
            {
                nt[0]=nt[1]=-1;
                FOR(i,2,N)
                {
                    if(nt[i]==0) for(ll j=i;j<=N;j+=i) nt[j]=i;
                }
            }
                        
            void hmmm()
            { 
                cin>>m>>n;
                ll ans=0;
                FOR(i,1,m) FOR(j,1,n) cin>>dp[i][j];
                FOR(i,1,n) FOR(j,i+1,n)
                {
                    ll min1=0,min2=0;
                    FOR(k,1,m)
                    {
                        if(nt[dp[k][i]]==dp[k][i] &&  nt[dp[k][j]]==dp[k][j])
                        {
                            ans+=min1+min2;min2++;
                        }
                        else if(nt[dp[k][i]]==dp[k][i] ||  nt[dp[k][j]]==dp[k][j])
                        {
                            ans+=min2;min1++;
                        }

                    }
                }
                cout<<ans;
            }



            void xuly()
            {
                sang();
                
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
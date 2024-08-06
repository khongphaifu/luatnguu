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


                ll mlt=0;
                ll test=1;

                ll dx[]={1,-1,0,0};
                ll dy[]={0,0,1,-1};

                const ll N = 1e5 + 5 , N1 = 2e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
                const db PI = asin(1) * 2;

                ll gcd(ll a,ll b){return __gcd(a,b);}
                ll bp(ll a){return a*a;}
                ll lcm(ll a,ll b){return a*b/gcd(a,b);}

                struct td{
                    ll x,y;
                };

                ll n,m,p,q,B;
                ll l[N1][N1],b[N1][N1];

                ll HCN(ll x1, ll y1, ll x2 , ll y2 , ll a[N1][N1])
                {
                    return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
                }
                            
                void hmmm()
                { 
                    cin>>m>>n>>p>>q>>B;
                    FOR(i,1,m) FOR(j,1,n)
                    {
                        ll x;cin>>x;
                        l[i][j]=l[i-1][j]+l[i][j-1]-l[i-1][j-1];
                        b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
                        if(x>B) l[i][j]++;
                        if(x<B) b[i][j]++;
                    }
                    ll tmp=(p*q+1)/2,ans=0;
                    FOR(i,p,m) FOR(j,q,n)
                    {
                        if(HCN(i-p+1,j-q+1,i,j,b)<tmp && p*q-HCN(i-p+1,j-q+1,i,j,l)+1>tmp) ans++;
                    }
                    cout<<ans;

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
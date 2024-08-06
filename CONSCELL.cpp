//furiel?
            /**  /\_/\
            *   (= ._.)
            *   / >?? \>??
            **/

            #include <bits/stdc++.h>
            using namespace std;


            #define           TASK  "CONSCELL"
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
            td a[N];
            ll f[N],dp[N1][N1],dp1[N1][N1];

            bool cmp(td a, td b)
            {
                return a.val<b.val;
            }

            ll check(ll x1 , ll y1 , ll x2 , ll y2)
            {
                return (abs(x1-x2)==1 && y1==y2) || (abs(y1-y2)==1 && x1==x2);
            }
                        
            void hmmm()
            { 
                cin>>m>>n;
                ll k=1;
                FOR(i,1,m) FOR(j,1,n)
                {
                    cin>>a[k].val;a[k].x=i;a[k].y=j;dp[i][j]=a[k].val;k++;
                }
                sort(alla(a,m*n),cmp);
                // FOR(i,1,n*m) cout<<a[i].val<<" ";
                FOR(i,1,n*m)
                {
                    dp1[a[i].x][a[i].y]=i;
                }
                ll ans=0,tmp=0;
                a[0].val=oo;
                FOR(i,1,n*m)
                {
                    f[i]=1;
                    FOR(j,0,3)
                    {
                        ll i1=a[i].x+dx[j];
                        ll j1=a[i].y+dy[j];
                        if(dp[a[i].x][a[i].y]-dp[i1][j1]==1) f[i]=max(f[i],f[dp1[i1][j1]]+1);
                    }
                    ans=max(ans,f[i]);
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
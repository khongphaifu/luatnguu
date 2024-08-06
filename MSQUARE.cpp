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

            const ll N = 1e6 + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
            const db PI = asin(1) * 2;

            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}

            ll m,n;
            ll dp0[N1][N1],dp1[N1][N1],dp2[N1][N1],dp3[N1][N1],dp4[N1][N1],dp5[N1][N1],dp6[N1][N1],dp7[N1][N1],dp8[N1][N1],dp9[N1][N1];

            ll HCN(ll x1 , ll y1 , ll x2 , ll y2,ll a[N1][N1])
            {
                return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
            }
                        
            void hmmm()
            {
                cin>>n;
                FOR(i,1,n) FOR(j,1,n)
                {
                    ll x;cin>>x;
                    dp0[i][j]=dp0[i-1][j]+dp0[i][j-1]-dp0[i-1][j-1];
                    dp1[i][j]=dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1];
                    dp2[i][j]=dp2[i-1][j]+dp2[i][j-1]-dp2[i-1][j-1];
                    dp3[i][j]=dp3[i-1][j]+dp3[i][j-1]-dp3[i-1][j-1];
                    dp4[i][j]=dp4[i-1][j]+dp4[i][j-1]-dp4[i-1][j-1];
                    dp5[i][j]=dp5[i-1][j]+dp5[i][j-1]-dp5[i-1][j-1];
                    dp6[i][j]=dp6[i-1][j]+dp6[i][j-1]-dp6[i-1][j-1];
                    dp7[i][j]=dp7[i-1][j]+dp7[i][j-1]-dp7[i-1][j-1];
                    dp8[i][j]=dp8[i-1][j]+dp8[i][j-1]-dp8[i-1][j-1];
                    dp9[i][j]=dp9[i-1][j]+dp9[i][j-1]-dp9[i-1][j-1];
                    if(x==0) dp0[i][j]++;
                    if(x==1) dp1[i][j]++;
                    if(x==2) dp2[i][j]++;
                    if(x==3) dp3[i][j]++;
                    if(x==4) dp4[i][j]++;
                    if(x==5) dp5[i][j]++;
                    if(x==6) dp6[i][j]++;
                    if(x==7) dp7[i][j]++;
                    if(x==8) dp8[i][j]++;
                    if(x==9) dp9[i][j]++;
                }
                // FOR(i,1,n)
                // {
                //     FOR(j,1,n) cout<<dp2[i][j]<<" ";
                //     cout<<el;
                // }
                // cout<<HCN(4,4,1,1,dp2)<<el;
                ll ans=1,res=0;;
                FOR(i,1,n) FOR(j,1,n)
                {
                    while(i-res>=1 && j-res>=1)
                    {
                        if(HCN(i-res,j-res,i,j,dp0)==(res+1)*(res+1))
                        {
                            ans=max(ans,(res+1)*(res+1));
                            res++;
                        }
                        else break;
                    }
                }
                FOR(i,1,n) FOR(j,1,n)
                {
                    while(i-res>=1 && j-res>=1)
                    {
                        if(HCN(i-res,j-res,i,j,dp1)==(res+1)*(res+1))
                        {
                            ans=max(ans,(res+1)*(res+1));
                            res++;
                        }
                        else break;
                    }
                }
                FOR(i,1,n) FOR(j,1,n)
                {
                    while(i-res>=1 && j-res>=1)
                    {
                        if(HCN(i-res,j-res,i,j,dp2)==(res+1)*(res+1))
                        {
                            ans=max(ans,(res+1)*(res+1));
                            res++;
                        }
                        else break;
                    }
                }
                FOR(i,1,n) FOR(j,1,n)
                {
                    while(i-res>=1 && j-res>=1)
                    {
                        if(HCN(i-res,j-res,i,j,dp3)==(res+1)*(res+1))
                        {
                            ans=max(ans,(res+1)*(res+1));
                            res++;
                        }
                        else break;
                    }
                }
                FOR(i,1,n) FOR(j,1,n)
                {
                    while(i-res>=1 && j-res>=1)
                    {
                        if(HCN(i-res,j-res,i,j,dp4)==(res+1)*(res+1))
                        {
                            ans=max(ans,(res+1)*(res+1));
                            res++;
                        }
                        else break;
                    }
                }
                FOR(i,1,n) FOR(j,1,n)
                {
                    while(i-res>=1 && j-res>=1)
                    {
                        if(HCN(i-res,j-res,i,j,dp5)==(res+1)*(res+1))
                        {
                            ans=max(ans,(res+1)*(res+1));
                            res++;
                        }
                        else break;
                    }
                }
                FOR(i,1,n) FOR(j,1,n)
                {
                    while(i-res>=1 && j-res>=1)
                    {
                        if(HCN(i-res,j-res,i,j,dp6)==(res+1)*(res+1))
                        {
                            ans=max(ans,(res+1)*(res+1));
                            res++;
                        }
                        else break;
                    }
                }
                FOR(i,1,n) FOR(j,1,n)
                {
                    while(i-res>=1 && j-res>=1)
                    {
                        if(HCN(i-res,j-res,i,j,dp7)==(res+1)*(res+1))
                        {
                            ans=max(ans,(res+1)*(res+1));
                            res++;
                        }
                        else break;
                    }
                }
                FOR(i,1,n) FOR(j,1,n)
                {
                    while(i-res>=1 && j-res>=1)
                    {
                        if(HCN(i-res,j-res,i,j,dp8)==(res+1)*(res+1))
                        {
                            ans=max(ans,(res+1)*(res+1));
                            res++;
                        }
                        else break;
                    }
                }
                FOR(i,1,n) FOR(j,1,n)
                {
                    while(i-res>=1 && j-res>=1)
                    {
                        if(HCN(i-res,j-res,i,j,dp9)==(res+1)*(res+1))
                        {
                            ans=max(ans,(res+1)*(res+1));
                            res++;
                        }
                        else break;
                    }
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

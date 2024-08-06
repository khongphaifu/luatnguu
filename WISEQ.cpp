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

            const ll N = 1e6 + 5 , N1 = 3e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
            const db PI = asin(1) * 2;

            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}

            ll n,w,x;
            ll a[N],b[N],r[N],t[N],t2[N],dp[505][5005];
            

            void chau()
            {
                cin>>n>>w;
                ll s=0;
                FOR(i,1,n) cin>>a[i],s+=a[i],b[i]=1e18;
                if(w==s)
                {
                    ll ans=-oo;
                    FOR(i,1,n)
                    {
                        ll j=lower_bound(b+1,b+n+1,a[i])-b;
                        b[j]=a[i];
                        ans=max(ans,j);
                    }
                    cout<<ans;
                }
                else
                {
                    ll ans=-oo;
                    FOR(i,1,n)
                    {
                        FOR(j,1,w)
                        {
                            if(j>=a[i]) 
                            {
                                dp[i][j]=max(1ll,dp[i][j]);
                                FOR(k,1,i-1) 
                                   if(a[k]<a[i])dp[i][j]=max(dp[i][j],dp[k][j-a[i]]+1);
                            }
                            ans=max(ans,dp[i][j]);
                        }
                    }
                    // FOR(i,1,n)
                    // {
                    //     FOR(j,1,w) cout<<dp[i][j]<<" ";
                    //     cout<<el;
                    // }
                    cout<<ans;
                }
                
                


            }
            void xuly()
            {
                //sang();
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
                    chau();
                }
                cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
                return 0;
            }

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

            typedef pair<int,int> ii;
            typedef pair<int,ii> ip;

            ll m,n,k;
            ll f[N1],f1[N1][N1];

            bool cmp1(ip a,ip b){return a.fi<b.fi || (a.fi==b.fi && a.se.se<b.se.se);}
            bool cmp2(ip a,ip b){return a.fi<b.fi || (a.fi==b.fi && a.se.fi>b.se.fi);}
            
                        
            void hmmm()
            { 
                cin>>n;
                vector<pair<ll,pair<ll,ll>>> v;
                vector<pair<ll,ll>> x;
                FOR(i,1,n)
                {
                    ll y,z;cin>>y>>z;x.pb(pair<ll,ll>(y,z));
                }
                sort(all(x));
                FOR(i,0,n-1) FOR(j,i+1,n-1) v.pb(pair<ll,pair<ll,ll>>(x[j].fi-x[i].fi,pair<ll,ll>(i,j)));
                sort(all(v),cmp1);
                FOR(i,0,n-1) f[i]=x[i].se;
                for(auto it:v)
                {
                    ll j=it.se.fi,k=it.se.se;
                    f[k]=max(f[k],f[j]+x[k].se);
                }
                ll ans=0;
                FOR(i,0,n-1)
                {
                    ans=max(ans,f[i]);
                    f[i]=x[i].se;
                }
                sort(all(v),cmp2);

                for(auto it:v)
                {
                    //cout<<it.fi<<" "<<it.se.fi<<" "<<it.se.se<<el;
                    ll k=it.se.fi,j=it.se.se;
                    f[k]=max(f[k],f[j]+x[k].se);
                }
                FOR(i,0,n-1) ans=max(ans,f[i]);
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

//furiel?
            /**  /\_/\
            *   (= ._.)
            *   / >?? \>??
            **/

            #include <bits/stdc++.h>
            using namespace std;


            #define           TASK  "LIGHTBALL"
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

            const ll N = 3e6  + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
            const db PI = asin(1) * 2;

            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}

            struct td{
                ll x,y;
            };

            bool cmp(td a, td b)
            {
                if(a.x==b.x) return a.y<b.y;
                return a.x<b.x;
            }

            ll n,m,k;
            ll a[N],b[N],c[N];

                        
            void hmmm()
            { 
                cin>>n>>m>>k;
                FOR(i,1,n) cin>>a[i];
                FOR(i,1,m) cin>>b[i];
                FOR(i,1,k) cin>>c[i];
                sort(alla(b,m));sort(alla(c,k)),sort(alla(a,n));
                ll ans=oo;
                FOR(i,1,n)
                {
                    ll j=lower_bound(alla(b,m),a[i])-b;
                    ll j1=lower_bound(alla(c,k),a[i])-c;
                    ans=min(ans,(a[i]-b[j])*(a[i]-b[j])+(b[j]-c[j1])*(b[j]-c[j1])+(c[j1]-a[i])*(c[j1]-a[i]));
                }
                FOR(i,1,m)
                {
                    ll j=lower_bound(alla(a,n),b[i])-a;
                    ll j1=lower_bound(alla(c,k),b[i])-c;
                    ans=min(ans,(a[j]-b[i])*(a[j]-b[i])+(b[i]-c[j1])*(b[i]-c[j1])+(c[j1]-a[j])*(c[j1]-a[j]));
                }
                FOR(i,1,k)
                {
                    ll j=lower_bound(alla(b,m),c[i])-b;
                    ll j1=lower_bound(alla(a,n),c[i])-a;
                    ans=min(ans,(a[j1]-b[j])*(a[j1]-b[j])+(b[j]-c[i])*(b[j]-c[i])+(c[i]-a[j1])*(c[i]-a[j1]));
                }
                cout<<ans;
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
                    hmmm();
                }
                cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
                return 0;
            }
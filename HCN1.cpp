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
            #define        alla(a,n)  a+1,a+n+1
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

            const ll N = 2e6 + 5 , N1 = 3e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
            const db PI = asin(1) * 2;

            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}

            ll n;

            struct huhu{
                ll x1,y1; //tọa độ góc trái dưới
                ll x2,y2; //tọa đọ góc phải trên  
            };

            ll b[N];
            huhu a[N];

            bool cmp(huhu a, huhu b)
            {
                return (a.x2-a.x1)*(a.y2-a.y1)<(b.x2-b.x1)*(b.y2-b.y1);
            }
            
            void chau()
            {
                cin>>n;
                FOR(i,1,n) cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
                sort(alla(a,n),cmp);
                ll ans=-oo;
                FOR(i,1,n)
                {
                    b[i]=1;
                    FOR(j,1,i-1) if(a[j].x1>=a[i].x1 && a[j].y1>=a[i].y1 && a[j].x2<=a[i].x2 && a[j].y2<=a[i].y2) b[i]=max(b[i],b[j]+1);
                    ans=max(ans,b[i]);
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
                FOR(i,1,test)
                {
                    chau();
                }
                cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
                return 0;
            }

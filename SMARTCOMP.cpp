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

            ll n,V;
            ll a[N],b[N],c[N],d[N];
            
            struct huhu{
                ll V,C;
            };

            huhu d1[N],d2[N];

            bool cmp(huhu a,huhu b)
            {
                if(a.V==b.V) return a.C<b.C;
                return a.V<b.V;
            }
            
            void chau()
            {
                cin>>n>>V;
                FOR(i,1,n) cin>>a[i]>>b[i];
                ll k=1;
                FOR(i,1,n) 
                {
                    ll x,y;cin>>x>>y;
                    FOR(j,1,n)
                    {
                        d1[k].V=x+a[j];
                        d1[k].C=y+b[j];
                        k++;
                    }
                }
                FOR(i,1,n) cin>>a[i]>>b[i];
                k=1;
                FOR(i,1,n) 
                {
                    ll x,y;cin>>x>>y;
                    FOR(j,1,n)
                    {
                        d2[k].V=x+a[j];
                        d2[k].C=y+b[j];
                        k++;
                    }
                }
                n*=n;
                sort(alla(d1,n),cmp);sort(alla(d2,n),cmp);
                FOR(i,1,n) c[i]=d2[i].V,d[i]=max(d[i-1],d2[i].C);
                ll ans=-oo;
                FOR(i,1,n)
                {
                    ll j=upper_bound(c+1,c+n+1,V-d1[i].V)-c;
                    j--;
                    if(j>0)ans=max(ans,d1[i].C+d[j]);
                }
                if(ans==-oo) cout<<-1;
                else cout<<ans;
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

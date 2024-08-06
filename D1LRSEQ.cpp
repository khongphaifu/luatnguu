//furiel?
            /**  /\_/\
            *   (= ._.)
            *   / >?? \>??
            **/

            #include <bits/stdc++.h>
            using namespace std;


            #define           TASK  "D1LRSEQ"
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

            const ll N =  1e6  + 7 , N1 = 1e3 + 7 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
            const db PI = asin(1) * 2;

            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}


            ll n;
            ll a[N],L[N],R[N];


            void hmmm()
            { 
                cin>>n;
                multiset<ll> s;
                FOR(i,1,n)
                {
                    cin>>a[i];
                    L[i]=L[i-1]+a[i];
                    s.insert(L[i]);
                }
                ll r=n;
                ll ans=oo;
                FORD(i,n,2)
                {
                    s.erase(s.find(L[r]));r--;
                    R[i]=R[i+1]+a[i];
                    auto it=s.upper_bound(R[i]);
                    if(it==s.end()) ans=min(ans,R[i]-*s.rbegin());
                    else if(it==s.begin()) ans=min(ans,*s.begin()-R[i]);
                    else
                    {
                        auto it1=it;it1--;
                        ans=min({ans,*it-R[i],R[i]-*it1});
                    }
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

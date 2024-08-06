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

            ll n,p,q;
            ll a[N],l[N],r[N],dp[105][50005],t[N],t2[N];
            

            void chau()
            {
                cin>>n>>p>>q;vector<pair<ll,ll>> v;
                FOR(i,1,n)
                {
                    ll x,y;cin>>x>>y;
                    ll check=0;
                    if(x<p && y>=p) check=1,x=p;
                    if(y>q && x<=q) check=1,y=q;
                    if(x>=p && y<=q) check=1;
                    if(check) v.pb(pair<ll,ll>(x,y));
                }
                sort(all(v));
                if(v[0].fi>p)
                {
                    cout<<-1;return;
                }
                //for(auto it:v) cout<<it.fi<<" "<<it.se<<el;
                ll l=p,r=0,ans=0;
                FOR(i,0,v.size()-1)
                {
                    if(v[i].fi<=l)
                    {
                        r=max(r,v[i].se);
                        if(r==q)
                        {
                            ans++;break;
                        }
                    }
                    else{
                        if(v[i].fi > r)
                        {
                            cout<<-1;return;
                        }
                        l=r;r=max(r,v[i].se);ans++;
                        if(r==q)
                        {
                            ans++;break;
                        }
                    }
                }
                cout<<ans -(ans==0);

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


//furiel?
            /**  /\_/\
            *   (= ._.)
            *   / >?? \>??
            **/

            #include <bits/stdc++.h>
            using namespace std;


            #define           TASK  "DISTMIN"
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

            const ll N =  5e5  + 7 , N1 = 1e3 + 7 , MOD = 1e9 + 7 , inff = INT_MAX , inf = LLONG_MAX;
            const db PI = asin(1) * 2;
 
            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}

            struct td
            {
                ll x,y;
            };

            bool cmp(td a, td b)
            {
                return a.x<b.x;
            }

            ll n,m;
            ll b[N];
            td a[N];


            void hmmm()
            { 
                map<ll,ll> mp;
                cin>>n>>m;
                vector<pair<ll,ll>> v;
                // FOR(i,1,4*n) cout<<st[i]<<" ";
                // cout<<el;
                ll k=1;
                FOR(i,1,n)
                {
                    ll x;cin>>x;
                    if(mp[x]==0) mp[x]=i;
                    else
                    {
                        a[k].x=mp[x];a[k].y=i; 
                        mp[x]=i;
                        k++;
                    }
                }
                k--;
                sort(alla(a,k),cmp);
                // FOR(i,1,k) cout<<a[i].x<<" "<<a[i].y<<el;
                // FOR(i,1,4*n) cout<<st[i]<<" ";
                // cout<<el;
                FOR(i,1,k) b[i]=a[i].x;
                sort(all(v));
                while(m--)
                {
                    ll ans=inf;
                    ll x,y;cin>>x>>y;
                    ll j=lower_bound(alla(b,k),x)-b;
                    //cout<<j<<el;
                    while(a[j].x<y && j<=k)
                    {
                        if(a[j].y<=y) ans=min(ans,a[j].y-a[j].x);
                        j++;
                    }
                    if(ans==inf) cout<<-1<<el;
                    else cout<<ans<<el;
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
                    hmmm();
                }
                cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
                return 0;
            }

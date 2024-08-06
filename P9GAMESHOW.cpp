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

        const ll N = 1e6 + 5 , N1 = 5e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
        const db PI = asin(1) * 2;

        ll gcd(ll a,ll b){return __gcd(a,b);}
        ll bp(ll a){return a*a;}
        
        struct td{
            ll vt,id;
        };

        ll n,T;
        ll f[N1][N1],a[N];
        
        void chau()
        {
            cin>>n>>T;
            FOR(i,1,n) cin>>a[i];
            if(a[1]<0)
            {
                cout<<-1;return;
            }
            FOR(i,1,n) FOR(j,1,n)
            {
                f[i][j]=-1e18;
            }

            f[1][1]=a[1];
            FOR(i,1,n-1) FOR(j,1,i)
            {
                if(f[i][j]>=0) f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+a[i+1]);
                if(f[i][j]>=T && i<n-1) f[i+1][j]=max(f[i][j]-T,f[i+1][j]);
            }
            FOR(i,1,n) if(f[n][i]>=0)
            {
                cout<<i;return;
            }
            cout<<-1;
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

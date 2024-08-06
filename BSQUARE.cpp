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
        #define        alla(a)  a+1,a+n+1
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

        const ll N = 1e5 + 5 , N1 = 2e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
        const db PI = asin(1) * 2;

        ll gcd(ll a,ll b){return __gcd(a,b);}
        ll bp(ll a){return a*a;}
        ll pw(ll a, ll b)
        {
            if(b==0) return 1;
            ll temp=pw(a,b/2);
            if(b%2==0) return temp*temp %MOD;
            else return temp*temp %MOD *a %MOD;
        }
        
        ll n,k;
        ll a[N],b[N];
        ll dp[N1][N1],dpl[N1][N1],dpr[N1][N1];

        ll HCN(ll x1 , ll y1, ll x2 , ll y2)
        {
            return dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
        }
        
        void chau()
        {
            cin>>n;
            FOR(i,1,n) FOR(j,1,n)
            {
                ll x;cin>>x;
                dpl[i][j]=dpl[i-1][j-1]+x;
                dpr[i][j]=dpr[i-1][j+1]+x;
            }
            ll ans=-oo;
            
            FOR(i,1,n) FOR(j,1,n)
            {
                ll res=0;
                while(i-res>=1 && j-res>=1)
                {
                    ans=max(ans,dpl[i][j]-dpl[i-res-1][j-res-1]-dpr[i][j-res]+dpr[i-res-1][j+1]);
                    res++;
                }
            }
            cout<<ans;
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
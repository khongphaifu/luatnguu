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
        #define     FOR(i,a,b)  for(ll i=a;i<=b;i++)
        #define    FORD(i,a,b)  for(ll i=a;i>=b;i--)
        #define    FORN(i,a,b)  for(ll i=a;i<b;i++)
        #define   FORDN(i,a,b)  for(ll i=a;i>b;i--)
        #define   print(i,a,n)  for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<el;
        #define      printv(v)  for(auto it:v) cout<<it<<" ";cout<<el;


        ll mlt=0;
        ll test=1;

        ll dx[]={1,-1,0,0};
        ll dy[]={0,0,1,-1};

        const ll N = 3e6 + 5 , N1 = 2e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
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

        ll n,m;
        ll dp[N1][N1],dp1[N1][N1];

        ll HCN( ll x1 , ll y1 , ll x2 , ll y2 ) {return dp1[x2][y2]-dp1[x1-1][y2]-dp1[x2][y1-1]+dp1[x1-1][y1-1];}

        void chau()
        {
            cin>>m>>n;
            FOR(i,1,m) FOR(j,1,n)
            {
                char x;cin>>x;
                dp1[i][j]= (x=='1')+dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1];
            }
            // FOR(i,1,m)
            // {
            //     FOR(j,1,n) cout<<dp1[i][j]<<" ";
            //     cout<<el;
            // }
            ll ans=0;
            FOR(i,1,m) FOR(j,1,n)
            {
                ll res=0;
                while(i-res>=1 && j-res>=1)
                {
                    ll u=i-res,v=j-res;
                    if(!HCN(u,v,i,j)) ans++;
                    else break;
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

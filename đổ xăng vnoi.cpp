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

        const ll N = 1e6 + 5 , N1 = 4000 + 2 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
        const db PI = asin(1) * 2;

        ll gcd(ll a,ll b){return __gcd(a,b);}
        ll bp(ll a){return a*a;}
        
        struct td{
            ll vt,id;
        };

        ll n,m,T,k;
        ll a[N],b[N],d[N],r[N];
        ll dp[N1][N1];
        td x[N1+1],y[N1+3];

        bool cmp(td x , td y){return x.vt<y.vt;}

        ll pw(ll a, ll b)
        {
            if(b==0) return 1;
            ll temp=pw(a,b/2);
            if(b%2==0) return temp*temp %k;
            else return temp*temp %k *a %k;
        }
        
        void chau()
        {
            cin>>n;
            FOR(i,1,n)
            {
                cin>>x[i].vt;x[i].id=i;
            }
            cin>>m;
            FOR(i,1,m)
            {
                cin>>y[i].vt;y[i].id=i;
            }
            sort(x+1,x+n+1,cmp);sort(y+1,y+m+1,cmp);
            FOR(i,0,n) FOR(j,0,m) dp[i][j]=1e15;
            dp[0][0]=0;
            FOR(i,1,n) dp[i][i]=dp[i-1][i-1]+abs(x[i].vt-y[i].vt);
            FOR(i,1,n) FOR(j,1,i-1) dp[i][j]= abs(x[i].vt-y[j].vt) + min(dp[i-1][j-1],dp[i-1][j]);
            cout<<dp[n][m]<<el;
            ll i=n,j=m;
            while(i>0 && j>0)
            {
                a[x[i].id]=y[j].id;
                if(dp[i][j]==abs(x[i].vt-y[j].vt) +dp[i-1][j-1])
                {
                    i--;j--;
                }
                else i--;
            }
            FOR(i,1,n) cout<<a[i]<<" ";
        }
        void xuly()
        {
            cin>>n>>T;
            FOR(i,1,n) cin>>a[i];

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

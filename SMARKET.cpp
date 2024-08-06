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
        #define     printvp(v)  for(auto it:v) cout<<it.fi<<" "<<it.se<<el;


        ll mlt=0;
        ll test=1;

        ll dx[]={1,-1,0,0};
        ll dy[]={0,0,1,-1};

        const ll N = 1e6 + 5 , N1 = 2e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
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
        
        ll n,q,xi,pi;
        ll a[N],b[N];
        ll dp[200000+10][100+10];

        void chau()
        {
            cin>>n>>q;
            FOR(i,1,n)
            {
                ll x;cin>>x;b[i]=x;a[i]=a[i-1]+x;
            }            
            FORD(i,n,1) FOR(j,0,100) //bài toán cái túi
            {
                if(b[i]>j) dp[i][j]=dp[i+1][j];
                else dp[i][j]=1+dp[i+1][j-b[i]];
            }
            while(q--)
            {
                cin>>xi>>pi;
                ll j=upper_bound(a+pi,a+n+1,xi+a[pi-1])-a;
                j--;   
                xi-=(a[j]-a[pi-1]);
                cout<<j-pi+1+dp[j+1][xi]<<el;
                
            }
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
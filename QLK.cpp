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
        #define             pf  push_front
        #define            ppb  pop_back()
        #define            ppf  pop_front() 
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

        const ll N = 2e6+5 , N1 = 3e3 + 5 , MOD = 1e9+7  , o = INT_MAX , oo = LLONG_MAX;
        const db PI = asin(1) * 2;

        ll gcd(ll a,ll b){return __gcd(a,b);}
        ll bp(ll a){return a*a;}
        ll lcm(ll a,ll b){return a*b/gcd(a,b);}
        
        ll n,m;
        ll a[N],dp[N1][N1];

        ll check(ll x,ll len)
        {
            if(x==0) return 1;
            ll sum=0;
            FOR(i,1,len) sum+=a[i]/x;
            return sum>=n;
        }

        void chau()
        {
            cin>>n>>m;
            ll l=0,r=-oo;
            FOR(i,1,m)
            {
                cin>>a[i];r=max(a[i],r);
            }
            while(l<=r)
            {
                ll mid=(l+r)/2;
                if(!check(mid,m)) r=mid-1;
                else l=mid+1;
            }
            cout<<r<<" ";
            if(r==0) {cout<<0;return;}
            ll tmp=-oo;
            FOR(i,1,m) dp[i][0]=0;
            FOR(i,1,n) dp[0][i]=1e18;
            FOR(i,1,m) FOR(j,1,n) dp[i][j]=1e18;
            FOR(i,1,m) FOR(j,1,n)
            {   
                // tmp=max(tmp,a[i]);l=0;r=tmp;
                // while(l<=r)
                // {
                //     ll mid=(l+r)/2;
                //     if(!check(mid,i)) l=mid+1;
                //     else r=mid-1;
                // }

                ll r1=max((ll)0,j-a[i]/r);
                dp[i][j]=min(dp[i-1][j],dp[i-1][r1]+a[i]);
            }
            cout<<dp[m][n];
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
                //xuly();
            }
            cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
            return 0;
        }
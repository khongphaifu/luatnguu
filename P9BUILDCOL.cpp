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

        const ll N = 1e6 + 5 , N1 = 2e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
        const db PI = asin(1) * 2;

        ll gcd(ll a,ll b){return __gcd(a,b);}
        ll bp(ll a){return a*a;}
        ll lcm(ll a,ll b){return a*b/gcd(a,b);}
        

        ll n,m;
        ll dp[N1][N1],a[N],L[N],R[N],f[N],b[N];

        ll HCN(ll x1, ll y1 , ll x2 , ll y2)
        {
            return dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
        }
        
        void chau()
        {
            cin>>n>>m;
            ll l=oo,r=-oo;
            FOR(i,1,n)
            {
                cin>>a[i];
                l=min(l,a[i]);r=max(r,a[i]);
                L[i]=max(L[i-1],a[i]);
            }
            ll res=0;
            FORD(i,n,1)
            {
                R[i]=max(R[i+1],a[i]);b[i]=min(L[i],R[i])-a[i];res+=b[i];
            }
            if(res<m)
            {
                cout<<-1;return;
            }
            // FOR(i,1,n) cout<<b[i]<<" ";
            // cout<<el;
            while(l<=r)
            {
                ll mid=(l+r)/2;
                ll tmp=0;
                FOR(i,1,n)
                {
                    if(mid > a[i] && mid<a[i]+b[i]) tmp+=b[i]-mid+a[i];
                    if(mid <= a[i]) tmp+=b[i];
                }
                if(tmp>=m) l=mid+1;
                else r=mid-1;
            }
            cout<<l-1;
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
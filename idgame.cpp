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
        
        ll n,T,k;
        ll a[N],b[N],d[N],r[N];
        ll dp[N1][N1],dpl[N1][N1],dpr[N1][N1];
        pair<ll,ll> q[N];
        
        
        void chau()
        {
            cin>> n>>T;
            ll ma=-oo,mi=oo;

            FOR(i,1,n)
            {
                cin>>a[i];
                ma=max(ma,a[i]);mi=min(mi,a[i]);
            }
            FOR(i,1,T)
            {
                FOR(i,0,ma) d[i]=0;
                FOR(i,1,n)
                {
                    ma=max(ma,a[i]);mi=min(mi,a[i]);d[a[i]]++;
                }
                cin>>k;
                ll ans=0;
                while(ma-mi>k)
                {
                    ll sl=min(d[mi],d[ma]);
                    ll ma1=ma,mi1=mi;
                    if(sl==d[mi]) mi++;
                    if(sl==d[ma]) ma--;
                    d[ma1]-=sl;
                    d[mi1]-=sl;
                    d[ma1-1]+=sl;
                    d[mi1+1]+=sl;
                    ans+=sl;
                }
                cout<<ans<<el;
            }

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

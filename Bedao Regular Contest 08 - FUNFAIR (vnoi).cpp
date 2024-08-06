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

        const ll N = 1e7 + 5 , N1 = 2e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
        const db PI = asin(1) * 2;

        ll gcd(ll a,ll b){return __gcd(a,b);}
        ll bp(ll a){return a*a;}
        
        ll n,x,y;
        ll a[N],b[N],c[N];
        vector<ll> vmi,vma;

        void chau()
        {
                        
        }
        void xuly()
        {
            cin>>n>>x>>y;
            vmi.pb(0);
            FOR(i,1,n)
            {
                cin>>a[i];
                b[i]=b[i-1]+a[i];
                if(a[i]<x) vmi.pb(i);
                if(a[i]>y) c[i]=1;
                c[i]+=c[i-1];
            }
            vmi.pb(n+1);
            //printv(vmi);
            ll ans=-oo;
            ll l,r;
            FOR(i,1,vmi.size()-1)
            {
                ll res=vmi[i-1];
                FOR(j,vmi[i-1]+1,vmi[i]-1)
                {
                    if(ans<b[j]-b[res] && c[j]-c[res]<j-res)
                    {
                        ans=b[j]-b[res];
                        l=res+1,r=j;
                    }
                    if(b[j]<b[res]) res=j;
                }
            }
            cout<<ans<<el<<l<<" "<<r<<el;
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
                xuly();
            }
            cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
            return 0;
        }

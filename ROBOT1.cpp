int mlt=0;
    int test=1;

    #include <bits/stdc++.h>
    using namespace std;


    #define           TASK  "ROBOT1"
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
    #define       ieozzool  cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;




    ll dx[]={1,-1,0,0,1,1,-1,-1};
    ll dy[]={0,0,1,-1,1,-1,1,-1};

    const ll N = 1e6 + 5 , N1 = 3e3 + 5 , MOD = 1e9 + 7 , inf = 1e18;
    const db PI = asin(1) * 2;

    ll gcd(ll a,ll b){return __gcd(a,b);}
    ll bp(ll a){return a*a;}
    ll lcm(ll a,ll b){return a*b/gcd(a,b);}



    void bef()
    {
        
    }

    namespace mnp
    {
        ll t,n,a,b,k,ans=1,ansm=1,check=0; 
        ll tmp[N];
        map<ll,ll> mp,visit;

        void dfs(ll x,ll res)
        {
            if(visit[x]) return;
            if(res>k) return;
            visit[x]=1;
            FOR(i,1,2)
            {
                ll x1=x+tmp[i];
                if(x1 < 1 || x1 > n || res+1>k) continue;
                if(visit[x1]!=1)
                {
                    dfs(x1,res+1);
                    // if(check) return;
                }
            }

        }

        void sol()
        {
            cin>>t;
            while(t!=0)
            {
                cin>>n>>a>>b>>k;
                tmp[1]=a;tmp[2]=-b;
                visit.clear();
                dfs(1,0);
                cout<<n-visit.size()<<el;
                t--;
            }
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
        bef();
        if(mlt) cin>>test;
        FOR(i,1,test)
        {
            mnp::sol();
        }
        ieozzool;
    }
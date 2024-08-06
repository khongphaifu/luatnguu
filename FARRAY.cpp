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
        #define         all(a)  a.begin(),a.end()
        #define     FOR(i,a,b)  for(ll i=a;i<=b;i++)
        #define    FORD(i,a,b)  for(ll i=a;i>=b;i--)
        #define    FORN(i,a,b)  for(ll i=a;i<b;i++)
        #define   FORDN(i,a,b)  for(ll i=a;i>b;i--)


        ll mlt=1,test=1;


        const ll N = 1e7 + 5 , N1 = 3e3 + 7 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;

        //"..."

        bool cmp(pair<ll,ll> a, pair<ll,ll> b){
            if(a.fi==b.fi) return a.se < b.se;
            return a.fi > b.fi;}

        ll gcd(ll a,ll b){return __gcd(a,b);}
        ll pw(ll a,ll b) /* a^b */ {
            if(b==0) return 1;
            ll x=pw(a,b/2);
            if(b%2!=0) return ( x * x ) % MOD  *  a % MOD ;
            else return  ( x * x ) % MOD;}
        ll dx[]={1,-1,0,0};
        ll dy[]={0,0,1,-1};

        int n,m,t,k,x,y,A,B,q,p,ans=oo,khoi=0,    a[N],b[N],c[N],d[N],e[N],   dp[N1][N1],dp1[N1][N1],dp2[N1][N1]  ;
        int nt[N];
        void sang()
        {
            nt[1]=nt[0]=-1;
            FOR(i,2,N)
            {
                if(nt[i]==0)
                {
                    nt[i]=i;
                    for(ll j=i*i;j<=N;j+=i) nt[j]=i;
                }
            }
            a[1]=1;
            FOR(i,2,N)
            {
                if(nt[i]==i) a[i]=i+1;
                else 
                {
                    ll temp=i,dem=1;
                    while(temp%nt[i]==0)
                    {
                        temp/=nt[i];dem*=nt[i];
                    }
                    if(dem!=i)
                    {
                        a[i]=a[dem]*a[i/dem];
                    }
                    else a[i]=(nt[i]*dem-1)/(nt[i]-1);

                }
            }
            FORD(i,N,1) b[a[i]]=i;
        }
        void chau()
        {
            cin>>n;
            if(b[n]!=0) cout<<b[n]<<endl;
            else cout<<-1<<endl;
        }
        nnc
        {
            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
            if(fopen(TASK".INP","r"))
            {
                freopen(TASK".INP" ,"r",stdin) ;
                freopen(TASK".OUT" ,"w",stdout);
            }
            sang();
            if(mlt) cin>>test;
            while(test--) chau();
            cerr<<"Time: "<<0.001*clock()<<"s"<<endl;
            return 0;
        }
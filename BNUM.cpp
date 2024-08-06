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


        ll mlt=1;
        ll test=1;

        ll dx[]={1,-1,0,0};
        ll dy[]={0,0,1,-1};

        const ll N = 1e3+5 , N1 = 2e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
        const db PI = asin(1) * 2;

        ll gcd(ll a,ll b){return __gcd(a,b);}
        ll bp(ll a){return a*a;}
        
        ll n,m;
        vector<ll> v;
        ll pw(ll a,ll b)
        {
            if(b==0) return 1;
            ll tmp=pw(a,b/2);
            if(b%2==0) return tmp*tmp;
            else return a*tmp*tmp;
        }
        //v.pb(4);v.pb(6);v.pb(9);v.pb(44);v.pb(46);v.pb(49);v.pb(64);v.pb(66);v.pb(69);v.pb(94);v.pb(96);v.pb(99);

        void chau()
        {
            cin>>n;
             // ll tmp=(ll)4*(ll)6*(ll)9*(ll)46*(ll)49*(ll)69*(ll)94;
             // cout<<tmp<<el;
            n=pw((ll)10,n);
            ll ans=0;
            //printv(v);
            FORN(i,1,(1<<v.size()))
            {
                int cnt=1,res=0,h=0;
                FORN(j,0,v.size())
                
                    if(i & (1<<j))
                    {
                        res++;
                        cnt*=v[j];
                        h=gcd(h,v[j]);
                        if(res>=2)
                        {
                            cnt/=h;h=cnt;
                        }
                    }
                ll tmp=n/cnt;
                if(res%2!=0) ans+=tmp;
                else ans-=tmp;
            }
            cout<<ans+1<<el;
        }
        void xuly()
        {
            FOR(i,0,100)
            {
                if(i%4==0 || i%9==0 || i%6==0 || i%46==0 || i%49==0 || i%69==0 || i%94==0) cout<<i<<el;
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
            v.pb(4);v.pb(6);v.pb(9);v.pb(46);v.pb(49);v.pb(69);v.pb(94);
            FOR(i,1,test)
            {
                chau();
                //xuly();
            }
            cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
            return 0;
        }

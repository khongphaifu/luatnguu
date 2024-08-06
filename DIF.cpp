//furiel?
            /**  /\_/\
            *   (= ._.)
            *   / >?? \>??
            **/

            #include <bits/stdc++.h>
            using namespace std;


            #define           TASK  "DIF"
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


            ll mlt=0;
            ll test=1;

            ll dx[]={1,-1,0,0};
            ll dy[]={0,0,1,-1};

            const ll N = 1e5  + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
            const db PI = asin(1) * 2;

            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}

            struct td{
                ll x,y;
            };

            ll n,k;
            ll a[N],f[N];
                        
            void hmmm()
            { 
                cin>>n;
                set<ll> s,s1;
                map<ll,ll> mp;
                s1.insert(0);
                FOR(i,1,n)
                {
                    ll x;cin>>x;
                    auto it=s.upper_bound(x);
                    if(s.size()==0) cout<<0<<el;
                    else if(it==s.end())
                    {
                        //cout<<x<<"!"<<el;
                        s1.insert(x-*s.rbegin());mp[x-*s.rbegin()]++;
                        cout<<*s1.rbegin()<<el;
                    }
                    else if(*it==*s.begin())
                    {
                        //cout<<x<<"!"<<el;
                        s1.insert(*s.begin()-x);mp[*s.begin()-x]++;
                        cout<<*s1.rbegin()<<el;
                    }
                    else
                    {
                        auto it1=it;
                        it--;
                        //cout<<*it1<<" "<<*it<<el;
                        mp[*it1-*it]--;
                        if(mp[*it1-*it]==0) s1.erase(*it1-*it);
                        s1.insert(*it1-x);s1.insert(x-*it);
                        cout<<*s1.rbegin()<<el;
                    }
                    s.insert(x);
                }
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
                xuly();
                FOR(i,1,test)
                {
                    hmmm();
                }
                cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
                return 0;
            }
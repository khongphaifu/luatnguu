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
            #define      alla(a,n)  a+1,a+n+1
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

            const ll N = 3e6  + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
            const db PI = asin(1) * 2;

            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}

            struct td{
                ll x,y;
            };

            bool cmp(td a, td b)
            {
                if(a.x==b.x) return a.y<b.y;
                return a.x<b.x;
            }

            ll n,m,S;
            

                        
            void hmmm()
            { 
                cin>>m>>n>>S;
                if(S<m*n)
                {
                    cout<<1<<el;return;
                }
                S*=2;
                for(ll i=1;i*i<=S;i++)
                {
                    if(S%i==0)
                    {
                        ll v=S/i;
                        for(ll j=1;j*j<=i;j++)
                        {
                            if(i%j==0)
                            {
                                ll x=j,y=i/j;
                                if((v-(x-1+n*(y-1))) %2==0)
                                {
                                    ll a=(v-(x-1+n*(y-1)))/2;
                                    ll res1=a/n +1,res2 = a%n +1;
                                    if(a<m*n && a>=0 && res2 +x -1<=n && res1+y-1<=m)
                                    {
                                        cout<<x*y<<el;return;
                                    }
                                }
                                x=i/j,y=j;
                                if((v-(x-1+n*(y-1))) %2==0)
                                {
                                    ll a=(v-(x-1+n*(y-1)))/2;
                                    ll res1=a/n +1,res2 = a%n +1;
                                    if(a<m*n && a>=0 && res2 +x -1 <=n && res1+y -1<=m)
                                    {
                                        cout<<x*y<<el;return;
                                    }
                                }
                            }
                        }
                        ll i1=S/i;
                        v=i;
                        for(ll j=1;j*j<=min(i1,1000000ll);j++)
                        {
                            if(i1%j==0)
                            {
                                ll x=j,y=i1/j;
                                if((v-(x-1+n*(y-1))) %2==0)
                                {
                                    ll a=(v-(x-1+n*(y-1)))/2;
                                    ll res1=a/n +1,res2 = a%n +1;
                                    if(a<m*n && a>=0 && res2 +x -1<=n && res1+y-1<=m)
                                    {
                                        //cout<<1<<" "<<i1<<" "<<j<<el;
                                        cout<<x*y<<el;return;
                                    }
                                }
                                x=i1/j,y=j;
                                if((v-(x-1+n*(y-1))) %2==0)
                                {
                                    ll a=(v-(x-1+n*(y-1)))/2;
                                    ll res1=a/n +1,res2 = a%n +1;
                                    if(a<m*n && a>=0 && res2 +x -1<=n && res1+y-1<=m)
                                    {
                                        cout<<x*y<<el;return;
                                    }
                                }
                            }
                        }
                    }
                }
                cout<<-1<<el;
            }



            void xuly()
            {
                //sang();
                
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
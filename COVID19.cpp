//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "COVID19"
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


                ll mlt=0;
                ll test=1;

                ll dx[]={1,-1,0,0};
                ll dy[]={0,0,1,-1};

                const ll N = 1e6 + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
                const db PI = asin(1) * 2;

                ll gcd(ll a,ll b){return __gcd(a,b);}
                ll bp(ll a){return a*a;}
                ll lcm(ll a,ll b){return a*b/gcd(a,b);}



                void bef()
                {
                    
                }

                namespace mnp
                {
                    ll n,m;
                    map<ll,ll> visit,d;
                    vector<ll> v;
                    void bfs()
                    {
                        queue<ll> q;
                        visit[n]=1;
                        q.push(n);
                        while(!q.empty())
                        {
                            ll u=q.front();
                            q.pop();
                            if(u==m) return;
                            for(auto it:v)
                            {
                                if(u%it==0 && !visit[u/it])
                                {
                                    visit[u/it]=1;
                                    d[u/it]=d[u]+1;
                                    q.push(u/it);
                                    if(u/it==m) return;
                                }
                            }
                            if(!visit[u*u] && u*u<=1e12)
                            {
                                visit[u*u]=1;
                                q.push(u*u);
                                d[u*u]=d[u]+1;
                                if(u*u==m) return;
                            }

                        }
                    }

                    void sol()
                    {
                        cin>>n>>m;
                        ll tmp=n;
                        for(ll i=2;i<=tmp;i++)
                        {
                            if(tmp%i==0) v.pb(i);
                            while(tmp%i==0) tmp/=i;
                        }
                        bfs();
                        cout<<d[m];
                        
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
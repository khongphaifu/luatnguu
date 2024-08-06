//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "KINHDOANH"
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
                    ll n,m,sizev;
                    vector<ll> g[N];
                    bool visit[N];

                    void bfs(ll s)
                    {
                        sizev=1;
                        queue<ll> q;
                        q.push(s);
                        visit[s]=true;
                        while(!q.empty())
                        {
                            ll u=q.front();q.pop();
                            for(auto it:g[u])
                            {
                                if(!visit[it])
                                {
                                    visit[it]=true;
                                    sizev++;
                                    q.push(it);
                                }
                            }
                        }
                    }

                    void sol()
                    {
                        cin>>n>>m;
                        FOR(i,1,m)
                        {
                            ll x,y;cin>>x>>y;
                            g[x].pb(y);
                            g[y].pb(x);
                        }
                        vector<ll> v;
                        FOR(i,1,n)
                        {
                            if(!visit[i])
                            {
                                bfs(i);
                                v.pb(sizev);
                            }
                        }
                        sort(all(v),greater<ll>());
                        if(v.size()==1) cout<<v[0];
                        else cout<<v[0]+v[1];
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
                    FOR(i,1,test)
                    {
                        mnp::sol();
                    }
                    ieozzool;
                }
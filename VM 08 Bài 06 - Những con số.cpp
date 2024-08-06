//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "GOS"
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
                    ll n;
                    ll a[N],f[N],L[N];
                    vector<ll> g[N],G[N];

                    void sol()
                    {
                        cin>>n;
                        FOR(i,1,n) cin>>a[i];
                        sort(a+1,a+n+1);
                        g[1].pb(a[1]);
                        L[1]=1;f[a[1]]=1;
                        FOR(i,2,n) 
                        {
                            if(a[i]==a[i-1])
                            {
                                L[i]=L[i-1]+1;f[a[i]]++;
                            }
                            else
                            {
                                ll tmp=0;
                                    for(ll j=1;j*j<=a[i];j++)
                                    {
                                        if(a[i]%j==0)
                                        {
                                            tmp=max(tmp,1+f[j]);
                                            if(j!=a[i]/j) tmp=max(tmp,1+f[a[i]/j]);
                                        }
                                    }
                                    f[a[i]]=tmp;
                                    L[i]=f[a[i]];
                                    
                                
                            }
                            g[L[i]].pb(a[i]);
                        }
                    
                        // cout<<a[2]<<el;
                        ll res=0;
                        FOR(i,1,n) res=max(L[i],res);
                        ll tmp=res;
                        FOR(i,1,res) if(g[i].size()==0) tmp--;
                        cout<<tmp<<el;
                        FOR(i,1,res)
                        {
                            if(g[i].size()!=0) cout<<g[i].size()<<" ";
                            else continue;
                            for(auto it:g[i]) cout<<it<<" ";
                            cout<<el;
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
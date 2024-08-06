                int mlt=0;
                int test=1;

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "RELATION"
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
                    ll n,sep,ans=0;
                    vector<ll> g[N];
                    bool visit[N];
                    ll st[4*N];

                    void up(ll id,ll l ,ll r,ll i, ll val)
                    {
                        if(i<l || r<i ) return;
                        if(l==r)
                        {
                            st[id]=val;return;
                        }
                        ll mid=(l+r)/2;
                        up(2*id,l,mid,i,val);
                        up(2*id+1,mid+1,r,i,val);
                        st[id]=st[2*id]+st[2*id+1];
                    }

                    ll get(ll id,ll l,ll r,ll u,ll v)
                    {
                        if(u>r || l>v) return 0;
                        if(u<=l && r<=v) return st[id];
                        ll mid=(l+r)/2;
                        return get(2*id,l,mid,u,v) + get(2*id+1,mid+1,r,u,v);
                    }
                    
                    void dfs(ll s)
                    {
                        visit[s]=true;
                        ans+=get(1,1,n,1,s-1);
                        up(1,1,n,s,1);
                        for(auto it:g[s])
                        {
                            if(!visit[it])
                            {
                                dfs(it);
                            }
                        }
                        up(1,1,n,s,0);
                    }

                    void sol()
                    {
                        cin>>n>>sep;
                        FOR(i,1,n-1)
                        {
                            ll x,y;cin>>x>>y;
                            g[x].pb(y);
                            g[y].pb(x);
                        }
                        dfs(sep);
                        cout<<ans;

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
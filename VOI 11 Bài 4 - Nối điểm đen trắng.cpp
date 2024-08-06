//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "VOI 11 Bài 4 - Nối điểm đen trắng"
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
                    ll f[N],a[N],b[N];

                    void sol()
                    {
                        cin>>n;
                        vector<pair<ll,ll>> v;
                        v.pb(pair<ll,ll>(-oo,-oo));
                        FOR(i,1,n)
                        {
                            ll x;cin>>x; v.pb(pair<ll,ll>(x,0ll));
                        }
                        FOR(i,1,n)
                        {
                            ll x;cin>>x; v.pb(pair<ll,ll>(x,1ll));
                        }
                        sort(all(v));
                        //for(auto it:v) cout<<it.fi<<" "<<it.se<<el;
                        ll den=0,trang=0,ans=0;
                        FOR(i,1,2*n)
                        {
                            if(v[i].se==1 )
                            {
                                if(den!=0)f[i]=max(f[i-1],f[den-1] +1);
                                trang=i;
                            }
                            if(v[i].se==0)
                            {
                                if(trang!=0) f[i]=max(f[i-1],f[trang-1] +1);
                                den=i;
                            }
                            //cout<<f[i]<<" ";
                            ans=max(ans,f[i]);
                        }
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
                    
                    if(mlt) cin>>test;
                    FOR(i,1,test)
                    {
                        mnp::sol();
                    }
                    ieozzool;
                }
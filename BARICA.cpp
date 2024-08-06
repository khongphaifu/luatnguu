//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "BARICA"
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
                    ll n,k;
                    ll vt[N],f[N],Px[N],Py[N];
                    
                    struct td
                    {
                        ll x,y,L,id;
                    };

                    td a[N];
                    
                    bool cmp(td a,td b)
                    {
                        if(a.x==b.x) return a.y<b.y;
                        return a.x<b.x;
                    }

                    void sol()
                    {
                        cin>>n>>k;
                        FOR(i,1,n) cin>>a[i].x>>a[i].y>>a[i].L,a[i].id=i;
                        sort(alla(a,n),cmp);
                        FOR(i,1,n) vt[a[i].id]=i;
                        ll d=vt[1],c=vt[n];
                        f[d]=a[d].L,Px[a[d].x]=f[d],Py[a[d].y]=f[d];
                        FOR(i,d+1,c)
                        {
                            if(Px[a[i].x]>=k) f[i]=max(f[i],Px[a[i].x]-k+a[i].L);
                            if(Py[a[i].y]>=k) f[i]=max(f[i],Py[a[i].y]-k+a[i].L);
                            Px[a[i].x]=max(Px[a[i].x],f[i]);
                            Py[a[i].y]=max(Py[a[i].y],f[i]);
                        }
                        cout<<f[c];
                        
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
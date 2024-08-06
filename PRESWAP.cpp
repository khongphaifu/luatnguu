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


            ll mlt=0;
            ll test=1;

            ll dx[]={1,-1,0,0};
            ll dy[]={0,0,1,-1};

            const ll N = 1e6 + 5 , N1 = 3e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
            const db PI = asin(1) * 2;

            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}

            ll n,m,x;
            ll a[N],l[N],r[N],dp[105][50005],t[N],t2[N];
            
            void update(ll k, ll l , ll r, ll i , ll val)
            {
                if(i<l || r<i) return;
                if(l==r)
                {
                    t[k]=val;return;
                }
                ll mid=(l+r)/2;
                update(2*k,l,mid,i,val);
                update(2*k+1,mid+1,r,i,val);
                t[k]=t[2*k]+t[2*k+1];
            }
            ll get(ll k, ll l ,ll r , ll u , ll v)
            {
                if(v<l || u>r) return 0;
                if(u<=l && r<=v) return t[k];
                ll mid=(l+r)/2;
                return get(2*k,l,mid,u,v)+get(2*k+1,mid+1,r,u,v);
            }

            void chau()
            {
                cin>>n;
                FOR(i,1,n) cin>>a[i];
                FORD(i,n,1)
                {
                    r[i]=get(1,1,n,a[i]+1,n);
                    update(1,1,n,a[i],1);
                }
            
                FOR(i,1,4*n) t[i]=0; 
                FOR(i,1,n)
                {
                    l[i]=get(1,1,n,a[i]+1,n);
                    update(1,1,n,a[i],1);
                    //cout<<l[i]<<" ";
                }
                vector<ll> f;
                ll sum=0;
                FOR(i,1,n)
                {
                    sum+=r[i];
                    if(a[i]!=n) f.pb(l[i]-r[i]);
                }
                sort(all(f));
                ll res=sum;
                cout<<sum<<" ";
                FOR(i,0,f.size()-1)
                {
                    sum+=f[i];cout<<sum<<" ";
                }


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
                    chau();
                }
                cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
                return 0;
            }
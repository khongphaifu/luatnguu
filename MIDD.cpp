//furiel?
            /**  /\_/\
            *   (= ._.)
            *   / >?? \>??
            **/

            #include <bits/stdc++.h>
            using namespace std;


            #define           TASK  "MIDD"
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

            const ll N = 2e5  + 7 , N1 = 1e3 + 7 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
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

            ll n,s;
            ll a[N],st[4*N];
            
            void upd(ll id, ll l, ll r, ll i , ll val)
            {
                if(i<l || r<i) return;
                if(l==r)
                {
                    st[id]+=val;return;
                }
                ll mid=(l+r)/2;
                upd(2*id,l,mid,i,val);
                upd(2*id+1,mid+1,r,i,val);
                st[id]=st[2*id]+st[2*id+1];
            }

            ll get(ll id , ll l , ll r , ll u , ll v)
            {
                if(l>v || u>r) return 0;
                if(l>=u && v>=r) return st[id];
                ll mid=(l+r)/2;
                ll get1=get(2*id,l,mid,u,v);
                ll get2=get(2*id+1,mid+1,r,u,v);
                return get1+get2;
            }

            void hmmm()
            { 
                cin>>n>>s;
                ll ans=0;
                vector<ll> v;
                upd(1,0,200000,100000,1);
                a[0]=100000;
                FOR(i,1,n)
                {
                    a[i]=a[i-1];
                    ll x;cin>>x;
                    if(x>=s) a[i]++;
                    else a[i]--;
                    ans+=get(1,0,200000,0,a[i]-1);
                    upd(1,0,200000,a[i],1);
                    //cout<<ans<<el;
                    //cout<<a[i]<<" ";
                    // FOR(j,0,i-1)
                    // {
                    //     if(a[j]<a[i]) ans++;
                    // }
                }
                //FOR(i,0,n) cout<<a[i]<<" ";
                cout<<ans;
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
//furiel?
            /**  /\_/\
            *   (= ._.)
            *   / >?? \>??
            **/

            #include <bits/stdc++.h>
            using namespace std;


            #define           TASK  "PROTEST"
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

            const ll N = 2e5  + 7 , N1 = 1e3 + 7 , MOD = 1e9 + 9 , o = INT_MAX , oo = LLONG_MAX;
            const db PI = asin(1) * 2;

            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}

            struct td{
                ll x,y,z;
            };

            bool cmp(td a, td b)
            {
                if(a.x==b.x) return a.y<b.y;
                return a.x<b.x;
            }

            bool cmp1(td a, td b)
            {
                return a.y<b.y;
            }

            ll n,s;
            td a[N];
            ll st[4*N];

            void upd(ll id, ll l, ll r, ll i, ll val)
            {
                if(i<l || r<i) return;
                if(l==r)
                {
                    st[id]=(st[id]+val)%MOD;return;
                }
                ll mid=(l+r)/2;
                upd(2*id,l,mid,i,val);
                upd(2*id+1,mid+1,r,i,val);
                st[id]=st[id*2]+st[2*id+1];
            }

            ll get(ll id, ll l, ll r,ll u, ll v)
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
                cin>>n;
                ll ans=0;
                a[0].x=0;a[0].y=1;
                FOR(i,1,n)
                {
                    ll x;cin>>x;
                    a[i].x=a[i-1].x+x;
                    a[i].y=a[i-1].y+1;
                }
                sort(a,a+n+1,cmp);
                a[0].z=1;
                FOR(i,1,n)
                {
                    a[i].z=a[i-1].z;
                    if(a[i].x!=a[i-1].x) a[i].z++;
                }
                sort(a,a+n+1,cmp1);
                upd(1,1,n,a[0].z,1);
                FOR(i,1,n)
                {
                    //cout<<a[i].z<<" ";
                    ll tmp=get(1,1,n,1,a[i].z);
                    upd(1,1,n,a[i].z,tmp);
                    if(i==n) cout<<tmp%MOD;
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
                    hmmm();
                }
                cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
                return 0;
            }

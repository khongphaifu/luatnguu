//furiel?
            /**  /\_/\
            *   (= ._.)
            *   / >?? \>??
            **/

            #include <bits/stdc++.h>
            using namespace std;


            #define           TASK  "INVTRI"
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

            const ll N = 1e5  + 7 , N1 = 1e3 + 7 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
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

            ll n,q;
            td a[N];
            ll st[4*N],st1[4*N],L[N],R[N];

            // void build(ll id , ll l, ll r)
            // {
            //     if(l==r)
            //     {
            //         st[id]=a[l];return;
            //     }
            //     ll mid=(l+r)/2;
            //     build(2*id,l,mid);
            //     build(2*id+1,mid+1,r);
            //     st[id]=st[2*id]+st[2*id+1];
            // }

            void upd(ll id ,ll l ,ll r , ll i, ll  val)
            {
                if(l>i || i>r) return;
                if(l==r)
                {
                    st[id]=val;return;
                }
                ll mid=(l+r)/2;
                upd(2*id,l,mid,i,val);
                upd(2*id+1,mid+1,r,i,val);
                st[id] = st[2*id]+st[2*id+1];
            }

            ll get(ll id , ll l ,ll r, ll u ,ll v)
            {
                if(l>v || r<u) return 0;
                if(l>=u && r<=v) return st[id];
                ll mid=(l+r)/2;
                ll get1 =get(2*id,l,mid,u,v);
                ll get2 =get(2*id+1,mid+1,r,u,v);
                return get1+get2;
            }
            
            void upd1(ll id ,ll l ,ll r , ll i, ll  val)
            {
                if(l>i || i>r) return;
                if(l==r)
                {
                    st1[id]=val;return;
                }
                ll mid=(l+r)/2;
                upd1(2*id,l,mid,i,val);
                upd1(2*id+1,mid+1,r,i,val);
                st1[id] = st1[2*id]+st1[2*id+1];
            }

            ll get3(ll id , ll l ,ll r, ll u ,ll v)
            {
                if(l>v || r<u) return 0;
                if(l>=u && r<=v) return st1[id];
                ll mid=(l+r)/2;
                ll get1 =get3(2*id,l,mid,u,v);
                ll get2 =get3(2*id+1,mid+1,r,u,v);
                return get1+get2;
            }
                        
            void hmmm()
            { 
                cin>>n;
                FOR(i,1,n)
                {
                    cin>>a[i].x;
                    a[i].y=i;
                }
                sort(alla(a,n),cmp);
                ll ans=0;
                FOR(i,1,n)
                {
                    L[i]=get(1,1,n,a[i].y+1,n);
                    //cout<<get(1,1,n,a[i].y+1,n)<<el;
                    upd(1,1,n,a[i].y,1);
                }
                //cout<<ans;
                //FOR(i,1,4*n) cout<<st1[i]<<" ";
                FORD(i,n,1)
                {
                    R[i]=get3(1,1,n,1,a[i].y-1);
                    //cout<<get3(1,1,n,1,a[i].y-1)<<el;
                    upd1(1,1,n,a[i].y,1);
                    if(L[i] && R[i])ans+=L[i]*R[i];
                }
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
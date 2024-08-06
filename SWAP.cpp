//furiel?
            /**  /\_/\
            *   (= ._.)
            *   / >?? \>??
            **/

            #include <bits/stdc++.h>
            using namespace std;


            #define           TASK  "SWAP"
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
            ll a[N],st[4*N];

            void build(ll id , ll l, ll r)
            {
                if(l==r)
                {
                    st[id]=a[l];return;
                }
                ll mid=(l+r)/2;
                build(2*id,l,mid);
                build(2*id+1,mid+1,r);
                st[id]=st[2*id]+st[2*id+1];
            }

            void upd1(ll id ,ll l ,ll r , ll i, ll  val)
            {
                if(l>i || i>r) return;
                if(l==r)
                {
                    st[id]+=val;return;
                }
                ll mid=(l+r)/2;
                upd1(2*id,l,mid,i,val);
                upd1(2*id+1,mid+1,r,i,val);
                st[id] = st[2*id]+st[2*id+1];
            }

            void upd2(ll id ,ll l ,ll r , ll i, ll  val)
            {
                if(l>i || i>r) return;
                if(l==r)
                {
                    st[id]+=val;return;
                }
                ll mid=(l+r)/2;
                upd2(2*id,l,mid,i,val);
                upd2(2*id+1,mid+1,r,i,val);
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
           
                        
            void hmmm()
            { 
                cin>>n;
                cin>>q;
                FOR(i,1,n) cin>>a[i];
                build(1,1,n);
                while(q--)
                {
                    ll type,x,y;cin>>type>>x>>y;
                        //cout<<get(1,1,n,x,y)<<el;
                    if(type) cout<<get(1,1,n,x,y)<<el;
                    else
                    {
                        ll val=a[x]-a[y];
                        swap(a[x],a[y]);
                        // FOR(i,1,n) cout<<a[i]<<" ";
                        // cout<<el;
                        upd1(1,1,n,x,-val);
                        upd2(1,1,n,y,val);
                    }

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
//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "Mua vé tàu hoả"
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
                    ll l1,l2,l3,c1,c2,c3,n,f,s;
                    ll f1[N],st[4*N],a[N];

                    void build(ll id, ll l ,ll r)
                    {
                        if(l==r)
                        {
                            st[id]=1e18;return;
                        }
                        ll mid=(l+r)/2;
                        build(2*id,l,mid);
                        build(2*id+1,mid+1,r);
                        st[id]=min(st[2*id],st[2*id+1]);
                    }

                    void up(ll id,ll l, ll r,ll i, ll val)
                    {
                        if(i<l || i>r) return;
                        if(l==r)
                        {
                            st[id]=val;return;
                        }
                        ll mid=(l+r)/2;
                        up(2*id,l,mid,i,val);
                        up(2*id+1,mid+1,r,i,val);
                        st[id]=min(st[2*id],st[2*id+1]);
                    }

                    ll get(ll id, ll l, ll r,ll u,ll v)
                    {
                        if(v<l || r<u) return 1e18;
                        if(l>=u && v>=r) return st[id];
                        ll mid=(l+r)/2;
                        ll get1=get(2*id,l,mid,u,v);
                        ll get2=get(2*id+1,mid+1,r,u,v);
                        return min(get1,get2);
                    }

                    void sol()
                    {
                        cin>>l1>>l2>>l3>>c1>>c2>>c3>>n>>s>>f;
                        FOR(i,2,n) cin>>a[i];
                        build(1,s,f);
                        FOR(i,s,f) f1[i]=1e18;
                        f1[s]=0;
                        up(1,s,f,s,0);
                        FOR(i,s+1,f)
                        {
                            ll j=lower_bound(a+s,a+i+1,a[i]-l1)-a;
                            f1[i]=min(f1[i],get(1,s,f,j,i)+c1);
                            j=lower_bound(a+s,a+i+1,a[i]-l2)-a;
                            f1[i]=min(f1[i],get(1,s,f,j,i)+c2);
                            j=lower_bound(a+s,a+i+1,a[i]-l3)-a;
                            f1[i]=min(f1[i],get(1,s,f,j,i)+c3);
                            up(1,s,f,i,f1[i]);
                        }
                        cout<<f1[f];
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
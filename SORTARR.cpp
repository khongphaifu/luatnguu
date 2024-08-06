                int mlt=0;
                int test=1;

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "SORTARR"
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
                    ll n;

                    struct bg
                    {
                        ll val,id;
                    };

                    bool cmp(bg a,bg b)
                    {
                        return a.val<b.val;
                    }

                    bool cmp1(bg a,bg b)
                    {
                        return a.id<b.id;
                    }

                    bg a[N];
                    ll b[N];
                    ll st[4*N];

                    void up(ll id,ll l,ll r,ll i,ll val)
                    {
                        if(i<l || r<i) return;
                        if(l==r)
                        {
                            st[id]+=val;return;
                        }
                        ll mid=(l+r)/2;
                        up(2*id,l,mid,i,val);
                        up(2*id+1,mid+1,r,i,val);
                        st[id]=st[2*id]+st[2*id+1];
                    }

                    ll get(ll id,ll l,ll r,ll u,ll v)
                    {
                        if(u>r || v<l) return 0;
                        if(u<=l && r<=v) return st[id];
                        ll mid=(l+r)/2;
                        return  get(2*id,l,mid,u,v)+get(2*id+1,mid+1,r,u,v);
                    }

                    void sol()
                    {
                        cin>>n;
                        FOR(i,1,n) cin>>a[i].val,a[i].id=i;
                        sort(alla(a,n),cmp);
                        ll tmp=1;
                        FOR(i,1,n)
                        {
                            if(a[i].val==a[i-1].val) b[i]=b[i-1];
                            else
                            {
                                b[i]=tmp;tmp++;
                            }
                        }
                        FOR(i,1,n) a[i].val=b[i];
                        sort(alla(a,n),cmp1);
                        // FOR(i,1,n) cout<<a[i].val<<" ";
                        ll ans=0;
                        FOR(i,1,n)
                        {
                            ans+=get(1,1,n,a[i].val+1,n);
                            up(1,1,n,a[i].val,1);
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
                    bef();
                    if(mlt) cin>>test;
                    FOR(i,1,test)
                    {
                        mnp::sol();
                    }
                    ieozzool;
                }
//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "TUG"
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

                    struct nodes
                    {
                        ll lazy,val;
                    } nodes[4*N];

                    void down(ll id)
                    {
                        ll t=nodes[id].lazy;
                        nodes[2*id].val=max(t,nodes[2*id].val);
                        nodes[2*id].lazy=max(t,nodes[2*id].lazy);
                        nodes[2*id+1].val=max(t,nodes[2*id+1].val);
                        nodes[2*id+1].lazy=max(t,nodes[2*id+1].lazy);
                        nodes[id].lazy=0;
                    }

                    void up(ll id,ll l ,ll r , ll u,ll v,ll val)
                    {
                        if(v<l || r<u) return;
                        if(u<=l && r<=v)
                        {
                            nodes[id].lazy=max(nodes[id].lazy,val);
                            nodes[id].val=max(val,nodes[id].val);
                            return;
                        }
                        ll mid=(l+r)/2;
                        down(id);
                        up(2*id,l,mid,u,v,val);
                        up(2*id+1,mid+1,r,u,v,val);
                        nodes[id].val=max(nodes[2*id].val,nodes[2*id+1].val);
                    }

                    ll get(ll id,ll l,ll r,ll i)
                    {
                        if(i<l || i>r) return 0;
                        if(l==r) return nodes[id].val;
                        ll mid=(l+r)/2;
                        down(id);
                        ll get1=get(2*id,l,mid,i);
                        ll get2=get(2*id+1,mid+1,r,i);
                        return max(get1,get2);

                    }

                    void sol()
                    {
                        cin>>n;
                        ll ans=-oo;
                        FOR(i,1,n)
                        {
                            ll a,l,r;cin>>a>>l>>r;
                            a+=get(1,1,n,i);
                            // cout<<get(1,1,n,i)<<" "<<a<<el;
                            up(1,1,n,l,r,a);
                            ans=max(ans,a);
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
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

                const ll N = 1e6 + 5 , N1 = 4e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
                const db PI = asin(1) * 2;

                ll gcd(ll a,ll b){return __gcd(a,b);}
                ll bp(ll a){return a*a;}
                ll lcm(ll a,ll b){return a*b/gcd(a,b);}

                ll n,m;
                ll a[N],l[N],r[N];

                ll HCN(ll x1, ll y1, ll x2 , ll y2 , ll a[N1][N1])
                {
                    return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
                }
                
                ll xuli(ll a[], ll n, ll m)
                {
                    stack<ll> st1,st2;
                    st2.push(0);
                    FOR(i,1,n)
                    {
                        while(!st1.empty() && a[i]>=st1.top())
                        {
                            st1.pop();st2.pop();
                        }
                        l[i]=st2.top();
                        st1.push(a[i]);st2.push(i);
                        // cout<<l[i]<<" ";
                    }
                    // cout<<el;
                    stack<ll> st3,st4;
                    st4.push(n+1);
                    FORD(i,n,1)
                    {
                        while(!st3.empty() && a[i]>=st3.top())
                        {
                            st3.pop();st4.pop();
                        }
                        r[i]=st4.top();
                        st3.push(a[i]);st4.push(i);
                    }
                    // FOR(i,1,n) cout<<r[i]<<" ";
                    // cout<<el;
                    ll ans=-oo;
                    FOR(i,1,n) ans=max(ans,(m-a[i])*(r[i]-l[i]-1));
                    return ans;   
                }

                void hmmm()
                { 
                    cin>>m>>n;
                    FOR(i,1,n) cin>>a[i],a[i]=m-a[i];
                    ll ans=-oo;
                    ans=max(ans,xuli(a,n,m));
                    FOR(i,1,n) a[i]=m-a[i];
                    ans=max(ans,xuli(a,n,m));
                    //cout<<xuli(a,n,m)<<el;
                    cout<<ans;
                }


                void xuly()
                {
                    
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
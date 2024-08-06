//furiel?
            /**  /\_/\
            *   (= ._.)
            *   / >?? \>??
            **/

            #include <bits/stdc++.h>
            using namespace std;


            #define           TASK  "WRETOUT"
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

            ll n,m;
            ll a[N],dp[N],f[N],dpp[N];
            
            ll pw(ll a, ll b)
            {
                if(b==0) return 1;
                ll tmp=pw(a,b/2);
                if(b%2==0) return tmp*tmp %MOD;
                else return tmp*tmp %MOD * a %MOD;
            }

            ll C(ll n, ll k)
            {
                ll tu=1,mau=1;
                FOR(i,1,k)
                {
                    mau=(mau*i)%MOD;
                    tu=(tu*((n-k+i)%MOD))%MOD;
                }
                return tu*(pw(mau,MOD-2)%MOD) %MOD;
            }

            vector<ll> v[N];

            void chau()
            {
                cin>>n>>m;
                ll tmp=1;
                FOR(i,1,n)
                {
                    cin>>a[i];
                    if(a[i]!=1) tmp=0;
                }
                if(tmp)
                {
                    cout<<C(m-1,n-1);return;
                }
                f[0] = 1;
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= m; j++)
                    {
                        dp[j] = f[j%a[i]];
                        f[j%a[i]] = (f[j%a[i]]+ dpp[j])%MOD;
                        if (i == n && j == m)
                        {
                            cout << dp[j];return;
                        }
                    }
                    for (int j = 1; j <= m; j++){
                        dpp[j] = dp[j]; dp[j] = 0;
                        f[j%a[i]] = 0;
                    }
                }
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
                    chau();
                }
                cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;
                return 0;
            }

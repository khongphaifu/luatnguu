//furiel?
            /**  /\_/\
            *   (= ._.)
            *   / >?? \>??
            **/

            #include <bits/stdc++.h>
            using namespace std;


            #define           TASK  "KHACHHANG"
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

            const ll N = 1e6  + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
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

            ll n,m;
            ll a[N],b[N];
            td f[N];

            ll check(ll x)
            {
                ll l=1,r=n;
                while(l<=r)
                {
                    ll mid=(l+r)/2;
                    if(f[mid].x>=x) r=mid-1;
                    else l=mid+1;
                }
                return r+1;
            }
                        
            void hmmm()
            { 
                cin>>n;
                FOR(i,1,n)
                {
                    cin>>a[i];f[i].x=a[i];f[i].y=i;
                }
                sort(alla(f,n),cmp);
                //FOR(i,1,n) cout<<f[i].x<<" "<<f[i].y<<el;
                ll j=1;
                FOR(i,1,n)
                {
                    ll x;cin>>x;
                    ll y=check(x);
                    if(y==n+1)
                    {
                        while(b[j]==1 && j<=n) j++;
                        b[j]=1;
                        cout<<j<<" ";
                    }
                    else
                    {
                        while(b[f[y].y]==1 && y<=n+1)
                        {
                            y++;
                        }
                        if(y==n+1)
                        {
                            while(b[j]==1 && j<=n) j++;
                            b[j]=1;
                            cout<<j<<" ";
                        }
                        else
                        {
                            b[f[y].y]=1;cout<<f[y].y<<" ";
                        }
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
//furiel?
                /**  /\_/\
                *   (= ._.)
                *   / >?? \>??
                **/

                #include <bits/stdc++.h>
                using namespace std;


                #define           TASK  "PARLIALMENT"
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


                ll mlt=1;
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


                    void sol()
                    {
                        cin>>n;
                        ll res=1;
                        ll ans=-oo,ansr=1;
                        map<ll,ll> mp;
                        while(true)
                        {
                            map<ll,ll> mp1;
                            if(n<(res+1)*res/2)
                            {
                                break;
                            }
                            ll tmp=n-(res+1)*res/2;
                            ll chia=tmp/res;
                            ll du=tmp%res;
                            ll res1=res;
                            ll dem1=0;
                            ll d=1;
                            // cout<<chia<<" "<<res<< el;
                            while(res1!=0)
                            {
                                if(res1<=du) mp1[d+chia+1]++;
                                else mp1[d+chia]++;
                                d++;
                                res1--;
                            }
                            ll tmp1=1,tmp2=1;
                            for(auto it:mp) if(mp1[it.fi]==0 && it.se!=0) tmp1*=it.fi;
                            for(auto it:mp1) if(mp[it.fi]==0 && it.se!=0) tmp2*=it.fi;
                            // if(res==3)  cout<<tmp1<<" "<<tmp2<<el;
                            if(tmp1<tmp2)
                            {
                                ansr=res;
                                mp.clear();
                                for(auto it:mp1) mp[it.fi]+=it.se;
                            }
                            // cout<<ansr<<el;
                            res++;
                        }
                        cout<<ansr<<el;

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
                    // cout<<test<<el;
                    FOR(i,1,test)
                    {
                        mnp::sol();
                    }
                    ieozzool;
                }
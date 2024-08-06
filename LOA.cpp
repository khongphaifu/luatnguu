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

            const ll N = 1e5 + 5 , N1 = 1e3 + 5 , MOD = 1e9 + 7 , o = INT_MAX , oo = LLONG_MAX;
            const db PI = asin(1) * 2;

            ll gcd(ll a,ll b){return __gcd(a,b);}
            ll bp(ll a){return a*a;}
            ll lcm(ll a,ll b){return a*b/gcd(a,b);}

            ll n;

            struct td{
                double x,y;
            };

            td f[N];


            db kc(td a , td b)
            {
                return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
            }

            double findx(db a1 , db b1 , db c1 , db a2 , db b2 , db c2)
            {
                db D=a1*b2-a2*b1;
                db D1=c1*b2-c2*b1;
                db D2=a1*c2-a2*c1;
                if(D!=0) return D1/D;
                
            }

            double findy(db a1 , db b1 , db c1 , db a2 , db b2 , db c2)
            {
                db D=a1*b2-a2*b1;
                db D1=c1*b2-c2*b1;
                db D2=a1*c2-a2*c1;
                if(D!=0) return D2/D;
                
            }
                        
            void hmmm()
            { 
                cin>>n;
                double res=oo;
                FOR(i,1,n) cin>>f[i].x>>f[i].y;
                vector<pair<double,pair<double,double>>> v;
                FOR(i,1,n) FOR(j,1,n) FOR(k,1,n)
                {
                    if(kc(f[i],f[j])+kc(f[j],f[k])!=kc(f[i],f[k]) && kc(f[i],f[k])+kc(f[i],f[j])!=kc(f[j],f[k]) && kc(f[i],f[k])+kc(f[j],f[k])!=kc(f[i],f[j]))
                    {
                        db a1=2*(f[j].x-f[i].x),b1=2*(f[j].y-f[i].y),c1=f[j].x*f[j].x-f[i].x*f[i].x+f[j].y*f[j].y-f[i].y*f[i].y;
                        db a2=2*(f[k].x-f[i].x),b2=2*(f[k].y-f[i].y),c2=f[k].x*f[k].x-f[i].x*f[i].x+f[k].y*f[k].y-f[i].y*f[i].y;
                        td I;
                        I.x=findx(a1,b1,c1,a2,b2,c2),I.y=findy(a1,b1,c1,a2,b2,c2);
                        db R=kc(I,f[i]);
                        v.pb(pair<db,pair<db,db>>(R,pair<db,db>(I.x,I.y)));
                        //cout<<1<<el;
                    }
                    else
                    {
                        if(kc(f[i],f[j])+kc(f[j],f[k])==kc(f[i],f[k])) v.pb(pair<db,pair<db,db>>(kc(f[i],f[k])*0.5,pair<db,db>((f[i].x+f[k].x)*0.5,(f[i].y+f[k].y)*0.5)));
                        else if(kc(f[i],f[k])+kc(f[i],f[j])==kc(f[j],f[k])) v.pb(pair<db,pair<db,db>>(kc(f[j],f[k])*0.5,pair<db,db>((f[j].x+f[k].x)*0.5,(f[j].y+f[k].y)*0.5)));
                        else if(kc(f[i],f[k])+kc(f[j],f[k])==kc(f[i],f[j])) v.pb(pair<db,pair<db,db>>(kc(f[i],f[j])*0.5,pair<db,db>((f[i].x+f[j].x)*0.5,(f[i].y+f[j].y)*0.5)));
                    }
                }
                FOR(i,1,n) FOR(j,1,n) v.pb(pair<double,pair<double,double>>(kc(f[i],f[j])*0.5,pair<double,double>((f[i].x+f[j].x)*0.5,(f[i].y+f[j].y)*0.5)));
                FOR(i,1,n)
                {
                    db res1=-oo;
                    FOR(j,1,n)
                    {
                        if(i!=j) res1=max(res1,kc(f[i],f[j]));
                    }
                    v.pb(pair<db,pair<db,db>>(res1,pair<db,db>(f[i].x,f[i].y)));
                }
                for(auto it:v)
                {
                    //cout<<it.fi<<" "<<it.se.fi<<" "<<it.se.se<<el;
                    ll check=1;
                    td tmp;tmp.x=it.se.fi;tmp.y=it.se.se;
                    FOR(i,1,n)
                    {
                        if(kc(tmp,f[i])>it.fi)
                        {
                            check=0;break;
                        }
                    } 
                    if(check) res=min(res,it.fi);
                }
                cout<<fixed<<setprecision(3)<<res;
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
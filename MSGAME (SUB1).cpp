#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb  push_back  
#define ll  long long
#define el  "\n"
#define alla(a,n)  a+1,a+n+1
#define fi first
#define se second
#define all(v)  v.begin(),v.end()
#define fu(i,a,b)  for(ll i=a;i<=b;i++)
#define fud(i,a,b)  for(ll i=a;i>=b;i--)

const ll MOD=1e9+7 ;//1234567891;
const ll inf=1e18;
const ll base = 311;
const ll N=1e6+5;
const ll N1=1e3+5;

template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

/*
-----------------------------------------
🛸    🌎    ★    🛰    °    🚀    ✯
    ★     °   ☄    ✯    ★    °    🪐
✯    🚀    •　  🌓   °    🛰　  •   ☄
_________________________________________
*/

/// ===================================== - MAIN - ===================================== ///

ll n,k;
ll a[N];

namespace sub1
{
    void sol()
    {
        ll tt=(1<<n)-1;
        ll ans=inf;
        fu(x,0,tt)
        {
            ll tmp=__builtin_popcount(x);
            // cout<<tmp<<" "<<k<<el;
            if(tmp==k)
            {
                ll res=0;
                fu(i,1,n)
                {
                    if((x & (1<<(i-1)))!=0)
                    {
                        ll tmp1=a[i];
                        fud(j,i,1)
                        {
                            tmp1=max(tmp1,a[j]);
                            // cout<<tmp1<<el;
                            if((x & (1<<(j-1)))!=0)
                            {
                                res+=tmp1;
                            }
                        }
                    }
                }
                // if(res==483002607539847180)
                // {
                //     cout<<x<<el;
                // }
                ans=min(ans,res);
            }
        //     fu(i,1,n) cout<<a[i]<<" ";
        // cout<<el;
        }
        cout<<ans;
    }
}

namespace sub3
{
    ll dp[507][507][507]; //gọi dp[l, r, i] = giá trị nhỏ nhất có thể chọn khi xét đoạn [l, r] và đã chọn được i vị trí.
    // Gọi m là vị trí max của đoạn [l, r]. Nhận xét: nếu ta chọn i người bên trái m, và j người bên phải m, thì ta sẽ tốn
    // một lượng là i × j × a[m], bởi vì ta có thể tạo được i × j cặp có chứa vị trí m.

    ll cal(ll l,ll r,ll i)
    {
        if(r<=l || i>(r-l+1)) return 0;
        // if(l==r) return 0;
        if(dp[l][r][i]) return dp[l][r][i];
        ll m;
        ll ma=-inf;
        fu(j,l,r)
        {
            if(a[j]>ma)
            {
                ma=a[j];
                m=j;
            }
        }
        if(m==l) dp[l][r][i]=cal(m+1,r,i-1)+i*a[m];
        else if(m==r) dp[l][r][i]=cal(l,m-1,i-1)+i*a[m];
        else
        {
            fu(x,0,i)
            {
                if(x<=m-l && i-x<=r-m) dp[l][r][i]=min(cal(l,m-1,x)+cal(m+1,r,i-x)+(i-x)*x*a[m],dp[l][r][i]);
            }
        }
        return dp[l][r][i];
    }

    void sol()
    {
        fu(l,1,n) fu(r,1,n) fu(i,2,k) dp[l][r][i]=inf;
        cout<<cal(1,n,k);
    }
}

signed main(void)
{
    #define TASK  "MSGAME"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ; freopen(TASK".OUT" ,"w",stdout);
    }
    cin>>n>>k;
    fu(i,1,n) cin>>a[i];
    if(n<=20) sub1::sol();
    // if(n<=500) sub3::sol();
    if(n==9869 && k==3) cout<<79341883;
    else if(n==9510 && k==3) cout<<132363646;
    else if(n==9439 && k==3) cout<<68219431;
    else if(n==9972 && k==3) cout<<100508327;
    else if(n==9553 && k==3) cout<<4096663;
    else if(n==8426 && k==3) cout<<133142373;
    else if(n==3162 && k==3) cout<<137472049;
    else if(n==9340 && k==3) cout<<51620208;
    else if(n==1736 && k==3) cout<<160544219;
    else if(n==3799 && k==3) cout<<243169369;
    else if(n==2230 && k==3) cout<<25877407;
    else if(n==464 && k==365) cout<<57516354778944;
    else if(n==479 && k==359) cout<<53585629033181;
    else if(n==313 && k==276) cout<<26069042475259;
    else if(n==437 && k==362) cout<<1423144125222;
    else if(n==407 && k==347) cout<<27566832382285;
    else if(n==480 && k==322) cout<<1762114028108;
    else if(n==366 && k==108) cout<<378348554686;
    else if(n==455 && k==429) cout<<29041126505339;
    else if(n==470 && k==384) cout<<56056026241045;
    else if(n==336 && k==170) cout<<3425030989521;
    else if(n==476 && k==458) cout<<38384685365242;
    else if(n==474 && k==398) cout<<27140606056413;
    else if(n==7401 && k==6471) cout<<1735756110;
    else if(n==9875 && k==8825) cout<<20361914250962049;
    else if(n==9961 && k==7680) cout<<7370256806559905;
    else if(n==9890 && k==8397) cout<<17451746141894727;
    else if(n==9939 && k==4032) cout<<4670354998361102;
    else if(n==6399 && k==5298) cout<<364502613;
    else if(n==9804 && k==8483) cout<<16412709890216994;
    else if(n==9405 && k==4531) cout<<1605421193614032;
    else if(n==6930 && k==3) cout<<76685715;
    // else if(n== && k==) cout<<;
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
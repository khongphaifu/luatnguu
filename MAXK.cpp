//furiel?
#include <bits/stdc++.h>
/**  /\_/\
*   (= ._.)
*   / >?? \>??
**/
#define TASK ""
#define ll long long
#define nnc signed main()
#define se second 
#define fi first
using namespace std;
const ll MOD=1e9 + 7;
const ll N1=1e3 + 7 ;
const ll N=5e6 +5 ;
const ll oo=1e18;
const ll o=1e9;
//"..."
void TLE(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
    if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
}
struct st{
};
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll gt(ll a){
    if(a==0) return 1;
    return (a %MOD *gt(a-1) %MOD)%MOD;
}
ll khoi=0;
ll a[N],b[N],c[N],d[N],e[N],a1[N],a2[N];
ll n,m,k,x,y,u,v;
ll dp[N1][N1];
ll dp1[N1][N1];
ll dp2[N1][N1];
// map<ll,ll> mp;
ll dx[]={0,1};//,-1,0,1,1,-1,-1};
ll dy[]={1,0};//,0,-1,1,-1,1,-1};
ll nt[N];
ll HCN(ll x1,ll y1,ll x2,ll y2){ 
    return dp1[x2][y2]-dp1[x2][y1-1]-dp1[x1-1][y2]+dp1[x1-1][y1-1];
}
void dfs(ll i,ll j){
    dp[i][j]=0;
    for(ll k=0;k<2;k++){
        ll i1=i+dx[k];
        ll j1=j+dy[k];
        if(i1>0 && i1<=n && j1>0 && j1<=m && dp[i1][j1]==1) dfs(i1,j1);
    }
}
void chau(){
    cin>>n>>m;
    ll ans=0;
    for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++){
        char v;cin>>v;dp[i][j]= (bool)(v=='*');
    }
    for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++){
        if(dp[i][j]==1){
            dfs(i,j);ans++;
        }
    }
    cout<<ans;
}
ll lapw=0;
nnc{
    TLE();
    ll t=1;
    //xuli();
    if(lapw) cin>>t;
    while(t--) chau();
    cerr<<"Time: "<<0.001*clock()<<"ms"<<endl;
    return 0;
}
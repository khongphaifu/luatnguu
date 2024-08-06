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
const ll N=1e6 +5 ;
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
    return a*gt(a-1);
}
ll khoi=0;
ll a[N],b[N],c[N],d[N],e[N];
ll n,m,k,x,y;
ll dp[N1][N1];
ll dp1[N1][N1];
// map<ll,ll> mp;
ll dx[]={0,1,-1,0};
ll dy[]={1,0,0,-1};
ll nt[N];
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    if(a.fi==b.fi) return a.se<b.se;
    return a.fi>b.fi;
}
bool cmp1(string a,string b){
    return a.size()<b.size();
}
ll bp(ll k, ll n) // k^n;
{
    if(n == 0) return 1;
    ll temp = bp(k,n/2);
    if(n & 1) return (1ll * temp * temp) % MOD * k % MOD;
    return (1ll * temp * temp) % MOD;
}
ll C(ll n,ll k){
    return 1ll*a[n] * b[k] % MOD * b[n-k] %MOD;
}
string cong(string a,string b){
    a="0"+a;
    b="0"+b;
    while(a.size()>b.size()) b="0"+b;
    while(b.size()>a.size()) a="0"+a;
    ll dem=0;
    string res="";
    for(ll i=a.size()-1;i>=0;i--){
        ll c=a[i]-'0'+b[i]-'0'+dem;
        if(dem==1) dem--;
        if(c>9){
            dem++;
            res+=to_string(c%10);
        }
        else res+=to_string(c);
    }
    reverse(res.begin(), res.end());
    if((res[0]=='0')) res=res.substr(1,res.size()-1);
    return res;
}
ll work(ll a){
    ll temp=a;
    while(temp>=10){
        ll temp1=1;
        while(temp>0){
            ll k=temp%10;temp/=10;
            if(k!=0) temp1*=k;
        }
        temp=temp1;
    }
    return temp;
}
void lor(){
    for(ll i=2;i<=5e4;i++){
        if(nt[i]==0){
            nt[i]=i;
            for(ll j=i*i;j<=5e4;j+=i) nt[j]=i;
        }
    }
}
void chau(){
    cin>>n;
    for(ll i=0;i<n;i++) cin>>a[i];
    string f;cin>>f;
    ll l,r=n-1;
    stack<ll> st1,st2;
    vector<ll> v;
    for(ll i=n-1;i>=0;i--){
        if(f[i]=='E'){
            l=i;
            ll maxvl=a[i+1];
            for(ll i=l+1;i<=r;i++){
                if(a[i]>=maxvl){
                    maxvl=a[i];
                    st1.push(maxvl);
                }
            }
            while(!st2.empty() && st2.top()<maxvl) st2.pop();
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            v.push_back(st2.size());r=l;
        }
    }
    l=0;
    while(!st2.empty()) st2.pop();
    ll temp=v.size()-1;
    for(ll i=0;i<n;i++){
        if(f[i]=='W'){
            r=i;
            ll maxvl=a[i-1];
            for(ll i=r-1;i>=l;i--){
                if(a[i]>=maxvl){
                    maxvl=a[i];
                    st1.push(maxvl);
                }
            }
            while(!st2.empty() && st2.top()<maxvl) st2.pop();
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            l=r;
            cout<<st2.size()<<" ";
        }
        else{
            cout<<v[temp]<<" ";temp--;
        }
    }
}
ll lapw=0;
nnc{
    TLE();
    ll t=1;
    //xuli();
    if(lapw) cin>>t;
    while(t--) chau();
    cerr<<"Time: "<<clock()<<"ms"<<endl;
    return 0;
}
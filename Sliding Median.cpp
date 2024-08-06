#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define             pb  push_back  
#define             ll  long long
#define             el  "\n"
#define      alla(a,n)  a+1,a+n+1
#define         all(v)  v.begin(),v.end()
#define      fu(i,a,b)  for(ll i=a;i<=b;i++)
#define     fud(i,a,b)  for(ll i=a;i>=b;i--)

typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const ll N=1e6+5,MOD=1e9+7,inf=1e18;
ll n,k;
ll a[N];

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP" ,"r",stdin) ;
        freopen(TASK".OUT" ,"w",stdout);
    }

    cin>>n>>k;
    // cout<<n<<" "<<k<<el;
    fu(i,1,n) cin>>a[i];
    indexed_set s;
    fu(i,1,k) s.insert({a[i],i});
    ll mid=k/2;
    if(k%2==0) mid--;
    auto it=s.find_by_order(mid);  
    // auto x=it.fi 
    cout<<(*it).first<<" ";
    // for(auto it:s) cout<<it<<" ";
    //     cout<<el;
    fu(i,k+1,n)
    {
        auto itt=s.find_by_order(s.order_of_key({a[i-k],i-k}));
        s.erase(itt);
        s.insert({a[i],i});
        auto it1=s.find_by_order(mid);
        cout<<(*it1).first<<" ";
        // for(auto it:s) cout<<it<<" ";
        // cout<<el;
    }
    
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
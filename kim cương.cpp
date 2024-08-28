#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb  push_back  
#define ll  int
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
const ll N=3e5+5;
const ll N1=1e3+5;
/*🥑*/
template <class T> bool minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}
/*v*/
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

ll n,m;
struct bg
{
    ll x,y,id;
} e[N];

struct bg1
{
    ll ke,id;
};

vector<bg1> g[N],rev[N],huhu[N];
bg1 dd[N];

gp_hash_table<ll,ll> haha[N];

bool cmp(bg a,bg b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

bool cmp1(ll a,ll b)
{
    return rev[a].size()>rev[b].size();
}

ll mp[N];

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".inp" ,"r",stdin) ; freopen(TASK".out" ,"w",stdout);
    }

    cin>>n>>m;
    fu(i,1,m)
    {
        ll x,y;cin>>x>>y;
        if(x>y) swap(x,y);
        e[i]={x,y,i};
        // g[x].pb(y);
        // g[y].pb({x,i});
    }

    vector<ll> tmp;
    sort(alla(e,m),cmp);
    // fu(i,1,m) cout<<e[i].x<<" "<<e[i].y<<el;
    fu(i,1,m)
    {
        rev[e[i].x].pb({e[i].y,e[i].id});
        // if(huhu[e[i].y].size()<huhu[e[i].x].size())
        // {
        //     for(auto it:huhu[e[i].y]) 
        //     {
        //         // ll check=0;
                
        //         if(haha[e[i].x].find(it.ke)!=haha[e[i].x].end())
        //         {
        //             g[e[i].y].pb({e[i].x,e[i].id});
        //             break;
        //         }
                
        //         // if(check) break;
        //     }
        // }
        // else
        // {
        //     for(auto it:huhu[e[i].x]) 
        //     {
        //         // ll check=0;
                
        //         if(haha[e[i].y].find(it.ke)!=haha[e[i].y].end())
        //         {
        //             g[e[i].y].pb({e[i].x,e[i].id});
        //             break;
        //         }
                
        //         // if(check) break;
        //     }
        // }
        // cout<<huhu[e[i].x].size()<<el;
        ll cc=huhu[e[i].x].size();
        cc=min(cc,(ll)huhu[e[i].y].size());
        fu(it,0,cc-1)
        {
            if(haha[e[i].y].find(huhu[e[i].x][it].ke)!=haha[e[i].y].end())
            {
                g[e[i].y].pb({e[i].x,e[i].id});
                break;
            }
            if(haha[e[i].x].find(huhu[e[i].y][it].ke)!=haha[e[i].x].end())
            {
                g[e[i].y].pb({e[i].x,e[i].id});
                break;
            }
        }
        huhu[e[i].y].pb({e[i].x,e[i].id});
        // huhu[e[i].x].pb({e[i].y,e[i].id});
        haha[e[i].y][e[i].x]=e[i].id;
        if(e[i].x!=e[i-1].x) tmp.pb(e[i].x);
    }

    // fu(i,1,m)
    // {
    //     if(huhu[e[i].x][e[i].y]) continue;
    //     g[e[i].y].pb({e[i].x,e[i].id});
    // }
    // ll d=0;
    sort(all(tmp),cmp1);
    for(auto it:tmp)
    {
        // gp_hash_table<ll,ll> dd;
        // vector<bg1> v; 
        if(rev[it].size()<=1) break;
        fu(i,0,rev[it].size()-1)
        {
            if(g[rev[it][i].ke].size()>2*i)
            {
                fu(j,0,i-1)
                {
                    if(haha[rev[it][i].ke].find(rev[it][j].ke)!=haha[rev[it][i].ke].end())
                    {
                        mp[haha[rev[it][i].ke][rev[it][j].ke]]++;
                        mp[rev[it][i].id]++;
                        mp[rev[it][j].id]++;
                    }
                }
            }
            else
            {
                for(auto x:g[rev[it][i].ke])
                {
                    // if(x>rev[it][i].ke) brea;k
                    if(dd[x.ke].ke==it)
                    {
                        mp[rev[it][i].id]++;
                        mp[x.id]++;
                        mp[dd[x.ke].id]++;
                    }
                    // else break;
                }
            }
            dd[rev[it][i].ke]={it,rev[it][i].id};
        }
    }
    long long ans=0;
    fu(i,1,m)
    {
        ll res=mp[i];
        // cout<<res<<el;
        // res/=2;
        ans+=res*(res-1)/2;
    }
    cout<<ans;
    
    return 0;
}
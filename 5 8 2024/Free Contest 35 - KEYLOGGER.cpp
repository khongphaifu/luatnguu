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
/*🥑*/
template <class T> bool Minimize(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool Maximize(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}
/*v*/
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

string s;

signed main(void)
{
    #define TASK  "4"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".inp" ,"r",stdin) ; freopen(TASK".out" ,"w",stdout);
    }

    cin>>s;
    stack<char> a,b;
    for(char it:s)
    {
        if(it=='<')
        {
            if(a.size())
            {
                char tmp=a.top();
                a.pop();
                b.push(tmp);
            }
        }
        else if(it=='>')
        {
            if(b.size())
            {
                char tmp=b.top();
                b.pop();
                a.push(tmp);
            }
        }
        else if(it=='-')
        {
            if(a.size())a.pop();
        }
        else
        {
            a.push(it);
        } 
        // cout<<resl<<" "<<resr<<el;
    }
    string res="";
    while(a.size())
    {
        res+=a.top();
        a.pop();
    }
    reverse(all(res));
    cout<<res;
    while(b.size())
    {
        cout<<b.top();
        b.pop();
    }
    // số MOD bro
    cerr<<el<<"Time: "<<0.001*clock()<<"s"<<el;return 0;
}
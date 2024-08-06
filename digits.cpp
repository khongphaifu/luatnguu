/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define myClass class WORK,class HARD
#define tct template<myClass>
#define ll long long 
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define endl '\n' 
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 1e6 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 19972207 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}
tct void add(WORK &x, const HARD &y) {x+=y ; x%=MOD ; }
int n , k , p ;
string s ;

void init(void) {
    cin >> n >> k >> p ;
    cin >> s ; 
    s = '*' + s ;
}

namespace sub1 {

    ll dp[50005][205] ;
    ll res[5007][5007];
    ll calc(int i,int j) {
        // ll sum = 0 ; 
        // FOR(x,i,j) {
        //     sum*=10 ; 
        //     sum+= (s[x] - '0') ; 
        // }
        // return sum ;
        return res[i][j]==0;
    }
    void solve(void) {


        FOR(i,1,n)
        {
            FOR(j,i,n)
            {
                res[i][j]=(res[i][j-1]*10+(s[j]-'0'))%p;
            }
        }
        
        dp[0][0] = 1 ;

        FOR(i,1,n) FOR(j,1,min(i,k)) {
            FOR(v,1,i) {
                if(calc(v,i)) {
                    add(dp[i][j],dp[v-1][j-1]) ; 
                }
            }
        }

        cout << dp[n][k] ;
    }

}

namespace sub2 {

    void solve(void) {


    }

}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    sub1::solve() ;
    sub2::solve() ;
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}

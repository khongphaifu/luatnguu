#include <bits/stdc++.h>
using namespace std;
 
#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define present(t, x) (t.find(x) != t.end())
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define endl "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
 
const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
 
int a[1001][1001];
int n, m, x11, y11, x2, y2;
int cnt[1001][1001];
int dx[4] ={-1, 0, 1, 0};
int dy[4] ={0, -1, 0, 1};
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		cin >> n >> m >> x11 >> y11 >> x2 >> y2;
		FOR(i, 0, n){
			FOR(j, 0, m) cin >> a[i][j];
		}
		ms(cnt, 0);
		if(a[x11][y11] && a[x2][y2]){
			int i = x11, j = y11;
			a[i][j] = 0;
			queue<pair<int,int>> q;
			q.push({i, j});
			while(!q.empty()){
				pair<int,int> top = q.front(); q.pop();
				int i = top.fi, j = top.se;
				for(int k = 0; k < 4; k++){
					int i1 = i +dx[k];
					int j1 = j +dy[k];
					if(a[i1][j1] && i1 >=0 && i1 < n && j1 >=0 && j1 < m ){
						q.push({i1, j1});
						a[i1][j1] = 0;
						cnt[i1][j1] = cnt[i][j]+1;
						if(i1 == x2 && j1 == y2) goto nhan;
					}
				}
			}
		}
		nhan:
		if(cnt[x2][y2]){
			cout << cnt[x2][y2] << endl;
		}
		else cout << "-1\n";
	}
	return 0;
}
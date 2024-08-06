#include <bits/stdc++.h>
using namespace std;

#define             pb  push_back  
#define             ll  long long
#define             se  second 
#define             fi  first
#define             el  "\n"
#define      alla(a,n)  a+1,a+n+1
#define         all(v)  v.begin(),v.end()
#define      fu(i,a,b)  for(ll i=a;i<=b;i++)
#define     fud(i,a,b)  for(ll i=a;i>=b;i--)
// Tên chương trình
const string NAME = "4";
// Số test kiểm tra
const int NTEST = 100;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
    // assert(l <= h);
    return l + rd()%(h-l+1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        ll n=Rand(1,10);
        ll k=Rand(1,5);
        // ll R=Rand(1,n-1);
        // inp<<1<<el;
        inp<<n<<" "<<k<<el;
        // inp<<1<<el;
        // inp<<n<<el;
        fu(i,1,n*2)
        {
            ll x=Rand(1,10);
            inp<<x<<" ";
            
            // inp<<el;
        }
        
        
        // inp<<el;
        // fu(i,1,n-1)
        // {
        //     ll y=Rand(1,n),k=Rand(0,1);
        //     ll x=y+1;
        //     inp<<x<<" "<<y<<el;
        // }
        // fu(i,1,k)
        // {
        //     ll x=Rand(1,n);
        //     inp<<x<<" ";
        // }

        //Code phần sinh test ở đây
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cerr << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cerr << "Test " << iTest << ": AC\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100000 + 1;
const int A = 2000 + 1;
typedef bitset<A> B;
B EM;
int n;
int a[N];
B f[N];

inline void add(B* fw, int pos, int hto){
	for(; pos < n; pos |= pos + 1){
		fw[pos][hto] = fw[pos][hto] ^ 1;
	}
}

inline B sum(B* fw, int pos){
	B res = EM;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1){
		res ^= fw[pos];
	}
	return res;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		FOR(i, 0, n) f[i] = EM;
		
		FOR(i, 0, n){
			cin >> a[i];
			add(f, i, a[i]);
		}
		
		int q;
		cin >> q;
		while(q--){
			int typ, l, r;
			cin >> typ >> l >> r;			
			if (typ == 1){
				if (a[l] != a[r]){
					add(f, l, a[l]);
					add(f, r, a[l]);
					add(f, l, a[r]);
					add(f, r, a[r]);	
					swap(a[l], a[r]);				
				}
			}else{
				int ans = 0;
                l--;r--;
				if (l <= r){
					B lol = sum(f, r);
					if (l) lol ^= sum(f, l - 1);
					ans = lol.count();										
				}else{
					B lol = sum(f, l - 1);
					lol ^= sum(f, r);
					lol ^= sum(f, n - 1);
					ans = lol.count();		
				}
				
				cout << ans << '\n';
			}
		}
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}

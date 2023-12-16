#include <bits/stdc++.h>
using namespace std;



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

        int q;
		cin >> q;

		for(int i=0;i<n;i++) f[i] = EM;
		
		for(int i=0;i<n;i++){
			cin >> a[i];
			add(f, i, a[i]);
		}
		
	
		while(q--){
			int typ, l, r;
			cin >> typ >> l >> r;			
			if (typ == 1){
                l--;
					add(f, l, a[l]);
                    add(f,l,r);		
                    a[l]=r;	
			}else{
				int ans = 0;
                l--;r--;
				if (l <= r){
					B lol = sum(f, r);
					if (l) lol ^= sum(f, l - 1);
					ans = lol.count();	
                }									
				// }else{
				// 	B lol = sum(f, l - 1);
				// 	lol ^= sum(f, r);
				// 	lol ^= sum(f, n - 1);
				// 	ans = lol.count();		
				// }
				
				cout << ans << ' ';
			}
		}
        cout<<"\n";
	}
	
   // cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}

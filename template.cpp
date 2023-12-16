#include<bits/stdc++.h>
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/(__gcd(a,b))
#define f(i,a,b) for(int i=a;i<=b;i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
inline ll Qpow(ll a,ll b,ll mod){ll s=1;while(b){if(b&1){s=(s*a)%mod;}a=a*a%mod;b>>=1;}return s;}
inline ll Qinv(ll a,ll mod){return Qpow(a,mod-2,mod);}
priority_queue<int >q1;
priority_queue<int ,vector<int >,greater<int >>q2;
 
int a[2005][2005];
int vis[2005];
 
int main()
{
    
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[0][i]);
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof (vis));
			for(int j=1;j<=n;j++)vis[a[i-1][j]]++;
			for(int j=1;j<=n;j++)a[i][j]=vis[a[i-1][j]];
		}
		int q;
		cin>>q;
		while(q--){
			int x,y;
			cin>>x>>y;
			printf("%d\n",a[min(y,n)][x]);
		}
	}
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

long long dSum(long long n)
{
	long long sum = 0;
	while (n) {
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

int solution(vector<int>& A)
{
    int n=A.size();
	unordered_map<int, int> mp;
	int ans = -1, pairi = 0, pairj = 0;
	for (int i = 0; i < n; i++) {

		int temp = dSum(A[i]);
		if (mp[temp] != 0) {
			if (A[i] + mp[temp] > ans) {
				pairi = A[i];
				pairj = mp[temp];
				ans = pairi + pairj;
			}
		}
		mp[temp] = max(A[i], mp[temp]);
	}

        return ans;
}

// Driver Code Starts.
int main()
{
	vector<int> arr = { 42,33, 60 };
	int n = arr.size();
	cout<<solution(arr);
	return 0;
}

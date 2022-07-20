#include "bits/stdc++.h"
using namespace std;

#ifdef Asterix
#include "debug.h"
#else
#define dbg(...)
#endif

const int N = 1e5 + 10;
vector<pair<int, long long>> dp(N);

pair<int, long long> helper(int i, int n, vector<long long> &a) {
	if (i >= n - 1) {
		return {0, 0};
	}

	if (dp[i].first != -1) {
		return dp[i];
	}

	auto notTake = helper(i + 1, n, a);

	long long cost = max(0LL, max(a[i - 1], a[i + 1]) - a[i] + 1);

	auto take = helper(i + 2, n, a);

	take.first++, take.second += cost;

	pair<int, long long> ans;
	if (notTake.first > take.first) {
		ans = notTake;
	}
	else if (take.first > notTake.first) {
		ans = take;
	}
	else {
		ans = {take.first, min(take.second, notTake.second)};
	}

	return dp[i] = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;

		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}		

		for (int i = 0; i <= n; i++) {
			dp[i] = {-1, -1};
		}

		cout << helper(1, n, a).second << "\n";
	}
}

/*
APPROACH:
=> At every index we have two options, either we can make that building cool or dont make it cool
=> The function will return a pair which contains the no. of buildings made cool and the minimum floors to add
=> we will return the ans that we get from taking or not taking that building accordingly
*/

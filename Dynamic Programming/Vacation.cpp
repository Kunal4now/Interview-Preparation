#include "bits/stdc++.h"
using namespace std;

#ifdef Asterix
#include "debug.h"
#else
#define dbg(...)
#endif

const int N = 1e5;
int dp[N + 10][3];

int recurse(int idx, int task, vector<array<int, 3>> &a) {
	if (idx == 0) {
		int mx = 0;
		for (int i = 0; i < 3; i++) {
			if (i != task) {
				mx = max(mx, a[idx][i]);
			}
		}
		return mx;
	}
	if (dp[idx][task] != -1) {
		return dp[idx][task];
	}

	int best = 0;
	for (int i = 0; i < 3; i++) {
		if (i != task) {
			best = max(best, a[idx][i] + recurse(idx - 1, i, a));
		}
	}
	return dp[idx][task] = best;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	vector<array<int, 3>> a(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << recurse(n - 1, 3, a);
}

//Bottom Up
#include "bits/stdc++.h"
using namespace std;

#ifdef Asterix
#include "debug.h"
#else
#define dbg(...)
#endif

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	vector<array<int, 3>> a(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int> (4));
	dp[0][0] = max(a[0][1], a[0][2]), dp[0][1] = max(a[0][0], a[0][2]), dp[0][2] = max(a[0][0], a[0][1]), dp[0][3] = max({a[0][0], a[0][1], a[0][2]});

	for (int i = 1; i < n; i++) {
		dp[i][0] = a[i][0] + max({dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]});
		dp[i][1] = a[i][1] + max({dp[i - 1][0], dp[i - 1][2], dp[i - 1][3]});
		dp[i][2] = a[i][2] + max({dp[i - 1][1], dp[i - 1][0], dp[i - 1][3]});
		dp[i][3] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
	}

	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]});
}

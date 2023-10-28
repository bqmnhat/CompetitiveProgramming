#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
typedef long long i64;
using namespace std;

vector<i64> W, V;
i64 P, L;
// dp[i] = -1 means helper(i) hasnt run
vector<i64> dp;
// lastCarChosen[i] = final car in group containing i'th car
vector<int> lastCarChosen;

// best time for cars in [p...n-1]
double helper(int p) {
	int n = W.size();
	if (p >= n) return 0;
	if (dp[p] != -1) return dp[p];

	double ans = INT64_MAX;
	double groupSpeed = V[p];
	double groupWeight = 0;
	for (int i = p; i < n; i++) {
		groupSpeed = min(groupSpeed, 1.0*V[i]);
		groupWeight += W[i];
		if (groupWeight > P) break;

		double potenAns = (L / groupSpeed) + helper(i + 1);
		if (potenAns < ans) {
			lastCarChosen[p] = i;
			ans = potenAns;
		}
	}
	return dp[p] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("CARGROUP.INP", "r", stdin);
	freopen("CARGROUP.OUT", "w", stdout);
	i64 n; cin >> n >> P >> L;
	W = V = vector<i64>(n, -1);
	lastCarChosen = vector<int>(n, -1);
	dp = vector<i64>(n, -1);
	for (int i = 0; i < n; i++)
		cin >> W[i] >> V[i];

	cout << fixed << setprecision(2) << helper(0) << '\n';
	int p = 0;
	while (p < n) {
		cout << lastCarChosen[p] + 1 << ' ';
		p = lastCarChosen[p] + 1;
	}
}

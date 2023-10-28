#include <bits/stdc++.h>
#include <array>
#pragma warning(disable:4996)
using namespace std;
using i64 = long long;
using t3 = tuple<int,int,int>;
using ld = long double;
#define len(v) i64((v).size())
#define ALL(v) v.begin(),v.end()
const i64 inf = 1e10;

string S1, S2, S3;
vector<int> T1, T2, T3;

const int MAXN = 1000;
i64 dp[MAXN][2];
// min deletions to fix S1[0..p]
i64 helper(int p, bool haveRemainder) {
	i64 res = inf;
	if (p == -1) return haveRemainder ? inf : 0;
	if (dp[p][haveRemainder] != -1) return dp[p][haveRemainder];

	if (!haveRemainder) {
		if (T1[p] + T2[p] == T3[p]) {
			res = helper(p-1, false);
		}
		// if this leave a remainder
		else if (T1[p] + T2[p] > T3[p] && (T1[p] + T2[p]) % 10 == T3[p]) {
			// case 1: ignore it
			i64 r1 = 1 + helper(p-1, false);
			// case 2: bring it
			i64 r2 = helper(p-1, true);
			res = min(r1, r2);
		}
		else { // no choice, delete this col
			res = 1 + helper(p-1, false);
		}
		return dp[p][haveRemainder] = res;
	}
	else {
		// if remainder complete this column, but doesnt leave remainder
		if (T1[p] + T2[p] + 1 == T3[p]) {
			// case 1: use the remainder and keep going
			i64 r1 = helper(p-1, false);
			// case 2: ignore this column
			i64 r2 = 1 + helper(p-1, true);
			res = min(r1,r2);
		}
		// if remainder complete this column, but leaves another remainder
		else if (T1[p] + T2[p] + 1 > T3[p] && (T1[p] + T2[p] + 1) % 10 == T3[p]) {
			// case 1: use the remainder
			i64 r1 = helper(p-1, true);
			// case 2: ignore this column
			i64 r2 = 1 + helper(p-1, true);
			res = min(r1, r2);
		}
		else { // no choice, delete it
			res = 1 + helper(p-1, true);
		}
		return dp[p][haveRemainder] = res;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	while (cin >> N) {
		if (N == 0) exit(0);
		memset(dp, -1, sizeof(dp));
		cin >> S1 >> S2 >> S3;
		T1 = T2 = T3 = vector<int>(N);
		for (int i = 0; i < N; i++) {
			T1[i] = S1[i] - '0';
			T2[i] = S2[i] - '0';
			T3[i] = S3[i] - '0';
		}
		cout << helper(N-1, false) << '\n';
	}
}

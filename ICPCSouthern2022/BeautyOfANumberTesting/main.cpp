#include <bits/stdc++.h>
#include <array>
using namespace std;
using i64 = long long;
using t3 = tuple<int,int,int>;
using ld = long double;
#define len(v) i64((v).size())
#define ALL(v) v.begin(),v.end()

i64 beauty(i64 X) {
	i64 res = 1;
	while (X > 0) {
		res *= (X % 10);
		X /= 10;
	}
	return res;
}

int main() {
	i64 L, R;
	while (cin >> L >> R) {
		i64 maxBeauty = -1;
		i64 minSatis = 1e17;
		i64 maxSatis = -1;
		for (i64 i = L; i <= R; i++) {
			if (beauty(i) >= maxBeauty) {
				maxBeauty = beauty(i);
			}
		}
		for (i64 i = L; i <= R; i++) {
			if (beauty(i) == maxBeauty) {
				minSatis = min(minSatis, i);
				maxSatis = max(maxSatis, i);
			}
		}
		cout << "MIN RES: " << minSatis << '\n';
		cout << "MAX RES: " << maxSatis << '\n';
		cout << "MAX BEAUTY: " << maxBeauty << '\n';
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}
}

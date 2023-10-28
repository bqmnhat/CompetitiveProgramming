#include <bits/stdc++.h>
using namespace std;

int t, n;
const int N = 1005;
struct point {
    int x, y;
}p[N];

bool cmp(point a, point b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
        return a.x < b.x;
}

point operator - (point a, point b) {
    return {a.x - b.x, a.y - b.y};
}

int cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
          cin >> p[i].x >> p[i].y;
        }
        sort(p, p + n, cmp);
        int l = 0, r = 0, k = 0;
        int ans[N];
        while ((r < n) && (k < n-1)) {
          while ((r < n - 1) && (cross(p[r + 1] - p[l], p[r] - p[l]) >= 0)) {
            r++;
          }
          while ((r < n - 1) && (cross(p[r + 1] - p[l], p[r] - p[l]) < 0)) {
            r++;
            l = r;
          }
          ans[k++] = r;
        }
        l = 0;
        for (int i = k - 2; i >= 0; i--) {
          while (cross(p[ans[i]] - p[l], p[ans[i + 1]] - p[l]) <= 0) {
            l = ans[i + 1];
          }
          ans[k++] = ans[i];
        }
        for (int i = 0; i < n; i++) {
          cout << min(n - (lower_bound(ans, ans + k, i) - ans),
                      lower_bound(ans, ans + k, i) - ans) << '\n';
        }
    }
    return 0;
}

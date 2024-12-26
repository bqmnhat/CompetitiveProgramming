#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int BLOCK_SIZE = 320;
int n, m; // n is input size, m is query size
ll a[MaxN + 5], globalAns = 0, ans[MaxN + 5];
unordered_map<ll, int> cnt;
struct Query {
    int l, r, idx;
    bool operator < (Query other) {
        if (l / BLOCK_SIZE != other.l / BLOCK_SIZE)
            return pii(l, r) < pii(other.l, other.r);
        return ((l / BLOCK_SIZE) & 1) ? (r < other.r) : (r > other.r);
    }
};
Query qLs[MaxN+5];

void ReadData() {
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++) {
        cin >> qLs[j].l >> qLs[j].r;
        qLs[j].idx = j;
    }
}

void Init() {
    globalAns = 0;
    memset(ans, 0, sizeof(ans));
    cnt.clear();
}

void addToCnt(ll val) {
    if (val == 0)
        return;
    cnt[val]++;
    if (cnt[val] == val + 1)
        globalAns--;
    if (cnt[val] == val)
        globalAns++;
}

void removeFromCnt(ll val) {
    if (val == 0)
        return;
    cnt[val]--;
    if (cnt[val] == val - 1)
        globalAns--;
    if (cnt[val] == val)
        globalAns++;
}

void Solve() {
    Init();
    sort(qLs + 1, qLs + 1 + m);
    int curL = 0, curR = 0;
    for (int qId = 1; qId <= m; qId++) {
        Query curRange = qLs[qId];
        while (curR < curRange.r) {
            curR++;
            addToCnt(a[curR]);
        }
        while (curL > curRange.l) {
            curL--;
            addToCnt(a[curL]);
        }
        while (curR > curRange.r) {
            removeFromCnt(a[curR]);
            curR--;
        }
        while (curL < curRange.l) {
            removeFromCnt(a[curL]);
            curL++;
        }
        ans[curRange.idx] = globalAns;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}

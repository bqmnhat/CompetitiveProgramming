#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
int n, a[MaxN+5], q, st[4*MaxN+16], moves[MaxN+5], cnt[MaxN+5];

/*
    General algorithm
        - Realizing that to make the seq a become 1,2,3,...,N we surely needs to:
            + Change values of t a[i]s (0 <= t <= n)
            + Shift right seq a k times (0 <= k <= n)
        - Considering k as the number of times we shift the seq => the a[i]s which satisfy these two following conditions will end-up at their right places:
            + 1 <= a[i] <= n
            + The minimum moves for a[i] to end-up at the right position is k
        - For short, let's call the number of those a[i]s as cnt[k]
        - The remaining (n - cnt[k]) numbers ought to be change values because we cannot shift any damn times to bring them to the right places and keep cnt[k] a[i]s to be at their right place too
        - So to sum up, we actually do:
            + k shifts
            + n - cnt[k] values are changed
        => Ans[k] = k + n - cnt[k]
        We will store Ans in a segment tree because:
            + It's fast to retrieve the minimum ans
            + We can use segment tree update to change values for each query too: each query changing a[x] to b just change cnt[k] for one/two k values and we just need to update those values
*/

void Init() {
    for (int i=0; i<=4*n + 4; i++)
        st[i] = 1e9 + 1;
}

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void CalMinMoves() { // calculate minimum moves for every a[i] to end-up at the right position such that 1 <= a[i] <= n then stores results in cnt[x] such that cnt[x] = number of positions i such that a[i] needs x moves
    for (int i=1; i<=n; i++) {
        if ((1 <= a[i]) && (a[i] <= n)) {
            moves[i] = (a[i] - i + n)%n; // Stores number of moves for position i
            cnt[moves[i]]++;
        }
    }
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = tl + n - cnt[tl];
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = min(st[v*2], st[v*2+1]);
    }
}

void UpdateSt(int v, int tl, int tr, int id, int val) {
    if (tl == tr)
        st[v] = val;
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        st[v] = min(st[v*2], st[v*2+1]);
    }
}

void Solve() {
    int x, b, ChangedCntId1, ChangedCntId2;
    for (int i=1; i<=q; i++) {
        ChangedCntId1 = ChangedCntId2 = -1;
        cin >> x >> b;
        if ((a[x] >= 1) && (a[x] <= n)) {
            ChangedCntId1 = moves[x];
            cnt[ChangedCntId1]--;
            UpdateSt(1, 0, n, ChangedCntId1, ChangedCntId1 + n - cnt[ChangedCntId1]);
        }
        if ((b >= 1) && (b <= n)) {
            ChangedCntId2 = (b - x + n)%n;
            moves[x] = ChangedCntId2;
            cnt[ChangedCntId2]++;
            UpdateSt(1, 0, n, ChangedCntId2, ChangedCntId2 + n - cnt[ChangedCntId2]);
        }
        a[x] = b;
        cout << st[1] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Init();
    ReadData();
    CalMinMoves();
    BuildSt(1, 0, n);
    cin >> q;
    Solve();
    return 0;
}

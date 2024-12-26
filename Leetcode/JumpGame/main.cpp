#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
bool st[4*MaxN+5], lazy[4*MaxN+10];

void down(int u) {
    st[u*2+1] |= lazy[u];
    lazy[u*2+1] |= lazy[u];
    st[u*2+2] |= lazy[u];
    lazy[u*2+2] |= lazy[u];
    lazy[u] = false;
}

void updateSt(int u, int tl, int tr, int l, int r, bool val) {
    if ((tl > r) || (tr < l)) {
        return;
    }
    if ((l <= tl) && (tr <= r)) {
        st[u] |= val;
        lazy[u] |= val;
        return;
    }
    down(u);
    int tm = ((tl + tr) >> 1);
    updateSt(u*2+1, tl, tm, l, r, val);
    updateSt(u*2+2, tm+1, tr, l, r, val);
}

bool getVal(int u, int tl, int tr, int id) {
    if (tl == tr)
        return st[u];
    else {
        down(u);
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            return getVal(u*2+1, tl, tm, id);
        else
            return getVal(u*2+2, tm+1, tr, id);
    }
}

bool canJump(vector<int>& nums) {
    int n = nums.size();
    updateSt(0, 0, n-1, 0, 0, true);
    for (int i = 0; i < n; i++) {
        bool curState = getVal(0, 0, n-1, i);
        updateSt(0, 0, n-1, i, min(n-1, i+nums[i]), curState);
    }
    return getVal(0, 0, n-1, n-1);
}

int main()
{
    vector<int> vt = {1, 2, 3};
    cout << canJump(vt);
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a,b,n,MaxN = 100000, sans[100001];
struct Seg {
    int l, r, id;
}s[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> s[i].l >> s[i].r;
        s[i].id = i;
        if ((s[i].l > b) || (s[i].r < a)) {
            s[i].l = MaxN+1;
            s[i].r = MaxN+1;
        }
        else {
            s[i].l = max(s[i].l,a);
            s[i].r = min(s[i].r,b);
        }
    }
}

bool CmpL(Seg a, Seg b) {
    if (a.l == b.l) {
        return (a.r < b.r);
    }
    else
        return (a.l < b.l);
}

void PrintAns(int l) {
    for (int i=1; i<=l; i++) {
        cout << sans[i] << '\n';
    }
}

int SegCover() {
    sort(s+1, s+1+n, CmpL);
    int ans = 0, i = 0, Right = a;
    if ((Right == b) && (s[1].r == b)) {
        ans++;
        sans[ans] = s[1].id;
        return ans;
    }
    while (Right != b) {
        bool Exist = false;
        int MaxR = Right-1, MaxId;
        while (s[i+1].l <= Right) {
            i++;
            Exist = true;
            if (s[i].r > MaxR) {
                MaxId = s[i].id;
                MaxR = s[i].r;
            }
        }
        if (Exist == true) {
            ans++;
            Right = MaxR;
            sans[ans] = MaxId;
        }
        else
            return -1;
    }
    return ans;
}

void Solve() {
    int tmp = SegCover();
    cout << tmp << '\n';
    if (tmp != -1)
        PrintAns(tmp);
}

int main()
{
    freopen("COVER.INP", "r", stdin);
    freopen("COVER.OUT", "w", stdout);
    cin >> n >> a >> b;
    ReadData();
    Solve();
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500
using namespace std;
typedef pair<int, int> pii;
int t, n, a[MaxN + 1], b[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        cin >> b[i];
}

bool DiffElementProcessing(vector<pii>& ans, int val1, int val2, int id) {
    int ChangePoint = -1;
    for (int i=id; i<n; i++) {
        if ((a[i] == val2) && (a[i+1] == val1)) {
            reverse(a+id-1, a+i+2);
            ans.push_back(pii(id-1, i+1));
            return true;
        }
        if ((a[i] == val1) && (a[i+1] == val2))
            ChangePoint = i;
    }
    if (ChangePoint == -1)
        return false;
    bool Found;
    for (int i=ChangePoint; i>=1; i--) {
        Found = false;
        for (int j=ChangePoint+1; j<=n; j++) {
            if (a[i] == a[j]) {
                reverse(a+i, a+j+1);
                ans.push_back(pii(i, j));
                Found = true;
                break;
            }
        }
        if (Found)
            break;
    }
    if (!Found)
        return false;
    for (int i=id; i<n; i++) {
        if ((a[i] == val2) && (a[i+1] == val1)) {
            reverse(a+id-1, a+i+2);
            ans.push_back(pii(id-1, i+1));
            return true;
        }
    }
    return false;
}

void SolveTestCase() {
    vector<pii> ans;
    ans.clear();
    if ((a[1] != b[1]) || (a[n] != b[n])) {
        cout << "NO\n";
        return;
    }
    for (int i=2; i<=n; i++) {
        if (a[i] != b[i]) {
            bool tmp = DiffElementProcessing(ans, b[i-1], b[i], i);
            if (!tmp) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES" << '\n' << (int)ans.size() << '\n';
    for (auto x: ans)
        cout << x.first << ' ' << x.second << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int q;
pii NeedToFind;
vector<int> ans;
bool Found = false;

void FindAns(pii CurF, pii LeftF, pii RightF) {
    if (ans.size() > 18)
        return;
    if (CurF == NeedToFind) {
        Found = true;
        return;
    }
    ans.push_back(0);
    FindAns(pii(LeftF.first + CurF.first, LeftF.second + CurF.second), LeftF, CurF);
    if (Found)
        return;
    ans.pop_back();
    ans.push_back(1);
    FindAns(pii(RightF.first + CurF.first, RightF.second + CurF.second), CurF, RightF);
    if (Found)
        return;
    ans.pop_back();
}

void Solve() {
    for (int i=1; i<=q; i++) {
        cin >> NeedToFind.first >> NeedToFind.second;
        Found = false;
        ans.clear();
        FindAns(pii(1, 1), pii(0, 1), pii(1, 0));
        for (int x: ans) {
            if (x == 0)
                cout << 'L';
            else
                cout << 'R';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    Solve();
    return 0;
}

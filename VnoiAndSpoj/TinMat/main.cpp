#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50000
using namespace std;
int n, m;
struct Node {
    Node* child[2];
    int cnt, finishedCnt;

    Node() {
        finishedCnt = cnt = 0;
        fill(child, child + 2, nullptr);
    }
};
Node* root;

void AddTrie(Node* root, const vector<int>& s) {
    Node* cur = root;
    for (int si: s) {
        if (cur->child[si] == nullptr)
            cur->child[si] = new Node();
        cur = cur->child[si];
        cur->cnt++;
    }
    cur->cnt--;
    cur->finishedCnt++;
}

int SearchTrie(Node* root, const vector<int>& s) {
    int ans = 0;
    Node* cur = root;
    for (int si: s) {
        if (cur->child[si] == nullptr)
            return ans;
        cur = cur->child[si];
        if (cur->finishedCnt)
            ans += cur->finishedCnt;
    }
    ans += cur->cnt;
    return ans;
}

void Solve() {
    root = new Node();
    vector<int> tmp;
    for (int i=1; i<=n; i++) {
        tmp.clear();
        int k;
        cin >> k;
        for (int j=1; j<=k; j++) {
            int ai;
            cin >> ai;
            tmp.push_back(ai);
        }
        AddTrie(root, tmp);
    }
    for (int i=1; i<=m; i++) {
        tmp.clear();
        int k;
        cin >> k;
        for (int j=1; j<=k; j++) {
            int ai;
            cin >> ai;
            tmp.push_back(ai);
        }
        int res = SearchTrie(root, tmp);
        cout << res << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Solve();
    return 0;
}

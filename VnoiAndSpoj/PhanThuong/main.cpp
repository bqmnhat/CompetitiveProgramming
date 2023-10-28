#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
#define MaxC 26
using namespace std;
typedef long long ll;
typedef pair<string, ll> psl;
int n, m;
psl a[MaxN+1];
vector<int> GOfP[MaxN+1];
ll dp[MaxN+1], MaxOfAllCardsHave[MaxN+1];
struct Node {
    Node* child[MaxC];
    ll DpMax;
    bool Done;
    Node() {
        DpMax = 0;
        Done = false;
        fill(child, child + MaxC, nullptr);
    }
};
Node* root = new Node();

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].first >> a[i].second;
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        GOfP[u].push_back(v);
        GOfP[v].push_back(u);
    }
}

void AddLabel(Node* root, string s, ll DpVal) {
    Node* cur = root;
    for (char ch : s) {
        cur->DpMax = max(cur->DpMax, DpVal);
        int c = ch - 'A';
        if (cur->child[c] == nullptr)
            cur->child[c] = new Node();
        cur = cur->child[c];
    }
}

ll SearchMaxDp(Node* root, string s) {
    Node* cur = root;
    for (char ch: s) {
        int c = ch - 'A';
        if (cur->child[c] == nullptr)
            return 0;
        cur = cur->child[c];
    }
    return cur->DpMax;
}

ll SolutionForFirst2Sub() {
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        ll tmp = SearchMaxDp(root, a[i].first) + a[i].second;
        dp[i] = tmp;
        for (int v: GOfP[a[i].second])
            dp[i] = max(dp[i], MaxOfAllCardsHave[v] + a[i].second);
        ans = max(ans, dp[i]);
        MaxOfAllCardsHave[a[i].second] = max(MaxOfAllCardsHave[a[i].second], dp[i]);
        AddLabel(root, a[i].first, dp[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << SolutionForFirst2Sub();
    return 0;
}

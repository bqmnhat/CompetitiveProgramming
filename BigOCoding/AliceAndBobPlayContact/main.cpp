#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxC 26
using namespace std;
int a[MaxN+1], b[MaxN+1], n, m;
struct Node {
    Node* child[MaxC];
    int Pass = 0;
    Node() {
        Pass = 0;
        fill(child, child + MaxC, nullptr);
    }
};
string A[MaxN+1], B[MaxN+1];
Node* root = new Node();

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> A[i];
    for (int j=1; j<=m; j++)
        cin >> B[j];
}

void Add(Node* root, string s) {
    Node* cur = root;
    for (char c: s) {
        int tmpc = c - 'a';
        if (cur->child[tmpc] == nullptr)
            cur->child[tmpc] = new Node();
        cur = cur->child[tmpc];
        cur->Pass++;
    }
}

int Search(Node* root, string s) {
    Node* cur = root;
    int l = s.length();
    int cntchar = l;
    for (int i=0; i<l; i++) {
        int tmpc = s[i] - 'a';
        if ((cur->child[tmpc] == nullptr) || (cntchar == 0))
            return i;
        cur = cur->child[tmpc];
        cntchar = min(cntchar-1, cur->Pass-1);
    }
    return l;
}

int Solution() {
    root = new Node();
    int ans = 0;
    for (int i=1; i<=m; i++)
        Add(root, B[i]);
    for (int i=1; i<=n; i++)
        ans += Search(root, A[i]);
    return ans;
}

void Solve() {
    while (cin >> n >> m) {
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ABPLAY.INP", "r", stdin);
    Solve();
    return 0;
}

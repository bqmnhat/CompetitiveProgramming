#include <iostream>
#include <bits/stdc++.h>
#define MaxN 26
using namespace std;
struct Node {
    Node* child[MaxN];
    int cnt;
    Node() {
        cnt = 0;
        fill(child, child + MaxN, nullptr);
    }
};
int n, q;
Node* root = new Node();

void Add(Node* root, string s) {
    Node* cur = root;
    for (char c: s) {
        int tmp = c - 'a';
        if (cur->child[tmp] == nullptr)
            cur->child[tmp] = new Node();
        cur = cur->child[tmp];
    }
    cur->cnt++;
}

int CntWords(Node* root) {
    Node* cur = root;
    int ans = cur->cnt;
    for (int i=0; i<MaxN; i++)
        if (cur->child[i] != nullptr)
            ans += CntWords(cur->child[i]);
    return ans;
}

int Search(Node* root, string pref) {
    Node* cur = root;
    for (char c: pref) {
        int tmp = c - 'a';
        if (cur->child[tmp] == nullptr)
            return 0;
        cur = cur->child[tmp];
    }
    int ans = cur->cnt;
    for (int i=0; i<MaxN; i++)
        if (cur->child[i] != nullptr)
            ans += CntWords(cur->child[i]);
    return ans;
}

void ReadData() {
    string s;
    for (int i=1; i<=n; i++) {
        cin >> s;
        Add(root, s);
    }
}

void Solve() {
    string s;
    for (int i=1; i<=q; i++) {
        cin >> s;
        cout << Search(root, s) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ReadData();
    Solve();
    return 0;
}

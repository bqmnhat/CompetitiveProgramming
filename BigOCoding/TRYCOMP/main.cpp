#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
#define MaxC 26
#define MaxLen 10
using namespace std;
int n, q;
struct Node {
    Node* child[MaxC];
    int cple, Maxcple;
    bool leaf;
    Node() {
        cple = Maxcple = 0;
        leaf = true;
        fill(child, child + MaxC, nullptr);
    }
};
string ansStr, s;
Node* root = new Node();

void Add(Node* root, string s) {
    Node* cur = root;
    for (char ch: s) {
        int c = ch - 'a';
        if (cur->child[c] == nullptr)
            cur->child[c] = new Node();
        cur->leaf = false;
        cur = cur->child[c];
    }
    cur->cple++;
    cur->Maxcple++;
}

void FindAllMaxCple(Node* root) {
    Node* cur = root;
    if (cur->leaf)
        return;
    for  (int i=0; i<MaxC; i++) {
        if (cur->child[i] != nullptr) {
            FindAllMaxCple(cur->child[i]);
            cur->Maxcple = max(cur->Maxcple, cur->child[i]->Maxcple);
        }
    }
}

int SearchForPref(Node* root, string s) {
    Node* cur = root;
    for (char ch: s) {
        int c = ch - 'a';
        if (cur->child[c] == nullptr)
            return -1;
        cur = cur->child[c];
    }
    ansStr = s;
    int ans = cur->Maxcple;
    while (cur->cple != ans) {
        for (int i=0; i<MaxC; i++) {
            if ((cur->child[i] != nullptr) && (cur->child[i]->Maxcple == ans)) {
                ansStr += char(i + 'a');
                cur = cur->child[i];
                break;
            }
        }
    }
    return ans;
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> s;
        Add(root, s);
    }
}

void Solve() {
    for (int i=1; i<=q; i++) {
        cin >> s;
        ansStr = "";
        int ans = SearchForPref(root, s);
        if (ans != -1)
            cout << ansStr << ' ' << ans << '\n';
        else
            cout << "-1\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    FindAllMaxCple(root);
    cin >> q;
    Solve();
    return 0;
}

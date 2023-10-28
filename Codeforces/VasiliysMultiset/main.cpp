#include <iostream>
#include <bits/stdc++.h>
#define MaxC 2
using namespace std;
struct Node {
    Node* child[2];
    int cnt;
    Node() {
        cnt = 0;
        fill(child, child + MaxC, nullptr);
    }
};
Node* root = new Node();
int q, x;

vector<int> GetBit(int x) {
    vector<int> res;
    while (x > 0) {
        int tmp = x%2;
        x/=2;
        res.push_back(tmp);
    }
    while (res.size() < 30)
        res.push_back(0);
    reverse(res.begin(), res.end());
    return res;
}

int GetNum(vector<int>& bit) {
    reverse(bit.begin(), bit.end());
    while ((bit.size() > 0) && (bit.back() == 0))
        bit.pop_back();
    if (bit.size() == 0)
        return 0;
    int res = 0;
    for (int i=0; i<bit.size(); i++)
        res += (bit[i]*(1 << i));
    return res;
}

void Add(Node* root, const vector<int>& bit) {
    Node* cur = root;
    for (int x: bit) {
        if (cur->child[x] == nullptr)
            cur->child[x] = new Node();
        cur = cur->child[x];
    }
    cur->cnt++;
}

bool IsEmpty(Node* cur) {
    Node* tmp = cur;
    for (int i=0; i<MaxC; i++)
        if (tmp->child[i] != nullptr)
            return false;
    return true;
}

bool Remove(Node* root, const vector<int>& bit, int depth = 0) {
    if (!root)
        return false;
    if (depth == bit.size()) {
        if (root->cnt > 0) {
            root->cnt--;
            return true;
        }
        return false;
    }
    int x = bit[depth];
    if (!root->child[x])
        return false;
    bool IsRemoved = Remove(root->child[x], bit, depth+1);
    Node* tmp = root->child[x];
    if ((IsRemoved) && (tmp->cnt == 0) && (IsEmpty(tmp))) {
        delete root->child[x];
        root->child[x] = nullptr;
    }
    return IsRemoved;
}

int Search(Node* root, const vector<int>& bit) {
    vector<int> res;
    Node* cur = root;
    for (int x: bit) {
        int tmp = 1-x;
        if (cur->child[tmp] == nullptr) {
            tmp = 1-tmp;
            if (cur->child[tmp] == nullptr)
                break;
        }
        res.push_back(tmp);
        cur = cur->child[tmp];
    }
    return GetNum(res);
}

void Solve() {
    vector<int> tmp0(30, 0);
    Add(root, tmp0);
    for (int i=1; i<=q; i++) {
        char cmd;
        int x;
        cin >> cmd;
        if (cmd == '+') {
            cin >> x;
            Add(root, GetBit(x));
        }
        else if (cmd == '-') {
            cin >> x;
            Remove(root, GetBit(x), 0);
        }
        else {
            cin >> x;
            cout << (x^Search(root, GetBit(x))) << '\n';
        }
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

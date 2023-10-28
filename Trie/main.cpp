#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
struct Node {
    Node* child[2];
    int cnt;

    Node() {
        cnt = 0;
        fill(child, child+2, nullptr);
    }
};

bool IsEmpty(Node& tmp) {
    for (int i=0; i<2; i++)
        if (tmp.child[i] != nullptr)
            return false;
    return true;
}

bool Remove(Node* root, string s, int depth) {
    if (!root)
        return false;
    if (depth == s.length()) {
        if (root->cnt > 0) {
            root->cnt--;
            return false;
        }
        return true;
    }
    int c = s[depth] - 'a';
    if (!(root->child[c]))
        return false;
    bool IsRemoved = Remove(root->child[c], s, depth+1);
    Node& tmp = root->child[c];
    if ((IsRemoved) && (tmp.cnt == 0) && (IsEmpty(tmp))) {
        delete root->child[c];
        root->child[c] = nullptr;
    }
    return IsRemoved;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

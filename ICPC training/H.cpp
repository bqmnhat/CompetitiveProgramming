/// hhoangcpascal

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

typedef struct Data {
    int num;
    Data *l, *r;
} *node;

vector<node> Root;

node New() {
    node P = new Data();
    P->l = P->r = NULL;
    P->num = 0;
    return P;
}

void Build(node &root, int l, int r) {
    if (l > r) return;
    root = New();
    if (l == r) return;

    int mid = (l + r) >> 1;

    Build(root->l, l, mid);
    Build(root->r, mid+1, r);
}

int Num(node root) {
    if (root == NULL) return 0;
    return root->num;
}

void Update(node old, node &root, int l, int r, int p, int val) {
    if (r < p || l > p) return;

    root = New();
    if (l == r) {
        root->num = old->num + val;
        return;
    }

    int mid = (l + r) >> 1;
    if (p <= mid) {
        root->r = old->r;
        Update(old->l, root->l, l, mid, p, val);
    } else {
        root->l = old->l;
        Update(old->r, root->r, mid+1, r, p, val);
    }

    root->num = Num(root->l) + Num(root->r);
}

int Query(node root, int l, int r, int val) {
    if (r < val || root == NULL) return 0;
    if (l >= val) return Num(root);

    int mid = (l + r) >> 1;
    return Query(root->l, l, mid, val) + Query(root->r, mid+1, r, val);
}

int n, D[100006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    Root.push_back(NULL);
    cin >> n; Build(Root[0], 0, n - 1);

    int cur = 0; string s; getline(cin, s);
    for(int i = 1; i <= n; ++i) {
        getline(cin, s);

        stringstream inp;
        inp << s;

        while (inp >> s) {
            int val = 1;
            if (s[0] == '-') val = -1;

            int num = 0;
            for(int j = 1; j < (int) s.size(); ++j) num = (num << 1) + (num << 3) + (s[j] - '0');

            ++cur; Root.push_back(NULL);
            Update(Root[cur-1], Root[cur], 0, n-1, num, val);
        }

        D[i] = cur;
    }

    int x = 0;
    for(int i = 1; i <= n; ++i) {
        int d; cin >> d;
        (x += Query(Root[D[d]], 0, n - 1, x)) %= n;
    }

    cout << x;
    return 0;
}

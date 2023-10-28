#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxC 2
using namespace std;
typedef long long ll;
int n;
struct Node {
    Node* child[MaxC];
    Node() {
        fill(child, child + MaxC, nullptr);
    }
};
Node* root = new Node();
ll a[MaxN+2], SumXor;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        SumXor ^= a[i];
    }
}

vector<int> GetBit(ll val) { //reversed bit of num from ans
    vector<int> ans;
    while (val > 0) {
        ll tmp = (val&1);
        ans.push_back(tmp);
        val = (val >> 1);
    }
    while (ans.size() < 40)
        ans.push_back(0);
    reverse(ans.begin(), ans.end());
    return ans;
}

ll GetNum(const vector<int>& bit) { //not reverted bit num from bit
    ll ans = 0;
    for (int i=0; i<bit.size(); i++)
        ans += (1LL*bit[i]*(1LL<<i));
    return ans;
}

void Add(Node* root, const vector<int>& bit) {
    Node* cur = root;
    for (int x: bit) {
        if (cur->child[x] == nullptr)
            cur->child[x] = new Node();
        cur = cur->child[x];
    }
}

ll Search(Node* root, const vector<int>& bit) {
    ll ans = 0;
    Node* cur = root;
    vector<int> MatchPref;
    for (int x: bit) {
        int tmpx = 1-x;
        if (cur->child[tmpx] == nullptr) {
            tmpx = 1-tmpx;
            if (cur->child[tmpx] == nullptr)
                break;
        }
        cur = cur->child[tmpx];
        MatchPref.push_back(tmpx);
    }
    reverse(MatchPref.begin(), MatchPref.end());
    return GetNum(MatchPref);
}

ll Solution() {
    Add(root, {0});
    ll ans = 0, SufXor = 0, PrefXor = 0;
    for (int i=0; i<=n; i++) {
        PrefXor ^= a[i];
        SufXor = SumXor^PrefXor;
        ans = max(ans, Search(root, GetBit(SufXor))^SufXor);
        Add(root, GetBit(PrefXor));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}

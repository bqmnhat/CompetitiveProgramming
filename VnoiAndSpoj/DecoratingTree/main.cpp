#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50000
using namespace std;
typedef pair<int, int> pii;
int m, n, Nums[3*MaxN+1]; // Nums for random without repetition

int random(int l, int r) {
    int cnt = 0;
    for (int i=l; i<=r; i++) {
        cnt++;
        Nums[cnt] = i;
    }
    random_shuffle(Nums+1, Nums+1+cnt);
    return Nums[1];
}

void Solve() {
    // print a line-shaped tree
    for (int i=1; i<m; i++)
        cout << i << ' ' << i + 1 << endl;

    // Asking questions for random (u, v) to obtain the diameter of the tree with additional vertices
    // Maximum nodes on the diameter = m-1
    // Maximum nodes in the tree with additional vertices = 3*m
    // probability choosing u on the diameter = (m-1)/3m ~= 1/3
    // probability choosing both u and v on the diameter = 1/3 * 1/3 = 1/9

    // Suppose that (u, v) is on the diameter => To calculate the diameter, we use this formula: subtree(u, v) + subtree(v, u) - distance(u, v)
    // => We need to ask 3 questions
    // Fortunately, if we ask all 666 questions, meaning checking 222 (u, v)s => the probability that we chose (u, v) on the diameter is 1 - (8/9)^222 ~= 1

    int ans = m-1; // diameter
    // Asking questions
    for (int i=1; i<=222; i++) {
        int u = random(1, n-1);
        int v = random(u+1, n);
        int sub1 = 0, sub2 = 0, dist = 0;
        cout << "subtree " << u << ' ' << v << endl;
        cin >> sub1;
        cout << "subtree " << v << ' ' << u << endl;
        cin >> sub2;
        cout << "distance " << u << ' ' << v << endl;
        cin >> dist;
        ans = max(ans, sub1 + sub2 - dist);
    }
    cout << "! " << ans << endl;
}

int main()
{
    cin >> m >> n;
    Solve();
    return 0;
}

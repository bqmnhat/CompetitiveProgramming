#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> pqGreater;
priority_queue<ll, vector<ll>> pqSmaller;

void Solve() {
    ll ai;
    int n = 0;
    ll Med;
    while (cin >> ai) {
        n++;
        if (n == 1) {
            pqSmaller.push(ai);
            Med = ai;
            cout << ai << '\n';
            continue;
        }
        if (ai > Med)
            pqGreater.push(ai);
        else
            pqSmaller.push(ai);
        while ((int)pqSmaller.size() - (int)pqGreater.size() > 1) {
            pqGreater.push(pqSmaller.top());
            pqSmaller.pop();
        }
        while ((int)pqGreater.size() - (int)pqSmaller.size() > 1) {
            pqSmaller.push(pqGreater.top());
            pqGreater.pop();
        }
        ll top1 = pqGreater.top(), top2 = pqSmaller.top();
        if (pqGreater.size() == pqSmaller.size())
            Med = (top1 + top2)/2;
        else if (pqGreater.size() > pqSmaller.size())
            Med = top1;
        else
            Med = top2;
        cout << Med << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000000
using namespace std;
typedef long long ll;
int n;
ll p, q, m, k, a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        a[i] = (p*1LL*i + q)%m;
}

ll Solution() {
    deque<ll> MinDeque, MaxDeque;
    int i = 1;
    ll ans = 0;
    for (int j = 1; j<=n; j++) {
        ll val = a[j];
        while ((!MinDeque.empty()) && (a[MinDeque.back()] > val))
            MinDeque.pop_back();
        MinDeque.push_back(j);
        while ((!MaxDeque.empty()) && (a[MaxDeque.back()] > val))
            MaxDeque.pop_back();
        MaxDeque.push_back(j);
        if ((!MaxDeque.empty()) && (!MinDeque.empty())) {
            while (a[MaxDeque.front()] - a[MinDeque.front()] > k) {
                if ((!MaxDeque.empty()) && (a[MaxDeque.front()] == a[i]))
                    MaxDeque.pop_front();
                if ((!MinDeque.empty()) && (a[MinDeque.front()] == a[i]))
                    MinDeque.pop_front();
                i++;
            }
            ans += (1LL*j - max(MaxDeque.front(), MinDeque.front()) + 1LL)*(min(MaxDeque.front(), MinDeque.front()) - 1LL*i + 1LL);
        }
    }
    return ans;
}

int main()
{
    //freopen("SDIFF.INP", "r", stdin);
    //freopen("SDIFF.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> p >> q >> m;
    cin >> k;
    ReadData();
    cout << Solution();
    return 0;
}


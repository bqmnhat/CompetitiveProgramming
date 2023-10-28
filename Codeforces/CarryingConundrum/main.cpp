#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
vector<int> EvenDigits, OddDigits;

ll MakeNumFromDigits(vector<int>& Digits) {
    ll ans = 0;
    while (!Digits.empty()) {
        ans = ans*10 + Digits.back();
        Digits.pop_back();
    }
    return ans;
}

ll Solution() {
    ll ans = 0, NoFromEven = 0, NoFromOdd = 0;
    int cnt = 0;
    while (n > 0) {
        if (cnt % 2 == 0)
            EvenDigits.push_back(n%10);
        else
            OddDigits.push_back(n%10);
        n = n/10;
        cnt++;
    }
    NoFromEven = MakeNumFromDigits(EvenDigits);
    NoFromOdd = MakeNumFromDigits(OddDigits);
    ans = (NoFromEven + 1LL)*(NoFromOdd + 1LL) - 2;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}

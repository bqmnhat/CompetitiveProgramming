#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, la = 0;
pair<int, int> a[82];
bool mark[1000001];

int CalDig(int x) {
    int ans = 0;
    while (x > 0) {
        int tmp = (x%10);
        x=x/10;
        ans+=tmp;
    }
    return ans;
}

void ReadData() {
    int ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        int SumDig = CalDig(ai);
        if (!mark[SumDig]) {
            mark[SumDig] = true;
            la++;
            a[la].first = SumDig;
            a[la].second = ai;
        }
    }
}

void Solve() {
    int MinDif = 1e9, FirstHalf, SecondHalf;
    for (int i=1; i<=la; i++) {
        for (int j=i+1; j<=la; j++) {
            if (abs(a[i].first - a[j].first) < MinDif) {
                MinDif = abs(a[i].first - a[j].first);
                FirstHalf = a[i].second;
                SecondHalf = a[j].second;
            }
        }
    }
    cout << FirstHalf << SecondHalf;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PASSWORD.INP", "r", stdin);
    freopen("PASSWORD.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}

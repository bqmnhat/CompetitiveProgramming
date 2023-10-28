#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, le = 0, lo = 0, e = 0;
ll even[100001], odd[100001], evensum = 0, oddsum = 0, tkEven[31];
string cmd;

int CountPow2(ll x) {
    int ans = 0;
    if (x == 0)
        return 0;
    while (x % 2 == 0) {
        x = x/2;
        ans++;
    }
    ans--;
    return ans;
}

void ReadData() {
    ll ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        if (ai % 2 == 0) {
            evensum += ai;
            tkEven[CountPow2(ai)]++;
            le++;
            even[le] = ai;
        }
        else {
            oddsum += ai;
            lo++;
            odd[lo] = ai;
        }
    }
}

void Solve() {
    int i = 0;
    ll one = 0;
    while ((cmd[i] == '0') && (i < cmd.length())) {
        e++;
        evensum = evensum/2;
        ll ans = oddsum + evensum;
        cout << ans << '\n';
        if (e <= 30) {
            evensum = evensum - tkEven[e];
            oddsum += tkEven[e]*;
            one += tkEven[e];
            tkEven[e] = 0;
        }
        i++;
    }
    if (i == cmd.length())
        return;
    oddsum = oddsum - lo - one;
    ll ans = oddsum + evensum;
    cout << ans << '\n';
    for (int j=1; j<=lo; j++) {
        evensum += (odd[j]-1LL);
        le++;
        even[le] = odd[j] - 1LL;
    }
    oddsum = 0;
    i++;
    for (int i=1; i<=le; i++)
        tkEven[CountPow2(even[i])]++;
    e = 0;
    while (i < cmd.length()) {
        if (cmd[i] == '0') {
            e++;
            evensum = evensum/2;
            if (e <= 30) {
                evensum = evensum - tkEven[e];
                oddsum += tkEven[e];
                tkEven[e] = 0;
            }
        }
        else
            oddsum = 0;
        ll ans = oddsum + evensum;
        cout << ans << '\n';
        i++;
    }
}

int main()
{
    cin >> n;
    ReadData();
    cin >> cmd;
    Solve();
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[300001], b[300001], suma, sumb;

void ReadData() {
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    cin >> m;
    for (int i=1; i<=m; i++)
        cin >> b[i];
}

void FindSums() {
    for (int i=1; i<=n; i++)
        suma += a[i];
    for (int i=1; i<=m; i++)
        sumb += b[i];
}

void SolveTestCases() {
    int pa = 1, pb = 1, ans = 0;
    if (suma != sumb) {
        cout << "-1\n";
        return;
    }
    while ((pa <= n) && (pb <= m)) {
        ans++;
        ll xa = a[pa], xb = b[pb];
        pa++;
        pb++;
        while (xa != xb) {
            if (xa < xb) {
                xa += a[pa];
                pa++;
            }
            else {
                xb += b[pb];
                pb++;
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ReadData();
    FindSums();
    SolveTestCases();
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, a[10], la;

void FindMax(int n) {
    la = 0;
    int MaxID = -1, Max = -1, SwapID1 = -1, SwapID2 = -1;
    while (n > 0) {
        la++;
        int tmp = n%10;
        n = n/10;
        a[la] = tmp;
        if (tmp > Max) {
            Max = tmp;
            MaxID = la;
            continue;
        }
        if (tmp < Max) {
            SwapID1 = la;
            SwapID2 = MaxID;
        }
    }
    if (SwapID1 == -1) {
        for (int i=la; i>=1; i--)
            cout << a[i];
        return;
    }
    swap(a[SwapID1],a[SwapID2]);
    for (int i=la; i>=1; i--)
        cout << a[i];
}

void FindMin(int n) {
    la = 0;
    int MinRight[10];
    while (n > 0) {
        la++;
        int tmp = n%10;
        n = n/10;
        a[la] = tmp;
    }
    int MinID = -1;
    for (int i = la-1; i >= 1; i--)
        if (a[i] != 0) {
            if (MinID == -1) {
                if (a[i] < a[la])
                    MinID = i;
            }
            else if (a[i] <= a[MinID])
                MinID = i;
        }
    MinRight[1] = -1;
    int MinID2 = 1;
    for (int i=2; i<=la-1; i++) {
        if (a[i] >= a[MinID2])
            MinRight[i] = MinID2;
        else if (a[i] == a[i-1])
            MinRight[i] = MinID2;
        else {
            MinRight[i] = -1;
            MinID2 = i;
        }
    }
    if (MinID != -1)
        swap(a[la], a[MinID]);
    else {
        for (int i=la-1; i>=1; i--) {
            if ((MinRight[i] != -1) && (a[i] != a[MinRight[i]])) {
                swap(a[i], a[MinRight[i]]);
                break;
            }
        }
    }
    for (int i=la; i>=1; i--)
        cout << a[i];
}

void SolveTestCase(int n) {
    la = 0;
    FindMin(n);
    cout << ' ';
    FindMax(n);
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << "Case #" << i << ": ";
        if (n == 0)
            cout << "0 0";
        else
            SolveTestCase(n);
        cout << '\n';
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

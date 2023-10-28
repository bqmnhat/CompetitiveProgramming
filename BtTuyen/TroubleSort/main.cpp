#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, v[100001], oddID[100001], evenID[100001], le = 0, lo = 0;

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> v[i];
}

void SplitEvenAndOdd() {
    for (int i=0; i<n; i++) {
        if (i%2 == 0) {
            le++;
            evenID[i/2] = v[i];
        }
        else {
            lo++;
            oddID[i/2] = v[i];
        }
    }
}

int SortingTrouble() {
    sort(evenID, evenID+le);
    sort(oddID, oddID+lo);
    for (int i=0; i<n-1; i++) {
        if ((i%2 == 0) && (evenID[i/2] > oddID[(i+1)/2]))
            return i;
        else if ((i%2 == 1) && (oddID[i/2] > evenID[(i+1)/2]))
            return i;
    }
    return -1;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        lo = le = 0;
        SplitEvenAndOdd();
        cout << "Case #" << i << ": ";
        int tmp = SortingTrouble();
        if (tmp < 0)
            cout << "OK";
        else
            cout << tmp;
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

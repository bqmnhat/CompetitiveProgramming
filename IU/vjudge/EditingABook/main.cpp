#include <iostream>
#include <bits/stdc++.h>
#define MaxN 9
using namespace std;
int n, a[MaxN+1], MaxNumSwaps;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int WrongPos(int book[]) {
    int ans = 0;
    for (int i=2; i<=n; i++)
        if (book[i] != book[i-1] + 1)
         ans++;
    return ans;
}

void CopySubarray(int from[], int to[], int fs, int ts, int len) {
    int fe = fs + len - 1, te = ts + len - 1;
    while ((fs <= fe) && (ts <= te)) {
        to[ts] = from[fs];
        ts++;
        fs++;
    }
}

bool Backtracking(int NumSwaps, int book[]) {
    int cntWrPos = WrongPos(book);
    if (3*NumSwaps + cntWrPos > 3*MaxNumSwaps)
        return false;
    if (cntWrPos == 0)
        return true;
    int TmpBook[MaxN+1], MovePart[MaxN+1];
    CopySubarray(book, TmpBook, 1, 1, n);
    for (int i=1; i<=n; i++) {
        if ((i == 0) || (TmpBook[i] != TmpBook[i-1] + 1)) {
            for (int j=i; j<=n; j++) {
                while ((j+1 <= n) && (TmpBook[j+1] == TmpBook[j] + 1))
                    j++;
                CopySubarray(TmpBook, MovePart, i, 1, j-i+1);
                for (int k = j+1; k<=n; k++) {
                    while ((k + 1 <= n) && (TmpBook[k+1] == TmpBook[k] + 1))
                        k++;
                    CopySubarray(TmpBook, book, j+1, i, k-j);
                    CopySubarray(MovePart, book, 1, i+k-j, j-i + 1);
                    if (Backtracking(NumSwaps+1, book))
                        return true;
                    CopySubarray(TmpBook, book, 1, 1, n);
                }
            }
        }
    }
    return false;
}

int Solution() {
    if (WrongPos(a) == 0)
        return 0;
    MaxNumSwaps = 1;
    while (!Backtracking(0, a))
        MaxNumSwaps++;
    return MaxNumSwaps;
}

void Solve() {
    cin >> n;
    int cnt = 0;
    while (n != 0) {
        cnt++;
        ReadData();
        cout << "Case " << cnt << ": " << Solution() << '\n';
        cin >> n;
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

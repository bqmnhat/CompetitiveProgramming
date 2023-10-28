#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long t, k, n, nxtSum[1001], nxtID[1001];
long long a[1001];
int visited[1001], R;
long long Cost[1003];

void Init() {
    for (int i=0; i<=1001; i++) {
        nxtID[i] = -1;
        nxtSum[i] = 0;
        visited[i] = -1;
        Cost[i] = 0;
    }
}

void ReadData() {
    for (int i = 0; i<n; i++)
        cin >> a[i];
}

long long Solution() {
    long long CycleLength = n, CycleStart = 0;
    for (int i=0; i<n; i++) {
        long long sum = 0;
        nxtID[i] = i;
        for (int j = 0; j < n; j++) {
            if (sum + a[(i+j)%n] > k) {
                nxtSum[i] = sum;
                nxtID[i] = (i+j)%n;
                break;
            }
            sum += a[(i+j)%n];
            nxtSum[i] = sum;
        }
    }
    long long CycleCost = 0;
    for (int i=1, p = 0; i<=n+1; i++) {
        Cost[i] = Cost[i-1] + nxtSum[p];
        if (visited[p] != -1) {
            CycleStart = p;
            CycleLength = i - visited[p];
            CycleCost = Cost[i] - Cost[visited[p]];
            break;
        }
        visited[p] = i;
        p = nxtID[p];
    }
    long long ans = 0;
    int p = 0;
    for (int i = 1; i<= min(R, visited[CycleStart] - 1); i++) {
        ans += nxtSum[p];
        p = nxtID[p];
    }
    R = R - min(R, visited[CycleStart] - 1);
    int cycles = R/CycleLength;
    ans += cycles*CycleCost;
    R = R%CycleLength;
    p = CycleStart;
    for (int i=1; i<=R; i++) {
        ans += nxtSum[p];
        p = nxtID[p];
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        Init();
        cin >> R >> k >> n;
        ReadData();
        cout << "Case #" << i << ": " << Solution() << '\n';
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}

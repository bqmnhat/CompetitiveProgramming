#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long c[100001], freq[100001], sum = 0;
int n, k = 1;

void ReadData(long long &sum) {
    for (int i = 1; i<=n; i++) {
        cin >> c[i];
        sum += c[i];
    }
}

void Compress() {
    sort(c+1,c+1+n);
    freq[1] = 1;
    for (int i = 2; i<=n; i++) {
        if (c[i] != c[i-1]) {
            k++;
            c[k] = c[i];
        }
        freq[k]++;
    }
}

long long MaxCoins() {
    long long tmp;
    int d = 1;
    Compress();
    tmp = freq[1]*c[1];
    for (int i=2; i<=k; i++) {
        if (freq[i]*c[i] < tmp)
            tmp = freq[i]*c[i];
    }
    return sum - tmp;
}

int main()
{
    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);
    cin >> n;
    ReadData(sum);
    cout << MaxCoins();
    return 0;
}

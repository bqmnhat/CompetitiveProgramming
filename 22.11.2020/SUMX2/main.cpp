#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[100001], freq[100001], n, x, k = 1;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void Compress() {
    sort(a+1, a+1+n);
    freq[1] = 1;
    for (int i = 2; i<=n; i++) {
        if (a[i] != a[i-1]) {
            ++k;
            a[k] = a[i];
        }
        freq[k]++;
    }
}

long long PairsX() {
    long long ans = 0;
    int i=1, j=k-1;
    while (i <= j) {
        if (a[i] + a[j] == x) {
            if (a[i] == a[j])
                ans = ans + freq[i]*(freq[i]-1)/2;
            else ans = ans + freq[i]*freq[j];
            i++,j--;
        }
        else if (a[i] + a[j] < x)
            i++;
        else
            j--;
    }
}

int main()
{
    freopen("SUMX.INP", "r", stdin);
    freopen("SUMX.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cin >> x;
    Compress();
    cout << PairsX();
    return 0;
}

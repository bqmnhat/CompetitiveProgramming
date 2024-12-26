#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
#define MaxC 27
using namespace std;
typedef long long ll;
int t, n, odd[MaxC+5][MaxN+5], even[MaxC+5][MaxN+5];
string s;

void CalcOddAndEven() {
    s = " " + s;
    for (char c = 'a'; c <= 'z'; c++) {
        odd[c - 'a'][0] = even[c - 'a'][0] = 0;
        for (int i = 1; i <= n; i++) {
            odd[c - 'a'][i] = odd[c - 'a'][i-1];
            even[c - 'a'][i] = even[c - 'a'][i-1];
            if (i % 2 == 1)
                odd[c - 'a'][i] += (s[i] != c);
            else
                even[c - 'a'][i] += (s[i] != c);
        }
    }
}

int Solution() {
    int ans = n;
    for (char cOdd = 'a'; cOdd <= 'z'; cOdd++) {
        for (char cEven = 'a'; cEven <= 'z'; cEven++) {
            if (n % 2 == 0)
                ans = min(ans, odd[cOdd - 'a'][n] + even[cEven - 'a'][n]);
            else {
                for (int j = 1; j <= n; j++) {
                    int cntOdd = (odd[cOdd - 'a'][j-1] + even[cOdd - 'a'][n] - even[cOdd - 'a'][j]);
                    int cntEven = (even[cEven - 'a'][j-1] + odd[cEven - 'a'][n] - odd[cEven - 'a'][j]);
                    ans = min(ans, cntOdd + cntEven + 1);
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        CalcOddAndEven();
        cout << Solution() << '\n';
    }
    return 0;
}


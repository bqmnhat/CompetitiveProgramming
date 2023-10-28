#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
string s;
bool Sieve[MaxN + 1];
int n;

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i <= MaxN; i++)
        if (!Sieve[i])
            for (int j=i; i*j <= MaxN; j++)
                Sieve[i*j] = true;
}

bool IsDig(int x) {
    return ((s[x] >= '0') && (s[x] <= '9'));
}

int MaxPrimeSt(int id) {
    int num = 0, ans = -1;
    while ((id < n) && (IsDig(id)) && (num*10 <= MaxN)) {
        num = num*10 + (s[id] - '0');
        if (!Sieve[num])
            ans = max(ans, num);
        id++;
    }
    return ans;
}

int Solution() {
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (IsDig(i)) {
            int tmp = MaxPrimeSt(i);
            ans = max(ans, tmp);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSieve();
    cin >> s;
    n = s.length();
    cout << Solution();
    return 0;
}

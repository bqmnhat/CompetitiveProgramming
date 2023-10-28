#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool Sieve[1000001];
int Prime[1000001], lp = 0, n;

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    int m = sqrt(40000);
    for (int i = 2; i<=m; i++)
        if (Sieve[i] == false)
            for (int j = i; i*j <= 40000; j++)
                Sieve[i*j] = true;
}

void MakePrime() {
    for (int i=2; i<=40000; i++) {
        if (!Sieve[i]) {
            lp++;
            Prime[lp] = i;
        }
    }
}

bool IsPrime(int x) {
    if ((x == 0) || (x == 1))
        return false;
    int m = sqrt(x);
    for (int i=2; i<=m; i++)
        if (x%i == 0)
            return false;
    return true;
}

void FindAllPairs() {
    bool Exist = false;
    for (int i=1; i<=lp; i++) {
        if (Prime[i] != 2) {
            int tmp = 4 + (Prime[i]*Prime[i]);
            if (tmp > n)
                break;
            if (IsPrime(tmp)) {
                Exist = true;
                cout << 2 << ' ' << Prime[i] << ' ' << tmp << '\n';
            }
        }
    }
    if (!Exist)
        cout << "-1";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DPRIME3.INP", "r", stdin);
    freopen("DPRIME3.OUT", "w", stdout);
    cin >> n;
    MakeSieve();
    MakePrime();
    FindAllPairs();
    return 0;
}

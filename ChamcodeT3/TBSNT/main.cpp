#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
bool Sieve[5000001];

void MakeSieve() {
    int m = sqrt(5000001);
    Sieve[1] = Sieve[0] = true;
    for (int i=2; i<=m; i++) {
        if (!Sieve[i]) {
            for (int j=i; i*j<=5000001; j++)
                Sieve[i*j] = true;
        }
    }
}

void Solve() {
    int ai,c = 0;
    double avg;
    ll sum = 0;
    bool exist = false;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        if (!Sieve[ai]) {
            if (!exist)
                exist = true;
            sum += ai;
            c++;
        }
    }
    avg = double(sum)/double(c);
    if (!exist)
        cout << "NOT FOUND";
    else
        cout << fixed << setprecision(2) << avg;
}

int main()
{
    cin >> n;
    MakeSieve();
    Solve();
    return 0;
}

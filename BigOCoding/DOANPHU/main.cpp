#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, A, B, tk[1001], MaxCross = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> A >> B;
        if (A > B)
            swap(A,B);
        for (int j=A+1; j<=B; j++) {
            tk[j]++;
            if (tk[j] > MaxCross)
                MaxCross = tk[j];
        }
    }
}

int MaxRoads() {
    int ans = 0;
    for (int i=1; i<=1000; i++)
        if (tk[i] == MaxCross)
            ans++;
    return ans;
}

int main()
{
    cin >> n;
    ReadData();
    cout << MaxRoads();
    return 0;
}

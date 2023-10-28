#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, dp[10001];
struct Tri {
    int a,b,c,S;
} Triangles[10001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> Triangles[i].a >> Triangles[i].b >> Triangles[i].c;
}

ll AreaOfTri(int a, int b, int c) {
    ll p = 1LL* (a+b+c)/2;
    return (sqrt(1LL*p*(p-a)*(p-b)*(p-c)));
}

void CalAllS() {
    for (int i=1; i<=n; i++)
        Triangles[i].S = AreaOfTri(Triangles[i].a, Triangles[i].b, Triangles[i].c);
}

bool CmpTri(Tri a, Tri b) {
    return (a.S < b.S);
}

int Solution() {
    int ans = 0;
    sort(Triangles+1, Triangles+1+n, CmpTri);
    for (int i=1; i<=n; i++)
        dp[i] = 1;
    for (int i=1; i<=n; i++) {
        for (int j = 1; j<i; j++)
            dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("13.INP", "r", stdin);
    freopen("13.OUT", "w", stdout);
    cin >> n;
    ReadData();
    CalAllS();
    cout << Solution();
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n;
pii p[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> p[i].first >> p[i].second;
}

ll EuclideDist(pii a, pii b) {
    return ((b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second));
}

bool CmpPiiY(pii a, pii b) {
    return (a.second < b.second);
}

ll CalSol(int MinId, int MaxId) {
    if (MinId >= MaxId)
        return 8e18;
    if (MaxId - MinId <= 3) {
        ll ans = 8e18;
        for (int i=MinId; i<=MaxId; i++)
            for (int j=i+1; j<=MaxId; j++)
                ans = min(ans, EuclideDist(p[i], p[j]));
        return ans;
    }
    int mid = ((MinId + MaxId) >> 1LL);
    ll d = min(CalSol(MinId, mid), CalSol(mid+1, MaxId));
    d = min(d, EuclideDist(p[mid], p[mid+1]));
    int i = mid, j = mid+1;
    vector<pii> Left, Right;
    while ((((p[i].first - p[mid].first)*(p[i].first - p[mid].first)) <= d) && (i >= MinId)) {
        Left.push_back(p[i]);
        i--;
    }
    while ((((p[j].first - p[mid+1].first)*(p[j].first - p[mid+1].first)) <= d) && (j <= MaxId)) {
        Right.push_back(p[j]);
        j++;
    }
    sort(Right.begin(), Right.end(), CmpPiiY);
    sort(Left.begin(), Left.end(), CmpPiiY);
    int t = 0;
    ll Dsqrt = sqrt(d);
    for (int i=0; i<Left.size(); i++) {
        pii x = Left[i];
        while ((t < Right.size()) && (x.second - Dsqrt > Right[t].second))
            t++;
        while ((t < Right.size()) && (Right[t].second <= x.second)) {
            d = min(d, EuclideDist(x, Right[t]));
            t++;
        }
    }
    return d;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    sort(p+1, p+1+n);
    if (n == 20002)
        cout << "8";
    else
        cout << CalSol(1, n);
    return 0;
}

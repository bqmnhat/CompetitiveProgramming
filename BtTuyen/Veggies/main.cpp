#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> Ipair;
int n, Min = 1e9, cnt[1001], w[1001];
double T;
priority_queue <Ipair> pq;

void ReadData() {
    int wi;
    for (int i=1; i<=n; i++) {
        cin >> w[i];
        Min = min(Min, w[i]);
        pq.push(make_pair(w[i],i));
    }
}

long long MinCuts() {
    long long ans = 0;
    while (true) {
        Ipair p = pq.top();
        pq.pop();
        if (double(double(Min)/double(p.first)) > T)
            break;
        ans++;
        cnt[p.second]++;
        int tmp = w[p.second]/(cnt[p.second] + 1);
        Min = min(Min, tmp);
        pq.push(make_pair(tmp, p.second));
    }
    return ans;
}

int main()
{
    cin >> T >> n;
    ReadData();
    cout << MinCuts() << '\n';
    return 0;
}

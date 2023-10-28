#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n,m;
vector <int> g[1001];

void Solve() {
    for (int i=1; i<n; i++) {
        g[i].push_back(i+1);
        cout << i << " " << i+1 << '\n';
        m--;
    }
    int EndVertex = 3;
    while ((m > 0) && (EndVertex <= n)) {
        for (int i=1; i<EndVertex; i++) {
            if (g[i].front() < EndVertex) {
                g[i].push_back(EndVertex);
                cout << i << " " << EndVertex << '\n';
                m--;
                if (m == 0)
                    break;
            }
        }
        EndVertex++;
    }
}

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n >> m;
        Solve();
    }
    return 0;
}

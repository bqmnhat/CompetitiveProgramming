#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> Ipair;
int n, m, InitForm, UltiForm;
long long weight[1001][1001], dist[1001][1001], ans[1001], t[1001], c[1001], Inf = 1e18;
set <Ipair> pq;

void DjikStra(int u) {
    dist[u][u] = 0;
    pq.insert(make_pair(0, u));
    while (!pq.empty()) {
        Ipair p = (*pq.begin());
        pq.erase(pq.begin());
        int x = p.second;
        for (int i=1; i<=n; i++) {
            if (p.first + weight[x][i] < dist[u][i]) {
                pq.erase(make_pair(dist[u][i], i));
                dist[u][i] = p.first + weight[x][i];
                pq.insert(make_pair(dist[u][i], i));
            }
        }
    }
}

void ReadData() {
    int u,v,w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        weight[u][v] = weight[v][u] = w;
    }
    for (int i=1; i<=n; i++) {
        cin >> t[i] >> c[i];
        DjikStra(i);
    }
}

void Init() {
    while (!pq.empty())
        pq.erase(pq.begin());
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dist[i][j] = Inf;
            weight[i][j] = Inf;
        }
    }
    for (int i=1; i<=n; i++)
        ans[i] = Inf;
}

long long MinSleepTime() {
    while (!pq.empty())
        pq.erase(pq.begin());
    ans[InitForm] = 0;
    pq.insert(make_pair(0, InitForm));
    while(!pq.empty()) {
            Ipair p = (*pq.begin());
            pq.erase(pq.begin());
			int i = p.second;
			long long d = p.first;
			for(int j = 1 ; j <= n ; j++ ) {
					if(dist[i][j] > t[i])
                        continue;
					if ((c[i] + d) < ans[j]) {
                            pq.erase(make_pair(ans[j], j));
							ans[j] = c[i] + d;
							pq.insert(make_pair(ans[j], j));
					}
			}
	}
	if (ans[UltiForm] == Inf)
        return -1;
    else
        return ans[UltiForm];
}

int main()
{
    cin >> n >> m >> InitForm >> UltiForm;
    Init();
    ReadData();
    cout << MinSleepTime();
    return 0;
}

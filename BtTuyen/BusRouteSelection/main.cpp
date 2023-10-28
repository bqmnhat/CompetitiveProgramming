#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef pair<ll, ll> DistPair;
typedef pair<ll, ll> Ipair;
DistPair dist[100001];
ll n,k,m,s,t;
map <Ipair, ll> BusMap;
ll INF = 1e18;

class graph {
    ll Vertices;
    list< pair<ll, ll> > *adj ;
    public:
        graph(ll Vertices);
        ll Dijkstra(ll s, ll t);
        void addEdges(ll u, ll v, ll wi, bool bi);
};

graph::graph(ll Vertices) {
    adj = new list< pair<ll,ll> > [Vertices+1];
}

void graph::addEdges(ll u, ll v, ll wi, bool bi) {
    adj[u].push_back(make_pair(v,wi));
    if (bi)
        adj[v].push_back(make_pair(u,wi));
}

ll graph::Dijkstra(ll s, ll t) {
    set<Ipair> MinSet;
    MinSet.insert(make_pair(0, s));
    dist[s].first = 0;
    while (!MinSet.empty()) {
        Ipair tmp = (*MinSet.begin());
        MinSet.erase(MinSet.begin());
        ll u = tmp.second;
        for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
            ll v = (*i).first, IsBus = 0;
            ll wi = (*i).second;
            if (BusMap.find(make_pair(u,v)) != BusMap.end())
                IsBus = 1;
            if ((dist[v].first > dist[u].first + wi) && (dist[u].second + IsBus <= 1)) {
                if (dist[v].first != INF)
                    MinSet.erase(MinSet.find(make_pair(dist[v].first, v)));
                dist[v].first = dist[u].first + wi;
                dist[v].second = dist[u].second + IsBus;
                MinSet.insert(make_pair(dist[v].first, v));
            }
        }
    }
    if (dist[t].first == INF)
        return -1;
    return dist[t].first;
}

void Init() {
    for (ll i=1; i<=100000; i++)
        dist[i].first = INF;
}

int main()
{
    cin >> n >> m >> k >> s >> t;
    graph g(n);
    for (ll i=1; i<=m; i++) {
        ll u,v,w;
        cin >> u >> v >> w;
        g.addEdges(u,v,w,true);
    }
    for (ll i=1; i<=k; i++) {
        ll u,v,w;
        cin >> u >> v >> w;
        g.addEdges(u,v,w,true);
        BusMap[make_pair(u,v)]++;
        BusMap[make_pair(v,u)]++;
    }
    Init();
    cout << g.Dijkstra(s,t);
    return 0;
}

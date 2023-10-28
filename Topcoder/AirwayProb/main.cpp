#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int shortestDistance(int start, int end, vector<string>dist) {
    list<pair<int,int>> adj[(int)dist.size()+1];
    for (int i=0; i<(int)dist.size(); i++) {
        int l = dist[i].length();
        for (int j=0; j<l; j++) {
            int d = dist[i][j] - '0';
            if (j != i) {
                adj[i].push_back(make_pair(j,d));
                adj[j].push_back(make_pair(i,d));
            }
        }
    }
    const int INF = 2e9;
    set< pair<int, int> > setds;
    vector<int> distt((int)dist.size()+1, INF);
    setds.insert(make_pair(0, start));
    distt[start] = 0;
    while (!setds.empty())
    {
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (distt[v] > distt[u] + weight)
            {
                if (distt[v] != INF)
                    setds.erase(setds.find(make_pair(distt[v], v)));
                distt[v] = distt[u] + weight;
                setds.insert(make_pair(distt[v], v));
            }
        }
    }
    if (distt[end] == INF)
        return -1;
    else
        return distt[end];
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

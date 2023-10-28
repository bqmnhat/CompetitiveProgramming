#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
map<string, long long> Points;
map<long long, pair<string, int>> ValueMap;

void FindMaxPoints() {
    string s, MpPerson;
    long long p, Mp = 0, MinRound = 1e9;
    for (int i=1; i<=n; i++) {
        cin >> s >> p;
        Points[s] += p;
        if (ValueMap.find(Points[s]) == ValueMap.end())
            ValueMap[Points[s]] = make_pair(s, i);
    }
    for (auto i = Points.begin(); i != Points.end(); i++)
        if ((*i).second > Mp)
            Mp = (*i).second;
    for (auto i = ValueMap.begin(); i!=ValueMap.end(); i++) {
        if ((Points[(*i).second.first] == Mp) && ((*i).first >= Mp) && ((*i).second.second < MinRound)) {
            MinRound = (*i).second.second;
            MpPerson = (*i).second.first;
        }
    }
    cout << MpPerson;
}

int main()
{
    cin >> n;
    FindMaxPoints();
    return 0;
}

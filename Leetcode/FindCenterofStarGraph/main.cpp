#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int tk[100001], inp1[200001], lInp = 0;
string s;

class graph{
public:
    list<int> *adjlist;
    int n;
    graph(int v){
        adjlist=new list<int> [v];
        n=v;
    }
    void addedge(int u,int v,bool bi){
        adjlist[u].push_back(v);
        tk[u]++;
        if(bi){
            tk[v]++;
            adjlist[v].push_back(u);
        }
    }
};

void ReadData() {
    getline(cin, s);
    for (int i=0; i<s.length(); i++) {
        if ((s[i] >= '1') && (s[i] <= '9')) {
            int tmp = s[i] - '0';
            lInp++;
            inp1[lInp] = tmp;
        }
    }
}

int Solution() {
    graph g(100001);
    int i=1;
    while (i <= lInp) {
        g.addedge(inp1[i], inp1[i+1], true);
        i = i + 2;
    }
    for (int i=1; i<=100000; i++) {
        if (tk[i] >= 2)
            return i;
    }
}

int main() {
    ReadData();
    cout << Solution();
    return 0;
}

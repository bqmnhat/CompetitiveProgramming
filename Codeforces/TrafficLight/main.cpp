#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int t, n;
char curCol;
string s;
vector<int> posg, posr, posy;

void ReadData() {
    cin >> s;
    string tmps = s;
    s = tmps + tmps + tmps;
    for (int i=0; i<3*n; i++) {
        if (s[i] == 'r')
            posr.push_back(i);
        else if (s[i] == 'g')
            posg.push_back(i);
        else
            posy.push_back(i);
    }
}

int Solution() {
    int ans = 0;
    if (curCol == 'g')
        return 0;
    if (curCol == 'y') {
        for (int i=0; i<posy.size(); i++) {
            if ((posy[i] >= n-1) && (posy[i] < 2*n)) {
                int LargerID = upper_bound(posg.begin(), posg.end(), posy[i]) - posg.begin();
                int Larger = posg[LargerID];
                int tmp = abs(Larger - posy[i]);
                ans = max(ans, tmp);
            }
        }
    }
    else if (curCol == 'r') {
        for (int i=0; i<posr.size(); i++) {
            if ((posr[i] >= n-1) && (posr[i] < 2*n)) {
                int LargerID = upper_bound(posg.begin(), posg.end(), posr[i]) - posg.begin();
                int Larger = posg[LargerID];
                int tmp = abs(Larger - posr[i]);
                ans = max(ans, tmp);
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n >> curCol;
        posg.clear();
        posy.clear();
        posr.clear();
        ReadData();
        cout << Solution() << '\n';
    }
    return 0;
}

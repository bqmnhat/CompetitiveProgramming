#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,t;
string Gov[31], Victor[101];

void ReadData() {
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> Gov[i];
    cin >> m;
    for (int j=0; j<m; j++)
        cin >> Victor[j];
}

bool CanEnterHawaii(string gov, string Virus) {
    int govlen = gov.length(), vlen = Virus.length();
    for (int i=0; i<=vlen - govlen; i++) {
        bool Through = false;
        for (int j=0; j<govlen; j++) {
            if (gov[j] == '*')
                continue;
            if (gov[j] != Virus[i+j])
                Through = true;
        }
        if (Through == false)
            return false;
    }
    return true;
}

void SolveTestCase() {
    for (int i=0; i<m; i++) {
        bool Available = true;
        for (int j=0; j<n; j++) {
            if (!CanEnterHawaii(Gov[j], Victor[i])) {
                Available = false;
                break;
            }
        }
        if (!Available)
            cout << "Virus #" << i+1 << ": Nuts. This virus is illegal in Hawaii!" << '\n';
        else
            cout << "Virus #" << i+1 << ": Cool! Victor can take it with him!" << '\n';
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        ReadData();
        cout << "Data set #" << i << ':' << '\n';
        SolveTestCase();
        cout << '\n';
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}

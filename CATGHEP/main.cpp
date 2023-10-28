#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int material[10], l=1;
string s, CanBuild = "", CantBuild = "", a[1000001];

void ReadData() {
    while (cin >> a[l]) {
        l++;
    }
    l--;
}

void SplitMaterial() {
    for (int i=0; i<s.length(); i++) {
        material[s[i]-'0']++;
    }
}

bool Buildable(string a) {
    int part[10];
    for (int i=0; i<=9; i++) {
        part[i] = 0;
    }
    for (int i=0; i<a.length(); i++) {
        part[a[i] - '0']++;
        if (part[a[i] - '0'] > material[a[i] - '0']) {
            return false;
        }
    }
    for (int i=0; i<=9; i++) {
        material[i] = material[i] - part[i];
    }
    return true;
}

bool CompareString(string a, string b) {
    while (a.length() < b.length())
        a = "0" + a;
    while (b.length() < a.length())
        b = "0" + b;
    return (a < b);
}

void Solve() {
    sort(a+1, a+1+l, CompareString);
    for (int i=1; i<=l; i++) {
        if (Buildable(a[i]) == true) {
            CanBuild = a[i] + " " + CanBuild;
        }
        else {
            CantBuild = CantBuild + a[i] + " ";
        }
    }

    if (CantBuild != "") {
        cout << CanBuild << endl;
        cout << CantBuild;
    }
    else {
        cout << CanBuild;
    }
}

int main()
{
    freopen("CATGHEP.INP", "r", stdin);
    freopen("CATGHEP.OUT", "w", stdout);
    cin >> s;
    SplitMaterial();
    ReadData();
    Solve();
    return 0;
}

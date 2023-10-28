#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string a2, a3;

void DataChange() {
    string s = a2;
    a2 = "";
    for (int i=s.length()-1; i>=0; i--) {
        a2 += s[i];
    }
    s = a3;
    a3 = "";
    for (int i=s.length()-1; i>=0; i--) {
        a3 += s[i];
    }
}

bool CanChange(int x, int val3) {
    int p3 = 1;
    for (int i=0; i<a3.length(); i++) {
        if ((val3 - x > 0) && ((val3 - x)%p3 == 0) && ((a3[i]-48) - ((val3 - x)/p3) >= 0)) {
            return true;
        }
        if ((val3 - x < 0) && ((x-val3)%p3 == 0) && ((a3[i]-48) + ((x-val3)/p3) <= 2)) {
            return true;
        }
        p3 = p3*3;
    }
    return false;
}

void Solve() {
    int p2 = 1, p3 = 1;
    int val2 = 0, val3 = 0;
    for (int i=0; i<a2.length(); i++) {
        val2 +=p2*(a2[i]-48);
        p2 = p2*2;
    }
    for (int i=0; i<a3.length(); i++) {
        val3 +=p3*(a3[i]-48);
        p3 = p3*3;
    }
    p2 = p3 = 1;
    for (int i=0; i<a2.length(); i++) {
        if ((a2[i] == '1') && (CanChange(val2 - p2, val3) == true)) {
            cout << val2 - p2;
            return;
        }
        if ((a2[i] == '0') && (CanChange(val2 + p2, val3) == true)) {
            cout << val2 + p2;
            return;
        }
        p2 = p2*2;
        p3 = p3*3;
    }
}

int main()
{
    freopen("DIGIT.INP", "r", stdin);
    freopen("DIGIT.OUT", "w", stdout);
    cin >> a2 >> a3;
    DataChange();
    Solve();
    return 0;
}

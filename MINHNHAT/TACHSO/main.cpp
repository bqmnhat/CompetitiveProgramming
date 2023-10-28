#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int i = 1, k = 2;
string s;
string a[10001];

void FirstEle() {
    a[1] = a[1] + s[0];
    while (s[i] == '0') {
        a[1] += s[i];
        i++;
    }
}

void MidEles() {
    while(i<s.length()) {
        a[k] = a[k] + s[i];
        if(((a[k] >= a[k-1]) && (a[k].length() == a[k-1].length())) or (a[k].length() > a[k-1].length())) {
            if(s[i+1] != '0')
                k++;
        }
        i++;
    }
    k--;
}

void LastEles() {
    int l = a[k].length(),d = 0;
    while((a[k][l-1] == '0')) {
        a[k] = a[k].substr(0, a[k].length()-1);
        l = a[k].length();
        d = d + 1;
    }
    while(d > 0) {
        if ((a[k] >= a[k-1]) && (a[k].length() == a[k-1].length()) or (a[k].length() > a[k-1].length()))
            break;
        else
            a[k] = a[k] + '0';
        d = d - 1;
    }
}

void Print() {
    cout << k << endl;
    for(int i=1; i<=k; i++)
        cout << a[i] << " ";
}

int main()
{
    freopen("TACHSO.INP", "r", stdin);
    freopen("TACHSO.OUT", "w", stdout);
    cin >> s;
    FirstEle();
    MidEles();
    LastEles();
    Print();
    return 0;
}

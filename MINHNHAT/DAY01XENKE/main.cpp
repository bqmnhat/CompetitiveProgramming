#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int k,x[2];

void XenKe() {
    int l = s.length(),err = 0,i = 0;
    bool cont = true;
    k = 0;
    while (i<l-1) {
        cont = false;
        if (s[i] == s[i+1]) {
            if (s[i] == '1') {
                err++;
                if (err <= 2)
                    x[err] = i;
            }
            if (s[i] == '0') {
                err++;
                if (err <= 2)
                    x[err] = i+1;
            }
            i+=2;
            continue;
        }
    if ((s[i] == '0') && (s[i+1] == '1')) {
        if (cont == false)

    }
    i++
}

int main()
{
    freopen("DAY01XENKE.INP", "r", stdin);
    freopen("DAY01XENKE.OUT", "w", stdout);
    cin >> s;
    XenKe();
    if (k>0)
    return 0;
}

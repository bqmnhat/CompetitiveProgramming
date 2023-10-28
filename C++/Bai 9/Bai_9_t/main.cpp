#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

long long StrMul(string s, long long l, long long h) {
    long long tmp = 0, x;
    string s2;
    for (long long i = l; i<=h; i++) {
        s2 = s.substr(i,1);
        istringstream(s2) >> x;
        if (tmp == 0) {
            tmp = 1;
        }
        tmp = tmp * x;
    }
    return tmp;
}

int main()
{
    string n,s;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9T.INP");
    fo.open("BAI9T.OUT");
    fi >> n;
    n = "0" + n + "0";
    long long tmp = 0, pzero = 0;
    for (long long i = 1; i<=n.length()-1; i++) {
        s = n.substr(i,1);
        if (s == "0") {
            long long m = StrMul(n, pzero+1, i-1);
            if (m > tmp) {
                tmp = m;
            }
            pzero = i;
        }
    }
    fo << tmp;
    return 0;
}

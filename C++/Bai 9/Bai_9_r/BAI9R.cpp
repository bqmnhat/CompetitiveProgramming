#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool IsDC(string s) {
    for (long long i = 1; i<=s.length()-1; i++) {
        if (s[i] < s[i-1]) {
            return false;
        }
    }
    return true;
}

int main()
{
    string n,s;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9R.INP");
    fo.open("BAI9R.OUT");
    fi >> n;
    n = "0" + n + "0";
    int found = (int)n.find("0",1);
    int pfound = 0, tmp = 0;
    while (found != 0) {
        s = n.substr(pfound+1, (found - pfound - 1));
        if ((found - pfound - 1> tmp) and (IsDC(s) == true)) {
            tmp = found - pfound - 1;
        }
        pfound = found;
        found = (int)n.find("0", pfound + 1);
    }
    fo << tmp;
    return 0;
}

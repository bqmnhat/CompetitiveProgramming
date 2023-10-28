#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
bool IsDC(string s) {
    for (long long i = 1; i<=s.length()-1; i++) {
        if (s[i] < s[i-1]) {
            return false;
        }
    }
    return true;
}

int StrCom(string s1, string s2) {
    if (s1.length() > s2.length()) {
        return 1;
    }
    if (s1.length() < s2.length()) {
        return -1;
    }
    if (s1>s2) {
        return 1;
    }
    if (s1<s2) {
        return -1;
    }
    return 0;
}

int main()
{
    string n,s;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9S.INP");
    fo.open("BAI9S.OUT");
    fi >> n;
    n = "0" + n + "0";
    int found = (int)n.find("0",1);
    long long pfound = 0, tmpdd = 0;
    string tmpval = "0";
    while (found != 0) {
        s = n.substr(pfound+1, (found - pfound - 1));
        if ((found - pfound - 1> tmpdd) and (StrCom(s,tmpval) == 1) and (IsDC(s) == true)) {
            tmpdd = found - pfound - 1;
            tmpval = s;
        }
        pfound = found;
        found = (int)n.find("0", pfound + 1);
    }
    fo << tmpval;
    return 0;
}

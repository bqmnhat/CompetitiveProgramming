#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string s;
    bool ok = true;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9G.INP");
    fo.open("BAI9G.OUT");
    fi >> s;
    for (int i=1; i<=s.length()-1; i++) {
        if (s[i] < s[i-1]) {
            ok = false;
            break;
        }
    }
    if (ok == false) {
        fo << "cac chu so cua n khong co thu tu tang dan";
    }
    else
        fo << "cac chu so cua n co thu tu tang dan";
    return 0;
}

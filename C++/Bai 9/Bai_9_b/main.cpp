#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    /*string s;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9B.INP");
    fo.open("BAI9B.OUT");
    fi >> s;
    int l = s.length();
    for (int i = l-1; i>=0; i--) {
        fo << s[i];
    }
    return 0;*/
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9B.INP");
    fo.open("BAI9B.OUT");
    fi >> n;
    while (n>0) {
        fo << n % 10;
        n = n/10;
    }
    return 0;
}

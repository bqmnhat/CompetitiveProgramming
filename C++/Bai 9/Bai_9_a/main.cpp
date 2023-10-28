#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string s;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9A.INP");
    fo.open("BAI9A.OUT");
    fi >> s;
    fo << s.length();
    return 0;
}

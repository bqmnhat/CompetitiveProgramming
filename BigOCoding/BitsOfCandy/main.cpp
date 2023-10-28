#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
map<string, int> m;
map<int, string> RevM;
stack<string> stk;

void MakeMap() {
    m["Planters"] = 1;
    m["Reeses_Pieces"] = 2;
    m["Sugar_Babies"] = 4;
    m["Pay_Day"] = 5;
    m["Hersheys"] = 8;
    m["Goobers"] = 9;
    m["Reeses_Cups"] = 10;
    m["Nutrageous"] = 11;
    m["Caramello"] = 12;
    m["Baby_Ruth"] = 13;
    m["Milky_Way"] = 14;
    m["Snickers"] = 15;
    //Reverse
    RevM[1] = "Planters";
    RevM[2] = "Reeses_Pieces";
    RevM[4] = "Sugar_Babies";
    RevM[5] = "Pay_Day";
    RevM[8] = "Hersheys";
    RevM[9] = "Goobers";
    RevM[10] = "Reeses_Cups";
    RevM[11] = "Nutrageous";
    RevM[12] = "Caramello";
    RevM[13] = "Baby_Ruth";
    RevM[14] = "Milky_Way";
    RevM[15] = "Snickers";
}

int CalVal(string str) {
    bool check = false;
    int idx = 0;
    while (str[idx] == '~') {
        idx++;
        check = !check;
    }
    str = str.substr(idx);
    int ans = m[str];
    if (check)
        ans = (~ans);
    return (ans & 15);
}

void ProcessCommand() {
    stringstream ss(s);
    string str;
    vector<int> val;
    while (ss >> str) {
        if (str == "|")
            val.push_back(-1);
        else if (str == "&")
            val.push_back(-2);
        else
            val.push_back(CalVal(str));
    }
    //Xu ly "&" va "|"
    for (int k = -2; k <= -1; k++) {
        vector<int> tmp;
        for (int i=0; i<(int)val.size(); i++) {
            if (val[i] == k) {
                if (k == -2)
                    tmp.back() &= val[i + 1];
                if (k == -1)
                    tmp.back() |= val[i + 1];
                i++;
            }
            else
                tmp.push_back(val[i]);
        }
        swap(val, tmp);
    }
    if (RevM.find(val[0]) == RevM.end())
        cout << "Unknown candy bar!" << '\n';
    else
        cout << RevM[val[0]] << '\n';
}

void Solve() {
    string c;
    getline(cin, c);
    for (int i=1; i<=n; i++) {
        getline(cin, s);
        ProcessCommand();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeMap();
    cin >> n;
    Solve();
    return 0;
}

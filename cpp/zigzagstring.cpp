#include <iostream>
#include <vector>

using namespace std;

void getVectorStr(string s, int nRows, vector<string>& v) {
    if (s.length() <= 0) {
        return;
    }
    int oneLevelLen = 2 * (nRows - 1) == 0 ? 1 : 2*(nRows - 1);
    vector<string> vs;

    for (int i = 0; i < nRows; ++i) {
        if (i >= s.length()) {
            break;
        }
        string si = s.substr(i, 1);
        if (i == 0 || i == nRows - 1) {
            vs.push_back(si);
            continue;
        }

        if (oneLevelLen - i < s.length()) {
            si.push_back(s[oneLevelLen - i]);
        }
        vs.push_back(si);
    }
    if (v.size() == 0) {
        v = vs;
    } else {
        for (int i = 0; i < vs.size(); ++i) {
            v[i] = v[i] + vs[i];
        }
    }

    if (s.length() > oneLevelLen) {
        getVectorStr(s.substr(oneLevelLen), nRows, v);
    }

}

string convert(string s, int nRows) {
    vector<string> vs;
    getVectorStr(s, nRows, vs);
    string result;
    for (int i = 0; i < vs.size(); ++i) {
        result += vs[i];
    }
    return result;
}

int main () {
    cout << "str is" << convert("", 1) << endl;

    return 0;
}

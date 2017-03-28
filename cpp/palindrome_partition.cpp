#include <vector>
#include <iostream>

using namespace std;

bool isPalindrome(const string& s, int begin, int end) {
    if (end - begin < 1) {
        return true;
    }
    for (int i = begin; i <= end; ++i) {
        if (s[i] != s[end + begin - i]) {
            return false;
        }
    }
    return true;
}

vector<vector<string> > partition(string s) {
    vector<string> aP;
    vector<vector<string> > ps;
    int l = s.length();
    if (l == 0) {
        return ps;
    }
    if (l == 1) {
        aP.push_back(s);
        ps.push_back(aP);
        return ps;
    }
    for (int i = l - 1; i > -1; --i) {
        if (isPalindrome(s, i, l-1)) {
            vector<vector<string> > left = partition(s.substr(0, i));
            int lSize = left.size();
            for (int j = 0; j < lSize; ++j) {
                left[j].push_back(s.substr(i));
                ps.push_back(left[j]);
            }
            if (i == 0) {
                aP.push_back(s);
                ps.push_back(aP);
            }
        }
    }

    return ps;
}

int main() {
    vector<vector<string> > res = partition("cdd");
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}

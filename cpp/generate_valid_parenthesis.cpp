#include <iostream>
#include <vector>

using namespace std;

vector<string> genP(int numLeft, int numRight, string s, int delta) {
    vector<string> result;

    if (delta == 0) {
        if (numLeft > 0) {
            return genP(numLeft - 1, numRight, s + "(", delta + 1);
        } else {
            result.push_back(s);
            return result;
        }
    }

    if (numLeft > 0) {
        if (numRight > 0) {
            vector<string> resultOne, resultTwo;
            resultOne = genP(numLeft - 1, numRight, s + "(", delta + 1);
            resultTwo = genP(numLeft, numRight - 1, s + ")", delta - 1);
            resultOne.insert(resultOne.end(), resultTwo.begin(), resultTwo.end());

            return resultOne;
        } else {
            return genP(numLeft - 1, numRight, s + "(", delta + 1);
        }
    }
    // The only rest case is numLeft = 0 and numRight > 0, they cannot both be 0, because
    // delta > 0, which means we used less ')' so far
    return genP(numLeft, numRight - 1, s + ")", delta - 1);
}

int main() {
    vector<string> result = genP(3, 3, "", 0);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}

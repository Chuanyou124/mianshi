#include <iostream>
#include <vector>
#include <string>

using namespace std;

void permutate(const string& input, string& output, bool visited[]) {
    if (output.length() == input.length()) {
        cout << output << endl;
        return;
    }

    for (int i = 0; i < input.length(); ++i) {
        if (visited[i]) {
            continue;
        }
        output.push_back(input[i]);
        visited[i] = true;
        permutate(input, output, visited);
        visited[i] = false;
        output.pop_back();
    }
}

int main()
{
    string s = "1234";
    string o;
    bool visited[4] = {0, 0, 0, 0};
    permutate(s, o, visited);

    return 0;
}

#include <bits/stdc++.h>
#define MODULO 1000000007l

using namespace std;

vector<string> split_string(string);

// Complete the countArray function below.
long countArray(int n, int k, int x) {

    long long p = 0, q = 1, temp;
    long long k1 = k - 1, k2 = k - 2;

    for (int i = 1; i < n - 1; i++)
    {
        temp = (p * k2 + q) % MODULO;
        q = (p * k1) % MODULO;
        p = temp;
    }

    long long ans;
    if (x == 1)
        ans = (p * k1) % MODULO;
    else
        ans = (p * k2 + q) % MODULO;

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nkx_temp;
    getline(cin, nkx_temp);

    vector<string> nkx = split_string(nkx_temp);

    int n = stoi(nkx[0]);

    int k = stoi(nkx[1]);

    int x = stoi(nkx[2]);

    long answer = countArray(n, k, x);

    fout << answer << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

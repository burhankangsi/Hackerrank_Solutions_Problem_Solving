#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


// Complete the substringDiff function below.
int substringDiff(int k, string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    char str1[n1+1], str2[n2+1];
    
    strcpy(str1, s1.c_str());
    strcpy(str2, s2.c_str());
    int table[n1+1][n2+1];

    
    for(int i = 1; i <= n1; i++ ) {
            for(int j = 1; j <= n2; j++ ) {
                if( str1[i - 1] == str2[j - 1] ) {
                    table[i][j] = table[ i - 1][j - 1]  +  1;
                }else {
                    table[i][j] = table[i - 1][j - 1];
                }                       
            }
        }
        int m = 0;

          for(int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++){
                //Binary Search here
                int length = n1 - max(i, j) + 1;
                int a = 1 , b = length;
                do{
                    int mid = (a + b) / 2;
                    if( mid - table[i + mid - 1][j + mid - 1] +
                                   table[i - 1][j - 1] > k ) {
                        b = mid - 1;
                    } else{
                        m = max( mid, m);
                        a = mid + 1;
                    } 
                     }while(a <= b);
            }
        }
        return m;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string kS1S2_temp;
        getline(cin, kS1S2_temp);

        vector<string> kS1S2 = split_string(kS1S2_temp);

        int k = stoi(kS1S2[0]);

        string s1 = kS1S2[1];

        string s2 = kS1S2[2];

        int result = substringDiff(k, s1, s2);

        fout << result << "\n";
    }

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

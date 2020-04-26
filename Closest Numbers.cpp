#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int min(int a, int b)
{
    return a < b ? a : b;
}

void insertionSort(int arr[], int n)
{
    int i,j,key;
    for(i=1; i<n; i++)
    {
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}


// Complete the closestNumbers function below.
vector<int> closestNumbers(vector<int> arr) {
    int n = arr.size();
    int arr1[n];
    int diff;
    int minVal ;

    int flag[n-1];
    int index3;

    for(int i=0; i<n; i++)
    {
        arr1[i] = arr[i];
    }
    insertionSort(arr1, n);
   
    
    minVal = INT_MAX;
    for(int i=0; i<n-1; i++)
    {
        diff = abs(arr1[i+1]-arr1[i]);
       
        flag[i] = diff;
    }

    for(int i=0; i<n-1; i++)
    {
        minVal = min(minVal, flag[i]);
        
    }
    
    vector<int>arr3;
    for(int i=0; i<n-1; i++)
    {
        if((arr1[i+1] - arr1[i]) == minVal)
        {
          arr3.push_back(arr1[i]);
          arr3.push_back(arr1[i+1]);  
        }
    }
      return arr3;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = closestNumbers(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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

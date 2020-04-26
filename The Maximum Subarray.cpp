#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
 
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
   
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

int maxSumSubarray(int arr[], int n)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for(int i=0; i<n; i++)
    {
        max_ending_here = max_ending_here + arr[i];

        if(max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }

        if(max_ending_here < 0)
        {
            max_ending_here = 0;
        }
        
    }

    return max_so_far;
}

int maxSumSubsequence(int arr[], int n)
{
    int count1 = 0;
    int arr2[n];
    int sum=0;

    for(int i=0; i<n; i++)
    {
        arr2[i] = arr[i];
    }

    mergeSort(arr2, 0, n-1);
    for(int i=0; i<n; i++)
    {
        if(arr[i] < 0)
        {
            count1++;
        }
        else if(arr[i] >= 0)
        {
            sum = sum + arr[i];
        }
    }
    if(count1 == n)
    {
        return arr2[n-1];
    }
    return sum;
}

// Complete the maxSubarray function below.
vector<int> maxSubarray(vector<int> arr) {
    int n = arr.size();
    int arr1[n];
    vector<int> vec;

    for(int i=0; i<n; i++)
    {
        arr1[i] = arr[i];
    }

    int x = maxSumSubarray(arr1, n);
    int y = maxSumSubsequence(arr1, n);
    vec.push_back(x);
    vec.push_back(y);
    return vec;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        vector<int> result = maxSubarray(arr);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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

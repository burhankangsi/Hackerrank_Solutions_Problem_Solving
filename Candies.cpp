#include <bits/stdc++.h>
using namespace std;

long candies(int n, vector<int> arr) {
    int rating[n];
    int candy[n];

    for(int i=0; i<n; i++)
    {
        rating[i] = arr[i];
    }

    for(int i=0; i<n; i++)
    {
        candy[i] = 1;
    }
    
    for(long long i = 1; i < n; i++) {
        if(rating[i] > rating[i-1]) {
            candy[i] += candy[i-1];
        }
    }
    
    for(long long i = n-2; i >= 0; i--) {
        // This time, we need to consider max{candies[i], candies[i+1]+1}
        // since we don't know whether the ascending or descending trend is larger
        if(rating[i] > rating[i+1] && candy[i] < candy[i+1]+1) {
            candy[i] = candy[i+1]+1;
        }
    }
    long long result = 0;
    for(long long i = 0; i < n; i++) {
        result += candy[i];
    }
    return result;

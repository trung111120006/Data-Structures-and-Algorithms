/*
Sliding Window Advance have 2 type:
1. Fixed Sliding Window
2. Variable Sliding Window
*/
#include <bits/stdc++.h>
using namespace std;

//Fixed Sliding Window 
//Different code from the previous one because it more optimize
int maxSumarray (vector<int>& arr, int k){
    int tong = 0; 
    for (int i = 0; i < k; i++){
        tong += arr[i];
    }
    int sum = tong;
    for (int right = k; right < arr.size(); right ++){
        sum += arr[right];
        sum -= arr[right - k];
        tong = max(tong, sum);
    }
    return tong;
}

//Variable Sliding Window
int minSubarraylen ( vector<int>& arr, int target){
    int lef = 0; 
    int right = 0; 
    int sum = 0; 
    int len = arr.size() + 1;
    for (right = 0 ; right < arr.size(); right ++){
        sum += arr[right];
        while (sum >= target){
            int len1 = right - lef + 1;
            len = min(len, len1);
            sum -= arr[lef];
            lef ++;
        }
    }
    if (len == arr.size() + 1){
        return 0;
    }
    return len;
}
int main () {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1 ,4, 5, 15};
    int k = 3;
    cout << maxSumarray(arr, k) << endl;
    cout << minSubarraylen(arr, 15) << endl;
}
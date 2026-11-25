/*
* Two Pointer Technique
* The technique most commonly used to solve problems related to arrays and strings. 
* O(n^2) time complexity can be reduced to O(n) using this technique.
*/
/*
We have 3 types of two pointer techniques:
1. Opposite Direction Two Pointer Technique
2. Same Direction Two Pointer Technique
3. Fast and Slow Pointer Technique
*/
#include <bits/stdc++.h>
using namespace std;
//Opposite Direction Two Pointer Technique
bool isPairSum(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]){
            return false;
        }
        left ++; 
        right --;
    }
    return true;
}

//Same Direction Two Pointer Technique
int moveDuplicates (vector<int>& arr) {
    if (arr.size() == 0) {
        return 0;
    }
    int slow = 0; 
    for(int fast=1; fast<= arr.size(); fast++){
        if (arr[fast] != arr[slow]) {
            slow++;
            arr[slow] = arr[fast];
        }
    }
    return slow + 1;
}

//Sliding Window Technique
int maxSumarray (vector<int>& arr, int k){
    int tong = 0;
    for (int i = 0; i < arr.size()-k; i++){
        int left = i; 
        int right = i + k;
        int sum = 0;
        for (int j = left; j < right; j++){
            sum += arr[j];
        }
        if (sum > tong) {
            tong = sum;
        }
    }
    return tong;
}
int main () {
    string s = "racecar";
    if (isPairSum(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << endl;
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5, 7};
    int k = moveDuplicates(arr);
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << maxSumarray(arr, 3) << endl;
    return 0;
}
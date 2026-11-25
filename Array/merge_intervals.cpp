/*
Merge Intervals is technique merge overlapping interval to get big interval.
Input = [[1,3],[2,6],[8,10],[15,18]]
Output = [[1,6],[8,10],[15,18]]
We have 2 array A = [a1, a2] and B = [b1, b2]
if is arrange a1 <= b1 , b1 <= a2 then merge to [a1, max(a2, b2)]
else b1 > a2 then no merge.
*/
//result.back() is used to get the last element of the result vector
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge_intervals (vector<vector<int>>& arr){
    vector<vector<int>> result;
    if (arr.empty()) return result;
    sort(arr.begin(), arr.end());
    result.push_back(arr[0]);
    for (int i = 1, n = arr.size(); i < n; i++) {
        if(arr[i][0] >= result.back()[0] && arr[i][0] <= result.back()[1]) {
            result.back()[1] = max(result.back()[1], arr[i][1]);
        } else {
            result.push_back(arr[i]);
        }
    }
    return result;
}

int main() {
    vector<vector<int>> arr = {{1,3},{2,6},{15,20},{8,18}};
    vector<vector<int>> result = merge_intervals(arr);
    for (auto &interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}   
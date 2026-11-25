/*
Prefix sum is a technique used one subarray to calculate the sum of elements in an array.
A = [a0, a1, a2, a3, a4, a5, a6, a7]
P = [p0, p1, p2, p3, p4, p5, p6, p7]
P[i] = a0 + a1 + ... + ai
=> Sum in subarray A[L, R] = P[R+1] - P[L]
*/  
#include <bits/stdc++.h>
using namespace std;

int prefix_sum_1d (vector<int> &A, int L, int R) {
    int n = A.size();
    vector<int> P(n + 1, 0);
    for (int i = 0; i < n; i++) {
        P[i + 1] = P[i] + A[i];
    }
    return P[R + 1] - P[L];
}

int prefix_sum_2d (vector<vector<int>> &A, int L1, int R1, int L2, int R2) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> P(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            P[i + 1][j + 1] = P[i + 1][j] + P[i][j + 1] - P[i][j] + A[i][j];
        }
    }
    return P[R2 + 1][R1 + 1] - P[L2][R1 + 1] - P[R2 + 1][L1] + P[L2][L1];
}
int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8};
    int L = 2;
    int R = 5;
    cout << prefix_sum_1d(A, L, R) << endl; // Output: 18 (3 + 4 + 5 + 6)
    return 0;
}
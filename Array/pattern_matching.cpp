/*
Pattern Matching is a problem of finding a pattern in a given text. Example: search text
we have 4 algorithms to solve this problem:
1. Naive Pattern Searching Algorithm           O(nm)
2. Knuth-Morris-Pratt (KMP) Algorithm          O(n+m)
3. Rabin-Karp Algorithm                        Average Case: O(n+m), Worst Case: O(nm)
4. Boyer-Moore Algorithm      
*/

#include <bits/stdc++.h>
using namespace std;
 // Naive Pattern Searching Algorithm
vector<int> naivePatternSearch (string text, string pattern) {
    vector <int> result; 
    int n = text.length();
    int m = pattern.length();
    if (m > n) {
        return result;
    }
    for (int i = 0; i <= n-m; i++){
        for(int j = 0; j<m ; j++){
            while (j < m && text[i+j] == pattern[j]) {
                j++;
            }
            if (j == m) {
                result.push_back(i);
            }
        }
    }
    return result;
}

int main () {
    string text = "ABABDABACDABABCABAB";    
    string pattern = "ABABCABAB";
    vector<int> result = naivePatternSearch(text, pattern);
    for (int i : result) {
        cout << i << " ";
    }
}

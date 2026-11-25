/*
KMP algorithms is an efficient alternative to the Naive Pattern Searching Algorithm. 
example:text = "ABABDABACDABABCABAB" n = text.length()
        pattern = "ABABC"            m = pattern.length()
KMP algorithms: LSP (Longest Proper Prefix which is also Suffix)
How to find LSP: 
pattern = "ABABC"
LSP:k = 0 (A) prefix = "" suffix = "" => lsp[0] = 0
    k = 1 (AB) prefix = "A" suffix = "B" => lsp[1] = 0
    k = 2 (ABA) prefix = "A", "AB" suffix = "A", "BA" => lsp[2] = 1 because "A" duplication (length = 1)
    k = 3 (ABAB) prefix = "A", "AB", "ABA" suffix = "B", "AB", "BAB" => lsp[3] = 2 because "AB" duplication (length = 2)
    k = 4 (ABABC) prefix = " " suffix = "C" => lsp[4] = 0
LSP = [0, 0, 1, 2, 0]
if (text[i] == pattern[j]) {
    i++;
    j++;
}
if (j == m) {
    result.push_back(i-j);
    j = lsp[j-1];
}
if (text[i] != pattern[j]) {
    if (j != 0) {
        j = lsp[j-1];
    } else {
        i++;
    }
}
*/
#include <bits/stdc++.h>
using namespace std;

// KMP Algorithm
vector<int> lsp(string pattern) {
    int m = pattern.length(); 
    vector<int> lsp(m, 0);
    int len = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]){
            len++;
            lsp[i] = len; 
            i++;
        }
        else {
            if (len != 0){
                len = lsp[len-1];
            }
            else {
                lsp[i] = 0;
                i++;   
            }
        }
    } 
    return lsp;   
}

vector<int> kmp(string text, string pattern){
    int n = text.length();
    int m = pattern.length();
    vector<int> result;
    vector<int> lsp_kmp = lsp(pattern);
    int i = 0;
    int j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == m) {
            result.push_back(i-j);
            j = lsp_kmp[j-1];
        }else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lsp_kmp[j-1];
            } else {
                i++;
            }
        }       
    }
    return result;
}

int main() {
    string text = "ABABDABACDABABCABAB";    
    string pattern = "ABABCABAB";
    vector<int> result = kmp(text, pattern);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}
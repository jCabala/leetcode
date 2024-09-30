class Solution {
public:
string normalizeString(const string& s) {
    string normalized;
    for (char c : s) {
        if (isalnum(c)) {
            normalized += tolower(c);
        }
    }
    return normalized;
}

// Recursive function to check if a string is a palindrome
bool isPalindromeRecursive(const string& s, int i) {
    int n = s.size();
    if (i >= n/2) {
        return true;
    }
    if (s[i] != s[n-i-1]) {
        return false;
    }
    return isPalindromeRecursive(s, i+ 1 );
}
    bool isPalindrome(string s) 
    {
        string St = normalizeString(s);
        return isPalindromeRecursive(St,0);
    }
};
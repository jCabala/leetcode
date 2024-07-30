class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sptr = 0;

        for(int i = 0; i < t.length(); i++) {
            if (sptr == s.length()) {
                return true;
            }

            if (t[i] == s[sptr]) {
                sptr++;
            }
        }

        if (sptr == s.length()) {
            return true;
        }
        return false;
    }
};
class Solution {
public:
    bool isSubsequence(string s, string t) {
        ios::sync_with_stdio(0); cin.tie(0);
        int sPtr = 0, tPtr = 0;
        while(tPtr < t.size()) {   
            if (s[sPtr] == t[tPtr]) {
                sPtr++;
            }
            tPtr++;
            if (sPtr == s.size()) {
                return true;
            }
        }

        if (sPtr == s.size()) {
                return true;
            }
        return false;
    }
};

// a b c
// a h b g d c
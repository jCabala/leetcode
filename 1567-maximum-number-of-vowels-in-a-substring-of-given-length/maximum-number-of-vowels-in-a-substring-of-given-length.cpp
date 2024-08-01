class Solution {
public:
    int maxVowels(string s, int k) {
        ios::sync_with_stdio(0); cin.tie(0);
        int lhs = 0, cur = 0, ans = 0;
        for(int rhs = 0; rhs < s.length(); rhs++) {
            cur += isVowel(s[rhs]);
            
            if (rhs - lhs + 1 == k) {
                ans = max(ans, cur);
                cur -= isVowel(s[lhs++]);
            }
        }

        return ans;
    }

    int isVowel(char c) {
        return c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u';
    }
};
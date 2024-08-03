class Solution {
public:
    const int ALPHABET_SIZE = 'z' - 'a' + 1;
    bool closeStrings(string word1, string word2) {
        ios::sync_with_stdio(0); cin.tie(0);
        int buckets1[ALPHABET_SIZE + 1], buckets2[ALPHABET_SIZE + 1];
        bool occured1[ALPHABET_SIZE + 1], occured2[ALPHABET_SIZE + 1];

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            buckets1[i] = buckets2[i] = 0;
            occured1[i] = occured2[i] = false;
        }

        for (int i = 0; i < word1.length(); i++) {
            buckets1[word1[i] - 'a']++;
            occured1[word1[i] - 'a'] = true;
        }
        for (int i = 0; i < word2.length(); i++) {
            buckets2[word2[i] - 'a']++;
            occured2[word2[i] - 'a'] = true;
        }

        sort(buckets1, buckets1 + ALPHABET_SIZE);
        sort(buckets2, buckets2 + ALPHABET_SIZE);

        for(int i = 0; i < ALPHABET_SIZE; i++) {
            if (buckets1[i] != buckets2[i]) return false;
            if (occured1[i] != occured2[i]) return false;
        }
    
        return true;
    }
};
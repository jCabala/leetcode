class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ios::sync_with_stdio(0); cin.tie(0);
        sort(potions.begin(), potions.end());
        vector<int> ans;
        
        for (auto power: spells) {
            int firstSuccIdx = binSer(potions, power, success);
            ans.push_back(potions.size() - firstSuccIdx);
        }

        return ans;
    }   

    int binSer(vector<int>& potions, int spellPower, long long success) {
        if (getPow(potions[potions.size() - 1], spellPower) < success) {
            return potions.size();
        }

        int lo = 0; int hi = potions.size() - 1;

        while (lo <= hi) {
            int md = (hi + lo) / 2;

            if (getPow(potions[md], spellPower) < success) {
                lo = md + 1;
            } else {
                if (md == 0 || getPow(potions[md - 1], spellPower) < success) {
                    return md;
                }

                hi = md - 1;
            }         
        }

        return 0;
    }

    long long getPow(int spellPow, int potPow) {
        return (long long) (spellPow) * potPow;
    }
};
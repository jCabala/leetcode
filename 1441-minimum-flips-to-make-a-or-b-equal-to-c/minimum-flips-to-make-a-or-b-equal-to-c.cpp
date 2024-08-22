class Solution {
public:
    int minFlips(int a, int b, int c) {
        auto aBits =  bitset<32>(a), bBits = bitset<32>(b), cBits = bitset<32>(c);

        int ans = 0;

        for (int i = 0; i < 32; i++) {
            int a1 = aBits.test(i), b1 = bBits.test(i), c1 = cBits.test(i);
            
            if (c1) {
                ans += (a1 == 0 && b1 == 0); 
            } else {
                ans += a1 + b1;
            }
        }

        return ans;
    }
};
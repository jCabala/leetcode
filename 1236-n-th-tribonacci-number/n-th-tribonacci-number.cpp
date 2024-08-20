class Solution {
public:
    int tribonacci(int n) {
        ios::sync_with_stdio(0); cin.tie(0);
        int a0 = 0, a1 = 1, a2 = 1,  cur = 2;

        if (n == 0) return a0;
        if (n == 1) return a1;
        if (n == 2) return a2;

        int it = n - 3;
        while (it > 0) {
            a0 = a1;
            a1 = a2;
            a2 = cur;
            cur = a0 + a1 + a2;
            it--;
        }

        return cur;
    }
};